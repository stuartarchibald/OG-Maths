/**
 * Copyright (C) 2014 - present by OpenGamma Inc. and the OpenGamma group of companies
 *
 * Please see distribution for license.
 */
// NOTE: This code is autogenerated, see src/generator/scripts/testgen.m
 
#include "gtest/gtest.h"
#include "terminal.hh"
#include "execution.hh"
#include "dispatch.hh"
#include "testnodes.hh"

using namespace std;
using namespace librdag;
using namespace testnodes;
using ::testing::TestWithParam;
using ::testing::Values;

/**
 * Check EXP node behaves
 */

UNARY_NODE_TEST_SETUP(EXP)

INSTANTIATE_NODE_TEST_CASE_P(EXPTests,EXP,
Values
(
// exp(real scalar of dimension: 1x1)
new CheckUnary<EXP>(OGRealScalar::create(     -5.0), OGRealScalar::create(      0.0067379469990855), MATHSEQUAL,
// NOTE: The tolerances used here are unduly slack, this is due to inconsistent libm's and will be fixed shortly.
1e-13, 1e-13),
// exp(real row vector of dimension: 1x11)
new CheckUnary<EXP>(OGRealDenseMatrix::create({{-5.0,-4.0,-3.0,-2.0,-1.0,
0.0,1.0,2.0,3.0,4.0,5.0}}), OGRealDenseMatrix::create({{0.0067379469990855,0.0183156388887342,0.0497870683678639,0.1353352832366127,0.3678794411714423,
1.0,2.7182818284590451,7.3890560989306504,20.0855369231876679,54.5981500331442362,148.4131591025765999}}), MATHSEQUAL,
// NOTE: The tolerances used here are unduly slack, this is due to inconsistent libm's and will be fixed shortly.
1e-13, 1e-13),
// exp(real column vector of dimension: 11x1)
new CheckUnary<EXP>(OGRealDenseMatrix::create({{-5.0},{-4.0},{-3.0},{-2.0},{-1.0},
{0.0},{1.0},{2.0},{3.0},{4.0},
{5.0}}), OGRealDenseMatrix::create({{0.0067379469990855},{0.0183156388887342},{0.0497870683678639},{0.1353352832366127},{0.3678794411714423},
{1.0},{2.7182818284590451},{7.3890560989306504},{20.0855369231876679},{54.5981500331442362},
{148.4131591025765999}}), MATHSEQUAL,
// NOTE: The tolerances used here are unduly slack, this is due to inconsistent libm's and will be fixed shortly.
1e-13, 1e-13),
// exp(complex scalar of dimension: 1x1)
new CheckUnary<EXP>(OGComplexScalar::create({     -7.0,     -7.0}), OGComplexScalar::create({      0.0006874698695266,     -0.0005990942309827}), MATHSEQUAL,
// NOTE: The tolerances used here are unduly slack, this is due to inconsistent libm's and will be fixed shortly.
1e-13, 1e-13),
// exp(complex row vector of dimension: 1x225)
new CheckUnary<EXP>(OGComplexDenseMatrix::create({{{-7.0,-7.0},{-7.0,-6.0},{-7.0,-5.0},{-7.0,-4.0},{-7.0,-3.0},
{-7.0,-2.0},{-7.0,-1.0},{-7.0,0.0},{-7.0,1.0},{-7.0,2.0},
{-7.0,3.0},{-7.0,4.0},{-7.0,5.0},{-7.0,6.0},{-7.0,7.0},
{-6.0,-7.0},{-6.0,-6.0},{-6.0,-5.0},{-6.0,-4.0},{-6.0,-3.0},
{-6.0,-2.0},{-6.0,-1.0},{-6.0,0.0},{-6.0,1.0},{-6.0,2.0},
{-6.0,3.0},{-6.0,4.0},{-6.0,5.0},{-6.0,6.0},{-6.0,7.0},
{-5.0,-7.0},{-5.0,-6.0},{-5.0,-5.0},{-5.0,-4.0},{-5.0,-3.0},
{-5.0,-2.0},{-5.0,-1.0},{-5.0,0.0},{-5.0,1.0},{-5.0,2.0},
{-5.0,3.0},{-5.0,4.0},{-5.0,5.0},{-5.0,6.0},{-5.0,7.0},
{-4.0,-7.0},{-4.0,-6.0},{-4.0,-5.0},{-4.0,-4.0},{-4.0,-3.0},
{-4.0,-2.0},{-4.0,-1.0},{-4.0,0.0},{-4.0,1.0},{-4.0,2.0},
{-4.0,3.0},{-4.0,4.0},{-4.0,5.0},{-4.0,6.0},{-4.0,7.0},
{-3.0,-7.0},{-3.0,-6.0},{-3.0,-5.0},{-3.0,-4.0},{-3.0,-3.0},
{-3.0,-2.0},{-3.0,-1.0},{-3.0,0.0},{-3.0,1.0},{-3.0,2.0},
{-3.0,3.0},{-3.0,4.0},{-3.0,5.0},{-3.0,6.0},{-3.0,7.0},
{-2.0,-7.0},{-2.0,-6.0},{-2.0,-5.0},{-2.0,-4.0},{-2.0,-3.0},
{-2.0,-2.0},{-2.0,-1.0},{-2.0,0.0},{-2.0,1.0},{-2.0,2.0},
{-2.0,3.0},{-2.0,4.0},{-2.0,5.0},{-2.0,6.0},{-2.0,7.0},
{-1.0,-7.0},{-1.0,-6.0},{-1.0,-5.0},{-1.0,-4.0},{-1.0,-3.0},
{-1.0,-2.0},{-1.0,-1.0},{-1.0,0.0},{-1.0,1.0},{-1.0,2.0},
{-1.0,3.0},{-1.0,4.0},{-1.0,5.0},{-1.0,6.0},{-1.0,7.0},
{0.0,-7.0},{0.0,-6.0},{0.0,-5.0},{0.0,-4.0},{0.0,-3.0},
{0.0,-2.0},{0.0,-1.0},{0.0,0.0},{0.0,1.0},{0.0,2.0},
{0.0,3.0},{0.0,4.0},{0.0,5.0},{0.0,6.0},{0.0,7.0},
{1.0,-7.0},{1.0,-6.0},{1.0,-5.0},{1.0,-4.0},{1.0,-3.0},
{1.0,-2.0},{1.0,-1.0},{1.0,0.0},{1.0,1.0},{1.0,2.0},
{1.0,3.0},{1.0,4.0},{1.0,5.0},{1.0,6.0},{1.0,7.0},
{2.0,-7.0},{2.0,-6.0},{2.0,-5.0},{2.0,-4.0},{2.0,-3.0},
{2.0,-2.0},{2.0,-1.0},{2.0,0.0},{2.0,1.0},{2.0,2.0},
{2.0,3.0},{2.0,4.0},{2.0,5.0},{2.0,6.0},{2.0,7.0},
{3.0,-7.0},{3.0,-6.0},{3.0,-5.0},{3.0,-4.0},{3.0,-3.0},
{3.0,-2.0},{3.0,-1.0},{3.0,0.0},{3.0,1.0},{3.0,2.0},
{3.0,3.0},{3.0,4.0},{3.0,5.0},{3.0,6.0},{3.0,7.0},
{4.0,-7.0},{4.0,-6.0},{4.0,-5.0},{4.0,-4.0},{4.0,-3.0},
{4.0,-2.0},{4.0,-1.0},{4.0,0.0},{4.0,1.0},{4.0,2.0},
{4.0,3.0},{4.0,4.0},{4.0,5.0},{4.0,6.0},{4.0,7.0},
{5.0,-7.0},{5.0,-6.0},{5.0,-5.0},{5.0,-4.0},{5.0,-3.0},
{5.0,-2.0},{5.0,-1.0},{5.0,0.0},{5.0,1.0},{5.0,2.0},
{5.0,3.0},{5.0,4.0},{5.0,5.0},{5.0,6.0},{5.0,7.0},
{6.0,-7.0},{6.0,-6.0},{6.0,-5.0},{6.0,-4.0},{6.0,-3.0},
{6.0,-2.0},{6.0,-1.0},{6.0,0.0},{6.0,1.0},{6.0,2.0},
{6.0,3.0},{6.0,4.0},{6.0,5.0},{6.0,6.0},{6.0,7.0},
{7.0,-7.0},{7.0,-6.0},{7.0,-5.0},{7.0,-4.0},{7.0,-3.0},
{7.0,-2.0},{7.0,-1.0},{7.0,0.0},{7.0,1.0},{7.0,2.0},
{7.0,3.0},{7.0,4.0},{7.0,5.0},{7.0,6.0},{7.0,7.0}}}), OGComplexDenseMatrix::create({{{0.0006874698695266,-0.0005990942309827},{0.0008755619682578,0.0002547939537040},{0.0002586664312337,0.0008744257523978},{-0.0005960458297653,0.0006901145469580},{-0.0009027563036842,-0.0001286847903287},
{-0.0003794767952699,-0.0008291719248475},{0.0004926919286687,-0.0007673222155837},{0.0009118819655545,0.0},{0.0004926919286687,0.0007673222155837},{-0.0003794767952699,0.0008291719248475},
{-0.0009027563036842,0.0001286847903287},{-0.0005960458297653,-0.0006901145469580},{0.0002586664312337,-0.0008744257523978},{0.0008755619682578,-0.0002547939537040},{0.0006874698695266,0.0005990942309827},
{0.0018687368539471,-0.0016285069616148},{0.0023800241880050,0.0006926017743549},{0.0007031282596549,0.0023769356330795},{-0.0016202205479798,0.0018759258325511},{-0.0024539460558317,-0.0003498015271496},
{-0.0010315248769040,-0.0022539229759813},{0.0013392755167285,-0.0020857980351942},{0.0024787521766664,0.0},{0.0013392755167285,0.0020857980351942},{-0.0010315248769040,0.0022539229759813},
{-0.0024539460558317,0.0003498015271496},{-0.0016202205479798,-0.0018759258325511},{0.0007031282596549,-0.0023769356330795},{0.0023800241880050,-0.0006926017743549},{0.0018687368539471,0.0016285069616148},
{0.0050797534322562,-0.0044267408812766},{0.0064695765015469,0.0018826868175874},{0.0019113007712960,0.0064611809388167},{-0.0044042160736693,0.0050992951021604},{-0.0066705169715861,-0.0009508591348179},
{-0.0028039753284917,-0.0061267978683562},{0.0036405283004232,-0.0056697868969039},{0.0067379469990855,0.0},{0.0036405283004232,0.0056697868969039},{-0.0028039753284917,0.0061267978683562},
{-0.0066705169715861,0.0009508591348179},{-0.0044042160736693,-0.0050992951021604},{0.0019113007712960,-0.0064611809388167},{0.0064695765015469,-0.0018826868175874},{0.0050797534322562,0.0044267408812766},
{0.0138082014479546,-0.0120331292968710},{0.0175861322419805,0.0051176733649273},{0.0051954541553336,0.0175633107363714},{-0.0119719005216626,0.0138613212141530},{-0.0181323450702902,-0.0025847031075998},
{-0.0076219951828865,-0.0166543633121944},{0.0098959819250312,-0.0154120786930890},{0.0183156388887342,0.0},{0.0098959819250312,0.0154120786930890},{-0.0076219951828865,0.0166543633121944},
{-0.0181323450702902,0.0025847031075998},{-0.0119719005216626,-0.0138613212141530},{0.0051954541553336,-0.0175633107363714},{0.0175861322419805,-0.0051176733649273},{0.0138082014479546,0.0120331292968710},
{0.0375345830796769,-0.0327094367071827},{0.0478040637062533,0.0139112785118707},{0.0141227086210353,0.0477420284222580},{-0.0325429996401548,0.0376789775748659},{-0.0492888241119187,-0.0070259514893501},
{-0.0207187310022429,-0.0452712531560930},{0.0269000678415716,-0.0418943734502045},{0.0497870683678639,0.0},{0.0269000678415716,0.0418943734502045},{-0.0207187310022429,0.0452712531560930},
{-0.0492888241119187,0.0070259514893501},{-0.0325429996401548,-0.0376789775748659},{0.0141227086210353,-0.0477420284222580},{0.0478040637062533,-0.0139112785118707},{0.0375345830796769,0.0327094367071827},
{0.1020295751242720,-0.0889134674202661},{0.1299449176992069,0.0378147755894509},{0.0383895022131823,0.1297762883139992},{-0.0884610445653820,0.1024220800566737},{-0.1339809149295426,-0.0190985162611352},
{-0.0563193499921279,-0.1230600248057767},{0.0731219655980596,-0.1138807140643681},{0.1353352832366127,0.0},{0.0731219655980596,0.1138807140643681},{-0.0563193499921279,0.1230600248057767},
{-0.1339809149295426,0.0190985162611352},{-0.0884610445653820,-0.1024220800566737},{0.0383895022131823,-0.1297762883139992},{0.1299449176992069,-0.0378147755894509},{0.1020295751242720,0.0889134674202661},
{0.2773451400257055,-0.2416918627937948},{0.3532269084823602,0.1027912173320610},{0.1043534862696817,0.3527685262888061},{-0.2404620499685837,0.2784120790510337},{-0.3641978864132929,-0.0519151497031734},
{-0.1530918656742263,-0.3345118292392623},{0.1987661103464130,-0.3095598756531122},{0.3678794411714423,0.0},{0.1987661103464130,0.3095598756531122},{-0.1530918656742263,0.3345118292392623},
{-0.3641978864132929,0.0519151497031734},{-0.2404620499685837,-0.2784120790510337},{0.1043534862696817,-0.3527685262888061},{0.3532269084823602,-0.1027912173320610},{0.2773451400257055,0.2416918627937948},
{0.7539022543433046,-0.6569865987187891},{0.9601702866503660,0.2794154981989259},{0.2836621854632262,0.9589242746631385},{-0.6536436208636119,0.7568024953079282},{-0.9899924966004454,-0.1411200080598672},
{-0.4161468365471424,-0.9092974268256817},{0.5403023058681398,-0.8414709848078965},{1.0,0.0},{0.5403023058681398,0.8414709848078965},{-0.4161468365471424,0.9092974268256817},
{-0.9899924966004454,0.1411200080598672},{-0.6536436208636119,-0.7568024953079282},{0.2836621854632262,-0.9589242746631385},{0.9601702866503660,-0.2794154981989259},{0.7539022543433046,0.6569865987187891},
{2.0493187984157140,-1.7858747328383988},{2.6100134424280022,0.7595300713439712},{0.7710737641656674,2.6066264306850795},{-1.7767875768817298,2.0572024707280030},{-2.6910786138197937,-0.3836039535411310},
{-1.1312043837568135,-2.4717266720048188},{1.4686939399158851,-2.2873552871788423},{2.7182818284590451,0.0},{1.4686939399158851,2.2873552871788423},{-1.1312043837568135,2.4717266720048188},
{-2.6910786138197937,0.3836039535411310},{-1.7767875768817298,-2.0572024707280030},{0.7710737641656674,-2.6066264306850795},{2.6100134424280022,-0.7595300713439712},{2.0493187984157140,1.7858747328383988},
{5.5706260504529617,-4.8545108341787717},{7.0947521125858772,2.0646167911025195},{2.0959958015330491,7.0855452601123137},{-4.8298093832693851,5.5920560936409816},{-7.3151100949011028,-1.0427436562359045},
{-3.0749323206393591,-6.7188496974282499},{3.9923240484412719,-6.2176763123679679},{7.3890560989306504,0.0},{3.9923240484412719,6.2176763123679679},{-3.0749323206393591,6.7188496974282499},
{-7.3151100949011028,1.0427436562359045},{-4.8298093832693851,-5.5920560936409816},{2.0959958015330491,-7.0855452601123137},{7.0947521125858772,-2.0646167911025195},{5.5706260504529617,4.8545108341787717},
{15.1425315660868645,-13.1959285866057172},{19.2855357450636120,5.6122103059854025},{5.6975072998337390,19.2605089252874215},{-13.1287830814621582,15.2007844630679543},{-19.8845308441469868,-2.8344711324870042},
{-8.3585326509353717,-18.2637270406667653},{10.8522619141979586,-16.9013965351500950},{20.0855369231876679,0.0},{10.8522619141979586,16.9013965351500950},{-8.3585326509353717,18.2637270406667653},
{-19.8845308441469868,2.8344711324870042},{-13.1287830814621582,-15.2007844630679543},{5.6975072998337390,-19.2605089252874215},{19.2855357450636120,-5.6122103059854025},{15.1425315660868645,13.1959285866057172},
{41.1616683929614098,-35.8702528866135708},{52.4235213679037884,15.2555692922506978},{15.4874305606508127,52.3554914184820461},{-35.6877324801191307,41.3200161842801990},{-54.0517588610781559,-7.7048913727311543},
{-22.7208474176192325,-49.6459573345805651},{29.4995063590424813,-45.9427590770791667},{54.5981500331442362,0.0},{29.4995063590424813,45.9427590770791667},{-22.7208474176192325,49.6459573345805651},
{-54.0517588610781559,7.7048913727311543},{-35.6877324801191307,-41.3200161842801990},{15.4874305606508127,-52.3554914184820461},{52.4235213679037884,-15.2555692922506978},{41.1616683929614098,35.8702528866135708},
{111.8890152216440299,-97.5054566039122932},{142.5019055182073373,41.4689367899228856},{42.0992010625383912,142.3169809429032284},{-97.0093146996155014,112.3194491453625261},{-146.9279139083189420,-20.9440662087459657},
{-61.7616666625049859,-134.9517036790433906},{80.1879720842972290,-124.8853671484961581},{148.4131591025765999,0.0},{80.1879720842972290,124.8853671484961581},{-61.7616666625049859,134.9517036790433906},
{-146.9279139083189420,20.9440662087459657},{-97.0093146996155014,-112.3194491453625261},{42.0992010625383912,-142.3169809429032284},{142.5019055182073373,-41.4689367899228856},{111.8890152216440299,97.5054566039122932},
{304.1458768811725122,-265.0473108620167864},{387.3603402909307647,112.7242573215641670},{114.4374932409418335,386.8576631782460709},{-263.6986573392297259,305.3159175943687842},{-399.3914784703783312,-56.9318745892772853},
{-167.8856161840321022,-366.8367638303333820},{217.9735073777263494,-339.4736241601933102},{403.4287934927351102,0.0},{217.9735073777263494,339.4736241601933102},{-167.8856161840321022,366.8367638303333820},
{-399.3914784703783312,56.9318745892772853},{-263.6986573392297259,-305.3159175943687842},{114.4374932409418335,-386.8576631782460709},{387.3603402909307647,-112.7242573215641670},{304.1458768811725122,265.0473108620167864},
{826.7542103268331175,-720.4732887981558633},{1052.9545740785492853,306.4163003037493240},{311.0733583712569725,1051.5881560175562299},{-716.8072684342765797,829.9347107360719065},{-1085.6585983674215186,-154.7568801561417047},
{-456.3604197327042584,-997.1657091307174596},{592.5134241903571137,-922.7849837957890031},{1096.6331584284585006,0.0},{592.5134241903571137,922.7849837957890031},{-456.3604197327042584,997.1657091307174596},
{-1085.6585983674215186,154.7568801561417047},{-716.8072684342765797,-829.9347107360719065},{311.0733583712569725,-1051.5881560175562299},{1052.9545740785492853,-306.4163003037493240},{826.7542103268331175,720.4732887981558633}}}), MATHSEQUAL,
// NOTE: The tolerances used here are unduly slack, this is due to inconsistent libm's and will be fixed shortly.
1e-13, 1e-13),
// exp(complex column vector of dimension: 225x1)
new CheckUnary<EXP>(OGComplexDenseMatrix::create({{{-7.0,-7.0}},{{-7.0,-6.0}},{{-7.0,-5.0}},{{-7.0,-4.0}},{{-7.0,-3.0}},
{{-7.0,-2.0}},{{-7.0,-1.0}},{{-7.0,0.0}},{{-7.0,1.0}},{{-7.0,2.0}},
{{-7.0,3.0}},{{-7.0,4.0}},{{-7.0,5.0}},{{-7.0,6.0}},{{-7.0,7.0}},
{{-6.0,-7.0}},{{-6.0,-6.0}},{{-6.0,-5.0}},{{-6.0,-4.0}},{{-6.0,-3.0}},
{{-6.0,-2.0}},{{-6.0,-1.0}},{{-6.0,0.0}},{{-6.0,1.0}},{{-6.0,2.0}},
{{-6.0,3.0}},{{-6.0,4.0}},{{-6.0,5.0}},{{-6.0,6.0}},{{-6.0,7.0}},
{{-5.0,-7.0}},{{-5.0,-6.0}},{{-5.0,-5.0}},{{-5.0,-4.0}},{{-5.0,-3.0}},
{{-5.0,-2.0}},{{-5.0,-1.0}},{{-5.0,0.0}},{{-5.0,1.0}},{{-5.0,2.0}},
{{-5.0,3.0}},{{-5.0,4.0}},{{-5.0,5.0}},{{-5.0,6.0}},{{-5.0,7.0}},
{{-4.0,-7.0}},{{-4.0,-6.0}},{{-4.0,-5.0}},{{-4.0,-4.0}},{{-4.0,-3.0}},
{{-4.0,-2.0}},{{-4.0,-1.0}},{{-4.0,0.0}},{{-4.0,1.0}},{{-4.0,2.0}},
{{-4.0,3.0}},{{-4.0,4.0}},{{-4.0,5.0}},{{-4.0,6.0}},{{-4.0,7.0}},
{{-3.0,-7.0}},{{-3.0,-6.0}},{{-3.0,-5.0}},{{-3.0,-4.0}},{{-3.0,-3.0}},
{{-3.0,-2.0}},{{-3.0,-1.0}},{{-3.0,0.0}},{{-3.0,1.0}},{{-3.0,2.0}},
{{-3.0,3.0}},{{-3.0,4.0}},{{-3.0,5.0}},{{-3.0,6.0}},{{-3.0,7.0}},
{{-2.0,-7.0}},{{-2.0,-6.0}},{{-2.0,-5.0}},{{-2.0,-4.0}},{{-2.0,-3.0}},
{{-2.0,-2.0}},{{-2.0,-1.0}},{{-2.0,0.0}},{{-2.0,1.0}},{{-2.0,2.0}},
{{-2.0,3.0}},{{-2.0,4.0}},{{-2.0,5.0}},{{-2.0,6.0}},{{-2.0,7.0}},
{{-1.0,-7.0}},{{-1.0,-6.0}},{{-1.0,-5.0}},{{-1.0,-4.0}},{{-1.0,-3.0}},
{{-1.0,-2.0}},{{-1.0,-1.0}},{{-1.0,0.0}},{{-1.0,1.0}},{{-1.0,2.0}},
{{-1.0,3.0}},{{-1.0,4.0}},{{-1.0,5.0}},{{-1.0,6.0}},{{-1.0,7.0}},
{{0.0,-7.0}},{{0.0,-6.0}},{{0.0,-5.0}},{{0.0,-4.0}},{{0.0,-3.0}},
{{0.0,-2.0}},{{0.0,-1.0}},{{0.0,0.0}},{{0.0,1.0}},{{0.0,2.0}},
{{0.0,3.0}},{{0.0,4.0}},{{0.0,5.0}},{{0.0,6.0}},{{0.0,7.0}},
{{1.0,-7.0}},{{1.0,-6.0}},{{1.0,-5.0}},{{1.0,-4.0}},{{1.0,-3.0}},
{{1.0,-2.0}},{{1.0,-1.0}},{{1.0,0.0}},{{1.0,1.0}},{{1.0,2.0}},
{{1.0,3.0}},{{1.0,4.0}},{{1.0,5.0}},{{1.0,6.0}},{{1.0,7.0}},
{{2.0,-7.0}},{{2.0,-6.0}},{{2.0,-5.0}},{{2.0,-4.0}},{{2.0,-3.0}},
{{2.0,-2.0}},{{2.0,-1.0}},{{2.0,0.0}},{{2.0,1.0}},{{2.0,2.0}},
{{2.0,3.0}},{{2.0,4.0}},{{2.0,5.0}},{{2.0,6.0}},{{2.0,7.0}},
{{3.0,-7.0}},{{3.0,-6.0}},{{3.0,-5.0}},{{3.0,-4.0}},{{3.0,-3.0}},
{{3.0,-2.0}},{{3.0,-1.0}},{{3.0,0.0}},{{3.0,1.0}},{{3.0,2.0}},
{{3.0,3.0}},{{3.0,4.0}},{{3.0,5.0}},{{3.0,6.0}},{{3.0,7.0}},
{{4.0,-7.0}},{{4.0,-6.0}},{{4.0,-5.0}},{{4.0,-4.0}},{{4.0,-3.0}},
{{4.0,-2.0}},{{4.0,-1.0}},{{4.0,0.0}},{{4.0,1.0}},{{4.0,2.0}},
{{4.0,3.0}},{{4.0,4.0}},{{4.0,5.0}},{{4.0,6.0}},{{4.0,7.0}},
{{5.0,-7.0}},{{5.0,-6.0}},{{5.0,-5.0}},{{5.0,-4.0}},{{5.0,-3.0}},
{{5.0,-2.0}},{{5.0,-1.0}},{{5.0,0.0}},{{5.0,1.0}},{{5.0,2.0}},
{{5.0,3.0}},{{5.0,4.0}},{{5.0,5.0}},{{5.0,6.0}},{{5.0,7.0}},
{{6.0,-7.0}},{{6.0,-6.0}},{{6.0,-5.0}},{{6.0,-4.0}},{{6.0,-3.0}},
{{6.0,-2.0}},{{6.0,-1.0}},{{6.0,0.0}},{{6.0,1.0}},{{6.0,2.0}},
{{6.0,3.0}},{{6.0,4.0}},{{6.0,5.0}},{{6.0,6.0}},{{6.0,7.0}},
{{7.0,-7.0}},{{7.0,-6.0}},{{7.0,-5.0}},{{7.0,-4.0}},{{7.0,-3.0}},
{{7.0,-2.0}},{{7.0,-1.0}},{{7.0,0.0}},{{7.0,1.0}},{{7.0,2.0}},
{{7.0,3.0}},{{7.0,4.0}},{{7.0,5.0}},{{7.0,6.0}},{{7.0,7.0}}}), OGComplexDenseMatrix::create({{{0.0006874698695266,-0.0005990942309827}},{{0.0008755619682578,0.0002547939537040}},{{0.0002586664312337,0.0008744257523978}},{{-0.0005960458297653,0.0006901145469580}},{{-0.0009027563036842,-0.0001286847903287}},
{{-0.0003794767952699,-0.0008291719248475}},{{0.0004926919286687,-0.0007673222155837}},{{0.0009118819655545,0.0}},{{0.0004926919286687,0.0007673222155837}},{{-0.0003794767952699,0.0008291719248475}},
{{-0.0009027563036842,0.0001286847903287}},{{-0.0005960458297653,-0.0006901145469580}},{{0.0002586664312337,-0.0008744257523978}},{{0.0008755619682578,-0.0002547939537040}},{{0.0006874698695266,0.0005990942309827}},
{{0.0018687368539471,-0.0016285069616148}},{{0.0023800241880050,0.0006926017743549}},{{0.0007031282596549,0.0023769356330795}},{{-0.0016202205479798,0.0018759258325511}},{{-0.0024539460558317,-0.0003498015271496}},
{{-0.0010315248769040,-0.0022539229759813}},{{0.0013392755167285,-0.0020857980351942}},{{0.0024787521766664,0.0}},{{0.0013392755167285,0.0020857980351942}},{{-0.0010315248769040,0.0022539229759813}},
{{-0.0024539460558317,0.0003498015271496}},{{-0.0016202205479798,-0.0018759258325511}},{{0.0007031282596549,-0.0023769356330795}},{{0.0023800241880050,-0.0006926017743549}},{{0.0018687368539471,0.0016285069616148}},
{{0.0050797534322562,-0.0044267408812766}},{{0.0064695765015469,0.0018826868175874}},{{0.0019113007712960,0.0064611809388167}},{{-0.0044042160736693,0.0050992951021604}},{{-0.0066705169715861,-0.0009508591348179}},
{{-0.0028039753284917,-0.0061267978683562}},{{0.0036405283004232,-0.0056697868969039}},{{0.0067379469990855,0.0}},{{0.0036405283004232,0.0056697868969039}},{{-0.0028039753284917,0.0061267978683562}},
{{-0.0066705169715861,0.0009508591348179}},{{-0.0044042160736693,-0.0050992951021604}},{{0.0019113007712960,-0.0064611809388167}},{{0.0064695765015469,-0.0018826868175874}},{{0.0050797534322562,0.0044267408812766}},
{{0.0138082014479546,-0.0120331292968710}},{{0.0175861322419805,0.0051176733649273}},{{0.0051954541553336,0.0175633107363714}},{{-0.0119719005216626,0.0138613212141530}},{{-0.0181323450702902,-0.0025847031075998}},
{{-0.0076219951828865,-0.0166543633121944}},{{0.0098959819250312,-0.0154120786930890}},{{0.0183156388887342,0.0}},{{0.0098959819250312,0.0154120786930890}},{{-0.0076219951828865,0.0166543633121944}},
{{-0.0181323450702902,0.0025847031075998}},{{-0.0119719005216626,-0.0138613212141530}},{{0.0051954541553336,-0.0175633107363714}},{{0.0175861322419805,-0.0051176733649273}},{{0.0138082014479546,0.0120331292968710}},
{{0.0375345830796769,-0.0327094367071827}},{{0.0478040637062533,0.0139112785118707}},{{0.0141227086210353,0.0477420284222580}},{{-0.0325429996401548,0.0376789775748659}},{{-0.0492888241119187,-0.0070259514893501}},
{{-0.0207187310022429,-0.0452712531560930}},{{0.0269000678415716,-0.0418943734502045}},{{0.0497870683678639,0.0}},{{0.0269000678415716,0.0418943734502045}},{{-0.0207187310022429,0.0452712531560930}},
{{-0.0492888241119187,0.0070259514893501}},{{-0.0325429996401548,-0.0376789775748659}},{{0.0141227086210353,-0.0477420284222580}},{{0.0478040637062533,-0.0139112785118707}},{{0.0375345830796769,0.0327094367071827}},
{{0.1020295751242720,-0.0889134674202661}},{{0.1299449176992069,0.0378147755894509}},{{0.0383895022131823,0.1297762883139992}},{{-0.0884610445653820,0.1024220800566737}},{{-0.1339809149295426,-0.0190985162611352}},
{{-0.0563193499921279,-0.1230600248057767}},{{0.0731219655980596,-0.1138807140643681}},{{0.1353352832366127,0.0}},{{0.0731219655980596,0.1138807140643681}},{{-0.0563193499921279,0.1230600248057767}},
{{-0.1339809149295426,0.0190985162611352}},{{-0.0884610445653820,-0.1024220800566737}},{{0.0383895022131823,-0.1297762883139992}},{{0.1299449176992069,-0.0378147755894509}},{{0.1020295751242720,0.0889134674202661}},
{{0.2773451400257055,-0.2416918627937948}},{{0.3532269084823602,0.1027912173320610}},{{0.1043534862696817,0.3527685262888061}},{{-0.2404620499685837,0.2784120790510337}},{{-0.3641978864132929,-0.0519151497031734}},
{{-0.1530918656742263,-0.3345118292392623}},{{0.1987661103464130,-0.3095598756531122}},{{0.3678794411714423,0.0}},{{0.1987661103464130,0.3095598756531122}},{{-0.1530918656742263,0.3345118292392623}},
{{-0.3641978864132929,0.0519151497031734}},{{-0.2404620499685837,-0.2784120790510337}},{{0.1043534862696817,-0.3527685262888061}},{{0.3532269084823602,-0.1027912173320610}},{{0.2773451400257055,0.2416918627937948}},
{{0.7539022543433046,-0.6569865987187891}},{{0.9601702866503660,0.2794154981989259}},{{0.2836621854632262,0.9589242746631385}},{{-0.6536436208636119,0.7568024953079282}},{{-0.9899924966004454,-0.1411200080598672}},
{{-0.4161468365471424,-0.9092974268256817}},{{0.5403023058681398,-0.8414709848078965}},{{1.0,0.0}},{{0.5403023058681398,0.8414709848078965}},{{-0.4161468365471424,0.9092974268256817}},
{{-0.9899924966004454,0.1411200080598672}},{{-0.6536436208636119,-0.7568024953079282}},{{0.2836621854632262,-0.9589242746631385}},{{0.9601702866503660,-0.2794154981989259}},{{0.7539022543433046,0.6569865987187891}},
{{2.0493187984157140,-1.7858747328383988}},{{2.6100134424280022,0.7595300713439712}},{{0.7710737641656674,2.6066264306850795}},{{-1.7767875768817298,2.0572024707280030}},{{-2.6910786138197937,-0.3836039535411310}},
{{-1.1312043837568135,-2.4717266720048188}},{{1.4686939399158851,-2.2873552871788423}},{{2.7182818284590451,0.0}},{{1.4686939399158851,2.2873552871788423}},{{-1.1312043837568135,2.4717266720048188}},
{{-2.6910786138197937,0.3836039535411310}},{{-1.7767875768817298,-2.0572024707280030}},{{0.7710737641656674,-2.6066264306850795}},{{2.6100134424280022,-0.7595300713439712}},{{2.0493187984157140,1.7858747328383988}},
{{5.5706260504529617,-4.8545108341787717}},{{7.0947521125858772,2.0646167911025195}},{{2.0959958015330491,7.0855452601123137}},{{-4.8298093832693851,5.5920560936409816}},{{-7.3151100949011028,-1.0427436562359045}},
{{-3.0749323206393591,-6.7188496974282499}},{{3.9923240484412719,-6.2176763123679679}},{{7.3890560989306504,0.0}},{{3.9923240484412719,6.2176763123679679}},{{-3.0749323206393591,6.7188496974282499}},
{{-7.3151100949011028,1.0427436562359045}},{{-4.8298093832693851,-5.5920560936409816}},{{2.0959958015330491,-7.0855452601123137}},{{7.0947521125858772,-2.0646167911025195}},{{5.5706260504529617,4.8545108341787717}},
{{15.1425315660868645,-13.1959285866057172}},{{19.2855357450636120,5.6122103059854025}},{{5.6975072998337390,19.2605089252874215}},{{-13.1287830814621582,15.2007844630679543}},{{-19.8845308441469868,-2.8344711324870042}},
{{-8.3585326509353717,-18.2637270406667653}},{{10.8522619141979586,-16.9013965351500950}},{{20.0855369231876679,0.0}},{{10.8522619141979586,16.9013965351500950}},{{-8.3585326509353717,18.2637270406667653}},
{{-19.8845308441469868,2.8344711324870042}},{{-13.1287830814621582,-15.2007844630679543}},{{5.6975072998337390,-19.2605089252874215}},{{19.2855357450636120,-5.6122103059854025}},{{15.1425315660868645,13.1959285866057172}},
{{41.1616683929614098,-35.8702528866135708}},{{52.4235213679037884,15.2555692922506978}},{{15.4874305606508127,52.3554914184820461}},{{-35.6877324801191307,41.3200161842801990}},{{-54.0517588610781559,-7.7048913727311543}},
{{-22.7208474176192325,-49.6459573345805651}},{{29.4995063590424813,-45.9427590770791667}},{{54.5981500331442362,0.0}},{{29.4995063590424813,45.9427590770791667}},{{-22.7208474176192325,49.6459573345805651}},
{{-54.0517588610781559,7.7048913727311543}},{{-35.6877324801191307,-41.3200161842801990}},{{15.4874305606508127,-52.3554914184820461}},{{52.4235213679037884,-15.2555692922506978}},{{41.1616683929614098,35.8702528866135708}},
{{111.8890152216440299,-97.5054566039122932}},{{142.5019055182073373,41.4689367899228856}},{{42.0992010625383912,142.3169809429032284}},{{-97.0093146996155014,112.3194491453625261}},{{-146.9279139083189420,-20.9440662087459657}},
{{-61.7616666625049859,-134.9517036790433906}},{{80.1879720842972290,-124.8853671484961581}},{{148.4131591025765999,0.0}},{{80.1879720842972290,124.8853671484961581}},{{-61.7616666625049859,134.9517036790433906}},
{{-146.9279139083189420,20.9440662087459657}},{{-97.0093146996155014,-112.3194491453625261}},{{42.0992010625383912,-142.3169809429032284}},{{142.5019055182073373,-41.4689367899228856}},{{111.8890152216440299,97.5054566039122932}},
{{304.1458768811725122,-265.0473108620167864}},{{387.3603402909307647,112.7242573215641670}},{{114.4374932409418335,386.8576631782460709}},{{-263.6986573392297259,305.3159175943687842}},{{-399.3914784703783312,-56.9318745892772853}},
{{-167.8856161840321022,-366.8367638303333820}},{{217.9735073777263494,-339.4736241601933102}},{{403.4287934927351102,0.0}},{{217.9735073777263494,339.4736241601933102}},{{-167.8856161840321022,366.8367638303333820}},
{{-399.3914784703783312,56.9318745892772853}},{{-263.6986573392297259,-305.3159175943687842}},{{114.4374932409418335,-386.8576631782460709}},{{387.3603402909307647,-112.7242573215641670}},{{304.1458768811725122,265.0473108620167864}},
{{826.7542103268331175,-720.4732887981558633}},{{1052.9545740785492853,306.4163003037493240}},{{311.0733583712569725,1051.5881560175562299}},{{-716.8072684342765797,829.9347107360719065}},{{-1085.6585983674215186,-154.7568801561417047}},
{{-456.3604197327042584,-997.1657091307174596}},{{592.5134241903571137,-922.7849837957890031}},{{1096.6331584284585006,0.0}},{{592.5134241903571137,922.7849837957890031}},{{-456.3604197327042584,997.1657091307174596}},
{{-1085.6585983674215186,154.7568801561417047}},{{-716.8072684342765797,-829.9347107360719065}},{{311.0733583712569725,-1051.5881560175562299}},{{1052.9545740785492853,-306.4163003037493240}},{{826.7542103268331175,720.4732887981558633}}}), MATHSEQUAL,
// NOTE: The tolerances used here are unduly slack, this is due to inconsistent libm's and will be fixed shortly.
1e-13, 1e-13),
// exp(complex matrix of dimension: 9x25)
new CheckUnary<EXP>(OGComplexDenseMatrix::create({{{-7.0,-7.0},{-7.0,2.0},{-6.0,-4.0},{-6.0,5.0},{-5.0,-1.0},
{-4.0,-7.0},{-4.0,2.0},{-3.0,-4.0},{-3.0,5.0},{-2.0,-1.0},
{-1.0,-7.0},{-1.0,2.0},{0.0,-4.0},{0.0,5.0},{1.0,-1.0},
{2.0,-7.0},{2.0,2.0},{3.0,-4.0},{3.0,5.0},{4.0,-1.0},
{5.0,-7.0},{5.0,2.0},{6.0,-4.0},{6.0,5.0},{7.0,-1.0}},{{-7.0,-6.0},{-7.0,3.0},{-6.0,-3.0},{-6.0,6.0},{-5.0,0.0},
{-4.0,-6.0},{-4.0,3.0},{-3.0,-3.0},{-3.0,6.0},{-2.0,0.0},
{-1.0,-6.0},{-1.0,3.0},{0.0,-3.0},{0.0,6.0},{1.0,0.0},
{2.0,-6.0},{2.0,3.0},{3.0,-3.0},{3.0,6.0},{4.0,0.0},
{5.0,-6.0},{5.0,3.0},{6.0,-3.0},{6.0,6.0},{7.0,0.0}},{{-7.0,-5.0},{-7.0,4.0},{-6.0,-2.0},{-6.0,7.0},{-5.0,1.0},
{-4.0,-5.0},{-4.0,4.0},{-3.0,-2.0},{-3.0,7.0},{-2.0,1.0},
{-1.0,-5.0},{-1.0,4.0},{0.0,-2.0},{0.0,7.0},{1.0,1.0},
{2.0,-5.0},{2.0,4.0},{3.0,-2.0},{3.0,7.0},{4.0,1.0},
{5.0,-5.0},{5.0,4.0},{6.0,-2.0},{6.0,7.0},{7.0,1.0}},{{-7.0,-4.0},{-7.0,5.0},{-6.0,-1.0},{-5.0,-7.0},{-5.0,2.0},
{-4.0,-4.0},{-4.0,5.0},{-3.0,-1.0},{-2.0,-7.0},{-2.0,2.0},
{-1.0,-4.0},{-1.0,5.0},{0.0,-1.0},{1.0,-7.0},{1.0,2.0},
{2.0,-4.0},{2.0,5.0},{3.0,-1.0},{4.0,-7.0},{4.0,2.0},
{5.0,-4.0},{5.0,5.0},{6.0,-1.0},{7.0,-7.0},{7.0,2.0}},{{-7.0,-3.0},{-7.0,6.0},{-6.0,0.0},{-5.0,-6.0},{-5.0,3.0},
{-4.0,-3.0},{-4.0,6.0},{-3.0,0.0},{-2.0,-6.0},{-2.0,3.0},
{-1.0,-3.0},{-1.0,6.0},{0.0,0.0},{1.0,-6.0},{1.0,3.0},
{2.0,-3.0},{2.0,6.0},{3.0,0.0},{4.0,-6.0},{4.0,3.0},
{5.0,-3.0},{5.0,6.0},{6.0,0.0},{7.0,-6.0},{7.0,3.0}},
{{-7.0,-2.0},{-7.0,7.0},{-6.0,1.0},{-5.0,-5.0},{-5.0,4.0},
{-4.0,-2.0},{-4.0,7.0},{-3.0,1.0},{-2.0,-5.0},{-2.0,4.0},
{-1.0,-2.0},{-1.0,7.0},{0.0,1.0},{1.0,-5.0},{1.0,4.0},
{2.0,-2.0},{2.0,7.0},{3.0,1.0},{4.0,-5.0},{4.0,4.0},
{5.0,-2.0},{5.0,7.0},{6.0,1.0},{7.0,-5.0},{7.0,4.0}},{{-7.0,-1.0},{-6.0,-7.0},{-6.0,2.0},{-5.0,-4.0},{-5.0,5.0},
{-4.0,-1.0},{-3.0,-7.0},{-3.0,2.0},{-2.0,-4.0},{-2.0,5.0},
{-1.0,-1.0},{0.0,-7.0},{0.0,2.0},{1.0,-4.0},{1.0,5.0},
{2.0,-1.0},{3.0,-7.0},{3.0,2.0},{4.0,-4.0},{4.0,5.0},
{5.0,-1.0},{6.0,-7.0},{6.0,2.0},{7.0,-4.0},{7.0,5.0}},{{-7.0,0.0},{-6.0,-6.0},{-6.0,3.0},{-5.0,-3.0},{-5.0,6.0},
{-4.0,0.0},{-3.0,-6.0},{-3.0,3.0},{-2.0,-3.0},{-2.0,6.0},
{-1.0,0.0},{0.0,-6.0},{0.0,3.0},{1.0,-3.0},{1.0,6.0},
{2.0,0.0},{3.0,-6.0},{3.0,3.0},{4.0,-3.0},{4.0,6.0},
{5.0,0.0},{6.0,-6.0},{6.0,3.0},{7.0,-3.0},{7.0,6.0}},{{-7.0,1.0},{-6.0,-5.0},{-6.0,4.0},{-5.0,-2.0},{-5.0,7.0},
{-4.0,1.0},{-3.0,-5.0},{-3.0,4.0},{-2.0,-2.0},{-2.0,7.0},
{-1.0,1.0},{0.0,-5.0},{0.0,4.0},{1.0,-2.0},{1.0,7.0},
{2.0,1.0},{3.0,-5.0},{3.0,4.0},{4.0,-2.0},{4.0,7.0},
{5.0,1.0},{6.0,-5.0},{6.0,4.0},{7.0,-2.0},{7.0,7.0}}}), OGComplexDenseMatrix::create({{{0.0006874698695266,-0.0005990942309827},{-0.0003794767952699,0.0008291719248475},{-0.0016202205479798,0.0018759258325511},{0.0007031282596549,-0.0023769356330795},{0.0036405283004232,-0.0056697868969039},
{0.0138082014479546,-0.0120331292968710},{-0.0076219951828865,0.0166543633121944},{-0.0325429996401548,0.0376789775748659},{0.0141227086210353,-0.0477420284222580},{0.0731219655980596,-0.1138807140643681},
{0.2773451400257055,-0.2416918627937948},{-0.1530918656742263,0.3345118292392623},{-0.6536436208636119,0.7568024953079282},{0.2836621854632262,-0.9589242746631385},{1.4686939399158851,-2.2873552871788423},
{5.5706260504529617,-4.8545108341787717},{-3.0749323206393591,6.7188496974282499},{-13.1287830814621582,15.2007844630679543},{5.6975072998337390,-19.2605089252874215},{29.4995063590424813,-45.9427590770791667},
{111.8890152216440299,-97.5054566039122932},{-61.7616666625049859,134.9517036790433906},{-263.6986573392297259,305.3159175943687842},{114.4374932409418335,-386.8576631782460709},{592.5134241903571137,-922.7849837957890031}},{{0.0008755619682578,0.0002547939537040},{-0.0009027563036842,0.0001286847903287},{-0.0024539460558317,-0.0003498015271496},{0.0023800241880050,-0.0006926017743549},{0.0067379469990855,0.0},
{0.0175861322419805,0.0051176733649273},{-0.0181323450702902,0.0025847031075998},{-0.0492888241119187,-0.0070259514893501},{0.0478040637062533,-0.0139112785118707},{0.1353352832366127,0.0},
{0.3532269084823602,0.1027912173320610},{-0.3641978864132929,0.0519151497031734},{-0.9899924966004454,-0.1411200080598672},{0.9601702866503660,-0.2794154981989259},{2.7182818284590451,0.0},
{7.0947521125858772,2.0646167911025195},{-7.3151100949011028,1.0427436562359045},{-19.8845308441469868,-2.8344711324870042},{19.2855357450636120,-5.6122103059854025},{54.5981500331442362,0.0},
{142.5019055182073373,41.4689367899228856},{-146.9279139083189420,20.9440662087459657},{-399.3914784703783312,-56.9318745892772853},{387.3603402909307647,-112.7242573215641670},{1096.6331584284585006,0.0}},{{0.0002586664312337,0.0008744257523978},{-0.0005960458297653,-0.0006901145469580},{-0.0010315248769040,-0.0022539229759813},{0.0018687368539471,0.0016285069616148},{0.0036405283004232,0.0056697868969039},
{0.0051954541553336,0.0175633107363714},{-0.0119719005216626,-0.0138613212141530},{-0.0207187310022429,-0.0452712531560930},{0.0375345830796769,0.0327094367071827},{0.0731219655980596,0.1138807140643681},
{0.1043534862696817,0.3527685262888061},{-0.2404620499685837,-0.2784120790510337},{-0.4161468365471424,-0.9092974268256817},{0.7539022543433046,0.6569865987187891},{1.4686939399158851,2.2873552871788423},
{2.0959958015330491,7.0855452601123137},{-4.8298093832693851,-5.5920560936409816},{-8.3585326509353717,-18.2637270406667653},{15.1425315660868645,13.1959285866057172},{29.4995063590424813,45.9427590770791667},
{42.0992010625383912,142.3169809429032284},{-97.0093146996155014,-112.3194491453625261},{-167.8856161840321022,-366.8367638303333820},{304.1458768811725122,265.0473108620167864},{592.5134241903571137,922.7849837957890031}},{{-0.0005960458297653,0.0006901145469580},{0.0002586664312337,-0.0008744257523978},{0.0013392755167285,-0.0020857980351942},{0.0050797534322562,-0.0044267408812766},{-0.0028039753284917,0.0061267978683562},
{-0.0119719005216626,0.0138613212141530},{0.0051954541553336,-0.0175633107363714},{0.0269000678415716,-0.0418943734502045},{0.1020295751242720,-0.0889134674202661},{-0.0563193499921279,0.1230600248057767},
{-0.2404620499685837,0.2784120790510337},{0.1043534862696817,-0.3527685262888061},{0.5403023058681398,-0.8414709848078965},{2.0493187984157140,-1.7858747328383988},{-1.1312043837568135,2.4717266720048188},
{-4.8298093832693851,5.5920560936409816},{2.0959958015330491,-7.0855452601123137},{10.8522619141979586,-16.9013965351500950},{41.1616683929614098,-35.8702528866135708},{-22.7208474176192325,49.6459573345805651},
{-97.0093146996155014,112.3194491453625261},{42.0992010625383912,-142.3169809429032284},{217.9735073777263494,-339.4736241601933102},{826.7542103268331175,-720.4732887981558633},{-456.3604197327042584,997.1657091307174596}},{{-0.0009027563036842,-0.0001286847903287},{0.0008755619682578,-0.0002547939537040},{0.0024787521766664,0.0},{0.0064695765015469,0.0018826868175874},{-0.0066705169715861,0.0009508591348179},
{-0.0181323450702902,-0.0025847031075998},{0.0175861322419805,-0.0051176733649273},{0.0497870683678639,0.0},{0.1299449176992069,0.0378147755894509},{-0.1339809149295426,0.0190985162611352},
{-0.3641978864132929,-0.0519151497031734},{0.3532269084823602,-0.1027912173320610},{1.0,0.0},{2.6100134424280022,0.7595300713439712},{-2.6910786138197937,0.3836039535411310},
{-7.3151100949011028,-1.0427436562359045},{7.0947521125858772,-2.0646167911025195},{20.0855369231876679,0.0},{52.4235213679037884,15.2555692922506978},{-54.0517588610781559,7.7048913727311543},
{-146.9279139083189420,-20.9440662087459657},{142.5019055182073373,-41.4689367899228856},{403.4287934927351102,0.0},{1052.9545740785492853,306.4163003037493240},{-1085.6585983674215186,154.7568801561417047}},
{{-0.0003794767952699,-0.0008291719248475},{0.0006874698695266,0.0005990942309827},{0.0013392755167285,0.0020857980351942},{0.0019113007712960,0.0064611809388167},{-0.0044042160736693,-0.0050992951021604},
{-0.0076219951828865,-0.0166543633121944},{0.0138082014479546,0.0120331292968710},{0.0269000678415716,0.0418943734502045},{0.0383895022131823,0.1297762883139992},{-0.0884610445653820,-0.1024220800566737},
{-0.1530918656742263,-0.3345118292392623},{0.2773451400257055,0.2416918627937948},{0.5403023058681398,0.8414709848078965},{0.7710737641656674,2.6066264306850795},{-1.7767875768817298,-2.0572024707280030},
{-3.0749323206393591,-6.7188496974282499},{5.5706260504529617,4.8545108341787717},{10.8522619141979586,16.9013965351500950},{15.4874305606508127,52.3554914184820461},{-35.6877324801191307,-41.3200161842801990},
{-61.7616666625049859,-134.9517036790433906},{111.8890152216440299,97.5054566039122932},{217.9735073777263494,339.4736241601933102},{311.0733583712569725,1051.5881560175562299},{-716.8072684342765797,-829.9347107360719065}},{{0.0004926919286687,-0.0007673222155837},{0.0018687368539471,-0.0016285069616148},{-0.0010315248769040,0.0022539229759813},{-0.0044042160736693,0.0050992951021604},{0.0019113007712960,-0.0064611809388167},
{0.0098959819250312,-0.0154120786930890},{0.0375345830796769,-0.0327094367071827},{-0.0207187310022429,0.0452712531560930},{-0.0884610445653820,0.1024220800566737},{0.0383895022131823,-0.1297762883139992},
{0.1987661103464130,-0.3095598756531122},{0.7539022543433046,-0.6569865987187891},{-0.4161468365471424,0.9092974268256817},{-1.7767875768817298,2.0572024707280030},{0.7710737641656674,-2.6066264306850795},
{3.9923240484412719,-6.2176763123679679},{15.1425315660868645,-13.1959285866057172},{-8.3585326509353717,18.2637270406667653},{-35.6877324801191307,41.3200161842801990},{15.4874305606508127,-52.3554914184820461},
{80.1879720842972290,-124.8853671484961581},{304.1458768811725122,-265.0473108620167864},{-167.8856161840321022,366.8367638303333820},{-716.8072684342765797,829.9347107360719065},{311.0733583712569725,-1051.5881560175562299}},{{0.0009118819655545,0.0},{0.0023800241880050,0.0006926017743549},{-0.0024539460558317,0.0003498015271496},{-0.0066705169715861,-0.0009508591348179},{0.0064695765015469,-0.0018826868175874},
{0.0183156388887342,0.0},{0.0478040637062533,0.0139112785118707},{-0.0492888241119187,0.0070259514893501},{-0.1339809149295426,-0.0190985162611352},{0.1299449176992069,-0.0378147755894509},
{0.3678794411714423,0.0},{0.9601702866503660,0.2794154981989259},{-0.9899924966004454,0.1411200080598672},{-2.6910786138197937,-0.3836039535411310},{2.6100134424280022,-0.7595300713439712},
{7.3890560989306504,0.0},{19.2855357450636120,5.6122103059854025},{-19.8845308441469868,2.8344711324870042},{-54.0517588610781559,-7.7048913727311543},{52.4235213679037884,-15.2555692922506978},
{148.4131591025765999,0.0},{387.3603402909307647,112.7242573215641670},{-399.3914784703783312,56.9318745892772853},{-1085.6585983674215186,-154.7568801561417047},{1052.9545740785492853,-306.4163003037493240}},{{0.0004926919286687,0.0007673222155837},{0.0007031282596549,0.0023769356330795},{-0.0016202205479798,-0.0018759258325511},{-0.0028039753284917,-0.0061267978683562},{0.0050797534322562,0.0044267408812766},
{0.0098959819250312,0.0154120786930890},{0.0141227086210353,0.0477420284222580},{-0.0325429996401548,-0.0376789775748659},{-0.0563193499921279,-0.1230600248057767},{0.1020295751242720,0.0889134674202661},
{0.1987661103464130,0.3095598756531122},{0.2836621854632262,0.9589242746631385},{-0.6536436208636119,-0.7568024953079282},{-1.1312043837568135,-2.4717266720048188},{2.0493187984157140,1.7858747328383988},
{3.9923240484412719,6.2176763123679679},{5.6975072998337390,19.2605089252874215},{-13.1287830814621582,-15.2007844630679543},{-22.7208474176192325,-49.6459573345805651},{41.1616683929614098,35.8702528866135708},
{80.1879720842972290,124.8853671484961581},{114.4374932409418335,386.8576631782460709},{-263.6986573392297259,-305.3159175943687842},{-456.3604197327042584,-997.1657091307174596},{826.7542103268331175,720.4732887981558633}}}), MATHSEQUAL,
// NOTE: The tolerances used here are unduly slack, this is due to inconsistent libm's and will be fixed shortly.
1e-13, 1e-13)
)
);
