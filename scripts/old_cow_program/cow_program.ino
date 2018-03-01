#include <SimbleeForMobile.h>
#include "SimbleeCOM.h"

//#define DEBUG

static float WeightLookUpTable[1024] = {
  0,0.782013685,1.56402737,2.346041056,3.128054741,3.910068426,4.692082111,
  5.474095797,6.256109482,7.038123167,7.820136852,8.602150538,9.384164223,
  10.16617791,10.94819159,11.73020528,12.51221896,13.29423265,14.07624633,
  14.85826002,15.6402737,16.42228739,17.20430108,17.98631476,18.76832845,
  19.55034213,20.33235582,21.1143695,21.89638319,22.67839687,23.46041056,
  24.24242424,25.02443793,25.80645161,26.5884653,27.37047898,28.15249267,
  28.93450635,29.71652004,30.49853372,31.28054741,32.06256109,32.84457478,
  33.62658847,34.40860215,35.19061584,35.97262952,36.75464321,37.53665689,
  38.31867058,39.10068426,39.88269795,40.66471163,41.44672532,42.228739,
  43.01075269,43.79276637,44.57478006,45.35679374,46.13880743,46.92082111,
  47.7028348,48.48484848,49.26686217,50.04887586,50.83088954,51.61290323,
  52.39491691,53.1769306,53.95894428,54.74095797,55.52297165,56.30498534,
  57.08699902,57.86901271,58.65102639,59.43304008,60.21505376,60.99706745,
  61.77908113,62.56109482,63.3431085,64.12512219,64.90713587,65.68914956,
  66.47116325,67.25317693,68.03519062,68.8172043,69.59921799,70.38123167,
  71.16324536,71.94525904,72.72727273,73.50928641,74.2913001,75.07331378,
  75.85532747,76.63734115,77.41935484,78.20136852,78.98338221,79.76539589,
  80.54740958,81.32942326,82.11143695,82.89345064,83.67546432,84.45747801,
  85.23949169,86.02150538,86.80351906,87.58553275,88.36754643,89.14956012,
  89.9315738,90.71358749,91.49560117,92.27761486,93.05962854,93.84164223,
  94.62365591,95.4056696,96.18768328,96.96969697,97.75171065,98.53372434,
  99.31573803,100.0977517,100.8797654,101.6617791,102.4437928,103.2258065,
  104.0078201,104.7898338,105.5718475,106.3538612,107.1358749,107.9178886,
  108.6999022,109.4819159,110.2639296,111.0459433,111.827957,112.6099707,
  113.3919844,114.173998,114.9560117,115.7380254,116.5200391,117.3020528,
  118.0840665,118.8660802,119.6480938,120.4301075,121.2121212,121.9941349,
  122.7761486,123.5581623,124.340176,125.1221896,125.9042033,126.686217,
  127.4682307,128.2502444,129.0322581,129.8142717,130.5962854,131.3782991,
  132.1603128,132.9423265,133.7243402,134.5063539,135.2883675,136.0703812,
  136.8523949,137.6344086,138.4164223,139.198436,139.9804497,140.7624633,
  141.544477,142.3264907,143.1085044,143.8905181,144.6725318,145.4545455,
  146.2365591,147.0185728,147.8005865,148.5826002,149.3646139,150.1466276,
  150.9286413,151.7106549,152.4926686,153.2746823,154.056696,154.8387097,
  155.6207234,156.402737,157.1847507,157.9667644,158.7487781,159.5307918,
  160.3128055,161.0948192,161.8768328,162.6588465,163.4408602,164.2228739,
  165.0048876,165.7869013,166.568915,167.3509286,168.1329423,168.914956,
  169.6969697,170.4789834,171.2609971,172.0430108,172.8250244,173.6070381,
  174.3890518,175.1710655,175.9530792,176.7350929,177.5171065,178.2991202,
  179.0811339,179.8631476,180.6451613,181.427175,182.2091887,182.9912023,
  183.773216,184.5552297,185.3372434,186.1192571,186.9012708,187.6832845,
  188.4652981,189.2473118,190.0293255,190.8113392,191.5933529,192.3753666,
  193.1573803,193.9393939,194.7214076,195.5034213,196.285435,197.0674487,
  197.8494624,198.6314761,199.4134897,200.1955034,200.9775171,201.7595308,
  202.5415445,203.3235582,204.1055718,204.8875855,205.6695992,206.4516129,
  207.2336266,208.0156403,208.797654,209.5796676,210.3616813,211.143695,
  211.9257087,212.7077224,213.4897361,214.2717498,215.0537634,215.8357771,
  216.6177908,217.3998045,218.1818182,218.9638319,219.7458456,220.5278592,
  221.3098729,222.0918866,222.8739003,223.655914,224.4379277,225.2199413,
  226.001955,226.7839687,227.5659824,228.3479961,229.1300098,229.9120235,
  230.6940371,231.4760508,232.2580645,233.0400782,233.8220919,234.6041056,
  235.3861193,236.1681329,236.9501466,237.7321603,238.514174,239.2961877,
  240.0782014,240.8602151,241.6422287,242.4242424,243.2062561,243.9882698,
  244.7702835,245.5522972,246.3343109,247.1163245,247.8983382,248.6803519,
  249.4623656,250.2443793,251.026393,251.8084066,252.5904203,253.372434,
  254.1544477,254.9364614,255.7184751,256.5004888,257.2825024,258.0645161,
  258.8465298,259.6285435,260.4105572,261.1925709,261.9745846,262.7565982,
  263.5386119,264.3206256,265.1026393,265.884653,266.6666667,267.4486804,
  268.230694,269.0127077,269.7947214,270.5767351,271.3587488,272.1407625,
  272.9227761,273.7047898,274.4868035,275.2688172,276.0508309,276.8328446,
  277.6148583,278.3968719,279.1788856,279.9608993,280.742913,281.5249267,
  282.3069404,283.0889541,283.8709677,284.6529814,285.4349951,286.2170088,
  286.9990225,287.7810362,288.5630499,289.3450635,290.1270772,290.9090909,
  291.6911046,292.4731183,293.255132,294.0371457,294.8191593,295.601173,
  296.3831867,297.1652004,297.9472141,298.7292278,299.5112414,300.2932551,
  301.0752688,301.8572825,302.6392962,303.4213099,304.2033236,304.9853372,
  305.7673509,306.5493646,307.3313783,308.113392,308.8954057,309.6774194,
  310.459433,311.2414467,312.0234604,312.8054741,313.5874878,314.3695015,
  315.1515152,315.9335288,316.7155425,317.4975562,318.2795699,319.0615836,
  319.8435973,320.6256109,321.4076246,322.1896383,322.971652,323.7536657,
  324.5356794,325.3176931,326.0997067,326.8817204,327.6637341,328.4457478,
  329.2277615,330.0097752,330.7917889,331.5738025,332.3558162,333.1378299,
  333.9198436,334.7018573,335.483871,336.2658847,337.0478983,337.829912,
  338.6119257,339.3939394,340.1759531,340.9579668,341.7399804,342.5219941,
  343.3040078,344.0860215,344.8680352,345.6500489,346.4320626,347.2140762,
  347.9960899,348.7781036,349.5601173,350.342131,351.1241447,351.9061584,
  352.688172,353.4701857,354.2521994,355.0342131,355.8162268,356.5982405,
  357.3802542,358.1622678,358.9442815,359.7262952,360.5083089,361.2903226,
  362.0723363,362.85435,363.6363636,364.4183773,365.200391,365.9824047,
  366.7644184,367.5464321,368.3284457,369.1104594,369.8924731,370.6744868,
  371.4565005,372.2385142,373.0205279,373.8025415,374.5845552,375.3665689,
  376.1485826,376.9305963,377.71261,378.4946237,379.2766373,380.058651,
  380.8406647,381.6226784,382.4046921,383.1867058,383.9687195,384.7507331,
  385.5327468,386.3147605,387.0967742,387.8787879,388.6608016,389.4428152,
  390.2248289,391.0068426,391.7888563,392.57087,393.3528837,394.1348974,
  394.916911,395.6989247,396.4809384,397.2629521,398.0449658,398.8269795,
  399.6089932,400.3910068,401.1730205,401.9550342,402.7370479,403.5190616,
  404.3010753,405.083089,405.8651026,406.6471163,407.42913,408.2111437,
  408.9931574,409.7751711,410.5571848,411.3391984,412.1212121,412.9032258,
  413.6852395,414.4672532,415.2492669,416.0312805,416.8132942,417.5953079,
  418.3773216,419.1593353,419.941349,420.7233627,421.5053763,422.28739,
  423.0694037,423.8514174,424.6334311,425.4154448,426.1974585,426.9794721,
  427.7614858,428.5434995,429.3255132,430.1075269,430.8895406,431.6715543,
  432.4535679,433.2355816,434.0175953,434.799609,435.5816227,436.3636364,
  437.14565,437.9276637,438.7096774,439.4916911,440.2737048,441.0557185,
  441.8377322,442.6197458,443.4017595,444.1837732,444.9657869,445.7478006,
  446.5298143,447.311828,448.0938416,448.8758553,449.657869,450.4398827,
  451.2218964,452.0039101,452.7859238,453.5679374,454.3499511,455.1319648,
  455.9139785,456.6959922,457.4780059,458.2600196,459.0420332,459.8240469,
  460.6060606,461.3880743,462.170088,462.9521017,463.7341153,464.516129,
  465.2981427,466.0801564,466.8621701,467.6441838,468.4261975,469.2082111,
  469.9902248,470.7722385,471.5542522,472.3362659,473.1182796,473.9002933,
  474.6823069,475.4643206,476.2463343,477.028348,477.8103617,478.5923754,
  479.3743891,480.1564027,480.9384164,481.7204301,482.5024438,483.2844575,
  484.0664712,484.8484848,485.6304985,486.4125122,487.1945259,487.9765396,
  488.7585533,489.540567,490.3225806,491.1045943,491.886608,492.6686217,
  493.4506354,494.2326491,495.0146628,495.7966764,496.5786901,497.3607038,
  498.1427175,498.9247312,499.7067449,500.4887586,501.2707722,502.0527859,
  502.8347996,503.6168133,504.398827,505.1808407,505.9628543,506.744868,
  507.5268817,508.3088954,509.0909091,509.8729228,510.6549365,511.4369501,
  512.2189638,513.0009775,513.7829912,514.5650049,515.3470186,516.1290323,
  516.9110459,517.6930596,518.4750733,519.257087,520.0391007,520.8211144,
  521.6031281,522.3851417,523.1671554,523.9491691,524.7311828,525.5131965,
  526.2952102,527.0772239,527.8592375,528.6412512,529.4232649,530.2052786,
  530.9872923,531.769306,532.5513196,533.3333333,534.115347,534.8973607,
  535.6793744,536.4613881,537.2434018,538.0254154,538.8074291,539.5894428,
  540.3714565,541.1534702,541.9354839,542.7174976,543.4995112,544.2815249,
  545.0635386,545.8455523,546.627566,547.4095797,548.1915934,548.973607,
  549.7556207,550.5376344,551.3196481,552.1016618,552.8836755,553.6656891,
  554.4477028,555.2297165,556.0117302,556.7937439,557.5757576,558.3577713,
  559.1397849,559.9217986,560.7038123,561.485826,562.2678397,563.0498534,
  563.8318671,564.6138807,565.3958944,566.1779081,566.9599218,567.7419355,
  568.5239492,569.3059629,570.0879765,570.8699902,571.6520039,572.4340176,
  573.2160313,573.998045,574.7800587,575.5620723,576.344086,577.1260997,
  577.9081134,578.6901271,579.4721408,580.2541544,581.0361681,581.8181818,
  582.6001955,583.3822092,584.1642229,584.9462366,585.7282502,586.5102639,
  587.2922776,588.0742913,588.856305,589.6383187,590.4203324,591.202346,
  591.9843597,592.7663734,593.5483871,594.3304008,595.1124145,595.8944282,
  596.6764418,597.4584555,598.2404692,599.0224829,599.8044966,600.5865103,
  601.3685239,602.1505376,602.9325513,603.714565,604.4965787,605.2785924,
  606.0606061,606.8426197,607.6246334,608.4066471,609.1886608,609.9706745,
  610.7526882,611.5347019,612.3167155,613.0987292,613.8807429,614.6627566,
  615.4447703,616.226784,617.0087977,617.7908113,618.572825,619.3548387,
  620.1368524,620.9188661,621.7008798,622.4828935,623.2649071,624.0469208,
  624.8289345,625.6109482,626.3929619,627.1749756,627.9569892,628.7390029,
  629.5210166,630.3030303,631.085044,631.8670577,632.6490714,633.431085,
  634.2130987,634.9951124,635.7771261,636.5591398,637.3411535,638.1231672,
  638.9051808,639.6871945,640.4692082,641.2512219,642.0332356,642.8152493,
  643.597263,644.3792766,645.1612903,645.943304,646.7253177,647.5073314,
  648.2893451,649.0713587,649.8533724,650.6353861,651.4173998,652.1994135,
  652.9814272,653.7634409,654.5454545,655.3274682,656.1094819,656.8914956,
  657.6735093,658.455523,659.2375367,660.0195503,660.801564,661.5835777,
  662.3655914,663.1476051,663.9296188,664.7116325,665.4936461,666.2756598,
  667.0576735,667.8396872,668.6217009,669.4037146,670.1857283,670.9677419,
  671.7497556,672.5317693,673.313783,674.0957967,674.8778104,675.659824,
  676.4418377,677.2238514,678.0058651,678.7878788,679.5698925,680.3519062,
  681.1339198,681.9159335,682.6979472,683.4799609,684.2619746,685.0439883,
  685.826002,686.6080156,687.3900293,688.172043,688.9540567,689.7360704,
  690.5180841,691.3000978,692.0821114,692.8641251,693.6461388,694.4281525,
  695.2101662,695.9921799,696.7741935,697.5562072,698.3382209,699.1202346,
  699.9022483,700.684262,701.4662757,702.2482893,703.030303,703.8123167,
  704.5943304,705.3763441,706.1583578,706.9403715,707.7223851,708.5043988,
  709.2864125,710.0684262,710.8504399,711.6324536,712.4144673,713.1964809,
  713.9784946,714.7605083,715.542522,716.3245357,717.1065494,717.888563,
  718.6705767,719.4525904,720.2346041,721.0166178,721.7986315,722.5806452,
  723.3626588,724.1446725,724.9266862,725.7086999,726.4907136,727.2727273,
  728.054741,728.8367546,729.6187683,730.400782,731.1827957,731.9648094,
  732.7468231,733.5288368,734.3108504,735.0928641,735.8748778,736.6568915,
  737.4389052,738.2209189,739.0029326,739.7849462,740.5669599,741.3489736,
  742.1309873,742.913001,743.6950147,744.4770283,745.259042,746.0410557,
  746.8230694,747.6050831,748.3870968,749.1691105,749.9511241,750.7331378,
  751.5151515,752.2971652,753.0791789,753.8611926,754.6432063,755.4252199,
  756.2072336,756.9892473,757.771261,758.5532747,759.3352884,760.1173021,
  760.8993157,761.6813294,762.4633431,763.2453568,764.0273705,764.8093842,
  765.5913978,766.3734115,767.1554252,767.9374389,768.7194526,769.5014663,
  770.28348,771.0654936,771.8475073,772.629521,773.4115347,774.1935484,
  774.9755621,775.7575758,776.5395894,777.3216031,778.1036168,778.8856305,
  779.6676442,780.4496579,781.2316716,782.0136852,782.7956989,783.5777126,
  784.3597263,785.14174,785.9237537,786.7057674,787.487781,788.2697947,
  789.0518084,789.8338221,790.6158358,791.3978495,792.1798631,792.9618768,
  793.7438905,794.5259042,795.3079179,796.0899316,796.8719453,797.6539589,
  798.4359726,799.2179863,800
};
const int dataLength = 10;
float weightFLdifference =0;
float weightBLdifference =0;
int topleft;
int topright;
int bottomleft;
int bottomright;
int opacity1;
int opacity2;
int opacity3;
int opacity4;
int BLval;
int TLval;
int TRval;
int BRval;
int BLvalpercent;
int BRpercentval;
int TLpercentval;
int TRpercentval;
int randNum1;
int randNum2;
int randNum3;
int randNum4;
int StatusUpdate;
int Calibrate;
float zeroval = 0;
float zerovalFL = 0;
float zerovalFR = 0;
float zerovalBL = 0;
float zerovalBR = 0;
const int PinBL = 2;
const int PinFL = 3;
const int PinFR = 4;
const int PinBR = 6;
int FLData = 0;
int FRData = 0;
int BLData = 0;
int BRData = 0;
volatile int i = 0;
//float FLArray[20] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
//float BLArray[20] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
//float FRArray[20] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
//float BRArray[20] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
float FLArray[dataLength] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
float BLArray[dataLength] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
float FRArray[dataLength] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
float BRArray[dataLength] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
const float Vthreshold = 30; // standard deviation threshold (30 lbs)
const float Lthreshold = 75; // weight threshold (75 lbs)
volatile int flag = 1;
volatile int LimpFlag = 1;
volatile int LimpDetected;
float weightFLLmean;
float weightFRLmean;
float weightBLLmean;
float weightBRLmean;
const int valueDelay = 10;
char* weightData;

