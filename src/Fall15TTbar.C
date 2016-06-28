/* These Efficiencies have been derived for Summer12 ttbar events and should
be used only for the same MC samples or for events with similar topology */

float BTagSFUtil::TagEfficiencyB(float JetPt, float JetEta) {

  if (JetPt>=300.) JetPt = 299.;

  if (TaggerOP=="cMVAv2L") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.815795004368;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.886824786663;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.910945951939;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.917719125748;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.917990326881;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.905194580555;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.89661693573;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.777073979378;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.862257182598;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.891278743744;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.898663461208;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.900313735008;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.885537028313;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.878169417381;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.724499762058;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.818275272846;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.853698134422;
if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.860752463341;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.849718213081;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.840853989124;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.794380545616;
  }

  if (TaggerOP=="cMVAv2M") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.626919150352;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.746057152748;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.788357615471;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.796857655048;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.792890191078;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.761066794395;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.745032429695;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.566644489765;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.696286857128;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.745110869408;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.758478820324;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.753808796406;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.714230358601;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.685773611069;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.484487354755;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.623418986797;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.674012362957;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.684972345829;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.658038139343;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.59693300724;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.539637207985;
  }


  if (TaggerOP=="cMVAv2T") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.430394291878;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.56863373518;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.612299621105;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.618415236473;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.602062106133;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.559142231941;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.527011990547;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.35617774725;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.502160608768;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.557408869267;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.568251132965;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.553134024143;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.499462783337;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.451681911945;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.286212146282;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.430897504091;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.484166353941;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.492211461067;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.454125225544;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.378873288631;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.29642790556;
  }


  if (TaggerOP=="CSVv2L") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.762248754501;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.847564041615;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.872861266136;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.879918456078;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.882792234421;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.872669458389;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.858637034893;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.724070191383;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.821053922176;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.851150155067;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.858662366867;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.862402915955;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.849800944328;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.848933935165;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.669675171375;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.774811983109;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.810556054115;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.821435570717;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.822479307652;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.821313261986;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.786239981651;
  }


  if (TaggerOP=="CSVv2M") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.602909445763;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.723289549351;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.759834766388;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.76381623745;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.757704377174;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.718211650848;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.700305938721;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.547532916069;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.677677452564;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.718517482281;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.724130868912;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.71468859911;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.662284910679;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.637594163418;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.466375172138;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.599007308483;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.636882066727;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.639951944351;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.618022978306;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.53252851963;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.485070109367;
  }

  if (TaggerOP=="CSVv2T") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.406940072775;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.527169048786;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.561695754528;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.563293278217;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.547118484974;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.509578764439;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.476311206818;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.341938436031;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.469324111938;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.512378096581;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.517984271049;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.501258075237;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.454942405224;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.416053473949;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.269869953394;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.394988387823;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.436696529388;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.438257098198;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.406672954559;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.334709763527;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.275289863348;
  }

  cout << "BTagSFUtil: Jet pt (" << JetPt << ") or jet eta (" << JetEta << ") out of range!" << endl;

  if (TaggerOP=="cMVAv2L") return 0.81;
  if (TaggerOP=="cMVAv2M") return 0.63;
  if (TaggerOP=="cMVAv2T") return 0.53;
  if (TaggerOP=="CSVv2L")  return 0.78;
  if (TaggerOP=="CSVv2M")  return 0.60;
  if (TaggerOP=="CSVv2T")  return 0.50;

  cout << "BTagSFUtil: Tagger (" << TaggerOP << ") not valid!" << endl;

  return 0.0;

}

