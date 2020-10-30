bool winnerSquareGame(int n) {
	vector<bool> dp(n + 1, false);
	dp[0] = false;
	for (int i=1; i<dp.size(); i++) {
		int temp = sqrt(i);
		if (temp * temp == i) {
			dp[i] = true;
		} else {
			for (int j=1; j*j<i; j++) {
				if (!dp[i - (j*j)]) {
					dp[i] = true;
					break;
				}
			}
		}
	}
	return dp.back();
}

//Most common
class Solution {
public:
    bool winnerSquareGame(int n) {
        int dp[n+1];
        //dp[]=0 loss
        //dp[]=1 win
        dp[0]=0; 
        for(int i=1;i<=n;i++){
            bool ok=0;
            for(int j=1;i>=j*j;j++){
                if(!dp[i-j*j]){
                    ok=1;
                    break;
                }
            }
            if(ok) dp[i]=1;
            else dp[i]=0;
        }
        return dp[n];
    }
};

//Third fastest
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int>v(n+1,-1);
        v[0]=0;
        for(int i=0;i<=n;i++){
            if(v[i]==-1)
                v[i]=0;
            if(v[i]==0){
                for(int j=1;(i+j*j)<=n;j++){
                    v[i+j*j]=1;
                }
            }
        }
        return v[n];
    }
};

//Second fastest
class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n + 1];
        fill ((bool*)dp, (bool*)dp + n + 1, false);
        for (int i = 1; i <= n; ++i){
            int v = sqrt(i);
            if (v * v == i)
                dp[i] = true;
            if (!dp[i]){
                for (int j = 1; i + j * j <= n; ++j)
                    dp[i + j * j] = true;
            }
        }
        return dp[n];
    }
};

