#!/usr/bin/perl
use 5.010 ;
#open file,"<$ARGV[1]" or die " can't open file $ARGV[1]";
open file,"<$ARGV[1]" or END ;
@lines=<file>;
close file ;

shift @lines for (1..3) ; # remove head of file
pop @lines for (1..6) ; # remove bottom of file

##### make aa value array and folder #####
undef $flag ;
@aaval=('X','A','R','N','D','C','Q','E','G','H','I','L','K','M','F','P','S','T','W','Y','V');
$aaval{$_}=$flag++ for @aaval ;

##### get the whole file information including elements and sequence
$flag=0 ;
for $line(@lines){
	#print $line ; #debug
	push(@sequence,($line=~/\s*\d+\s+(\w)/));
	$pssmline=substr($line,10,60);
	#say $pssmline ; #debug
	$pssm[$flag]=[map{s/ //;$_}($pssmline=~/(...)/g)] ;
	ArrayMaxMin();
    $flag++ ;	
}
#print join(" ",@sequence) ; #debug
#say "$max $min" ; #debug

	
##### scaling elements (x-min/max-min)
for $line (0..$flag){
	$pssmscale[$line]=[map{($_-$min)/($max-$min)}@{$pssm[$line]}]; # original scale method
}
#say $pssmscale[0][0]; #debug
#say for @{$pssm[0]} ; #debug

##### make pssm400
for $line (0..$flag){
	#say "$sequence[$line] $aaval{$sequence[$line]}"; #debug
	$pssm400[$aaval{$sequence[$line]}][$_]+=$pssmscale[$line][$_] for (0..19) ;
}

$lable=1 ;
print "$ARGV[0]";
for $x (1..20){
	for $y (0..19){
		print $pssm400[$x][$y]?" $lable:$pssm400[$x][$y]": "$lable0"		;
		#print $pssm400[$x][$y]? (" $lable:" . 1/(1+exp(-$pssm400[$x][$y]))) : "$lable0"           ; # logistic scale
		$lable++ ;
	}
	#print $/ ;
}
print $/ ;
##### get the local maximum and minumum in this file
sub ArrayMaxMin{
	$max=$max>$pssm[$flag]->[$_]?$max:$pssm[$flag]->[$_] for (0..19) ;
	$min=$min<$pssm[$flag]->[$_]?$min:$pssm[$flag]->[$_] for (0..19) ;
}