void setup() {
  // put your setup code here, to run once:
  pinMode(PinFL, INPUT);
  pinMode(PinBL, INPUT);
  pinMode(PinFR, INPUT);
  pinMode(PinBR, INPUT);
  Serial.begin(9600); // sets up serial communications for debugging
//  SimbleeForMobile.deviceName = "COW_MAT";
//  SimbleeForMobile.advertisementData = "";
//  SimbleeForMobile.begin();
  SimbleeCOM.mode = LOW_LATENCY;
  SimbleeCOM.begin();
}

void loop(){

  int FLData = analogRead(PinFL);
  FLArray[i] = WeightLookUpTable[FLData];//convertWeight(FLData);
  int FRData = analogRead(PinFR);
  FRArray[i] = WeightLookUpTable[FRData];//convertWeight(FRData);
  int BLData = analogRead(PinBL);
  BLArray[i] = WeightLookUpTable[BLData];//convertWeight(BLData);
  int BRData = analogRead(PinBR);
  BRArray[i] = WeightLookUpTable[BRData];//convertWeight(BRData);
  i++;

  // debug statements
  #ifdef DEBUG
    Serial.print("Back right data: ");
    Serial.println(BRData);
    Serial.print("Back left data: ");
    Serial.println(BLData);
    Serial.print("Front right data: ");
    Serial.println(FRData);
    Serial.print("Front Left data: ");
    Serial.println(FLData);
  #endif
  
  float FLStd = standardDev(FLArray);
  float FRStd = standardDev(FRArray);
  float BLStd = standardDev(BLArray);
  float BRStd = standardDev(BRArray);
//  float FLStd = 0;
//  float FRStd = 0;
//  float BLStd = 0;
//  float BRStd = 0;
  //Serial.println(FLStd);
  if (i == dataLength) // prevents indexing overflow 
  {
    i = 0;
  }

  // Variance Threshold Comparisons
  if (FLStd > Vthreshold or FRStd > Vthreshold or BLStd > Vthreshold or BRStd > Vthreshold){
    flag = 0;
  }
  else{
    flag = 1;
  }

  if (flag == 1) {
    weightFLLmean = mean(FLArray);
    weightFRLmean = mean(FRArray);
    weightBLLmean = mean(BLArray);
    weightBRLmean = mean(BRArray);
    //Serial.println(weightFLLmean);
    weightFLdifference = abs(weightFLLmean - weightFRLmean);
    weightBLdifference = abs(weightBLLmean - weightBRLmean);

    // Weight Threshold Comparisons
    if (weightFLdifference > Lthreshold or weightBLdifference > Lthreshold) {
      // Tell Phone that Limp has been detected Alert User
      LimpFlag = 1;
    }
    else{
      LimpFlag = 0;
    }
  }
  //LimpFlag = 1 is set here, make sure to delete later
  #ifdef DEBUG
    LimpFlag = 1;
  #endif
  delay(valueDelay); // delay means you wait X milliseconds (should be 100 ms for 20 values) 

  randNum1 = weightFLLmean-zerovalFL; // random(700,900); put the weight variables over here
  randNum2 = weightFRLmean-zerovalFR; // random(700,900);
  randNum3 = weightBLLmean-zerovalBL; // random(700,900);
  randNum4 = weightBRLmean-zerovalBR; // random(700,900);
  #ifdef DEBUG
    randNum1 =400-zerovalFL; //weightFLLmean; // random(700,900); put the weight variables over here
    randNum2 =365-zerovalFR; //weightFRLmean; // random(700,900);
    randNum3 =401-zerovalBL; //weightBLLmean; // random(700,900);
    randNum4 =200-zerovalBR; //weightBRLmean; // random(700,900);  
  #endif
  opacity1 = randNum1 / 4; // takes in values between 1-100
  opacity2 = randNum2 / 4;
  opacity3 = randNum3 / 4;
  opacity4 = randNum4 / 4;
  
  weightData = new char[5]{0, randNum1, randNum2, randNum3, randNum4};
  SimbleeCOM.send(weightData, 5);
  delay(100);
  
  /*if (SimbleeForMobile.updatable) {
    SimbleeForMobile.updateColor( topleft, rgba(opacity1, 0, 0, 100));
    SimbleeForMobile.updateColor( topright, rgba(opacity2, 0, 0, 100));
    SimbleeForMobile.updateColor( bottomleft, rgba(opacity3, 0, 0, 100));
    SimbleeForMobile.updateColor( bottomright, rgba(opacity4, 0, 0, 100));
    SimbleeForMobile.updateValue(BLval, randNum3);  // used to change the value of a text box
    SimbleeForMobile.updateValue(BLvalpercent, 100 * abs(randNum3 - randNum4) / randNum3); // used to change the value of a text box
    SimbleeForMobile.updateValue(TLval, randNum1);  // used to change the value of a text box
    SimbleeForMobile.updateValue(TLpercentval, 100 * abs(randNum1 - randNum2) / randNum1); // used to change the value of a text box
    SimbleeForMobile.updateValue(TRval, randNum2);  // used to change the value of a text box
    SimbleeForMobile.updateValue( TRpercentval, 100 * abs(randNum2 - randNum1) / randNum2); // used to change the value of a text box
    SimbleeForMobile.updateValue(BRval, randNum4);  // used to change the value of a text box
    SimbleeForMobile.updateValue(BRpercentval, 100 * abs(randNum4 - randNum3) / randNum4); // used to change the value of a text box

    // Possibly replace with message about bad hoof
    if(LimpFlag){
      LimpDetected = int(weightFLdifference>Lthreshold) + 2*int(weightBLdifference>Lthreshold);
      #ifdef DEBUG
        LimpDetected = int(abs(randNum1-randNum2)>Lthreshold)+2*int(abs(randNum3-randNum4)>Lthreshold);
        weightFLLmean = randNum1;
        weightFRLmean = randNum2;
        weightBLLmean = randNum3;
        weightBRLmean = randNum4;
      #endif
      switch(LimpDetected){
        case 1: // case where front legs have a limp
        if(weightFLLmean < weightFRLmean){
          SimbleeForMobile.updateText(StatusUpdate, "The cow has a limp on front left leg");
        }
        else{
          SimbleeForMobile.updateText(StatusUpdate, "The cow has a limp on front right leg");          
        }
        break;
        
        case 2: // case where back legs have a limp
        if(weightBLLmean < weightBRLmean){
          SimbleeForMobile.updateText(StatusUpdate, "The cow has a limp on back left leg");
        }
        else{
          SimbleeForMobile.updateText(StatusUpdate, "The cow has a limp on back right leg");          
        }
        break;

        case 3: // case where both front and back legs have a limp
        if(weightFLLmean < weightFRLmean && weightBLLmean < weightBRLmean){
          SimbleeForMobile.updateText(StatusUpdate, "The cow has a limp on back & front left legs");
        }
        if(weightFLLmean < weightFRLmean && weightBLLmean > weightBRLmean){
          SimbleeForMobile.updateText(StatusUpdate, "The cow has a limp on front left and back right legs");    
        }
        if(weightFLLmean > weightFRLmean && weightBLLmean < weightBRLmean){
          SimbleeForMobile.updateText(StatusUpdate, "The cow has a limp on front right and back left legs");    
        }
        if(weightFLLmean > weightFRLmean && weightBLLmean > weightBRLmean){
          SimbleeForMobile.updateText(StatusUpdate, "The cow has a limp on back & front right legs");    
        }
        break;

        default:
        break;
      }     
    }
    else{
      SimbleeForMobile.updateText(StatusUpdate, "The Cow Is Good!"); // used to change the value of a text box
    }
}*/

//  SimbleeForMobile.process() ;

}