float BTagSFUtil::TagEfficiencyC(float JetPt, float JetEta) {

  if (JetPt>=300.) JetPt = 299.;

  if (TaggerOP=="cMVAv2L") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.356370925903;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.390322744846;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.406007528305;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.451337367296;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.472892254591;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.513566076756;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.53137999773;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.333257913589;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.378181755543;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.413352310658;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.436691552401;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.459706872702;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.519376456738;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.517870187759;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.304749250412;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.360106647015;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.397319078445;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.424173742533;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.480025023222;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.481656998396;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.482574909925;
  }

  if (TaggerOP=="cMVAv2M") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.143776357174;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.16271546483;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.170078873634;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.206905066967;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.19960847497;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.205658271909;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.221090450883;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.121043287218;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.132812023163;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.16158054769;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.177428767085;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.185217827559;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.189037889242;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.176110029221;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0930839627981;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.119505673647;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.144967108965;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.132994413376;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.164814442396;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.159375414252;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.155362606049;
  }

  if (TaggerOP=="cMVAv2T") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.0463191270828;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.0450115837157;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.0481297820807;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.0589671172202;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.0539544932544;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.0486885122955;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.0956817194819;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0346488915384;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0368289574981;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0463413409889;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0436602421105;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0478399805725;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0556757040322;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0495257787406;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0247254613787;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0283070355654;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0399569123983;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0351743772626;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0410476624966;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0551304668188;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0318589732051;
  }
  
  if (TaggerOP=="CSVv2L") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.333838015795;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.350223302841;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.326638907194;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.368230521679;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.366943329573;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.40287783742;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.430959671736;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.317459911108;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.343802988529;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.351783424616;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.352571755648;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.373315185308;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.391356378794;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.39520585537;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.291063159704;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.333139181137;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.346517235041;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.349243819714;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.38118159771;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.397626072168;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.396141082048;
  }

  if (TaggerOP=="CSVv2M") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.148223534226;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.161392554641;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.158053651452;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.178019613028;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.166416496038;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.17408414185;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.184983402491;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.129684448242;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.144055396318;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.155932366848;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.156738996506;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.151396304369;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.140195459127;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.13259011507;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0967272669077;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.120535381138;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.128637954593;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.12442715466;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.128310114145;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.114916503429;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.091979637742;
  }

  if (TaggerOP=="CSVv2T") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.0465994216502;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.0407951213419;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.0375447273254;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.0404699631035;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.040902171284;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.0334508605301;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.0680036619306;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0368960686028;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0326676256955;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0347037911415;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0385629087687;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0342811755836;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0351041257381;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0360710546374;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0261827390641;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0265143178403;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0332705900073;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0247713606805;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0303604509681;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0425921306014;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0266001615673;
  }

  cout << "BTagSFUtil: Jet pt (" << JetPt << ") or jet eta (" << JetEta << ") out of range!" << endl;

  if (TaggerOP=="cMVAv2L") return 0.35;
  if (TaggerOP=="cMVAv2M") return 0.22;
  if (TaggerOP=="cMVAv2T") return 0.06;
  if (TaggerOP=="CSVv2L")  return 0.32;
  if (TaggerOP=="CSVv2M")  return 0.19;
  if (TaggerOP=="CSVv2T")  return 0.04;

  cout << "BTagSFUtil: Tagger (" << TaggerOP << ") not valid!" << endl;

  return 0.0;

}


float BTagSFUtil::TagEfficiencyLight(float JetPt, float JetEta) {

  if (JetPt>=300.) JetPt = 299.;

  if (TaggerOP=="cMVAv2L") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.0866834297776;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.0944764465094;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.100861757994;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.100455135107;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.1190257743;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.13274858892;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.143092140555;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0909727215767;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.100413195789;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.104130581021;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.114426627755;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.132626593113;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.147097021341;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.168326377869;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.105774305761;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.127085387707;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.13446880877;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.151321783662;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.167348071933;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.182425841689;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.191957831383;
  }
  
  //#
  //# btagging efficiencies on MC for CMVAv2 MEDIUM WP 
  //#

  
  
  //  efficienciesMC_CMVAif (JetPt>'l','M')] = [
  if (TaggerOP=="cMVAv2M") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.0101834991947;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.00957410223782;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.0104316519573;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.0116350119933;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.0141519317403;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.0161932446063;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.0165150221437;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00974768493325;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00912322755903;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00998216494918;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.012970643118;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.01370546408;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0146999880672;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0197267848998;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0104736760259;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0128574892879;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0137135749683;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0182166285813;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0189476851374;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0189055278897;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0184890404344;
  }

  //#
  //# btagging efficiencies on MC for CMVAv2 TIGHT WP 
  //#



  //efficienciesMC_CMVAif (JetPt>'l','T')] = [
  if (TaggerOP=="cMVAv2T") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.00205240724608;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.00127708900254;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.0011497187661;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.000897619407624;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.00111395737622;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.00154228310566;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.00190135161392;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.001714178361;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00111462571658;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0014004711993;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00132417317946;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00155619403813;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00104505685158;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.000724958954379;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00130546744913;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00133321539033;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00130113959312;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00210598297417;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00170271459501;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00141030410305;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00219043530524;
  }






