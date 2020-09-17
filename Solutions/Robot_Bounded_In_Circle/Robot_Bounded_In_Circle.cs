
//Fascinating solution:
//Uses System.Numerics.Complex to store direction and position, which allows easy translation via addition and rotation via multiplication.

using System.Numerics;

public class Solution
{
	public bool IsRobotBounded(string instructions)
	{
		(Complex direction, Complex position) = instructions.Aggregate(
			(Direction: Complex.One, Position: Complex.Zero),
			(t, i) => i switch
			{
				'G' => (t.Direction, t.Position + t.Direction),
				'L' => (t.Direction * Complex.ImaginaryOne, t.Position),
				'R' => (t.Direction * -Complex.ImaginaryOne, t.Position)
			}
		);

		return direction != Complex.One || position == Complex.Zero;
	}
}

//Most common
public class Solution {
    public bool IsRobotBounded(string cmd) {
        int x = 0;
        int y = 0;
        int v = 0; // 0 - north, 3 - west, 2 - south, 1 - east;
        for(int step = 0; step < cmd.Length; step++){
            switch (cmd[step])
            {
                case 'G':
                    switch(v){
                        case 0:
                            x += 1;
                            break;
                        case 1:
                            y += 1;
                            break;
                        case 2:
                            x -= 1;
                            break;
                        case 3:
                            y -= 1;
                            break;
                        default:
                            break;
                    }
                    break;
                case 'L':
                    v = v == 0 ? 3 : v - 1;
                    break;
                case 'R':
                    v = (v + 1) % 4;
                    break;
                default:
                    break;
            }
        }
        
        return (x == 0 && y == 0) || v != 0;
    }
}

//Fastest
public class Solution {
    public bool IsRobotBounded(string instructions) {
        var chars = new List<char>();
        var dirs = new char[] {'N', 'W', 'S', 'E'};
        int currDir = 0;
        for(int j = 0; j < 4; j++){
            for(int i = 0; i < instructions.Length; i++){
                switch(instructions[i]){
                    case 'G':
                        chars.Add(dirs[currDir]);
                        break;
                    case 'L':
                        currDir = (currDir + 1) % 4;
                        break;
                    case 'R':
                        currDir = currDir == 0 ? 3 : currDir - 1;
                        break;
                }
            }
        }
        var ver = 0;
        var hor = 0;
        for(int i = 0; i < chars.Count; i++){
            switch(chars[i]){
                case 'N':
                    ver++;
                    break;
                case 'S':
                    ver--;
                    break;
                case 'W':
                    hor++;
                    break;
                case 'E':
                    hor--;
                    break;
            }
        }
        return ver == 0 && hor == 0;
    }
}