float convertWeight(int rawData)
{
  return (float) rawData * 105 / 96;
}
float standardDev(float* inputData) {
  float compareRawData = 0;
  float difference;
  float dataMean = mean(inputData);
  for (int i = 0; i < dataLength; i++){
    difference = inputData[i] - dataMean;
    difference *= difference;
    compareRawData += difference;

  }
  return sqrt(compareRawData / dataLength);
}

float mean(float* inputData) {
  float weightsum = 0;
  for (int i = 0; i < dataLength; i++) {
    weightsum += inputData[i];
  }
  return weightsum / dataLength;
}

void ui()
{
  /*SimbleeForMobile.beginScreen();
  // rectangle sizes
  topleft = SimbleeForMobile.drawRect(0, 0, SimbleeForMobile.screenWidth / 2, SimbleeForMobile.screenHeight / 2.6, RED);
  bottomleft = SimbleeForMobile.drawRect(0, SimbleeForMobile.screenHeight / 2.6, SimbleeForMobile.screenWidth / 2, SimbleeForMobile.screenHeight / 2.45, RED);
  topright = SimbleeForMobile.drawRect(SimbleeForMobile.screenWidth / 2, 0, SimbleeForMobile.screenWidth / 2, SimbleeForMobile.screenHeight / 2.6, RED);
  bottomright = SimbleeForMobile.drawRect(SimbleeForMobile.screenWidth / 2, SimbleeForMobile.screenHeight / 2.6, SimbleeForMobile.screenWidth / 2, SimbleeForMobile.screenHeight / 2.45, RED);
  BLval = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.2, SimbleeForMobile.screenHeight * 0.55, "876 lb");
  BLvalpercent = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.18, SimbleeForMobile.screenHeight * 0.58, "% of limp");
  SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.25, SimbleeForMobile.screenHeight * 0.58, "%");
  TLval = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.2, SimbleeForMobile.screenHeight * 0.2, "");
  TLpercentval = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.18, SimbleeForMobile.screenHeight * 0.24, "% of limp");
  SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.25, SimbleeForMobile.screenHeight * 0.24, "%");
  TRval = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.7, SimbleeForMobile.screenHeight * 0.2, "");
  TRpercentval = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.67, SimbleeForMobile.screenHeight * 0.24, "% of limp");
  SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.735, SimbleeForMobile.screenHeight * 0.24, "%");
  BRval = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.67, SimbleeForMobile.screenHeight * 0.55, "");
  BRpercentval = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.67, SimbleeForMobile.screenHeight * 0.58, "% of limp");
  SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.739, SimbleeForMobile.screenHeight * 0.58, "%");
  StatusUpdate = SimbleeForMobile.drawText(SimbleeForMobile.screenWidth * 0.15, SimbleeForMobile.screenHeight * 0.8, "The Cow is Good!");
  Calibrate = SimbleeForMobile.drawButton(SimbleeForMobile.screenWidth * 0.25, SimbleeForMobile.screenHeight * 0.9, SimbleeForMobile.screenWidth * 0.5, "Calibrate");
  SimbleeForMobile.setEvents(Calibrate, EVENT_PRESS);
  SimbleeForMobile.endScreen(); */
}

void ui_event(event_t &event){
  if (event.id == Calibrate)
  {
    if (event.type == EVENT_PRESS)
    { 
       //ADD in calibrate here
       zerovalFL=weightFLLmean;
       zerovalFR=weightFRLmean;
       zerovalBL=weightBLLmean;
       zerovalBR=weightBRLmean;
    }
  }
  
}

void SimbleeCOM_onReceive(unsigned int esn, const char* payload, int len, int rssi){
  Serial.printf("%d ", rssi);
  Serial.printf("\n");
  for (int i = 0; i < len; i++){
    Serial.printf("%d ", payload[i]);
  }
  Serial.printf("\n");
}


