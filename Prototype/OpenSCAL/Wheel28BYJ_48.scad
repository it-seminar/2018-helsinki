use <StepperMotor28BYJ_48.scad>
use <Wheel.scad>

module wheel28BYJ_48(spokeCount = 12)
{
    difference()
    {
        wheel(spokeCount);
        translate([0,0,12])
            rotate([180,0,0])
                resize([6.2,6.2,0]) AxisCut_28BYJ_48();
    }   
}

wheel28BYJ_48(7);
