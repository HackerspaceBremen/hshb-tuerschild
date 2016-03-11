wand = 2;
breite = 60;
laenge = 60;
hoehe = 20;

rled = 2.5;
dipbreite = 4;
diplaenge = 10;

$fn = 50;

difference()
{
    cube([breite, laenge, hoehe]);
    translate([wand,wand,wand])
        cube([breite-2*wand,laenge-2*wand,hoehe-wand]);
    translate([15,laenge*0.25-0.5*dipbreite,0])
        cube([diplaenge,dipbreite,wand]);
    translate([15,laenge*0.5-0.5*dipbreite,0])
        cube([diplaenge,dipbreite,wand]);
    translate([15,laenge*0.75-0.5*dipbreite,0])
        cube([diplaenge,dipbreite,wand]);
    translate([15+diplaenge+15,laenge*0.25,0])
        cylinder(r=rled,h=wand);
    translate([15+diplaenge+15,laenge*0.5,0])
        cylinder(r=rled,h=wand);
    translate([15+diplaenge+15,laenge*0.75,0])
        cylinder(r=rled,h=wand);
}