//Fastest
static const int B[] = {
2,5,7,10,12,15,17,20,22,34,39,44,52,57,62,65,67,72,85,95,109,119,124,127,130,132,137,142,147,150,170,177,180,182,187,192,197,204,210,215,238,243,249,255,257,260,262,267,272,275,312,317,322,327,332,335,340,345,350,369,377,390,392,397,425,430,437,442,447,449,464,502,507,510,512,515,517,520,522,554,572,589,595,600,613,619,652,663,665,680,702,704,707,724,770,787,793,827,850,855,860,862,865,867,872,894,918,923,928,935,940,979,990,997,1007,1010,1020,1057,1095,1105,1112,1122,1152,1180,1182,1185,1202,1257,1270,1307,1312,1315,1317,1345,1350,1365,1382,1385,1387,1404,1432,1437,1442,1455,1477,1507,1510,1517,1520,1527,1530,1562,1564,1567,1572,1595,1625,1642,1675,1677,1690,1692,1697,1705,1729,1734,1757,1795,1802,1812,1822,1830,1852,1865,1870,1887,1892,1899,1904,1955,1960,1978,1989,2015,2065,2072,2125,2127,2137,2164,2177,2182,2210,2233,2247,2254,2257,2262,2288,2295,2312,2325,2327,2380,2390,2392,2397,2442,2470,2504,2509,2530,2569,2574,2587,2589,2600,2602,2652,2659,2672,2685,2737,2747,2800,2810,2815,2862,2895,2905,2927,2929,2932,2934,2940,2975,2977,2980,2992,2997,3057,3062,3070,3102,3115,3122,3135,3142,3182,3187,3189,3192,3197,3209,3230,3237,3247,3252,3267,3302,3307,3315,3354,3382,3387,3400,3427,3432,3437,3442,3447,3485,3512,3517,3562,3567,3575,3577,3635,3642,3645,3655,3692,3697,3712,3720,3752,3772,3790,3869,3900,3902,3907,3915,3920,3947,3952,3954,3982,3987,3995,4060,4077,4080,4155,4182,4199,4262,4289,4323,4420,4430,4432,4437,4447,4452,4454,4464,4512,4517,4522,4539,4550,4562,4567,4600,4635,4642,4654,4665,4675,4680,4687,4692,4707,4750,4755,4760,4770,4777,4790,4810,4817,4822,4845,4869,4872,4925,4935,4940,4947,4955,5007,5020,5067,5122,5135,5182,5197,5200,5205,5252,5257,5265,5270,5280,5307,5322,5345,5367,5382,5387,5397,5400,5437,5460,5512,5517,5525,5527,5577,5579,5649,5675,5712,5715,5780,5785,5827,5832,5842,5865,5870,5872,5875,5904,5962,6040,6045,6092,6110,6120,6177,6182,6190,6195,6205,6237,6302,6312,6320,6357,6367,6372,6375,6385,6387,6414,6432,6437,6442,6460,6502,6507,6512,6515,6517,6522,6539,6557,6559,6562,6567,6572,6585,6630,6642,6647,6652,6669,6687,6692,6707,6710,6725,6760,6817,6822,6840,6845,6850,6885,6887,6892,6905,6955,7072,7079,7122,7185,7190,7204,7252,7364,7377,7452,7525,7535,7555,7577,7605,7627,7632,7638,7665,7767,7769,7772,7865,7885,7915,7942,7947,7990,8000,8007,8055,8057,8072,8142,8187,8192,8197,8255,8267,8272,8312,8322,8335,8340,8354,8359,8374,8387,8402,8420,8430,8437,8442,8447,8452,8470,8507,8512,8515,8517,8522,8562,8580,8585,8595,8637,8640,8642,8670,8692,8757,8762,8772,8777,8827,8832,8840,8845,8920,8952,8970,8990,9075,9080,9102,9115,9182,9190,9197,9237,9242,9247,9307,9349,9355,9395,9437,9440,9447,9460,9512,9517,9557,9594,9632,9635,9682,9687,9697,9724,9757,9762,9767,9817,9830,9854,9882,9927,9945,9947,9950,9979,10054,10064,10075,10125,10140,10155,10160,10220,10232,10285,10394,10452,10465,10482,10562,10567,10577,10617,10622,10637,10660,10670,10682,10712,10720,10725,10757,10762,10777,10795,10805,10817,10875,10892,10897,10927,10957,10965,11050,11072,11089,11102,11147,11165,11200,11230,11237,11252,11260,11310,11356,11377,11395,11397,11400,11447,11475,11480,11492,11512,11557,11577,11632,11640,11647,11650,11702,11715,11730,11752,11774,11817,11845,11882,11910,11942,11962,12027,12060,12077,12084,12092,12155,12175,12290,12307,12322,12387,12402,12415,12437,12449,12454,12522,12562,12572,12632,12682,12687,12727,12755,12762,12812,12817,12825,12835,12845,12880,12882,12885,12892,12920,12942,12954,13015,13017,13022,13072,13093,13132,13175,13229,13260,13322,13332,13351,13359,13377,13452,13502,13525,13559,13637,13644,13702,13715,13770,13807,13827,13837,13845,13865,13882,13910,13962,13997,14007,14030,14040,14073,14100,14120,14144,14157,14197,14229,14275,14307,14322,14367,14372,14489,14502,14534,14555,14572,14620,14627,14637,14640,14682,14697,14710,14744,14757,14762,14812,14835,14875,14877,14882,14892,14952,14957,14960,14965,14970,15017,15035,15045,15087,15130,15147,15150,15192,15264,15305,15310,15342,15377,15414,15432,15447,15490,15504,15545,15557,15600,15613,15650,15652,15680,15702,15722,15730,15790,15800,15932,15992,16005,16012,16027,16044,16085,16109,16235,16250,16257,16272,16315,16322,16330,16352,16429,16439,16447,16450,16505,16544,16575,16587,16592,16595,16677,16694,16705,16755,16757,16762,16767,16784,16835,16925,16954,17045,17255,17372,17425,17430,17432,17435,17498,17520,17572,17583,17615,17622,17629,17635,17680,17682,17770,17845,17855,17935,18010,18025,18077,18132,18137,18139,18167,18200,18234,18252,18280,18350,18397,18415,18502,18564,18572,18610,18627,18632,18649,18775,18790,18795,18819,18870,18882,18887,18904,18924,19122,19125,19130,19132,19169,19223,19234,19305,19332,19387,19442,19465,19485,19492,19509,19544,19645,19760,19772,19812,19847,19890,19895,19924,19937,19942,19989,20017,20040,20052,20132,20257,20315,20320,20377,20405,20432,20480,20490,20495,20512,20522,20587,20627,20650,20655,20697,20810,20865,20867,20937,21010,21015,21017,21067,21075,21177,21197,21227,21247,21262,21302,21307,21312,21317,21335,21359,21385,21392,21437,21442,21502,21515,21567,21572,21582,21595,21600,21675,21680,21687,21754,21757,21762,21827,21877,21970,22007,22025,22055,22149,22219,22237,22247,22352,22367,22432,22440,22492,22497,22600,22607,22690,22705,22724,22750,22780,22800,22865,22887,22952,22957,22972,22984,23062,23075,23120,23130,23140,23142,23205,23210,23262,23277,23317,23382,23387,23432,23450,23455,23465,23492,23522,23562,23585,23602,23630,23692,23725,23777,23790,23797,23867,23875,23927,23970,24065,24102,24107,24130,24135,24237,24247,24260,24310,24315,24320,24362,24395,24427,24432,24437,24442,24447,24490,24497,24520,24562,24575,24580,24635,24642,24702,24707,24752,24780,24817,24830,24845,24850,24895,24915,24937,24947,24990,25077,25095,25132,25170,25194,25197,25255,25335,25345,25367,25372,25482,25500,25510,25512,25590,25595,25647,25670,25675,25703,25755,25812,25832,25840,25925,26007,26072,26168,26182,26190,26210,26317,26327,26372,26377,26390,26449,26502,26507,26512,26520,26554,26567,26622,26637,26680,26687,26702,26765,26775,26817,26830,26899,27007,27047,27152,27170,27200,27244,27302,27307,27315,27380,27495,27505,27562,27637,27640,27642,27692,27767,27772,27817,27832,27840,27885,27892,27942,27952,27955,27957,27965,28045,28050,28067,28072,28082,28125,28135,28142,28230,28247,28264,28322,28447,28492,28497,28509,28555,28562,28645,28747,28762,28764,28822,28849,28975,29107,29109,29135,29165,29170,29197,29257,29267,29272,29335,29377,29382,29437,29450,29512,29517,29522,29562,29567,29590,29630,29637,29642,29668,29692,29697,29702,29757,29770,29887,29925,30010,30027,30045,30095,30175,30185,30227,30305,30372,30440,30505,30559,30583,30617,30622,30760,30777,30820,30925,30932,30955,31029,31087,31120,31200,31202,31239,31260,31287,31375,31382,31397,31447,31460,31473,31577,31590,31688,31732,31740,31760,31780,31812,31822,31850,31887,31930,31954,32077,32125,32227,32239,32260,32295,32340,32370,32494,32502,32504,32507,32522,32572,32635,32637,32650,32677,32682,32692,32715,32730,32754,32757,32767,32812,32817,32827,32840,32877,32890,32897,32929,32942,32947,32962,32970,33002,33007,33012,33040,33045,33152,33192,33202,33235,33245,33280,33300,33365,33477,33490,33507,33555,33652,33714,33755,33820,33830,33887,33915,33937,33942,34005,34010,34017,34027,34032,34080,34182,34221,34255,34262,34307,34327,34340,34379,34502,34595,34619,34637,34682,34692,34697,34710,34762,34767,34827,34855,34872,35017,35025,35030,35035,35115,35122,35237,35247,35370,35432,35445,35465,35477,35557,35615,35620,35687,35697,35700,35710,35795,35817,35874,35880,35919,35937,35942,36017,36067,36127,36132,36135,36220,36257,36265,36285,36295,36374,36400,36447,36465,36470,36504,36522,36577,36652,36710,36720,36725,36740,36849,36895,36975,36985,37005,37082,37104,37117,37135,37362,37432,37497,37507,37539,37547,37560,37635,37655,37682,37700,37720,37752,37757,37807,37822,37825,37827,37830,37835,37845,37882,37887,37972,38007,38012,38062,38080,38130,38170,38192,38335,38350,38387,38430,38461,38557,38610,38642,38675,38692,38709,38760,38794,38807,38855,38882,38952,38997,39017,39020,39100,39122,39127,39145,39195,39247,39275,39307,39312,39327,39460,39525,39557,39559,39632,39682,39687,39762,39780,39790,39795,39824,39842,39892,39947,39960,40035,40077,40120,40165,40290,40367,40385,40450,40487,40535,40567,40640,40647,40671,40705,40755,40800,40812,40817,40885,40892,40895,40937,40947,41012,41050,41100,41225,41249,41392,41439,41490,41525,41555,41557,41585,41615,41665,41682,41687,41762,41767,41769,41817,41897,41900,41937,41947,41990,42005,42010,42067,42165,42302,42317,42322,42330,42364,42432,42452,42500,42585,42590,42642,42680,42687,42697,42710,42755,42762,42772,42799,42822,42829,42850,42857,42937,42952,43100,43165,43170,43212,43355,43372,43435,43487,43495,43525,43557,43572,43585,43607,43615,43617,43622,43682,43822,43862,43882,43932,43940,43970,44062,44132,44137,44142,44169,44244,44252,44265,44285,44322,44330,44442,44455,44465,44572,44647,44775,44829,44850,44902,44904,44942,45012,45045,45072,45077,45169,45227,45240,45260,45330,45375,45427,45442,45650,45682,45692,45760,45767,45812,45822,45877,45892,45947,45975,46077,46137,46145,46150,46197,46202,46254,46267,46300,46315,46345,46682,46697,46757,46794,46807,46872,46920,47002,47010,47132,47137,47175,47187,47192,47255,47270,47294,47314,47335,47502,47567,47600,47620,47622,47637,47640,47642,47652,47685,47687,47780,47860,47932,47937,48154,48212,48280,48295,48372,48440,48445,48460,48492,48497,48535,48607,48620,48652,48654,48659,48687,48705,48822,48887,48895,48927,48932,48937,48942,48947,48955,48984,49010,49030,49057,49062,49140,49142,49192,49194,49207,49324,49362,49382,49442,49470,49480,49650,49680,49732,49752,49822,49850,49872,50055,50057,50065,50070,50115,50150,50227,50247,50312,50330,50372,50382,50507,50510,50512,50557,50585,50700,50864,50877,50915,50949,51014,51034,51077,51192,51194,51202,51257,51274,51297,51337,51365,51372,51617,51719,51945,51955,51974,52002,52113,52200,52205,52260,52262,52275,52327,52405,52410,52442,52445,52492,52567,52577,52620,52637,52655,52702,52840,52947,52997,53062,53135,53142,53182,53187,53197,53205,53257,53317,53387,53437,53442,53497,53510,53567,53697,53775,53859,53900,53937,53952,53965,54002,54015,54060,54095,54152,54165,54179,54247,54257,54327,54335,54405,54457,54485,54522,54615,54650,54660,54665,54692,54815,54822,54849,54920,54927,54947,54990,55080,55132,55185,55197,55252,55262,55315,55322,55382,55392,55445,55465,55567,55577,55582,55712,55770,55804,55835,55902,55910,55952,55965,56072,56110,56155,56185,56187,56240,56247,56270,56317,56362,56372,56382,56402,56512,56557,56567,56600,56642,56692,56770,56777,56892,56932,56947,56955,57052,57072,57202,57207,57212,57220,57377,57382,57405,57460,57507,57577,57669,57702,57715,57720,57757,57760,57800,57807,57817,57902,57905,57975,58060,58072,58145,58182,58225,58247,58255,58362,58395,58487,58500,58507,58609,58637,58642,58650,58755,58925,59007,59014,59160,59255,59300,59345,59367,59495,59497,59512,59534,59567,59585,59642,59675,59692,59789,59817,59835,59865,59887,59915,59950,60012,60095,60117,60203,60302,60437,60487,60497,60502,60530,60595,60600,60767,60772,60814,60817,60827,60882,60942,60952,61012,61020,61040,61072,61115,61132,61267,61322,61380,61419,61450,61477,61494,61562,61625,61632,61635,61640,61642,61692,61705,61752,61767,61817,61880,61882,61887,61897,61957,61965,62017,62050,62060,62062,62197,62210,62220,62240,62298,62312,62530,62560,62570,62645,62742,62747,62752,62810,62882,63057,63420,63434,63500,63552,63575,63580,63635,63715,63750,63752,63760,63830,63889,63897,63915,63954,63960,64082,64202,64220,64290,64355,64430,64469,64554,64577,64605,64872,65057,65062,65182,65257,65260,65364,65470,65522,65572,65624,65632,65652,65715,65757,65762,65970,65975,66010,66027,66055,66079,66140,66159,66307,66310,66320,66395,66450,66497,66510,66572,66575,66627,66640,66647,66690,66767,66905,67002,67080,67137,67182,67225,67247,67262,67327,67332,67354,67395,67437,67502,67517,67585,67869,67925,68007,68029,68085,68090,68137,68180,68187,68209,68289,68317,68380,68437,68442,68525,68567,68575,68595,68627,68634,68692,68707,68772,68804,68809,68827,68835,68897,68920,68947,68991,69030,69082,69115,69132,69137,69139,69149,69202,69212,69370,69440,69442,69447,69552,69557,69574,69617,69635,69745,69760,69767,69812,69822,69892,70007,70040,70062,70135,70192,70197,70210,70220,70262,70322,70345,70377,70382,70460,70525,70627,70754,70815,70850,70980,71045,71077,71099,71182,71240,71247,71290,71317,71359,71567,71617,71622,71627,71687,71762,71790,71877,71905,71920,71955,72072,72080,72100,72165,72202,72204,72230,72250,72367,72380,72432,72495,72505,72512,72567,72685,72772,72815,72892,72925,72930,72937,73017,73022,73072,73100,73187,73190,73197,73444,73452,73497,73515,73557,73567,73634,73637,73707,73780,73827,74002,74137,74205,74225,74257,74295,74312,74330,74375,74385,74387,74419,74432,74437,74470,74484,74497,74512,74562,74567,74635,74640,74650,74715,74795,74812,74817,74835,74892,74927,74957,75007,75121,75127,75140,75207,75415,75417,75480,75589,75595,75730,75915,76012,76065,76077,76192,76247,76312,76322,76330,76512,76562,76687,76692,76752,76772,76840,76845,76884,76902,77095,77100,77190,77227,77277,77285,77365,77532,77562,77567,77572,77610,77615,77637,77695,77702,77734,77742,77747,77785,77935,77942,77955,77970,78002,78072,78125,78234,78252,78275,78322,78330,78332,78385,78390,78447,78455,78470,78574,78637,78710,78752,78762,78802,78850,78880,78904,78925,78937,78942,78975,79040,79074,79190,79197,79225,79367,79382,79437,79497,79502,79507,79560,79604,79637,79697,79700,79747,79757,79770,79885,79924,79942,80050,80082,80145,80177,80490,80507,80524,80562,80602,80665,80697,80745,80750,80762,80784,80887,80920,80942,80952,80985,80990,81165,81180,81192,81207,81267,81270,81304,81447,81517,81572,81692,81752,81775,81822,81850,81855,81879,81952,82017,82025,82077,82095,82110,82115,82199,82225,82275,82327,82372,82497,82507,82562,82572,82574,82620,82622,82630,82637,82682,82692,82767,82817,82882,82914,82947,83045,83115,83130,83137,83254,83312,83332,83345,83377,83395,83447,83545,83562,83577,83642,83757,83839,83887,84007,84014,84022,84057,84099,84182,84229,84240,84344,84405,84447,84495,84580,84677,84687,84692,84820,84864,84877,84910,84947,85000,85017,85022,85057,85187,85197,85204,85209,85332,85449,85560,85697,85702,85724,85752,85772,85815,85827,85942,86010,86072,86122,86127,86212,86224,86275,86309,86317,86392,86394,86502,86572,86627,86637,86695,86762,86822,86827,86860,86887,86955,87012,87115,87210,87220,87322,87382,87432,87460,87477,87492,87659,87692,87752,87762,87765,87767,87807,87815,87817,87822,87882,88017,88029,88067,88077,88094,88127,88134,88142,88220,88660,88680,88745,88784,88915,88920,88965,89117,89260,89312,89349,89392,89447,89505,89539,89562,89567,89572,89582,89635,89675,89687,89692,89702,89707,89709,89760,89765,89767,89857,89874,89877,89897,89915,90045,90077,90100,90110,90112,90175,90202,90240,90339,90365,90692,90732,90734,90767,90882,90892,90897,91017,91137,91147,91169,91177,91187,91197,91210,91255,91295,91375,91405,91502,91512,91622,91687,91715,91749,91832,91930,92035,92055,92145,92300,92432,92437,92534,92575,92627,92632,92645,92807,92812,92820,92827,92892,92957,92962,93002,93012,93017,93022,93067,93072,93080,93119,93132,93165,93184,93204,93225,93295,93444,93524,93552,93557,93572,93615,93622,93632,93665,93704,93822,93942,93969,94034,94044,94062,94142,94192,94267,94317,94382,94440,94525,94627,94632,94637,94697,94772,94775,94785,94882,94887,94900,94952,95030,95115,95277,95375,95414,95420,95494,95550,95617,95622,95767,95777,95790,95812,95817,95822,95880,95892,95897,95909,95937,95947,95985,96012,96130,96142,96200,96202,96220,96345,96377,96560,96655,96740,96742,96747,96820,96910,96915,96922,96957,97145,97177,97240,97250,97260,97352,97375,97437,97512,97557,97567,97580,97637,97687,97697,97877,97955,98002,98005,98012,98085,98202,98280,98300,98345,98365,98477,98605,98610,98682,98685,98735,98742,98770,98804,98807,98817,98865,98872,98930,98932,98945,98984,99017,99127,99132,99205,99270,99335,99342,99385,99387,99507,99515,99535,99710,99840,99899,99919,
};

class Solution {
public:
    static bool winnerSquareGame(int N) {
        /*static int h[100001] = {1};
        function<bool(int, bool)> WSG = [&](int n, bool w) constexpr {
            if (h[n]) {
                if (h[n] - 1) return w;
                return !w;
            } else if (n == 0) return !w;
            for (int i = sqrt(n); i >= 1; i--)
                if (WSG(n - i * i, !w) == w) {
                    h[n] = 2;
                    return w;
                }
            h[n] = 1;
            return !w;
        };
        return WSG(N, true) == true;*/
        static int a[100001];
        if (!a[0]) {
            for (int& i : a) i = 1;
            for (int i : B) a[i] = 2;
        }
        return a[N] == 1;
    }
};
static const auto speedup = []() {
std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0;
}();