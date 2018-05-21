use <StepperMotor28BYJ_48.scad>;

Chassis();

module Chassis(length = 120, width = 100, thickness = 5, wheelRadius = 40)
{
    difference()
    {
        union()
        {
            translate([0,0,0.5*thickness])
            cube([width, length, thickness], center = true);
            translate([-0.5*(width-thickness), -0.5*(length-55), 22.5])
            cube([thickness,55,40], center = true);
            translate([0.5*(width-thickness), -0.5*(length-55), 22.5])
            cube([thickness,55,40], center = true);
            translate([0,0.5*length - 20,0])
            cylinder(d=10, h=23+wheelRadius, $fn=64);
            translate([0,0.5*length - 20,23+wheelRadius])
            sphere(d=10, $fn=64);
            
        }
        union()
        {
            translate([-0.5*(width-thickness), -0.5*(length-55), 25])
            rotate([90,0,90])
            MotorCut_28BYJ_48();
            translate([0.5*(width-thickness), -0.5*(length-55), 25])
            rotate([90,0,-90])
            MotorCut_28BYJ_48();
            translate([-0.5*width+20,-0.5*(length-55),2.5])
            cube([20,10,10], center=true);
            translate([0.5*width-20,-0.5*(length-55),2.5])
            cube([20,10,10], center=true);
        }
    }
}