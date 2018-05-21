DoubleLightSensor();

module DoubleLightSensor()
{
    union()
    {
        difference()
        {
            translate([0,0,5])
            cube([25, 10, 10], center=true);
            translate([0,0,-1])
            cylinder(d=5.4, h=12, $fn=64);
            translate([7.5,0,-1])
            cylinder(d=5.4, h=12, $fn=64);
            translate([-7.5,0,-1])
            cylinder(d=5.4, h=12, $fn=64);
        }
        //translate([17,0,25])
        //cube([10,10,50],center=true);
        //translate([-17,0,25])
        //cube([10,10,50],center=true);
    }
}