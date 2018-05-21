MotorCut_28BYJ_48();
//AxisCut_28BYJ_48();

module MotorCut_28BYJ_48()
{
	union()
	{
		cylinder(d=29.2,h=25,$fn=64);
		translate([0,-10.6,12.5])
		cube([16,16,25], center=true);
		hull()
		{
			translate([17.5,0,0])
			cylinder(d=8, h=25, $fn=64);
			translate([-17.5,0,0])
			cylinder(d=8, h=25, $fn=64);
		}
		translate([17.5,0,-1])
		cylinder(d=3.8,h=50,$fn=64,center=true);
		translate([-17.5,0,-1])
		cylinder(d=3.8,h=50,$fn=64,center=true);
		translate([0,8,-12])
		cylinder(d=12,h=28,$fn=64,center=true);
	}
}

module AxisCut_28BYJ_48()
{
    translate([0,0,-2])
	difference()
	{
		cylinder(d=5.2,h=10.6,$fn=64);
		translate([0,4.8,8])
		cube([10,6,8], center=true);
		translate([0,-4.8,8])
		cube([10,6,8], center=true);
	}
}
