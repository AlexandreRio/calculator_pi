    #!/usr/bin/perl -w

    use strict;
    use Spreadsheet::ParseExcel;

my @array=('m_ShortDesc','m_LongDesc','m_Category','m_Source','m_Formula','m_Result_Unit','m_Input_parameter','m_Input_unit','m_Input_parameter1','m_Input_unit1','m_Input_parameter2','m_Input_unit2','m_Input_parameter3','m_Input_unit3','m_Input_parameter4','m_Input_unit4','m_Input_parameter5','m_Input_unit5','m_Input_parameter6','m_Input_unit6','m_Input_parameter7','m_Input_unit7','m_Input_parameter8','m_Input_unit8','m_Input_parameter9','m_Input_unit9'
);

my $header = q|

/* WARNING - DO NOT EDIT FILE - FILE IS AUTO GENERATED BY FUNCTIONS2CPP.PL*/

/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  ROUTE Plugin
 * Author:   SaltyPaws
 *
 ***************************************************************************
 *   Copyright (C) 2012 by Brazil BrokeTail                                *
 *   $EMAIL$                                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#include "functions.h"

 CFormula::CFormula(void)
{
    this->Selected_Formula = 1;
|;

my $footer = q|
}
|;

my $filename='functions.cpp';
open(my $fh, '>', "$filename");

    my $parser   = Spreadsheet::ParseExcel->new();
    my $workbook = $parser->parse('functions.xls');
    my $empty_line="yes";

    if ( !defined $workbook ) {
        die $parser->error(), ".\n";
    }

    my $Startrow_found="No";
    print $fh "$header\n";

    for my $worksheet ( $workbook->worksheets() ) {

        my ( $row_min, $row_max ) = $worksheet->row_range();
        my ( $col_min, $col_max ) = $worksheet->col_range();

        for my $row ( $row_min .. $row_max ) {
            for my $col ( $col_min .. $col_max ) {

                my $cell = $worksheet->get_cell( $row, $col );
                next unless $cell;
		$a=$cell->unformatted();

		if ($a =~ /-------------->/)
			{
			print "Found Starting Row",$row,"\n";
			$row_min=$row+3;
			$Startrow_found="yes";
			last;
			}
                #print "\n";
            }
        }

	if ($Startrow_found =~ /No/)
		{
		print "Start row sequence not found, error in spreadsheet\n";
		exit 0;
		}
        for my $row ( $row_min .. $row_max ) {
            for my $col ( $col_min .. $col_max ) {

                my $cell = $worksheet->get_cell( $row, $col );
                #next unless $cell;
		if ($cell and $col==0) {$empty_line="no";} 
		if (!$cell and $col==0) {$empty_line="yes";print "Empty:"} 
		if ($cell)
			{
		        #print "Row, Col    = ($row, $col)\n";
		        #print "Value       = ", $cell->value(),       "\n";
		        #print "Unformatted = ", $cell->unformatted(), "\n";
			$a=$cell->unformatted();
			$a=~ s/\R/\\n/g; #Re~ s/\R//g; #remove line feed, page feed, CR
			$a =~ s/[^\w .:+-=\*()\^\/\\]//g;
			$a=~ s/ {3,}/\\t/g; #replace double space with single space
			$a=~ s/\t* {2}/ /g; #replace double space with single space
			}
		else
			{
				$a="";
			}

		if ($empty_line =~ /no/ and $col<@array) {
			print $fh "this->$array[$col].Add(_(\"$a\"))\;\n"; 
			print  "this->$array[$col].Add(_(\"$a\"))\;\n"; 
		}

                
            }
	$empty_line="yes"; 
	print $fh "\n";
        }
    }
print $fh "$footer\n";
close ($fh); 