//
// btagging efficiencies on MC for CSVv2 LOOSE WP 
//



//efficienciesMC_CSVif (JetPt>'l','L')] = [
  if (TaggerOP=="CSVv2L") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.12603238225;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.0948777273297;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.068054266274;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.0618899166584;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.0730534270406;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.0819452777505;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.0874963179231;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.142002254725;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.108213119209;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0816416069865;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0814305990934;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0865499898791;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.105574257672;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.108610466123;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.168119996786;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.139982774854;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.117695190012;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.119392178953;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.132157757878;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.14649374783;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.162008374929;
  }

//
// btagging efficiencies on MC for CSVv2 MEDIUM WP 
//


//efficienciesMC_CSVif (JetPt>'l','M')] = [
  if (TaggerOP=="CSVv2M") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.0112318480387;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.0113384015858;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.00914892647415;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.00772258033976;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.00949382968247;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.0111417314038;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.0116981947795;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0111722769216;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0115915844217;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00927104149014;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00822949409485;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00928192865103;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00836690701544;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0118986470625;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0121467355639;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0159387215972;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0120216030627;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0127446157858;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0119238086045;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0142056308687;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.0150406695902;
  }


//
// btagging efficiencies on MC for CSVv2 TIGHT WP 
//
//efficienciesMC_CSVif (JetPt>'l','T')] = [
  if (TaggerOP=="CSVv2T") {
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)<0.8) return  0.00222137756646;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)<0.8) return  0.00145930575673;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)<0.8) return  0.00114606611896;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)<0.8) return  0.000695244700182;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)<0.8) return  0.00133819610346;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)<0.8) return  0.00153939228039;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)<0.8) return  0.00154242909048;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00187711545732;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.0014102255227;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00138171971776;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00140616181307;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00133975804783;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00104818423279;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=0.8 && fabs(JetEta)<1.6) return  0.00136825477239;
    if (JetPt>20.0 && JetPt<30.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00143571989611;
    if (JetPt>30.0 && JetPt<60.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00147300038952;
    if (JetPt>60.0 && JetPt<90.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00122315110639;
    if (JetPt>90.0 && JetPt<120.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00170518108644;
    if (JetPt>120.0 && JetPt<180.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00192294816952;
    if (JetPt>180.0 && JetPt<240.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00129882863257;
    if (JetPt>240.0 && JetPt<300.0 && fabs(JetEta)>=1.6 && fabs(JetEta)<2.4) return  0.00104440480936;
  }

  cout << "BTagSFUtil: Jet pt (" << JetPt << ") or jet eta (" << JetEta << ") out of range!" << endl;

  if (TaggerOP=="cMVAv2L") return 0.100;
  if (TaggerOP=="cMVAv2M") return 0.010;
  if (TaggerOP=="cMVAv2T") return 0.001;
  if (TaggerOP=="CSVv2L")  return 0.100;
  if (TaggerOP=="CSVv2M")  return 0.010;
  if (TaggerOP=="CSVv2T")  return 0.001;

  cout << "BTagSFUtil: Tagger (" << TaggerOP << ") not valid!" << endl;

  return 0.0;

}

