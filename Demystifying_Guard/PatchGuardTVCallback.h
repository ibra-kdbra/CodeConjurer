__int64 __fastcall PatchGuardTVCallback(__int64 a1, __int64 a2)
{
  __int64 v2; // r12
  __int64 v4; // rsi
  int v6; // eax
  int v7; // r14d
  __int64 v8; // r8
  __int64 v9; // rcx
  int v10; // edi
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9
  __int64 v15; // r14
  PSLIST_ENTRY Pool2; // rax
  __int64 v17; // r13
  __int64 v18; // r15
  __int64 v19; // rdx
  unsigned int v20; // eax
  ULONG_PTR v21; // rdi
  __int64 v22; // rcx
  __int64 v23; // rbx
  int v24; // eax
  unsigned __int64 v25; // rax
  unsigned __int128 v26; // rax
  unsigned __int64 v27; // rax
  unsigned __int128 v28; // rax
  unsigned __int64 v29; // rcx
  int v30; // ecx
  int v31; // ecx
  unsigned int v32; // r10d
  __int64 v33; // rbx
  __int64 v34; // rdx
  int v35; // ecx
  unsigned int v36; // eax
  int v37; // ecx
  int v38; // ecx
  int v39; // ecx
  unsigned __int64 v40; // rax
  __int64 v41; // rcx
  unsigned int v42; // r10d
  __int64 v43; // r14
  unsigned __int64 v44; // rsi
  unsigned __int64 v45; // rax
  unsigned __int128 v46; // rax
  __int64 v47; // rcx
  __int64 v48; // rax
  __int64 v49; // rbx
  unsigned int *v50; // rax
  int v51; // ecx
  unsigned __int64 v52; // rdx
  int v53; // eax
  unsigned __int64 v54; // rcx
  unsigned __int64 v55; // r12
  unsigned int v56; // r15d
  unsigned __int64 v57; // rbx
  unsigned int v58; // esi
  unsigned __int64 v59; // rax
  unsigned __int128 v60; // rax
  unsigned __int64 v61; // rbx
  ULONG_PTR v62; // r8
  unsigned int v63; // r9d
  char *v64; // r13
  __int64 v65; // r10
  int v66; // ecx
  __int64 v67; // rax
  int v68; // eax
  unsigned int v69; // r15d
  unsigned int v70; // r8d
  __int64 v71; // r9
  int v72; // r15d
  bool v73; // zf
  __int64 v74; // r8
  __int64 v75; // rdx
  unsigned __int64 v76; // r8
  int v77; // r10d
  unsigned __int64 v78; // rbx
  unsigned __int64 v79; // rsi
  _QWORD *v80; // rsi
  __int64 v81; // r8
  _QWORD *v82; // r9
  const char *v83; // rax
  unsigned int v84; // r10d
  __int64 v85; // r14
  unsigned __int64 v86; // rbx
  unsigned int v87; // r11d
  __int64 v88; // rdx
  __int64 v89; // rax
  __int64 v90; // rbx
  unsigned int v91; // r8d
  unsigned __int64 v92; // rdx
  __int64 v93; // rax
  unsigned __int64 i26; // rax
  unsigned int v95; // edx
  unsigned int v96; // ebx
  __int64 v97; // r8
  unsigned __int8 v98; // r15
  unsigned __int64 v99; // rsi
  __int64 v100; // r13
  unsigned __int64 v101; // r12
  unsigned __int64 v102; // r14
  int v103; // eax
  bool v104; // zf
  int v105; // edx
  __int64 v106; // rbx
  unsigned int *v107; // rbx
  unsigned __int64 v108; // r12
  __int64 v109; // r13
  __int64 v110; // r8
  _QWORD *v111; // r9
  const char *v112; // rax
  int v113; // r11d
  __int64 v114; // r15
  unsigned __int64 v115; // r14
  unsigned __int64 v116; // rsi
  unsigned int v117; // r10d
  __int64 v118; // rdx
  __int64 v119; // rax
  __int64 v120; // rsi
  unsigned __int64 v121; // rcx
  __int64 v122; // r8
  unsigned __int64 v123; // rdx
  __int64 v124; // rax
  unsigned __int64 i25; // rax
  unsigned int v126; // esi
  unsigned __int8 v127; // r12
  unsigned __int64 v128; // r14
  unsigned __int64 v129; // r13
  unsigned __int64 v130; // r15
  int v131; // eax
  int *v132; // rsi
  bool v133; // zf
  __int64 v134; // rax
  __int64 v135; // rcx
  __int64 v136; // rbx
  unsigned __int16 v137; // dx
  _QWORD *v138; // rsi
  __int64 v139; // r8
  _QWORD *v140; // r9
  const char *v141; // rax
  int v142; // r10d
  __int64 v143; // r14
  unsigned __int64 v144; // rbx
  unsigned int v145; // r11d
  __int64 v146; // rax
  __int64 v147; // rbx
  unsigned __int128 v148; // rax
  unsigned int v149; // r8d
  unsigned __int64 v150; // rax
  __int64 v151; // rax
  unsigned __int64 i24; // rax
  unsigned int v153; // ebx
  __int64 v154; // rcx
  __int64 v155; // rdx
  __int64 v156; // r8
  unsigned __int8 v157; // r12
  unsigned __int64 v158; // rsi
  unsigned __int64 v159; // r13
  unsigned __int64 v160; // r14
  int v161; // eax
  __int64 v162; // rcx
  __int64 v163; // rcx
  unsigned int i23; // ebx
  __int64 v165; // rcx
  unsigned __int64 v166; // rdx
  __int64 v167; // r8
  __int64 v168; // r9
  unsigned __int64 v169; // rdx
  unsigned __int64 v170; // r8
  int v171; // eax
  unsigned __int64 v172; // rax
  unsigned __int128 v173; // rax
  void (*v174)(void); // rax
  int v175; // r14d
  __int64 v176; // rbx
  unsigned int v177; // ecx
  unsigned __int8 v178; // si
  volatile signed __int8 **v179; // r8
  volatile signed __int8 *v180; // rdx
  unsigned __int64 v181; // r14
  __int64 v182; // r12
  unsigned __int64 v183; // r13
  __int64 *v184; // rax
  __int64 v185; // r8
  __int64 v186; // r9
  __int64 *v187; // r15
  _BYTE *v188; // rbx
  char v189; // cl
  __int64 v190; // rdx
  int *v191; // rcx
  __int64 v192; // rcx
  __int64 v193; // rax
  bool v194; // zf
  int *v195; // rcx
  unsigned int v196; // eax
  void (*v197)(void); // rax
  int v198; // r13d
  __int64 v199; // rbx
  unsigned int v200; // ecx
  unsigned __int8 v201; // si
  _QWORD **v202; // r15
  _QWORD *v203; // r14
  unsigned __int64 v204; // rbx
  int *v205; // rcx
  __int64 v206; // rcx
  _QWORD **v207; // r12
  _QWORD *v208; // r14
  unsigned __int8 v209; // r15
  int v210; // r13d
  int *v211; // rsi
  unsigned __int8 v212; // r15
  __int64 v213; // rcx
  char *v214; // rbx
  _QWORD *v215; // rsi
  __int64 v216; // r8
  _QWORD *v217; // r9
  const char *v218; // rax
  unsigned int v219; // r10d
  __int64 v220; // r14
  unsigned __int64 v221; // rbx
  unsigned int v222; // r11d
  __int64 v223; // rax
  __int64 v224; // rbx
  unsigned int v225; // r8d
  unsigned __int64 v226; // rax
  __int64 v227; // rax
  unsigned __int64 i22; // rax
  unsigned int v229; // ebx
  __int64 v230; // rdx
  __int64 v231; // r8
  unsigned __int8 v232; // r12
  unsigned __int64 v233; // rsi
  unsigned __int64 v234; // r13
  int v235; // eax
  __int64 v236; // r8
  unsigned int v237; // edx
  __int64 v238; // r14
  int v239; // ecx
  __int64 v240; // rbx
  __int64 v241; // rsi
  unsigned __int64 v242; // rbx
  unsigned __int64 v243; // rsi
  int v244; // eax
  __int64 v245; // rcx
  unsigned __int8 v246; // r14
  __int64 v247; // rdx
  unsigned int *v248; // rcx
  unsigned int *v249; // rbx
  char v250; // r15
  unsigned __int64 v251; // r12
  __int64 v252; // r8
  __int64 *v253; // r9
  unsigned int *v254; // r10
  __int64 v255; // rcx
  __int64 v256; // rax
  __int64 v257; // rax
  ULONG_PTR v258; // rax
  unsigned __int64 v259; // rsi
  unsigned int *v260; // r12
  void (*v261)(void); // rax
  __int64 v262; // rbx
  unsigned int v263; // ecx
  void (__fastcall *v264)(__int64, _QWORD); // rax
  unsigned __int64 *v265; // r9
  __int64 v266; // r13
  unsigned __int64 v267; // r8
  __int64 v268; // rdx
  __int64 v269; // rax
  _QWORD **v270; // r15
  _QWORD *v271; // rsi
  unsigned int v272; // r13d
  unsigned __int8 v273; // r12
  unsigned int *v274; // r14
  char *v275; // rbx
  __int64 v276; // rcx
  unsigned int *v277; // r8
  int *v278; // rcx
  _QWORD **v279; // r10
  _QWORD *i14; // r9
  int v281; // r12d
  unsigned int *v282; // r13
  __int64 v283; // rbx
  void (*v284)(void); // rax
  unsigned int v285; // ecx
  unsigned __int8 v286; // r14
  volatile signed __int8 **v287; // r8
  volatile signed __int8 *v288; // rdx
  _QWORD **v289; // r15
  _QWORD *v290; // rsi
  __int64 v291; // rax
  int *v292; // r13
  char *v293; // rcx
  __int64 v294; // rdx
  __int64 v295; // rbx
  _QWORD **v296; // r15
  __int64 (*v297)(void); // rax
  __int64 v298; // rcx
  __int64 v299; // rdx
  unsigned int v300; // r13d
  unsigned int *v301; // rcx
  __int64 v302; // r12
  _QWORD *v303; // rax
  __int64 v304; // r8
  unsigned __int64 v305; // rax
  __int64 v306; // rcx
  int v307; // ebx
  unsigned __int64 v308; // rax
  unsigned __int128 v309; // rax
  unsigned __int64 v310; // rsi
  __int64 v311; // rax
  unsigned __int64 v312; // rdx
  unsigned __int64 v313; // r8
  __int64 v314; // r9
  __int64 v315; // r11
  int v316; // r10d
  unsigned __int64 *v317; // r9
  unsigned __int64 v318; // r8
  unsigned __int64 v319; // rax
  unsigned __int128 v320; // rax
  unsigned __int64 v321; // rax
  unsigned __int128 v322; // rax
  unsigned int v323; // ebx
  unsigned __int64 v324; // r9
  unsigned __int64 v325; // rax
  unsigned __int128 v326; // rax
  unsigned __int64 v327; // rax
  unsigned __int128 v328; // rax
  __int64 v329; // r14
  _QWORD *v330; // rbx
  __int64 v331; // rsi
  __int64 v332; // rax
  unsigned __int64 v333; // rsi
  unsigned int *v334; // r15
  unsigned __int64 v335; // rbx
  int v336; // ecx
  int *v337; // rcx
  unsigned __int64 v338; // rax
  unsigned __int128 v339; // rax
  int v340; // ecx
  int v341; // ecx
  int v342; // ecx
  char *v343; // rbx
  int i15; // r13d
  unsigned int v345; // esi
  __int64 v346; // r14
  _QWORD *v347; // rcx
  int v348; // edx
  __int64 v349; // r8
  char v350; // al
  __int64 v351; // rax
  __int64 v352; // rcx
  __int64 (__fastcall *v353)(_QWORD); // rax
  __int64 v354; // r14
  __int64 v355; // r12
  char *v356; // rbx
  int v357; // r15d
  __int64 v358; // rsi
  _QWORD *v359; // rcx
  int v360; // edx
  __int64 v361; // r8
  char v362; // al
  __int64 v363; // rax
  __int64 v364; // rax
  __int64 (__fastcall *v365)(__int64); // rax
  ULONG_PTR *v366; // rax
  ULONG_PTR v367; // r13
  int *v368; // rdx
  __int64 v369; // rax
  __int64 v370; // rax
  __int64 v371; // rax
  __int64 (__fastcall *v372)(ULONG_PTR, char *); // rax
  unsigned int *v373; // rax
  unsigned __int64 v374; // r15
  unsigned int v375; // r11d
  int v376; // r14d
  unsigned int *v377; // r12
  int v378; // ecx
  int *v379; // rax
  __int64 v380; // r8
  __int64 v381; // rdx
  unsigned int v382; // esi
  unsigned int v383; // r9d
  int v384; // r10d
  ULONG_PTR v385; // rbx
  __int64 v386; // r9
  int v387; // ecx
  int v388; // ecx
  int v389; // ecx
  int v390; // ecx
  __int64 v391; // rax
  int v392; // eax
  unsigned __int64 v393; // rcx
  __int64 v394; // r11
  int v395; // eax
  char **v396; // rbx
  int v397; // esi
  __int64 v398; // rcx
  __int64 v399; // rdx
  char *v400; // rdx
  __int64 v401; // r9
  unsigned __int64 v402; // rax
  __int64 v403; // rdx
  __int64 (__fastcall *v404)(unsigned __int64, __int64, _QWORD, int *); // rax
  __int64 v405; // rdx
  __int64 (__fastcall *v406)(unsigned __int64, __int64, __int64, int *); // rax
  __int64 v407; // rax
  __int64 v408; // rdx
  __int64 (__fastcall *v409)(unsigned __int64, __int64, __int64, int *); // rax
  __int64 (__fastcall *v410)(unsigned __int64); // rax
  __int64 v411; // rbx
  __int64 v412; // rax
  __int64 v413; // r8
  __int64 v414; // rsi
  int v415; // r9d
  unsigned int v416; // eax
  __int64 v417; // r14
  int v418; // ecx
  unsigned int v419; // eax
  __int64 v420; // r9
  _QWORD *v421; // rcx
  int v422; // r8d
  unsigned __int64 v423; // rdx
  int v424; // ebx
  __int64 v425; // r15
  __int64 *v426; // r13
  unsigned int *v427; // rdi
  __int64 v428; // r12
  __int64 v429; // rdx
  _QWORD *v430; // rsi
  int v431; // ecx
  _QWORD *v432; // rax
  _QWORD *v433; // r10
  const char *v434; // rax
  int v435; // r11d
  __int64 v436; // rbx
  unsigned __int64 v437; // r8
  unsigned int v438; // r9d
  __int64 v439; // rdx
  __int64 v440; // rax
  __int64 v441; // r8
  unsigned __int64 v442; // rcx
  unsigned int v443; // edx
  unsigned __int64 v444; // r9
  __int64 v445; // rax
  unsigned __int64 i17; // rax
  _DWORD *v447; // rbx
  ULONG_PTR v448; // r15
  int v449; // r13d
  int v450; // eax
  _BYTE *v451; // rsi
  unsigned int v452; // r9d
  _QWORD *v453; // r14
  unsigned int *v454; // r12
  int v455; // ecx
  _QWORD *v456; // rax
  __int64 v457; // rdx
  _QWORD *v458; // r10
  const char *v459; // rax
  int v460; // ebx
  __int64 v461; // r15
  unsigned __int64 v462; // rcx
  unsigned __int64 v463; // r8
  unsigned int v464; // r11d
  __int64 v465; // rdx
  unsigned __int64 v466; // rax
  __int64 v467; // r8
  unsigned __int64 v468; // rcx
  unsigned __int64 v469; // r9
  unsigned __int64 v470; // rdx
  __int64 v471; // rax
  unsigned __int64 i18; // rax
  _DWORD *v473; // rdx
  int v474; // r15d
  __int64 v475; // r14
  unsigned int v476; // eax
  _BYTE *v477; // rbx
  int v478; // ecx
  unsigned int v479; // eax
  __int64 v480; // r8
  int v481; // edx
  unsigned __int64 v482; // rcx
  int v483; // esi
  __int64 v484; // r14
  _QWORD *v485; // rax
  int v486; // ecx
  __int64 v487; // rdx
  unsigned __int64 v488; // r12
  __int64 v489; // r15
  int v490; // r11d
  __int64 v491; // rsi
  const char *v492; // rax
  unsigned int v493; // r10d
  __int64 v494; // rdx
  unsigned __int64 v495; // rax
  __int64 v496; // r8
  unsigned __int64 v497; // rcx
  unsigned int v498; // edx
  unsigned __int64 v499; // r10
  __int64 v500; // rax
  unsigned __int64 i19; // rax
  __int64 v502; // rdx
  _DWORD *v503; // rsi
  ULONG_PTR v504; // r15
  __int64 v505; // r14
  __int64 v506; // rax
  int v507; // ecx
  _QWORD *v508; // rax
  _QWORD *v509; // rax
  ULONG_PTR v510; // rsi
  __int64 v511; // rax
  __int64 v512; // r14
  unsigned int v513; // r12d
  unsigned int *v514; // r15
  unsigned int v515; // r10d
  unsigned int v516; // ecx
  __int64 v517; // rax
  _DWORD *v518; // rdx
  __int64 v519; // r9
  unsigned int v520; // r13d
  __int64 v521; // r8
  unsigned int v522; // r13d
  unsigned int v523; // eax
  __int64 v524; // rax
  unsigned int v525; // esi
  unsigned int v526; // r12d
  unsigned int v527; // esi
  unsigned int *v528; // rax
  unsigned int *v529; // r14
  ULONG_PTR v530; // r8
  unsigned int *v531; // rax
  unsigned int v532; // eax
  int v533; // r9d
  __int64 v534; // r14
  _DWORD *v535; // r13
  int v536; // ecx
  __int64 v537; // rsi
  unsigned int v538; // eax
  __int64 v539; // r11
  int v540; // ecx
  unsigned int v541; // eax
  __int64 v542; // r8
  int v543; // edx
  unsigned __int64 v544; // rcx
  int v545; // ebx
  __int64 v546; // rdx
  _QWORD *v547; // rax
  int v548; // ecx
  __int64 v549; // r8
  unsigned int *v550; // rax
  unsigned __int64 v551; // rcx
  unsigned __int64 i20; // rax
  bool v553; // cl
  _DWORD *v554; // r15
  __int64 v555; // rax
  __int64 v556; // r8
  __int64 v557; // rax
  __int64 v558; // rdx
  _DWORD *v559; // rax
  unsigned int v560; // r10d
  __int64 v561; // rcx
  int v562; // r14d
  int v563; // eax
  __int16 v564; // ax
  int v565; // r10d
  unsigned __int8 *v566; // r8
  unsigned __int8 *v567; // r9
  __int64 *v568; // r11
  unsigned __int8 *v569; // rbx
  unsigned __int8 *v570; // rsi
  __int64 v571; // rdx
  __int64 v572; // rax
  unsigned int v573; // r8d
  __int64 *v574; // r9
  __int64 v575; // rcx
  __int64 v576; // rax
  __int64 v577; // rdx
  __int64 v578; // rax
  int v579; // r9d
  unsigned __int8 *v580; // r8
  __int64 v581; // rdx
  __int64 v582; // rax
  int v583; // r9d
  unsigned __int8 *v584; // r8
  __int64 v585; // rdx
  __int64 v586; // rax
  int v587; // ecx
  unsigned int v588; // esi
  __int64 v589; // r12
  unsigned __int64 v590; // r8
  unsigned int *v591; // rdx
  unsigned int v592; // esi
  unsigned int v593; // r13d
  unsigned int v594; // eax
  unsigned int v595; // r15d
  bool v596; // cf
  _DWORD *v597; // rdx
  unsigned __int64 v598; // rbx
  __int64 *v599; // r8
  unsigned int v600; // r9d
  unsigned __int64 v601; // r11
  int *v602; // rdx
  __int64 v603; // rax
  _QWORD *v604; // r10
  int v605; // r14d
  unsigned __int64 v606; // rsi
  const char *v607; // rax
  unsigned __int64 v608; // r8
  unsigned int v609; // r11d
  __int64 v610; // rdx
  __int64 v611; // rax
  __int64 v612; // r8
  unsigned __int64 v613; // rcx
  unsigned int v614; // r9d
  unsigned __int64 v615; // rdx
  __int64 v616; // rax
  unsigned __int64 v617; // rax
  unsigned int *v618; // r15
  unsigned int v619; // r12d
  char *v620; // rax
  char v621; // r8
  __int64 v622; // rbx
  ULONG_PTR v623; // rcx
  int *v624; // rdx
  unsigned __int64 v625; // rsi
  __int64 *v626; // r8
  unsigned int v627; // r9d
  ULONG_PTR v628; // rbx
  __int64 v629; // rax
  _QWORD *v630; // r11
  int v631; // r15d
  unsigned __int64 v632; // r14
  const char *v633; // rax
  unsigned __int64 v634; // r8
  unsigned int v635; // r10d
  __int64 v636; // rdx
  __int64 v637; // rax
  __int64 v638; // r8
  unsigned __int64 v639; // rcx
  unsigned int v640; // r9d
  unsigned __int64 v641; // rdx
  __int64 v642; // rax
  unsigned __int64 i21; // rax
  unsigned int *v644; // r15
  ULONG_PTR v645; // rbx
  int *v646; // rdx
  __int64 *v647; // r8
  __int64 v648; // rax
  unsigned int v649; // r9d
  unsigned __int64 v650; // rbx
  unsigned __int64 v651; // r11
  __int64 v652; // rax
  _QWORD *v653; // r10
  int v654; // r14d
  unsigned __int64 v655; // rsi
  const char *v656; // rax
  unsigned __int64 v657; // r8
  unsigned int v658; // r11d
  __int64 v659; // rdx
  __int64 v660; // rax
  __int64 v661; // r8
  unsigned __int64 v662; // rcx
  unsigned int v663; // r9d
  unsigned __int64 v664; // rdx
  __int64 v665; // rax
  unsigned __int64 v666; // rax
  unsigned int *v667; // r9
  __int64 v668; // r8
  char *v669; // rax
  _BYTE *v670; // rax
  char *v671; // rdx
  char *v672; // rbx
  __int64 v673; // r12
  __int64 v674; // rdx
  __int64 v675; // r8
  __int64 v676; // rsi
  __int64 v677; // r14
  __int64 v678; // r8
  int v679; // edx
  __int64 v680; // r8
  char v681; // al
  __int64 v682; // rax
  __int64 v683; // rax
  char *v684; // rbx
  unsigned __int8 v685; // r14
  __int64 i16; // rsi
  _QWORD *v687; // rcx
  int v688; // edx
  __int64 v689; // r8
  char v690; // al
  __int64 v691; // rax
  __int64 v692; // rax
  char *v693; // rbx
  _QWORD *v694; // rcx
  int v695; // edx
  __int64 v696; // r8
  char v697; // al
  __int64 v698; // rax
  __int64 v699; // rax
  __int64 v700; // rsi
  int v701; // eax
  int v702; // ebx
  unsigned __int64 v703; // rbx
  char *v704; // rcx
  __int64 v705; // rdx
  unsigned __int64 v706; // r8
  __int64 v707; // rax
  __int64 v708; // r14
  __int64 v709; // rsi
  unsigned __int64 v710; // rax
  __int64 v711; // rcx
  unsigned __int64 v712; // rbx
  unsigned __int64 v713; // rcx
  _QWORD *v714; // rsi
  __int64 v715; // r8
  _QWORD *v716; // r9
  const char *v717; // rax
  unsigned int v718; // r11d
  __int64 v719; // r14
  unsigned __int64 v720; // rbx
  unsigned int v721; // r10d
  __int64 v722; // rdx
  __int64 v723; // rax
  __int64 v724; // rbx
  unsigned int v725; // r8d
  unsigned __int64 v726; // rdx
  __int64 v727; // rax
  unsigned __int64 i13; // rax
  unsigned int v729; // ebx
  __int64 v730; // rdx
  __int64 v731; // r8
  unsigned __int8 v732; // r15
  unsigned __int64 v733; // rsi
  __int64 v734; // r13
  unsigned __int64 v735; // r12
  unsigned __int64 v736; // r14
  int v737; // eax
  __int64 v738; // r8
  unsigned int v739; // r8d
  __int64 *v740; // r9
  unsigned __int64 *v741; // r10
  __int64 v742; // rax
  __int64 v743; // rdx
  __int64 v744; // rax
  __int64 v745; // rdx
  __int64 v746; // r8
  unsigned __int8 v747; // r14
  unsigned __int64 v748; // rbx
  __int64 v749; // r12
  unsigned __int64 v750; // r15
  unsigned __int64 v751; // rsi
  int v752; // eax
  __int64 v753; // r8
  __int16 v754; // ax
  __int64 v755; // rcx
  int (__fastcall *v756)(__int16 *, _QWORD, _QWORD, _QWORD, __int64, _DWORD, _QWORD, __int64 *); // rax
  __int64 v757; // rcx
  __int64 (*v758)(void); // rax
  __int64 v759; // rax
  __int64 (*v760)(void); // rax
  __int64 v761; // rax
  unsigned int v762; // r10d
  unsigned __int8 v763; // dl
  __int64 v764; // r15
  unsigned __int64 v765; // r9
  _QWORD *v766; // rsi
  __int64 v767; // r9
  _QWORD *v768; // r10
  const char *v769; // rax
  int v770; // ebx
  __int64 v771; // r14
  unsigned __int64 v772; // r8
  unsigned int v773; // r11d
  __int64 v774; // rdx
  __int64 v775; // rax
  __int64 v776; // r8
  unsigned __int64 v777; // rcx
  unsigned int v778; // r9d
  unsigned __int64 v779; // rdx
  unsigned __int8 v780; // dl
  __int64 v781; // rax
  unsigned __int64 i11; // rax
  unsigned int v783; // r10d
  unsigned int *v784; // rsi
  unsigned int v785; // r9d
  unsigned int *v786; // r9
  unsigned int v787; // ebx
  const char *v788; // rax
  __int64 v789; // r14
  unsigned __int64 v790; // r8
  unsigned int v791; // r11d
  __int64 v792; // rdx
  __int64 v793; // rax
  __int64 v794; // r8
  unsigned int v795; // r10d
  unsigned __int64 v796; // rdx
  __int64 v797; // rax
  unsigned __int64 i12; // rax
  __int64 v799; // rax
  _QWORD *v800; // rcx
  int v801; // edx
  __int64 v802; // r8
  char v803; // al
  __int64 v804; // rax
  _QWORD *v805; // rsi
  _QWORD *v806; // r9
  int v807; // r11d
  const char *v808; // rax
  __int64 v809; // r14
  unsigned __int64 v810; // rbx
  unsigned int v811; // r10d
  __int64 v812; // rdx
  __int64 v813; // rax
  __int64 v814; // rbx
  unsigned __int64 v815; // rcx
  unsigned int v816; // r8d
  unsigned __int64 v817; // rdx
  __int64 v818; // rax
  unsigned __int64 i9; // rax
  unsigned int v820; // ebx
  __int64 v821; // rcx
  __int64 v822; // rdx
  __int64 v823; // r8
  unsigned __int8 v824; // r12
  unsigned __int64 v825; // rsi
  unsigned __int64 v826; // r13
  unsigned __int64 v827; // r14
  int v828; // eax
  unsigned int v829; // r9d
  unsigned int *v830; // r10
  unsigned int v831; // r11d
  const char *v832; // rax
  __int64 v833; // r14
  unsigned __int64 v834; // r8
  unsigned int v835; // ebx
  __int64 v836; // rdx
  __int64 v837; // rax
  __int64 v838; // r8
  unsigned int v839; // r9d
  unsigned __int64 v840; // rdx
  __int64 v841; // rax
  unsigned __int64 i10; // rax
  __int64 v843; // rcx
  __int64 v844; // rax
  unsigned int v845; // r8d
  const char *v846; // rsi
  __int64 v847; // r8
  __int64 v848; // r9
  const char *v849; // rax
  int v850; // r10d
  __int64 m; // r14
  unsigned __int64 v852; // rbx
  unsigned int v853; // r11d
  __int64 v854; // rax
  __int64 v855; // rbx
  unsigned __int128 v856; // rax
  char v857; // r10
  __int64 v858; // rdx
  __int64 v859; // r8
  unsigned __int64 v860; // rax
  __int64 v861; // rax
  unsigned __int64 n; // rax
  unsigned int v863; // ebx
  __int64 v864; // rcx
  unsigned __int8 v865; // r12
  unsigned __int64 v866; // rsi
  unsigned __int64 v867; // r13
  unsigned __int64 v868; // r14
  int v869; // eax
  __int64 v870; // rcx
  __int64 v871; // rcx
  unsigned __int8 v872; // r14
  __int64 v873; // rdx
  unsigned int *v874; // rcx
  unsigned int *v875; // rbx
  char v876; // r15
  unsigned __int64 v877; // r12
  __int64 v878; // r8
  __int64 *v879; // r9
  unsigned int *v880; // r10
  __int64 v881; // rcx
  __int64 v882; // rax
  __int64 v883; // rax
  __int64 v884; // rcx
  unsigned __int8 v885; // r14
  unsigned int *v886; // rcx
  unsigned __int64 v887; // rax
  unsigned __int64 v888; // rsi
  unsigned __int64 v889; // rcx
  unsigned __int64 v890; // rdx
  unsigned int v891; // eax
  int v892; // r8d
  int v893; // edx
  unsigned __int64 v894; // rbx
  unsigned __int64 v895; // rsi
  int *v896; // rsi
  int v897; // eax
  __int64 v898; // rbx
  __int64 v899; // rdx
  __int64 v900; // rax
  _QWORD *v901; // rsi
  __int64 v902; // r8
  _QWORD *v903; // r9
  const char *v904; // rax
  int v905; // r10d
  __int64 v906; // r14
  unsigned __int64 v907; // rbx
  unsigned int v908; // r11d
  __int64 v909; // rdx
  __int64 v910; // rax
  __int64 v911; // rbx
  unsigned __int64 v912; // rcx
  unsigned int v913; // r8d
  unsigned __int64 v914; // rdx
  __int64 v915; // rax
  unsigned __int64 mm; // rax
  unsigned int v917; // edx
  unsigned int v918; // ebx
  __int64 v919; // rcx
  __int64 v920; // r8
  unsigned __int8 v921; // r15
  unsigned __int64 v922; // rsi
  __int64 v923; // r13
  unsigned __int64 v924; // r12
  unsigned __int64 v925; // r14
  int v926; // eax
  __int64 v927; // rax
  __int64 v928; // rcx
  _QWORD *v929; // rsi
  __int64 v930; // r8
  _QWORD *v931; // r9
  const char *v932; // rax
  int v933; // r10d
  __int64 v934; // r14
  unsigned __int64 v935; // rbx
  unsigned int v936; // r11d
  __int64 v937; // rax
  __int64 v938; // rbx
  unsigned __int128 v939; // rax
  unsigned int v940; // r8d
  unsigned __int64 v941; // rax
  __int64 v942; // rax
  unsigned __int64 nn; // rax
  __int64 v944; // rcx
  __int64 v945; // rdx
  __int64 v946; // r8
  unsigned __int8 v947; // r12
  unsigned __int64 v948; // rsi
  unsigned __int64 v949; // r13
  int v950; // eax
  __int64 v951; // rdx
  __int64 v952; // rax
  int v953; // eax
  __int64 v954; // rbx
  __int64 (__fastcall *v955)(_QWORD); // rax
  unsigned int v956; // r12d
  __int64 v957; // rax
  __int64 v958; // r14
  char *v959; // rsi
  unsigned __int64 v960; // rbx
  char v961; // r13
  int *v962; // r12
  __int64 v963; // r12
  unsigned __int64 v964; // rbx
  int *v965; // r15
  unsigned __int64 *v966; // rax
  unsigned __int64 *v967; // rbx
  unsigned __int64 v968; // rcx
  unsigned __int64 v969; // r12
  unsigned __int8 v970; // r12
  __int64 v971; // r13
  __int64 v972; // rdx
  unsigned __int64 v973; // r15
  unsigned __int64 v974; // rcx
  _QWORD *v975; // rcx
  int v976; // edx
  __int64 v977; // r8
  char v978; // al
  char *v979; // rsi
  unsigned __int64 v980; // rbx
  char v981; // r13
  int *v982; // r12
  __int64 v983; // r12
  unsigned __int64 v984; // rbx
  char v985; // al
  int *v986; // r15
  unsigned __int64 *v987; // rax
  unsigned __int64 *v988; // rbx
  unsigned __int64 v989; // rcx
  unsigned __int8 v990; // r12
  __int64 v991; // r13
  __int64 v992; // rdx
  unsigned __int64 v993; // r15
  unsigned __int64 v994; // rcx
  _QWORD *v995; // rcx
  int v996; // edx
  __int64 v997; // r8
  char v998; // al
  __int64 (__fastcall *v999)(__int64); // rax
  __int64 v1000; // r15
  unsigned __int64 v1001; // rbx
  unsigned int v1002; // r13d
  __int64 v1003; // rax
  __int64 v1004; // rdx
  __int64 v1005; // r8
  int *v1006; // r14
  char v1007; // si
  char v1008; // r12
  __int64 v1009; // r14
  unsigned __int64 v1010; // rbx
  char v1011; // al
  int *v1012; // rsi
  unsigned __int64 *v1013; // rax
  unsigned __int64 *v1014; // rbx
  unsigned __int64 v1015; // rcx
  __int64 v1016; // r14
  __int64 v1017; // r12
  char *v1018; // r14
  __int64 v1019; // rdx
  unsigned __int64 v1020; // rsi
  unsigned __int64 v1021; // rcx
  _QWORD *v1022; // rcx
  int v1023; // edx
  __int64 v1024; // r8
  char v1025; // al
  __int64 v1026; // r8
  unsigned __int64 v1027; // rcx
  __int64 v1028; // r9
  unsigned int *v1029; // rbx
  unsigned __int64 v1030; // r10
  char *v1031; // r14
  unsigned int v1032; // r11d
  unsigned __int64 v1033; // rdx
  unsigned int v1034; // eax
  __int64 v1035; // r12
  __int64 v1036; // r9
  _QWORD *v1037; // r10
  int v1038; // ebx
  const char *v1039; // rax
  unsigned __int64 v1040; // rsi
  __int64 v1041; // r15
  unsigned __int64 v1042; // r8
  unsigned int v1043; // r11d
  __int64 v1044; // rdx
  __int64 v1045; // rax
  __int64 v1046; // r8
  unsigned __int64 v1047; // rcx
  unsigned int v1048; // r9d
  unsigned __int64 v1049; // rdx
  __int64 v1050; // rax
  unsigned __int64 j; // rax
  unsigned int v1052; // r13d
  unsigned __int8 v1053; // r14
  unsigned __int64 v1054; // rbx
  __int64 v1055; // r12
  unsigned __int64 v1056; // r15
  unsigned __int64 v1057; // rsi
  int v1058; // eax
  __int64 v1059; // rcx
  unsigned __int64 v1060; // rax
  __int64 v1061; // rcx
  unsigned int *v1062; // rdx
  __int64 v1063; // r15
  unsigned __int64 v1064; // r14
  __int64 v1065; // r8
  _QWORD *v1066; // r9
  int v1067; // r10d
  const char *v1068; // rax
  unsigned __int64 v1069; // rsi
  __int64 v1070; // r12
  unsigned __int64 v1071; // rbx
  unsigned int v1072; // r11d
  __int64 v1073; // rax
  __int64 v1074; // rbx
  unsigned __int128 v1075; // rax
  unsigned int v1076; // r8d
  unsigned __int64 v1077; // rax
  __int64 v1078; // rax
  unsigned __int64 k; // rax
  unsigned int v1080; // ecx
  unsigned int v1081; // ebx
  __int64 v1082; // r8
  unsigned __int8 v1083; // r15
  unsigned __int64 v1084; // rsi
  __int64 v1085; // r13
  unsigned __int64 v1086; // r12
  unsigned __int64 v1087; // r14
  int v1088; // eax
  unsigned int *v1089; // rcx
  __int64 v1090; // rax
  _QWORD *v1091; // rsi
  __int64 v1092; // r8
  _QWORD *v1093; // r9
  const char *v1094; // rax
  unsigned int v1095; // r10d
  __int64 v1096; // r14
  unsigned __int64 v1097; // rbx
  unsigned int v1098; // r11d
  __int64 v1099; // rax
  __int64 v1100; // rbx
  __int64 v1101; // r8
  unsigned __int64 v1102; // rax
  __int64 v1103; // rax
  unsigned __int64 i; // rax
  unsigned int v1105; // ebx
  __int64 v1106; // rdx
  unsigned __int8 v1107; // r12
  unsigned __int64 v1108; // rsi
  unsigned __int64 v1109; // r13
  unsigned __int64 v1110; // r14
  int v1111; // eax
  int v1112; // r12d
  __int64 **v1113; // r15
  unsigned int v1114; // eax
  unsigned __int64 v1115; // r13
  char *v1116; // rbx
  __int64 v1117; // r14
  __int64 v1118; // rsi
  _QWORD *v1119; // rcx
  int v1120; // edx
  __int64 v1121; // r8
  char v1122; // al
  __int64 v1123; // rax
  __int64 v1124; // rax
  _QWORD *v1125; // rsi
  __int64 v1126; // r8
  _QWORD *v1127; // r9
  const char *v1128; // rax
  unsigned int v1129; // r10d
  __int64 v1130; // r14
  unsigned __int64 v1131; // rbx
  unsigned int v1132; // r11d
  __int64 v1133; // rax
  __int64 v1134; // rbx
  unsigned int v1135; // r8d
  unsigned __int64 v1136; // rax
  __int64 v1137; // rax
  unsigned __int64 i2; // rax
  unsigned int v1139; // ebx
  __int64 v1140; // rdx
  __int64 v1141; // r8
  unsigned __int8 v1142; // r12
  unsigned __int64 v1143; // rsi
  unsigned __int64 v1144; // r13
  unsigned __int64 v1145; // r14
  int v1146; // eax
  __int64 v1147; // rax
  __int64 v1148; // rcx
  unsigned int v1149; // edx
  unsigned __int64 v1150; // rbx
  unsigned __int64 v1151; // rsi
  _QWORD *v1152; // rsi
  __int64 v1153; // r8
  _QWORD *v1154; // r9
  const char *v1155; // rax
  unsigned int v1156; // r10d
  __int64 v1157; // r14
  unsigned __int64 v1158; // rbx
  unsigned int v1159; // r11d
  __int64 v1160; // rax
  __int64 v1161; // rbx
  unsigned int v1162; // r8d
  unsigned __int64 v1163; // rax
  __int64 v1164; // rax
  unsigned __int64 i3; // rax
  unsigned int v1166; // edx
  unsigned int v1167; // ebx
  __int64 v1168; // r8
  unsigned __int8 v1169; // r15
  unsigned __int64 v1170; // rsi
  __int64 v1171; // r13
  unsigned __int64 v1172; // r12
  int v1173; // eax
  __int64 v1174; // rsi
  __int64 v1175; // rcx
  int v1176; // eax
  __int64 v1177; // rcx
  unsigned int v1178; // ebx
  bool i1; // zf
  _QWORD *v1180; // rcx
  int v1181; // edx
  __int64 v1182; // r8
  char v1183; // al
  int v1184; // esi
  __int64 v1185; // r14
  unsigned int v1186; // ecx
  char v1187; // bl
  volatile signed __int8 **v1188; // r8
  volatile signed __int8 *v1189; // rdx
  unsigned __int8 v1190; // bl
  unsigned int v1191; // eax
  int v1192; // r8d
  int v1193; // edx
  unsigned __int64 v1194; // rbx
  unsigned __int64 v1195; // rsi
  _QWORD *v1196; // rsi
  __int64 v1197; // r8
  _QWORD *v1198; // r9
  const char *v1199; // rax
  int v1200; // r11d
  __int64 v1201; // r14
  unsigned __int64 v1202; // rbx
  unsigned int v1203; // r10d
  __int64 v1204; // rdx
  __int64 v1205; // rax
  __int64 v1206; // rbx
  unsigned __int64 v1207; // rcx
  unsigned int v1208; // r8d
  unsigned __int64 v1209; // rdx
  __int64 v1210; // rax
  unsigned __int64 i4; // rax
  unsigned int v1212; // edx
  unsigned int v1213; // ebx
  __int64 v1214; // rcx
  __int64 v1215; // r8
  unsigned __int8 v1216; // r15
  unsigned __int64 v1217; // rsi
  __int64 v1218; // r13
  unsigned __int64 v1219; // r12
  unsigned __int64 v1220; // r14
  int v1221; // eax
  __int64 v1222; // r13
  __int64 v1223; // rax
  _DWORD *v1224; // r14
  unsigned int v1225; // r15d
  int v1226; // esi
  __int64 v1227; // rcx
  _QWORD *v1228; // rsi
  __int64 v1229; // r8
  _QWORD *v1230; // r9
  const char *v1231; // rax
  int v1232; // r11d
  __int64 v1233; // r14
  unsigned __int64 v1234; // rbx
  unsigned int v1235; // r10d
  __int64 v1236; // rdx
  __int64 v1237; // rax
  __int64 v1238; // rbx
  unsigned __int64 v1239; // rcx
  unsigned int v1240; // r8d
  unsigned __int64 v1241; // rdx
  __int64 v1242; // rax
  unsigned __int64 i5; // rax
  unsigned int v1244; // ebx
  __int64 v1245; // rcx
  __int64 v1246; // rdx
  __int64 v1247; // r8
  unsigned __int8 v1248; // r12
  unsigned __int64 v1249; // rsi
  unsigned __int64 v1250; // r13
  int v1251; // eax
  unsigned int v1252; // eax
  unsigned int v1253; // r11d
  unsigned int v1254; // r12d
  int v1255; // eax
  __int64 v1256; // r8
  __int16 v1257; // ax
  char *v1258; // r8
  int v1259; // r10d
  unsigned __int8 *v1260; // r9
  __int64 v1261; // rdx
  __int64 v1262; // rax
  __int64 *v1263; // r9
  unsigned int v1264; // r8d
  unsigned __int64 *v1265; // r10
  __int64 v1266; // rax
  __int64 v1267; // rdx
  __int64 v1268; // rax
  unsigned __int8 *v1269; // r8
  int v1270; // r10d
  unsigned __int8 *v1271; // r9
  __int64 v1272; // rdx
  __int64 v1273; // rax
  unsigned __int8 *v1274; // r8
  int v1275; // r10d
  unsigned __int8 *v1276; // r9
  __int64 v1277; // rdx
  __int64 v1278; // rax
  int v1279; // eax
  __int64 v1280; // rbx
  int v1281; // eax
  __int64 v1282; // r9
  int v1283; // eax
  ULONG_PTR v1284; // rcx
  unsigned __int8 v1285; // bl
  __int64 v1286; // rdx
  int v1287; // eax
  unsigned __int64 v1288; // rbx
  unsigned __int64 v1289; // rsi
  _QWORD *v1290; // r11
  __int64 v1291; // r8
  _QWORD *v1292; // r9
  const char *v1293; // rax
  int v1294; // esi
  __int64 v1295; // r14
  unsigned __int64 v1296; // rbx
  unsigned int v1297; // r10d
  __int64 v1298; // rdx
  __int64 v1299; // rax
  __int64 v1300; // rbx
  unsigned __int64 v1301; // rcx
  unsigned int v1302; // r8d
  unsigned __int64 v1303; // rdx
  __int64 v1304; // rax
  unsigned __int64 i6; // rax
  unsigned int v1306; // edx
  unsigned int v1307; // ebx
  __int64 v1308; // rcx
  __int64 v1309; // r8
  unsigned __int8 v1310; // r15
  unsigned __int64 v1311; // rsi
  __int64 v1312; // r13
  unsigned __int64 v1313; // r12
  unsigned __int64 v1314; // r14
  int v1315; // eax
  unsigned __int64 v1316; // rcx
  _QWORD *v1317; // rsi
  __int64 v1318; // r8
  _QWORD *v1319; // r9
  const char *v1320; // rax
  int v1321; // r11d
  __int64 v1322; // r14
  unsigned __int64 v1323; // rbx
  unsigned int v1324; // r10d
  __int64 v1325; // rdx
  __int64 v1326; // rax
  __int64 v1327; // rbx
  unsigned __int64 v1328; // rcx
  unsigned int v1329; // r8d
  unsigned __int64 v1330; // rdx
  __int64 v1331; // rax
  unsigned __int64 i7; // rax
  __int64 v1333; // rcx
  __int64 v1334; // rdx
  __int64 v1335; // r8
  unsigned __int8 v1336; // r12
  unsigned __int64 v1337; // rsi
  unsigned __int64 v1338; // r13
  int v1339; // eax
  __int64 v1340; // rcx
  int *v1341; // r13
  __int64 v1342; // r8
  int *v1343; // r12
  unsigned int *v1344; // rbx
  unsigned __int64 v1345; // rsi
  __int64 v1346; // rdx
  unsigned __int64 v1347; // r15
  unsigned int v1348; // r14d
  _QWORD *v1349; // r8
  int v1350; // r10d
  const char *v1351; // rax
  __int64 v1352; // r11
  unsigned __int64 v1353; // rcx
  unsigned __int64 v1354; // r13
  unsigned int v1355; // r9d
  __int64 v1356; // rdx
  __int64 v1357; // rax
  __int64 v1358; // r13
  unsigned __int64 v1359; // rcx
  unsigned int v1360; // edx
  unsigned __int64 v1361; // r9
  __int64 v1362; // rax
  unsigned __int64 i8; // rax
  unsigned int v1364; // r13d
  unsigned int v1365; // eax
  _BYTE *v1366; // rsi
  char *v1367; // rbx
  char v1368; // cl
  volatile signed __int32 *v1369; // rcx
  struct _KPRCB *v1370; // rdx
  __int64 v1371; // r8
  int v1372; // ecx
  struct _KPRCB *v1373; // rax
  unsigned __int64 v1374; // rcx
  BOOL v1375; // r9d
  int *v1376; // rcx
  __int64 v1377; // rdx
  unsigned __int8 v1378; // r14
  unsigned __int64 v1379; // rbx
  __int64 v1380; // r12
  unsigned __int64 v1381; // r15
  unsigned __int64 v1382; // rsi
  int v1383; // eax
  bool v1384; // zf
  __int64 v1385; // rax
  __int64 v1386; // rcx
  __int64 v1387; // rcx
  unsigned __int8 v1388; // r14
  __int64 v1389; // rdx
  unsigned int *v1390; // rcx
  unsigned int *v1391; // rbx
  char v1392; // r15
  unsigned __int64 v1393; // r12
  __int64 v1394; // r8
  __int64 *v1395; // r9
  unsigned int *v1396; // r10
  __int64 v1397; // rcx
  __int64 v1398; // rax
  __int64 v1399; // rax
  __int64 v1400; // r9
  _QWORD *v1401; // rbx
  int v1402; // r11d
  _QWORD *v1403; // r10
  __int64 v1404; // r14
  const char *v1405; // rax
  __int64 v1406; // r8
  unsigned int v1407; // esi
  __int64 v1408; // rax
  __int64 v1409; // r8
  unsigned __int128 v1410; // rax
  unsigned int v1411; // r9d
  unsigned __int64 v1412; // rax
  __int64 v1413; // rax
  int v1414; // eax
  int v1415; // r10d
  int v1416; // r10d
  __int64 v1417; // rbx
  unsigned int v1418; // ebx
  __int64 v1419; // rax
  unsigned int v1420; // esi
  unsigned __int64 v1421; // rax
  __int64 v1422; // rdx
  int v1423; // ecx
  _QWORD *v1424; // rax
  __int64 v1425; // r8
  struct _KPRCB *CurrentPrcb; // rdx
  unsigned __int64 v1427; // rcx
  unsigned __int64 v1428; // rdx
  unsigned __int64 v1429; // rdx
  __int64 v1430; // r14
  __int64 v1431; // rsi
  __int64 v1432; // rdx
  __int64 v1433; // r8
  int v1434; // ecx
  _QWORD *v1435; // rax
  unsigned __int64 v1436; // rcx
  __int64 Ldtr; // r15
  unsigned __int16 Tr; // ax
  unsigned __int64 v1439; // rdx
  __int64 v1440; // r9
  unsigned __int16 v1441; // r12
  __int64 v1442; // r11
  _QWORD *v1443; // r8
  const char *v1444; // rcx
  unsigned __int64 v1445; // rbx
  unsigned int v1446; // r10d
  __int64 v1447; // rdx
  __int64 v1448; // rax
  __int64 v1449; // rbx
  unsigned __int64 v1450; // rcx
  unsigned int v1451; // esi
  __int64 v1452; // rax
  unsigned __int64 ii; // rax
  unsigned int v1454; // ebx
  _QWORD *v1455; // rcx
  int v1456; // edx
  __int64 v1457; // r8
  char v1458; // al
  int v1459; // eax
  __int64 v1460; // rdx
  void (__fastcall *v1461)(char *, __int64); // rax
  unsigned int v1462; // r10d
  __int16 *v1463; // rcx
  _DWORD *v1464; // r8
  __int64 v1465; // rsi
  unsigned __int64 v1466; // r13
  __int64 v1467; // r12
  __int64 v1468; // r15
  unsigned __int8 v1469; // r14
  __int16 v1470; // r9
  int v1471; // eax
  __int64 v1472; // rcx
  unsigned __int64 v1473; // rbx
  __int64 v1474; // rdx
  _DWORD *v1475; // r15
  __int64 v1476; // rax
  __int64 v1477; // rax
  unsigned __int64 v1478; // r12
  __int64 v1479; // rax
  unsigned int *v1480; // rax
  __int64 v1481; // rcx
  unsigned __int64 v1482; // rbx
  unsigned __int64 v1483; // rdx
  struct _KPRCB *v1484; // r8
  __int64 v1485; // r14
  _QWORD *v1486; // r8
  int v1487; // ebx
  const char *v1488; // rax
  int v1489; // r10d
  __int64 v1490; // r11
  int v1491; // r9d
  unsigned __int64 v1492; // rsi
  __int64 v1493; // rdx
  __int64 v1494; // rax
  __int64 *v1495; // r8
  __int64 v1496; // rsi
  unsigned __int64 v1497; // rcx
  int v1498; // r15d
  int v1499; // edx
  __int64 v1500; // r9
  __int64 v1501; // rax
  unsigned __int64 jj; // rax
  unsigned int *v1503; // rax
  __int64 v1504; // rax
  unsigned int v1505; // esi
  _QWORD *v1506; // rdx
  int v1507; // r9d
  unsigned __int64 v1508; // rbx
  const char *v1509; // rax
  __int64 v1510; // rax
  int v1511; // r8d
  __int64 v1512; // rax
  unsigned __int64 kk; // rax
  unsigned int v1514; // ebx
  int *v1515; // r8
  __int64 v1516; // rdx
  unsigned __int64 v1517; // rcx
  __int64 v1518; // rax
  __int64 v1519; // rdx
  int v1520; // eax
  __int64 v1521; // rbx
  __int64 v1522; // rbx
  int v1523; // eax
  __int64 v1524; // r12
  unsigned __int64 v1525; // r13
  __int64 v1526; // rbx
  __int64 v1527; // rsi
  struct _KPRCB *v1528; // rdx
  unsigned __int64 v1529; // r11
  unsigned __int64 v1530; // rdi
  __int64 v1531; // r14
  unsigned __int64 v1532; // r15
  __int64 v1533; // r10
  unsigned int v1534; // r8d
  PSLIST_ENTRY v1535; // r9
  unsigned __int64 v1536; // rsi
  _QWORD *v1537; // rdx
  unsigned __int64 v1538; // rcx
  unsigned __int64 v1539; // rax
  __int64 v1540; // rbx
  _QWORD *v1541; // rcx
  char *Next; // r8
  int v1543; // r10d
  signed __int64 v1544; // r8
  unsigned int v1545; // ebx
  unsigned int v1546; // ebx
  __int64 v1547; // rdx
  __int64 v1548; // rcx
  __int64 v1549; // r8
  __int64 v1550; // r9
  unsigned __int8 CurrentIrql; // al
  unsigned int v1552; // ebx
  __int64 v1553; // rdx
  __int64 v1554; // rcx
  __int64 v1555; // r8
  __int64 v1556; // r9
  unsigned __int8 v1557; // al
  unsigned int v1558; // ebx
  __int64 v1559; // rdx
  __int64 v1560; // rcx
  __int64 v1561; // r8
  __int64 v1562; // r9
  unsigned __int8 v1563; // al
  int v1564; // ecx
  int v1565; // ecx
  int v1566; // ecx
  int v1567; // ecx
  int v1568; // ecx
  volatile signed __int32 *v1569; // rax
  unsigned int v1570; // ebx
  __int64 v1571; // rdx
  __int64 v1572; // rcx
  __int64 v1573; // r8
  __int64 v1574; // r9
  unsigned __int8 v1575; // al
  signed __int32 v1576[8]; // [rsp+0h] [rbp-100h] BYREF
  __int64 v1577; // [rsp+28h] [rbp-D8h]
  __int64 *v1578; // [rsp+38h] [rbp-C8h]
  int *v1579; // [rsp+50h] [rbp-B0h]
  _BYTE *v1580; // [rsp+58h] [rbp-A8h]
  unsigned int v1581; // [rsp+60h] [rbp-A0h]
  unsigned __int64 v1582; // [rsp+68h] [rbp-98h]
  __int64 v1583; // [rsp+70h] [rbp-90h]
  ULONG_PTR BugCheckParameter2; // [rsp+78h] [rbp-88h]
  unsigned __int64 v1585; // [rsp+80h] [rbp-80h]
  int v1586; // [rsp+88h] [rbp-78h]
  unsigned int *v1587; // [rsp+90h] [rbp-70h]
  unsigned int *v1588; // [rsp+98h] [rbp-68h]
  unsigned __int8 v1589; // [rsp+A0h] [rbp-60h] BYREF
  unsigned __int8 v1590; // [rsp+A1h] [rbp-5Fh] BYREF
  char v1591[2]; // [rsp+A2h] [rbp-5Eh] BYREF
  int v1592; // [rsp+A4h] [rbp-5Ch]
  unsigned __int64 v1593; // [rsp+A8h] [rbp-58h]
  int v1594; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v1595; // [rsp+B8h] [rbp-48h]
  _BYTE *v1596; // [rsp+C0h] [rbp-40h]
  __int64 v1597; // [rsp+C8h] [rbp-38h]
  int v1598; // [rsp+D0h] [rbp-30h]
  int v1599; // [rsp+D4h] [rbp-2Ch]
  char *v1600; // [rsp+D8h] [rbp-28h]
  __int64 v1601; // [rsp+E0h] [rbp-20h] BYREF
  PSLIST_ENTRY v1602; // [rsp+E8h] [rbp-18h]
  unsigned int v1603; // [rsp+F0h] [rbp-10h]
  _BYTE *v1604; // [rsp+F8h] [rbp-8h] BYREF
  _DWORD *v1605; // [rsp+100h] [rbp+0h]
  unsigned int v1606; // [rsp+108h] [rbp+8h]
  _BYTE *v1607; // [rsp+110h] [rbp+10h] BYREF
  __int64 v1608; // [rsp+118h] [rbp+18h]
  __int64 v1609; // [rsp+120h] [rbp+20h] BYREF
  unsigned int v1610; // [rsp+128h] [rbp+28h] BYREF
  unsigned int v1611; // [rsp+12Ch] [rbp+2Ch] BYREF
  __int64 v1612; // [rsp+130h] [rbp+30h]
  unsigned int v1613; // [rsp+138h] [rbp+38h] BYREF
  int v1614; // [rsp+140h] [rbp+40h]
  unsigned __int64 v1615; // [rsp+148h] [rbp+48h]
  unsigned __int64 v1616; // [rsp+150h] [rbp+50h] BYREF
  __int64 v1617; // [rsp+158h] [rbp+58h]
  int v1618; // [rsp+160h] [rbp+60h] BYREF
  __int64 v1619; // [rsp+168h] [rbp+68h]
  int v1620; // [rsp+170h] [rbp+70h] BYREF
  __int64 v1621; // [rsp+178h] [rbp+78h] BYREF
  _DWORD *v1622; // [rsp+180h] [rbp+80h]
  unsigned __int64 v1623; // [rsp+188h] [rbp+88h]
  __int64 v1624; // [rsp+190h] [rbp+90h]
  unsigned __int64 v1625; // [rsp+198h] [rbp+98h]
  int v1626; // [rsp+1A0h] [rbp+A0h]
  int v1627; // [rsp+1A4h] [rbp+A4h]
  int v1628; // [rsp+1A8h] [rbp+A8h]
  int v1629; // [rsp+1ACh] [rbp+ACh]
  int v1630; // [rsp+1B0h] [rbp+B0h]
  int v1631; // [rsp+1B4h] [rbp+B4h]
  int v1632; // [rsp+1B8h] [rbp+B8h]
  int v1633; // [rsp+1BCh] [rbp+BCh]
  int v1634; // [rsp+1C0h] [rbp+C0h]
  int v1635; // [rsp+1C4h] [rbp+C4h]
  int v1636; // [rsp+1C8h] [rbp+C8h]
  int v1637; // [rsp+1CCh] [rbp+CCh]
  int v1638; // [rsp+1D0h] [rbp+D0h]
  int v1639; // [rsp+1D4h] [rbp+D4h]
  int v1640; // [rsp+1D8h] [rbp+D8h]
  int v1641; // [rsp+1DCh] [rbp+DCh]
  int v1642; // [rsp+1E0h] [rbp+E0h]
  __int64 v1643; // [rsp+1E8h] [rbp+E8h]
  __int64 v1644; // [rsp+1F0h] [rbp+F0h] BYREF
  int v1645; // [rsp+1F8h] [rbp+F8h]
  int v1646; // [rsp+1FCh] [rbp+FCh]
  int v1647; // [rsp+200h] [rbp+100h] BYREF
  int v1648[6]; // [rsp+208h] [rbp+108h] BYREF
  __int16 v1649; // [rsp+220h] [rbp+120h] BYREF
  __int64 v1650; // [rsp+222h] [rbp+122h]
  __int64 v1651; // [rsp+230h] [rbp+130h]
  __int64 v1652; // [rsp+238h] [rbp+138h] BYREF
  __int64 v1653; // [rsp+240h] [rbp+140h] BYREF
  __int64 v1654; // [rsp+248h] [rbp+148h] BYREF
  char v1655; // [rsp+250h] [rbp+150h] BYREF
  __int64 v1656; // [rsp+258h] [rbp+158h] BYREF
  __int64 v1657; // [rsp+260h] [rbp+160h]
  __int64 v1658; // [rsp+268h] [rbp+168h]
  __int64 v1659; // [rsp+270h] [rbp+170h] BYREF
  __int64 v1660; // [rsp+278h] [rbp+178h] BYREF
  __int128 v1661; // [rsp+280h] [rbp+180h]
  __int128 v1662; // [rsp+290h] [rbp+190h]
  __int16 v1663[8]; // [rsp+2A0h] [rbp+1A0h] BYREF
  __int16 v1664[8]; // [rsp+2B0h] [rbp+1B0h] BYREF
  __int16 v1665[8]; // [rsp+2C0h] [rbp+1C0h] BYREF
  __int16 v1666; // [rsp+2D0h] [rbp+1D0h] BYREF
  __int64 v1667; // [rsp+2D2h] [rbp+1D2h]
  __int64 v1668; // [rsp+2E0h] [rbp+1E0h]
  __int64 v1669; // [rsp+2E8h] [rbp+1E8h] BYREF
  unsigned int v1670; // [rsp+2F0h] [rbp+1F0h]
  int v1671; // [rsp+2F8h] [rbp+1F8h] BYREF
  unsigned int v1672; // [rsp+300h] [rbp+200h]
  _DWORD *v1673; // [rsp+308h] [rbp+208h]
  __int16 v1674[4]; // [rsp+310h] [rbp+210h] BYREF
  _BYTE *v1675; // [rsp+318h] [rbp+218h]
  __int16 v1676[4]; // [rsp+320h] [rbp+220h] BYREF
  _BYTE *v1677; // [rsp+328h] [rbp+228h]
  unsigned int v1678; // [rsp+330h] [rbp+230h]
  unsigned __int64 v1679; // [rsp+338h] [rbp+238h] BYREF
  __int64 v1680; // [rsp+340h] [rbp+240h]
  __int64 v1681; // [rsp+348h] [rbp+248h]
  __int64 v1682; // [rsp+350h] [rbp+250h]
  __int64 v1683; // [rsp+358h] [rbp+258h]
  __int64 v1684; // [rsp+360h] [rbp+260h]
  char v1685[16]; // [rsp+368h] [rbp+268h] BYREF
  char v1686[16]; // [rsp+378h] [rbp+278h] BYREF
  char v1687[16]; // [rsp+388h] [rbp+288h] BYREF
  __int64 v1688; // [rsp+398h] [rbp+298h] BYREF
  __int16 v1689; // [rsp+3A0h] [rbp+2A0h]
  __int16 v1690; // [rsp+3A2h] [rbp+2A2h]
  unsigned __int64 v1691; // [rsp+3B8h] [rbp+2B8h]
  int v1692; // [rsp+3C0h] [rbp+2C0h]
  unsigned int v1693; // [rsp+3C4h] [rbp+2C4h]
  unsigned __int64 v1694; // [rsp+3C8h] [rbp+2C8h]
  char v1695[16]; // [rsp+3D0h] [rbp+2D0h] BYREF
  __int64 v1696; // [rsp+3E0h] [rbp+2E0h]
  __int64 v1697; // [rsp+3E8h] [rbp+2E8h]
  char v1698[8]; // [rsp+3F0h] [rbp+2F0h] BYREF
  char v1699[8]; // [rsp+3F8h] [rbp+2F8h] BYREF
  __int64 v1700; // [rsp+400h] [rbp+300h]
  __int64 v1701; // [rsp+408h] [rbp+308h]
  __int64 v1702; // [rsp+410h] [rbp+310h]
  unsigned int *v1703; // [rsp+418h] [rbp+318h]
  __int64 v1704; // [rsp+420h] [rbp+320h]
  __int64 v1705; // [rsp+428h] [rbp+328h]
  __int64 v1706; // [rsp+430h] [rbp+330h]
  char v1707[8]; // [rsp+438h] [rbp+338h] BYREF
  char v1708[8]; // [rsp+440h] [rbp+340h] BYREF
  char v1709[8]; // [rsp+448h] [rbp+348h] BYREF
  __int64 v1710; // [rsp+450h] [rbp+350h]
  __int64 v1711; // [rsp+458h] [rbp+358h]
  __int64 v1712; // [rsp+460h] [rbp+360h]
  __int64 v1713; // [rsp+468h] [rbp+368h]
  __int64 v1714; // [rsp+470h] [rbp+370h]
  __int64 v1715; // [rsp+478h] [rbp+378h]
  __int64 v1716; // [rsp+480h] [rbp+380h]
  __int64 v1717; // [rsp+488h] [rbp+388h]
  __int64 v1718; // [rsp+490h] [rbp+390h]
  __int64 v1719; // [rsp+498h] [rbp+398h]
  __int64 v1720; // [rsp+4A0h] [rbp+3A0h]
  char v1721[8]; // [rsp+4A8h] [rbp+3A8h] BYREF
  __int64 v1722; // [rsp+4B0h] [rbp+3B0h]
  __int64 v1723; // [rsp+4B8h] [rbp+3B8h]
  __int64 v1724; // [rsp+4C0h] [rbp+3C0h]
  __int64 v1725; // [rsp+4C8h] [rbp+3C8h]
  __int64 v1726; // [rsp+4D8h] [rbp+3D8h]
  __int64 v1727; // [rsp+4E0h] [rbp+3E0h]
  __int64 v1728; // [rsp+4E8h] [rbp+3E8h]
  ULONG_PTR v1729; // [rsp+4F0h] [rbp+3F0h]
  __int64 v1730; // [rsp+4F8h] [rbp+3F8h]
  ULONG_PTR v1731; // [rsp+500h] [rbp+400h]
  __int64 v1732; // [rsp+508h] [rbp+408h]
  unsigned __int64 v1733; // [rsp+510h] [rbp+410h]
  __int64 v1734; // [rsp+518h] [rbp+418h]
  __int64 v1735; // [rsp+520h] [rbp+420h]
  __int64 v1736; // [rsp+528h] [rbp+428h]
  __int64 v1737; // [rsp+530h] [rbp+430h]
  __int64 v1738; // [rsp+538h] [rbp+438h]
  unsigned __int64 v1739; // [rsp+540h] [rbp+440h]
  unsigned __int64 v1740; // [rsp+548h] [rbp+448h]
  unsigned __int64 v1741; // [rsp+550h] [rbp+450h]
  __int64 v1742; // [rsp+558h] [rbp+458h]
  __int64 v1743; // [rsp+560h] [rbp+460h]
  __int64 v1744; // [rsp+568h] [rbp+468h]
  __int64 v1745; // [rsp+570h] [rbp+470h]
  __int64 v1746; // [rsp+578h] [rbp+478h]
  __int64 v1747; // [rsp+580h] [rbp+480h]
  __int64 v1748; // [rsp+588h] [rbp+488h]
  char v1749[16]; // [rsp+590h] [rbp+490h] BYREF
  char v1750[16]; // [rsp+5A0h] [rbp+4A0h] BYREF
  char v1751[16]; // [rsp+5B0h] [rbp+4B0h] BYREF
  ULONG_PTR v1752; // [rsp+5C0h] [rbp+4C0h]
  char v1753[16]; // [rsp+5C8h] [rbp+4C8h] BYREF
  char v1754[16]; // [rsp+5D8h] [rbp+4D8h] BYREF
  char v1755[16]; // [rsp+5E8h] [rbp+4E8h] BYREF
  char v1756[16]; // [rsp+5F8h] [rbp+4F8h] BYREF
  char v1757[16]; // [rsp+608h] [rbp+508h] BYREF
  char v1758[16]; // [rsp+618h] [rbp+518h] BYREF
  char v1759[16]; // [rsp+628h] [rbp+528h] BYREF
  char v1760[16]; // [rsp+638h] [rbp+538h] BYREF
  char v1761[16]; // [rsp+648h] [rbp+548h] BYREF
  char v1762[16]; // [rsp+658h] [rbp+558h] BYREF
  __int64 v1763; // [rsp+668h] [rbp+568h]
  char v1764[24]; // [rsp+670h] [rbp+570h] BYREF
  char v1765[8]; // [rsp+688h] [rbp+588h] BYREF
  ULONG_PTR v1766; // [rsp+690h] [rbp+590h]
  int v1767; // [rsp+69Ch] [rbp+59Ch]
  __int64 v1768; // [rsp+6A0h] [rbp+5A0h]
  __int64 v1769; // [rsp+6A8h] [rbp+5A8h]
  char v1770[16]; // [rsp+6B0h] [rbp+5B0h] BYREF
  char v1771[16]; // [rsp+6C0h] [rbp+5C0h] BYREF
  char v1772[16]; // [rsp+6D0h] [rbp+5D0h] BYREF
  char v1773[8]; // [rsp+6E0h] [rbp+5E0h] BYREF
  unsigned __int64 v1774; // [rsp+6E8h] [rbp+5E8h]
  char v1775[8]; // [rsp+6F8h] [rbp+5F8h] BYREF
  unsigned __int64 v1776; // [rsp+700h] [rbp+600h]
  char v1777[48]; // [rsp+710h] [rbp+610h] BYREF
  char v1778[24]; // [rsp+740h] [rbp+640h] BYREF
  char v1779[48]; // [rsp+758h] [rbp+658h] BYREF
  unsigned __int8 *v1780; // [rsp+788h] [rbp+688h]
  int v1782; // [rsp+800h] [rbp+700h]
  unsigned __int64 v1783; // [rsp+800h] [rbp+700h]
  __int64 v1784; // [rsp+800h] [rbp+700h]
  BOOL v1785; // [rsp+800h] [rbp+700h]
  unsigned __int8 v1786; // [rsp+800h] [rbp+700h]
  __int64 v1787; // [rsp+800h] [rbp+700h]
  unsigned int v1788; // [rsp+800h] [rbp+700h]
  int v1789; // [rsp+800h] [rbp+700h]
  int v1790; // [rsp+800h] [rbp+700h]
  int v1791; // [rsp+800h] [rbp+700h]
  unsigned int v1792; // [rsp+800h] [rbp+700h]
  __int16 v1793; // [rsp+800h] [rbp+700h]
  int v1794; // [rsp+800h] [rbp+700h]
  __int64 v1795; // [rsp+800h] [rbp+700h]
  __int64 v1796; // [rsp+800h] [rbp+700h]
  __int64 v1797; // [rsp+800h] [rbp+700h]
  unsigned __int8 v1798; // [rsp+800h] [rbp+700h]
  unsigned __int8 v1799; // [rsp+800h] [rbp+700h]
  __int64 v1800; // [rsp+800h] [rbp+700h]
  unsigned int v1801; // [rsp+800h] [rbp+700h]
  unsigned int *v1802; // [rsp+800h] [rbp+700h]
  __int64 v1803; // [rsp+800h] [rbp+700h]
  __int64 **v1804; // [rsp+800h] [rbp+700h]
  __int64 v1805; // [rsp+800h] [rbp+700h]
  int v1806; // [rsp+800h] [rbp+700h]
  __int64 v1807; // [rsp+800h] [rbp+700h]
  unsigned __int16 v1808; // [rsp+800h] [rbp+700h]
  __int16 v1809; // [rsp+800h] [rbp+700h]
  char v1810; // [rsp+808h] [rbp+708h] BYREF

  v2 = a2;
  if ( !__31 )
    KeBugCheck(0x33u);
  v4 = *(_QWORD *)&MaxDataSize;
  _InterlockedOr(v1576, 0);
  if ( !v4 )
    return 3221225635i64;
  if ( *(_QWORD *)a1 < 0x40ui64
    || *(_QWORD *)(a1 + 8) != (unsigned int)KiGetNtDdiVersion()
    || (*(_DWORD *)(a1 + 20) & 0x7FFFFFFE) != 0
    || *(_QWORD *)(a1 + 24)
    || *(_QWORD *)(a1 + 32)
    || *(_QWORD *)(a1 + 40)
    || *(_QWORD *)(v2 + 16)
    || *(_QWORD *)(v2 + 24)
    || *(_QWORD *)(v2 + 32)
    || *(_DWORD *)(v2 + 4) >= *(_DWORD *)(v4 + 2004) )
  {
    return 3221225485i64;
  }
  v6 = *(_DWORD *)(a1 + 48);
  v7 = 1;
  v8 = *(_QWORD *)(a1 + 56);
  v9 = *(unsigned int *)(a1 + 52);
  v10 = *(_DWORD *)(a1 + 20) & 1;
  if ( v6 )
  {
    if ( v6 <= 0 )
      return 3221225485i64;
    if ( v6 > 4 )
    {
      if ( __PAIR64__(v9, v6) == 5 )
      {
        if ( (unsigned __int8)ObGetCurrentIrql(v9, 16i64, v8, 4294967294i64) || KeAreApcsDisabled() )
        {
          v1546 = KeAreAllApcsDisabled();
          CurrentIrql = ObGetCurrentIrql(v1548, v1547, v1549, v1550);
          KeBugCheckEx(0xC8u, ((unsigned __int64)CurrentIrql << 16) | 0xFF, v1546, 0i64, 0i64);
        }
        goto LABEL_33;
      }
      return 3221225485i64;
    }
    if ( (_DWORD)v9 != 16 || !(unsigned __int8)KeVerifyGroupAffinity(*(_QWORD *)(a1 + 56), 0i64) )
      return 3221225485i64;
    if ( *(int *)(a1 + 20) >= 0 )
    {
      if ( (unsigned __int8)ObGetCurrentIrql(v12, v11, v13, v14) || KeAreApcsDisabled() )
      {
        v1558 = KeAreAllApcsDisabled();
        v1563 = ObGetCurrentIrql(v1560, v1559, v1561, v1562);
        KeBugCheckEx(0xC8u, ((unsigned __int64)v1563 << 16) | 0xFF, v1558, 0i64, 0i64);
      }
    }
    else if ( (unsigned __int8)ObGetCurrentIrql(v12, v11, v13, v14) > 1u )
    {
      v1552 = KeAreAllApcsDisabled();
      v1557 = ObGetCurrentIrql(v1554, v1553, v1555, v1556);
      KeBugCheckEx(0xC8u, ((unsigned __int64)v1557 << 16) | 0xFF, v1552, 0i64, 0i64);
    }
  }
  else
  {
    if ( (_DWORD)v9 != 16 || (unsigned __int64)(*(_QWORD *)(v8 + 8) - 1i64) > 0xFFFFFFFE )
      return 3221225485i64;
    if ( (unsigned __int8)ObGetCurrentIrql(v9, 16i64, v8, 4294967294i64) || KeAreApcsDisabled() )
    {
      v1570 = KeAreAllApcsDisabled();
      v1575 = ObGetCurrentIrql(v1572, v1571, v1573, v1574);
      KeBugCheckEx(0xC8u, ((unsigned __int64)v1575 << 16) | 0xFF, v1570, 0i64, 0i64);
    }
  }
LABEL_33:
  v1624 = 2744i64;
  if ( v10 )
  {
    v15 = *(_QWORD *)(v4 + 2648) + 2751i64;
    v1624 = v15;
    if ( v15 != 2744 )
    {
      Pool2 = (PSLIST_ENTRY)ExAllocatePool2(64i64, v15, 1953384779i64);
      v7 = 1;
      goto LABEL_39;
    }
    v7 = 1;
  }
  ++Lookaside.L.TotalAllocates;
  v1602 = RtlpInterlockedPopEntrySList(&Lookaside.L.ListHead);
  v17 = (__int64)v1602;
  if ( v1602 )
    goto LABEL_40;
  ++Lookaside.L.AllocateMisses;
  Pool2 = (PSLIST_ENTRY)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))Lookaside.L.AllocateEx)(
                          (unsigned int)Lookaside.L.Type,
                          Lookaside.L.Size,
                          Lookaside.L.Tag);
LABEL_39:
  v1602 = Pool2;
  v17 = (__int64)Pool2;
LABEL_40:
  if ( !v17 )
    return 3221225626i64;
  v18 = v17 + 32;
  v1608 = v17 + 32;
  memmove((void *)(v17 + 32), (const void *)v4, 0xA68ui64);
  *(_QWORD *)(v17 + 2656) = v4;
  *(_QWORD *)(v17 + 2664) = v17 + 2696;
  *(_DWORD *)(v17 + 2056) = *(_DWORD *)v2;
  *(_DWORD *)(v17 + 2060) = *(_DWORD *)(v2 + 4);
  *(_DWORD *)(v17 + 2064) = 0;
  *(_DWORD *)(v17 + 2072) = 0;
  *(_DWORD *)(v17 + 2428) |= 0x1000u;
  if ( v10 )
    *(_QWORD *)(v17 + 2672) = (v17 + 2751) & 0xFFFFFFFFFFFFFFF8ui64;
  v20 = *(_DWORD *)(a1 + 16);
  v1580 = (_BYTE *)(v17 + 32);
  v21 = v17 + 32;
  if ( v20 > 0x80000 )
    v20 = 0x80000;
  *(_DWORD *)(v17 + 2068) = v20;
  v1599 = 0;
  if ( !v20 )
    v20 = 1;
  v1614 = 0;
  *(_DWORD *)(v17 + 2068) = v20;
  v1657 = a1;
  v1658 = v2;
  v22 = *(unsigned int *)(v17 + 2392);
  if ( (_DWORD)v22 != -1 )
  {
    v23 = (*(__int64 (__fastcall **)(__int64, __int64, __int64))(v17 + 648))(v22, v19, 6i64);
    if ( v23 || (v23 = (*(__int64 (__fastcall **)(_QWORD))(v17 + 656))(0i64)) != 0 )
    {
      if ( (*(int (__fastcall **)(__int64, char *))(v17 + 672))(v23, v1777) >= 0 )
      {
        *(_QWORD *)(v17 + 2408) = v23;
        v33 = (*(__int64 (**)(void))(v17 + 712))();
        v34 = (*(__int64 (__fastcall **)(__int64))(v17 + 744))(v33);
        if ( v34 )
        {
          (*(void (__fastcall **)(__int64, __int64))(v17 + 760))(v33, v34);
          v35 = 0;
        }
        else
        {
          v35 = 4;
        }
        v36 = *(_DWORD *)(v17 + 2428) & 0xFFFFFFFB;
        v1614 = 1;
        *(_DWORD *)(v17 + 2428) = v35 | v36;
        *(_DWORD *)(v17 + 2064) += 0x10000;
        goto LABEL_91;
      }
      (*(void (__fastcall **)(__int64))(v17 + 664))(v23);
    }
  }
  v24 = *(_DWORD *)(v17 + 2428);
  if ( (v24 & 8) != 0 && (v24 & 0x1000) == 0 )
  {
    v25 = __rdtsc();
    v26 = (__ROR8__(v25, 3) ^ v25) * (unsigned __int128)0x7010008004002001ui64;
    v1732 = *((_QWORD *)&v26 + 1);
    if ( (((unsigned __int8)v26 ^ BYTE8(v26)) & 3) == 0 )
    {
      v27 = __rdtsc();
      v28 = (__ROR8__(v27, 3) ^ v27) * (unsigned __int128)0x7010008004002001ui64;
      v1735 = *((_QWORD *)&v28 + 1);
      v29 = ((unsigned __int64)v28 ^ *((_QWORD *)&v28 + 1)) % 0xB;
      if ( (unsigned int)v29 > 5 )
      {
        v37 = v29 - 6;
        if ( v37 )
        {
          v38 = v37 - 1;
          if ( v38 )
          {
            v39 = v38 - 1;
            if ( v39 )
            {
              if ( v39 == 1 )
              {
                v1631 = -1333354875;
                v32 = __ROR4__(-1333354868, 33);
              }
              else
              {
                v40 = __rdtsc();
                v41 = __ROR8__(v40, 3);
                v1736 = ((v41 ^ v40) * (unsigned __int128)0x7010008004002001ui64) >> 64;
                v42 = (67117057 * (v41 ^ v40)) ^ v1736;
                v32 = ((((((v42 % 0x1A + 97) << 8) | ((v42 >> 5)
                                                    - 26
                                                    * ((unsigned int)((1321528399 * (unsigned __int64)(v42 >> 5)) >> 32) >> 3)
                                                    + 65)) << 8) | ((v42 >> 10)
                                                                  - 26
                                                                  * ((unsigned int)((1321528399
                                                                                   * (unsigned __int64)(v42 >> 10)) >> 32) >> 3)
                                                                  + 97)) << 8) | ((v42 >> 15) % 0x1A + 65);
              }
            }
            else
            {
              v1632 = 1684422978;
              v32 = __ROR4__(1684422978, 8);
            }
          }
          else
          {
            v1633 = -2100910376;
            v32 = __ROL4__(-2100910376, 7);
          }
        }
        else
        {
          v1634 = 1314342514;
          v32 = __ROR4__(1314342516, 24);
        }
      }
      else if ( (_DWORD)v29 == 5 )
      {
        v1630 = 680282605;
        v32 = __ROR4__(680282605, 5);
      }
      else if ( (_DWORD)v29 )
      {
        v30 = v29 - 1;
        if ( v30 )
        {
          v31 = v30 - 1;
          if ( v31 )
          {
            if ( v31 == 1 )
            {
              v1627 = -1474152136;
              v32 = __ROR4__(-1474152133, 15);
            }
            else
            {
              v1626 = 1728537748;
              v32 = __ROL4__(1728537748, 4);
            }
          }
          else
          {
            v1628 = -2051698419;
            v32 = __ROR4__(-2051698419, 2);
          }
        }
        else
        {
          v1629 = -1297272415;
          v32 = __ROL4__(-1297272415, 1);
        }
      }
      else
      {
        v1639 = -795291432;
        v32 = __ROR4__(-795291432, 6);
      }
      v43 = (*(__int64 (__fastcall **)(__int64, _QWORD, _QWORD))(v17 + 264))(64i64, *(_QWORD *)(v17 + 1880), v32);
      if ( v43 )
      {
        (*(void (__fastcall **)(__int64, _QWORD))(v17 + 440))(v43, *(unsigned __int16 *)(v17 + 1888));
        v44 = *(unsigned int *)(*(_QWORD *)(v17 + 1752) + *(_QWORD *)(v17 + 1296));
        if ( (_DWORD)v44 )
        {
          v45 = __rdtsc();
          v46 = (__ROR8__(v45, 3) ^ v45) * (unsigned __int128)0x7010008004002001ui64;
          v1737 = *((_QWORD *)&v46 + 1);
          v44 = (*((_QWORD *)&v46 + 1) ^ (unsigned __int64)v46) % v44;
        }
        v47 = 0i64;
        while ( 1 )
        {
          v48 = (*(__int64 (__fastcall **)(__int64))(v17 + 960))(v47);
          v49 = v48;
          if ( !v48 )
            goto LABEL_88;
          v47 = v48;
          if ( !(_DWORD)v44 )
            break;
          LODWORD(v44) = v44 - 1;
        }
        if ( (*(int (__fastcall **)(__int64))(v17 + 944))(v48) < 0 )
        {
          (*(void (__fastcall **)(__int64))(v17 + 968))(v49);
LABEL_88:
          (*(void (__fastcall **)(__int64))(v17 + 272))(v43);
          goto LABEL_89;
        }
        (*(void (__fastcall **)(__int64, char *))(v17 + 1096))(v49, v1777);
        (*(void (__fastcall **)(__int64, __int64, _QWORD, _QWORD, _QWORD))(v17 + 472))(v49, v43, 0i64, 0i64, 0i64);
        v59 = __rdtsc();
        v60 = (__ROR8__(v59, 3) ^ v59) * (unsigned __int128)0x7010008004002001ui64;
        v1738 = *((_QWORD *)&v60 + 1);
        v61 = ((unsigned __int64)v60 ^ *((_QWORD *)&v60 + 1))
            % (*(unsigned int (__fastcall **)(__int64))(v17 + 464))(v43);
        _disable();
        _enable();
        (*(void (__fastcall **)(char *, _QWORD))(v17 + 432))(v1695, 0i64);
        (*(void (__fastcall **)(char *, __int64))(v17 + 448))(v1764, v43);
        while ( (*(int (__fastcall **)(unsigned int *, char *))(v17 + 456))(&v1610, v1764) >= 0 )
        {
          if ( !(_DWORD)v61 )
          {
            (*(void (__fastcall **)(char *, _QWORD))(v17 + 432))(v1695, v1610);
            break;
          }
          LODWORD(v61) = v61 - 1;
        }
        (*(void (__fastcall **)(char *, char *))(v17 + 480))(v1695, v1762);
        (*(void (__fastcall **)(__int64))(v17 + 272))(v43);
        v7 = 1;
        v1599 = 1;
        goto LABEL_91;
      }
LABEL_89:
      v7 = 1;
    }
  }
  v1599 = 0;
LABEL_91:
  v1612 = 0i64;
  v50 = &v1613;
  v51 = 4;
  v52 = 0xFFFFFFFFi64;
  do
  {
    *(_BYTE *)v50 = 0;
    v50 = (unsigned int *)((char *)v50 + 1);
    --v51;
  }
  while ( v51 );
  v53 = *(_DWORD *)(v17 + 2068);
  v54 = *(unsigned int *)(v17 + 2056);
  v1598 = *(_DWORD *)(v17 + 2056);
  if ( *(_DWORD *)(v17 + 2064) >= v53 )
    goto LABEL_2472;
  v55 = v1739;
  v56 = v54;
  v57 = v1740;
  v58 = v1678;
  v1615 = v1739;
  v1623 = v1740;
  v1606 = v1678;
  v1603 = v1670;
  while ( 1 )
  {
    if ( (*(_DWORD *)(v21 + 2392) & 0x110000) != 1114112 )
      __writedr(7u, 0i64);
    if ( v56 == *(_DWORD *)(v21 + 2004) )
      break;
    v62 = v21;
    if ( *(_QWORD *)(v21 + 2624) )
      v62 = *(_QWORD *)(v21 + 2624);
    v63 = 0;
    v64 = (char *)(v62 + *(unsigned int *)(v62 + 2000));
    v1579 = (int *)v64;
    if ( (_DWORD)v1612 && HIDWORD(v1612) <= v56 )
    {
      v63 = HIDWORD(v1612);
      v64 = (char *)(v62 + v1613);
      v1579 = (int *)v64;
    }
    if ( v63 != v56 )
    {
      v65 = v56 - v63;
      v63 = v56;
      while ( 1 )
      {
        v54 = *(unsigned int *)v64;
        if ( (int)v54 > 12 )
          break;
        if ( (_DWORD)v54 == 12 )
          goto LABEL_128;
        v66 = v54 - 1;
        if ( !v66 )
          goto LABEL_128;
        v54 = (unsigned int)(v66 - 6);
        if ( (_DWORD)v54 )
        {
          v54 = (unsigned int)(v54 - 1);
          if ( !(_DWORD)v54 )
          {
            v68 = *((unsigned __int16 *)v64 + 16);
LABEL_133:
            v67 = (v68 + 55) & 0xFFFFFFF8;
            goto LABEL_134;
          }
          if ( (_DWORD)v54 != 2 )
            goto LABEL_130;
          v67 = (unsigned int)(16 * (*((_DWORD *)v64 + 7) + 3));
        }
        else
        {
          v67 = (unsigned int)(24 * (*((_DWORD *)v64 + 6) + 2));
        }
LABEL_134:
        v64 += v67;
        if ( !--v65 )
        {
          v55 = v1615;
          v57 = v1623;
          v58 = v1606;
          v1579 = (int *)v64;
          goto LABEL_136;
        }
      }
      if ( (_DWORD)v54 == 28 )
      {
        v68 = *((unsigned __int16 *)v64 + 20);
        goto LABEL_133;
      }
      if ( (_DWORD)v54 == 30 )
      {
        v54 = *((_DWORD *)v64 + 9) != 0 ? (unsigned int)(*((_DWORD *)v64 + 9) - 1) : 0;
        v52 = ((*((_DWORD *)v64 + 9) != 0 ? *((_DWORD *)v64 + 9) - 1 : 0) / 0xCu + 7) & 0xFFFFFFF8;
        v67 = (unsigned int)v52 + 24 * (*((unsigned __int16 *)v64 + 20) + 2);
        goto LABEL_134;
      }
      if ( (int)v54 <= 32 )
      {
LABEL_130:
        v67 = 48i64;
        goto LABEL_134;
      }
      if ( (int)v54 <= 34 )
      {
        v54 = *((_DWORD *)v64 + 8) & 0xFFF;
        v52 = (v54 + *((unsigned int *)v64 + 10) + 4095i64) >> 12;
        v67 = (unsigned int)(20 * v52 + 48);
        goto LABEL_134;
      }
      if ( (_DWORD)v54 != 43 )
        goto LABEL_130;
LABEL_128:
      v54 = *((unsigned int *)v64 + 4);
      v52 = v54 / 0xC;
      v67 = 4 * (unsigned int)(v54 / 0xC) + 48;
      goto LABEL_134;
    }
LABEL_136:
    LODWORD(v1612) = 1;
    HIDWORD(v1612) = v63;
    v69 = 0;
    v1613 = (_DWORD)v64 - v62;
    if ( !*(_DWORD *)(v21 + 2028) )
    {
      v70 = 0;
      v54 = *(int *)v64;
      v52 = *(unsigned int *)(v1657 + 48);
      v71 = *(_QWORD *)(v1657 + 56);
      if ( (int)v54 > 21 )
      {
        if ( (_DWORD)v54 == 24 )
          goto LABEL_174;
        if ( (int)v54 <= 27 )
          goto LABEL_146;
        if ( (int)v54 <= 29 )
          goto LABEL_174;
        if ( (unsigned int)v54 > 0x23 || (v74 = 0x940000000i64, !_bittest64(&v74, v54)) )
        {
          if ( (unsigned int)(v54 - 43) > 1 )
            goto LABEL_146;
        }
LABEL_169:
        if ( (_DWORD)v52 )
          goto LABEL_146;
      }
      else
      {
        if ( (_DWORD)v54 == 21 )
        {
          v70 = *((_DWORD *)v64 + 11);
          if ( (_DWORD)v52 != 4 )
            goto LABEL_146;
          goto LABEL_161;
        }
        if ( (v54 & 0x80000000) != 0i64 )
          goto LABEL_146;
        if ( (int)v54 <= 1 )
          goto LABEL_169;
        if ( (int)v54 > 3 )
        {
          if ( (_DWORD)v54 != 7 )
          {
            if ( (_DWORD)v54 != 8 )
            {
              if ( (_DWORD)v54 != 9 && (unsigned int)(v54 - 11) > 3 )
                goto LABEL_146;
              goto LABEL_169;
            }
LABEL_174:
            if ( (_DWORD)v52 != 5 )
              goto LABEL_146;
LABEL_175:
            ++*(_QWORD *)(v1658 + 8);
            goto LABEL_176;
          }
          v70 = *((_DWORD *)v64 + 7);
          v73 = (_DWORD)v52 == 1;
LABEL_152:
          if ( !v73 )
            goto LABEL_146;
          goto LABEL_161;
        }
        if ( (_DWORD)v52 )
        {
          if ( (unsigned int)(v54 - 2) <= 1 )
          {
            v70 = *((_DWORD *)v64 + 10);
            if ( (_DWORD)v54 == 3 && (_DWORD)v52 != 2 )
              goto LABEL_146;
            if ( (_DWORD)v54 == 2 )
            {
              v73 = (_DWORD)v52 == 3;
              goto LABEL_152;
            }
          }
LABEL_161:
          if ( !(unsigned int)KeCheckProcessorGroupAffinity(*(_QWORD *)(v1657 + 56), v70) )
            goto LABEL_146;
          goto LABEL_175;
        }
      }
      v75 = *((unsigned int *)v64 + 4);
      if ( !(_DWORD)v75 )
        goto LABEL_146;
      v76 = *(_QWORD *)v71;
      v54 = *((_QWORD *)v64 + 1);
      v1672 = *(_DWORD *)(v71 + 8);
      v52 = v54 + v75;
      v1741 = v76;
      if ( v54 >= v76 + v1672 || v52 <= v76 )
        goto LABEL_146;
      goto LABEL_175;
    }
LABEL_176:
    v77 = *(_DWORD *)v64;
    v1782 = *(_DWORD *)v64;
    if ( *(int *)v64 > 28 )
    {
      if ( v77 <= 37 )
      {
        if ( v77 == 37 )
        {
          v54 = 2i64;
          if ( (*(_DWORD *)(v21 + 2396) & 2) != 0
            || !(*(unsigned __int8 (__fastcall **)(__int64, unsigned __int64))(v21 + 1048))(2i64, v52)
            || *(_DWORD *)(v21 + 2240) )
          {
            goto LABEL_146;
          }
          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
          *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
          *(_QWORD *)(v21 + 2264) = *(int *)v64;
          goto LABEL_1804;
        }
        if ( v77 == 29 )
        {
          v1091 = (_QWORD *)*((_QWORD *)v64 + 1);
          v1092 = *((unsigned int *)v64 + 4);
          v1093 = v1091;
          *(_DWORD *)(v21 + 2032) += v1092;
          v1094 = (const char *)v1091;
          v1095 = *(_DWORD *)(v21 + 2012);
          v1096 = *(_QWORD *)(v21 + 2016);
          v54 = (unsigned __int64)v1091 + v1092;
          if ( v1091 < (_QWORD *)((char *)v1091 + v1092) )
          {
            do
            {
              _mm_prefetch(v1094, 0);
              v1094 += 64;
            }
            while ( (unsigned __int64)v1094 < v54 );
          }
          v1097 = *(_QWORD *)(v21 + 2016);
          v1098 = (unsigned int)v1092 >> 7;
          if ( (unsigned int)v1092 >> 7 )
          {
            do
            {
              v1099 = 8i64;
              do
              {
                v1100 = v1093[1] ^ __ROL8__(*v1093 ^ v1097, v1095);
                v1093 += 2;
                v1097 = __ROL8__(v1100, v1095);
                --v1099;
              }
              while ( v1099 );
              v54 = __ROL8__(v1096 ^ ((char *)v1093 - (char *)v1091), 17) ^ v1096 ^ ((char *)v1093 - (char *)v1091);
              v1720 = (v54 * (unsigned __int128)0x7010008004002001ui64) >> 64;
              v1095 = ((unsigned __int8)v54 ^ (unsigned __int8)(v1720 ^ v1095)) & 0x3F;
              if ( !v1095 )
                v1095 = 1;
              --v1098;
            }
            while ( v1098 );
            v21 = (ULONG_PTR)v1580;
          }
          v1101 = v1092 & 0x7F;
          if ( (unsigned int)v1101 >= 8 )
          {
            v1102 = (unsigned __int64)(unsigned int)v1101 >> 3;
            do
            {
              v54 = v1095;
              v1097 = __ROL8__(*v1093++ ^ v1097, v1095);
              v1101 = (unsigned int)(v1101 - 8);
              --v1102;
            }
            while ( v1102 );
          }
          for ( ; (_DWORD)v1101; v1101 = (unsigned int)(v1101 - 1) )
          {
            v1103 = *(unsigned __int8 *)v1093;
            v54 = v1095;
            v1093 = (_QWORD *)((char *)v1093 + 1);
            v1097 = __ROL8__(v1103 ^ v1097, v1095);
          }
          for ( i = v1097; ; LODWORD(v1097) = i ^ v1097 )
          {
            i >>= 31;
            if ( !i )
              break;
          }
          v1105 = v1097 & 0x7FFFFFFF;
          if ( v1105 == *((_DWORD *)v64 + 5) )
            goto LABEL_1778;
          if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
            v69 = 1;
          v54 = *((unsigned int *)v64 + 4);
          v1106 = *((_QWORD *)v64 + 1);
          if ( *((_DWORD *)v64 + 4) )
          {
            v1101 = 64i64;
            if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
            {
              v1107 = KeGetCurrentIrql();
              __writecr8(2ui64);
              v1108 = v1106 & 0xFFFFFFFFFFFFF000ui64;
              v1803 = (v1106 + v54 - 1) | 0xFFF;
              v1109 = (v1106 & 0xFFFFFFFFFFFFF000ui64) - 1;
              while ( 1 )
              {
                v1110 = v1107;
                while ( 1 )
                {
                  v1111 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                            v1108,
                            0i64,
                            v1101,
                            v1093);
                  if ( v1111 != -1073741267 )
                    break;
                  if ( v69 )
                    goto LABEL_1796;
                  if ( v1107 > 1u )
                    goto LABEL_1776;
                  v1110 = v1107;
                  __writecr8(v1107);
                  KeGetCurrentIrql();
                  __writecr8(2ui64);
                }
                if ( v1111 < 0 )
                  break;
LABEL_1776:
                v1108 += 4096i64;
                v1109 += 4096i64;
                if ( v1109 == v1803 )
                {
                  __writecr8(v1110);
                  v64 = (char *)v1579;
                  goto LABEL_1778;
                }
              }
LABEL_1796:
              __writecr8(v1110);
              v64 = (char *)v1579;
            }
          }
          if ( *(_DWORD *)(v21 + 2240) )
          {
LABEL_1778:
            v1112 = 1;
          }
          else
          {
            v1112 = 1;
            *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = *((unsigned int *)v64 + 5) ^ (unsigned __int64)v1105;
            v54 = *((_QWORD *)v64 + 1);
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
              *(_QWORD *)(v21 + 2264) = *(int *)v64;
              *(_QWORD *)(v21 + 2272) = v54;
              *(_DWORD *)(v21 + 2240) = 1;
              __b9(v21, 0i64);
            }
          }
          v1113 = (__int64 **)*((_QWORD *)v64 + 1);
          v1114 = *((_DWORD *)v64 + 4) >> 4;
          v1804 = v1113;
          if ( v1114 )
          {
            v1115 = v1114;
            v1585 = v1114;
            do
            {
              v1116 = (char *)v1579;
              v1117 = **v1113;
              v1654 = 0i64;
              v1118 = (*(__int64 (__fastcall **)(__int64, __int64 *, __int64, _QWORD *))(v21 + 768))(
                        v1117,
                        &v1654,
                        v1101,
                        v1093);
              if ( v1118 )
              {
                do
                {
                  ++v1112;
                  if ( !(*(__int64 (__fastcall **)(__int64, char *))(v21 + 504))(v1118, v1721) )
                  {
                    if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
                    {
                      v1119 = *(_QWORD **)(v21 + 2632);
                      v1120 = 48;
                      v1121 = 6i64;
                      do
                      {
                        v1120 -= 8;
                        *v1119 = *(_QWORD *)v1116;
                        v1116 += 8;
                        ++v1119;
                        --v1121;
                      }
                      while ( v1121 );
                      if ( v1120 )
                      {
                        do
                        {
                          v1122 = *v1116++;
                          *(_BYTE *)v1119 = v1122;
                          v1119 = (_QWORD *)((char *)v1119 + 1);
                          --v1120;
                        }
                        while ( v1120 );
                        v21 = (ULONG_PTR)v1580;
                      }
                      v1116 = *(char **)(v21 + 2632);
                    }
                    *((_QWORD *)v1116 + 3) = v1118;
                    *((_QWORD *)v1116 + 4) = v1117;
                    v1123 = *(_QWORD *)(v21 + 1384);
                    *(_QWORD *)v1123 = v1116;
                    *(_DWORD *)(v1123 + 16) = 48;
                    v1124 = *(_QWORD *)(v21 + 1384);
                    *(_QWORD *)(v1124 + 8) = v1118;
                    *(_DWORD *)(v1124 + 20) = 4096;
                    if ( !*(_DWORD *)(v21 + 2240) )
                    {
                      *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                      *(_QWORD *)(v21 + 2256) = v1116 - 0x4C48B4211BBACBEBi64;
                      *(_QWORD *)(v21 + 2264) = *(int *)v1116;
                      *(_QWORD *)(v21 + 2272) = 6i64;
                      *(_DWORD *)(v21 + 2240) = 1;
                      __b9(v21, 0i64);
                    }
                  }
                  v1118 = (*(__int64 (__fastcall **)(__int64, __int64 *))(v21 + 768))(v1117, &v1654);
                }
                while ( v1118 );
                v1113 = v1804;
                v1115 = v1585;
              }
              v1113 += 2;
              v1112 = 1;
              --v1115;
              v1804 = v1113;
              v1585 = v1115;
            }
            while ( v1115 );
          }
          goto LABEL_146;
        }
        v54 = (unsigned int)(v77 - 30);
        if ( v77 == 30 )
        {
          if ( (v64[42] & 1) != 0 )
          {
            if ( !*(_QWORD *)(v21 + 2376) )
              goto LABEL_1745;
            v54 = *(unsigned int *)(v21 + 2396);
            if ( (v54 & 4) != 0 )
              goto LABEL_1745;
            if ( *(_DWORD *)(v21 + 2028) )
            {
              if ( (v54 & 0x20) != 0 )
                goto LABEL_1745;
            }
            else
            {
              *(_DWORD *)(v21 + 2396) = v54 ^ ((unsigned __int8)v54 ^ (unsigned __int8)(8 * v54)) & 0x20;
            }
          }
          v1026 = *(unsigned int *)(v21 + 2028);
          v1027 = *((unsigned int *)v64 + 9);
          v1588 = (unsigned int *)*((_QWORD *)v64 + 1);
          v1028 = (__int64)&v1588[3 * v1026];
          v1029 = (unsigned int *)(v1028 + 12);
          v1585 = v1028;
          v1587 = (unsigned int *)(v1028 + 12);
          v1030 = v1027 / 0xC;
          BugCheckParameter2 = v1027 / 0xC;
          v1593 = (unsigned __int64)&v1588[3 * (unsigned int)(v1027 / 0xC)];
          v1031 = &v64[v1026 + 48];
          v1583 = (__int64)v1031;
          v1032 = v1027 / 0xC - 1;
          v1801 = v1032;
          if ( (unsigned int)(v1027 / 0xC) )
          {
            v1033 = (unsigned __int64)&v64[((v1032 + 7i64) & 0xFFFFFFFFFFFFFFF8ui64) + 48];
            v1597 = v1033;
          }
          else
          {
            v1033 = (unsigned __int64)(v64 + 48);
            v1597 = (__int64)(v64 + 48);
            v1801 = v1027 / 0xC - 1;
          }
          v54 = 3i64 * *((unsigned __int16 *)v64 + 20);
          v1582 = v1033 + 24i64 * *((unsigned __int16 *)v64 + 20);
          if ( (_DWORD)v1030 && (unsigned int)v1026 < v1032 )
          {
            do
            {
              if ( *v1031 >= 0 )
              {
                v1034 = *(_DWORD *)(v1028 + 4);
                v1035 = *((_QWORD *)v64 + 3) + v1034;
                v1036 = *v1029 - v1034;
                *(_DWORD *)(v21 + 2032) += v1036;
                v1037 = (_QWORD *)v1035;
                v1038 = *(_DWORD *)(v21 + 2012);
                v1039 = (const char *)v1035;
                v1040 = *(_QWORD *)(v21 + 2016);
                v1595 = v1035;
                v1041 = (unsigned int)v1036;
                if ( v1035 < (unsigned __int64)(v1035 + v1036) )
                {
                  do
                  {
                    _mm_prefetch(v1039, 0);
                    v1039 += 64;
                  }
                  while ( (unsigned __int64)v1039 < v1035 + v1036 );
                }
                v1042 = v1040;
                v1043 = (unsigned int)v1036 >> 7;
                if ( (unsigned int)v1036 >> 7 )
                {
                  do
                  {
                    v1044 = 8i64;
                    do
                    {
                      v1045 = v1042 ^ *v1037;
                      v1046 = v1037[1];
                      v1037 += 2;
                      v1042 = __ROL8__(__ROL8__(v1045, v1038) ^ v1046, v1038);
                      --v1044;
                    }
                    while ( v1044 );
                    v1047 = __ROL8__(v1040 ^ ((unsigned __int64)v1037 - v1035), 17) ^ v1040 ^ ((unsigned __int64)v1037
                                                                                             - v1035);
                    v1718 = (v1047 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                    v1038 = ((unsigned __int8)v1047 ^ (unsigned __int8)(v1718 ^ v1038)) & 0x3F;
                    if ( !v1038 )
                      LOBYTE(v1038) = 1;
                    --v1043;
                  }
                  while ( v1043 );
                  v21 = (ULONG_PTR)v1580;
                }
                v1048 = v1036 & 0x7F;
                if ( v1048 >= 8 )
                {
                  v1049 = (unsigned __int64)v1048 >> 3;
                  do
                  {
                    v1042 = __ROL8__(*v1037++ ^ v1042, v1038);
                    v1048 -= 8;
                    --v1049;
                  }
                  while ( v1049 );
                }
                if ( v1048 )
                {
                  do
                  {
                    v1050 = *(unsigned __int8 *)v1037;
                    v1037 = (_QWORD *)((char *)v1037 + 1);
                    v1042 = __ROL8__(v1050 ^ v1042, v1038);
                    --v1048;
                  }
                  while ( v1048 );
                  v1031 = (char *)v1583;
                }
                for ( j = v1042; ; LOBYTE(v1042) = j ^ v1042 )
                {
                  j >>= 7;
                  if ( !j )
                    break;
                }
                v54 = (unsigned __int8)*v1031;
                v1052 = v1042 & 0x7F;
                if ( v1052 == (*v1031 & 0x7F) )
                  goto LABEL_1692;
                if ( v1041 && (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
                {
                  v1053 = KeGetCurrentIrql();
                  __writecr8(2ui64);
                  v1054 = v1035 & 0xFFFFFFFFFFFFF000ui64;
                  v1055 = (v1041 - 1 + v1035) | 0xFFF;
                  v1056 = v1054 - 1;
                  while ( 1 )
                  {
                    v1057 = v1053;
                    while ( 1 )
                    {
                      v1058 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(v21 + 1112))(v1054, 0i64);
                      if ( v1058 != -1073741267 )
                        break;
                      if ( v1053 > 1u )
                        goto LABEL_1690;
                      v1057 = v1053;
                      __writecr8(v1053);
                      KeGetCurrentIrql();
                      __writecr8(2ui64);
                    }
                    if ( v1058 < 0 )
                      break;
LABEL_1690:
                    v1054 += 4096i64;
                    v1056 += 4096i64;
                    if ( v1056 == v1055 )
                    {
                      __writecr8(v1057);
                      goto LABEL_1692;
                    }
                  }
                  __writecr8(v1057);
                  v1035 = v1595;
                  LOBYTE(v54) = *(_BYTE *)v1583;
                }
                v1060 = v54 & 0x7F;
                if ( *(_DWORD *)(v21 + 2240) )
                {
LABEL_1692:
                  v64 = (char *)v1579;
                }
                else
                {
                  v1061 = v1052;
                  v64 = (char *)v1579;
                  v54 = v1060 ^ v1061;
                  *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v54;
                  if ( !*(_DWORD *)(v21 + 2240) )
                  {
                    *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                    *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                    *(_QWORD *)(v21 + 2264) = *(int *)v64;
                    *(_QWORD *)(v21 + 2272) = v1035;
                    *(_DWORD *)(v21 + 2240) = 1;
                    __b9(v21, 0i64);
                  }
                }
                v1028 = v1585;
                *(_DWORD *)(v21 + 2032) += 64;
                v1031 = (char *)v1583;
                v1029 = v1587;
              }
              ++v1031;
              v1028 += 12i64;
              v1583 = (__int64)v1031;
              v1029 += 3;
              v1585 = v1028;
              v1587 = v1029;
            }
            while ( (unsigned __int64)v1029 < v1593 && *(_DWORD *)(v21 + 2032) < *(_DWORD *)(v21 + 2036) );
            LODWORD(v1030) = BugCheckParameter2;
            LODWORD(v1026) = ((int)v1028 - (int)v1588) / 12;
            *(_DWORD *)(v21 + 2028) = v1026;
            v1033 = v1597;
            if ( (unsigned int)v1026 < v1801 )
              goto LABEL_146;
          }
          if ( *(_DWORD *)(v21 + 2032) >= *(_DWORD *)(v21 + 2036) )
            goto LABEL_146;
          if ( (_DWORD)v1030 )
            v1059 = 3i64 * (unsigned int)(v1026 - v1030 + 1);
          else
            v1059 = 3i64 * (unsigned int)v1026;
          v54 = v1033 + 8 * v1059;
          v1587 = (unsigned int *)v54;
          while ( 1 )
          {
            v1062 = (unsigned int *)(v54 + 8);
            v1063 = 2i64;
            v1583 = 2i64;
            v1802 = (unsigned int *)(v54 + 8);
            do
            {
              if ( (*v1062 & 0x80000000) == 0 )
              {
                v1064 = *((_QWORD *)v64 + 3) + *(v1062 - 2);
                v1065 = *(v1062 - 1) - *(v1062 - 2);
                *(_DWORD *)(v21 + 2032) += v1065;
                v1066 = (_QWORD *)v1064;
                v1067 = *(_DWORD *)(v21 + 2012);
                v1068 = (const char *)v1064;
                v1069 = *(_QWORD *)(v21 + 2016);
                v1070 = (unsigned int)v1065;
                v1585 = v1064;
                v1595 = (unsigned int)v1065;
                if ( v1064 < v1064 + v1065 )
                {
                  do
                  {
                    _mm_prefetch(v1068, 0);
                    v1068 += 64;
                  }
                  while ( (unsigned __int64)v1068 < v1064 + v1065 );
                }
                v1071 = v1069;
                v1072 = (unsigned int)v1065 >> 7;
                if ( (unsigned int)v1065 >> 7 )
                {
                  do
                  {
                    v1073 = 8i64;
                    do
                    {
                      v1074 = v1066[1] ^ __ROL8__(*v1066 ^ v1071, v1067);
                      v1066 += 2;
                      v1071 = __ROL8__(v1074, v1067);
                      --v1073;
                    }
                    while ( v1073 );
                    v1075 = (__ROL8__(v1069 ^ ((unsigned __int64)v1066 - v1064), 17) ^ v1069 ^ ((unsigned __int64)v1066
                                                                                              - v1064))
                          * (unsigned __int128)0x7010008004002001ui64;
                    v1719 = *((_QWORD *)&v1075 + 1);
                    v1067 = ((unsigned __int8)v1075 ^ (unsigned __int8)(BYTE8(v1075) ^ v1067)) & 0x3F;
                    if ( !v1067 )
                      LOBYTE(v1067) = 1;
                    --v1072;
                  }
                  while ( v1072 );
                  v21 = (ULONG_PTR)v1580;
                  v1070 = v1595;
                  v1062 = v1802;
                  v1063 = v1583;
                }
                v1076 = v1065 & 0x7F;
                if ( v1076 >= 8 )
                {
                  v1077 = (unsigned __int64)v1076 >> 3;
                  do
                  {
                    v1071 = __ROL8__(*v1066++ ^ v1071, v1067);
                    v1076 -= 8;
                    --v1077;
                  }
                  while ( v1077 );
                }
                if ( v1076 )
                {
                  do
                  {
                    v1078 = *(unsigned __int8 *)v1066;
                    v1066 = (_QWORD *)((char *)v1066 + 1);
                    v1071 = __ROL8__(v1078 ^ v1071, v1067);
                    --v1076;
                  }
                  while ( v1076 );
                  v21 = (ULONG_PTR)v1580;
                }
                for ( k = v1071; ; LODWORD(v1071) = k ^ v1071 )
                {
                  k >>= 31;
                  if ( !k )
                    break;
                }
                v1080 = *v1062;
                v1081 = v1071 & 0x7FFFFFFF;
                if ( v1081 != (*v1062 & 0x7FFFFFFF) )
                {
                  if ( v1070 )
                  {
                    v1082 = 64i64;
                    if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
                    {
                      v1083 = KeGetCurrentIrql();
                      __writecr8(2ui64);
                      v1084 = v1064 & 0xFFFFFFFFFFFFF000ui64;
                      v1085 = (v1064 + v1070 - 1) | 0xFFF;
                      v1086 = (v1064 & 0xFFFFFFFFFFFFF000ui64) - 1;
                      while ( 1 )
                      {
                        v1087 = v1083;
                        while ( 1 )
                        {
                          v1088 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                                    v1084,
                                    0i64,
                                    v1082,
                                    v1066);
                          if ( v1088 != -1073741267 )
                            break;
                          if ( v1083 > 1u )
                            goto LABEL_1735;
                          v1087 = v1083;
                          __writecr8(v1083);
                          KeGetCurrentIrql();
                          __writecr8(2ui64);
                        }
                        if ( v1088 < 0 )
                          break;
LABEL_1735:
                        v1084 += 4096i64;
                        v1086 += 4096i64;
                        if ( v1086 == v1085 )
                        {
                          __writecr8(v1087);
                          v1062 = v1802;
                          v1063 = v1583;
                          goto LABEL_1737;
                        }
                      }
                      __writecr8(v1087);
                      v1062 = v1802;
                      v1064 = v1585;
                      v1063 = v1583;
                      v64 = (char *)v1579;
                      v1080 = *v1802;
                    }
                  }
                  v1090 = v1080;
                  if ( !*(_DWORD *)(v21 + 2240) )
                  {
                    LODWORD(v1090) = v1080 & 0x7FFFFFFF;
                    *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v1090 ^ v1081;
                    if ( !*(_DWORD *)(v21 + 2240) )
                    {
                      *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                      *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                      *(_QWORD *)(v21 + 2264) = *(int *)v64;
                      *(_QWORD *)(v21 + 2272) = v1064;
                      *(_DWORD *)(v21 + 2240) = 1;
                      __b9(v21, 0i64);
                      v1062 = v1802;
                    }
                  }
                }
              }
LABEL_1737:
              v64 = (char *)v1579;
              v1062 += 3;
              --v1063;
              v1802 = v1062;
              v1583 = v1063;
            }
            while ( v1063 );
            v1089 = v1587;
            ++*(_DWORD *)(v21 + 2028);
            v54 = (unsigned __int64)(v1089 + 6);
            v1587 = (unsigned int *)v54;
            if ( v54 == v1582 )
              goto LABEL_1745;
            if ( *(_DWORD *)(v21 + 2032) >= *(_DWORD *)(v21 + 2036) )
              goto LABEL_146;
          }
        }
        v54 = (unsigned int)(v77 - 31);
        if ( v77 != 31 )
        {
          if ( v77 == 32 )
          {
            sub_1403F3F04(v21, v64);
            goto LABEL_146;
          }
          if ( v77 == 33 )
          {
            sub_1403F2FCC(v21, v64);
            goto LABEL_146;
          }
          v54 = (unsigned int)(v77 - 35);
          if ( v77 != 35 )
          {
            if ( v77 == 36 )
            {
              v846 = (const char *)*((_QWORD *)v64 + 1);
              v847 = *((unsigned int *)v64 + 4);
              v848 = (__int64)v846;
              *(_DWORD *)(v21 + 2032) += v847;
              v849 = v846;
              v850 = *(_DWORD *)(v21 + 2012);
              for ( m = *(_QWORD *)(v21 + 2016); v849 < &v846[v847]; v849 += 64 )
                _mm_prefetch(v849, 0);
              v852 = *(_QWORD *)(v21 + 2016);
              v853 = (unsigned int)v847 >> 7;
              if ( (unsigned int)v847 >> 7 )
              {
                do
                {
                  v854 = 8i64;
                  do
                  {
                    v855 = *(_QWORD *)(v848 + 8) ^ __ROL8__(*(_QWORD *)v848 ^ v852, v850);
                    v848 += 16i64;
                    v852 = __ROL8__(v855, v850);
                    --v854;
                  }
                  while ( v854 );
                  v856 = (__ROL8__(m ^ (v848 - (_QWORD)v846), 17) ^ m ^ (unsigned __int64)(v848 - (_QWORD)v846))
                       * (unsigned __int128)0x7010008004002001ui64;
                  v1715 = *((_QWORD *)&v856 + 1);
                  v857 = v856 ^ BYTE8(v856) ^ v850;
                  v858 = 0xFFFFFFFFi64;
                  v850 = v857 & 0x3F;
                  if ( !v850 )
                    LOBYTE(v850) = 1;
                  --v853;
                }
                while ( v853 );
                v21 = (ULONG_PTR)v1580;
              }
              else
              {
                v858 = 0xFFFFFFFFi64;
              }
              v859 = v847 & 0x7F;
              if ( (unsigned int)v859 >= 8 )
              {
                v860 = (unsigned __int64)(unsigned int)v859 >> 3;
                do
                {
                  v852 = __ROL8__(*(_QWORD *)v848 ^ v852, v850);
                  v848 += 8i64;
                  v859 = (unsigned int)(v859 - 8);
                  --v860;
                }
                while ( v860 );
              }
              for ( ; (_DWORD)v859; v859 = (unsigned int)(v859 - 1) )
              {
                v861 = *(unsigned __int8 *)v848++;
                v852 = __ROL8__(v861 ^ v852, v850);
              }
              for ( n = v852; ; LODWORD(v852) = n ^ v852 )
              {
                n >>= 31;
                if ( !n )
                  break;
              }
              v863 = v852 & 0x7FFFFFFF;
              if ( v863 == *((_DWORD *)v64 + 5) )
                goto LABEL_1396;
              v859 = 0i64;
              if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
                v69 = 1;
              v864 = *((unsigned int *)v64 + 4);
              v858 = *((_QWORD *)v64 + 1);
              if ( *((_DWORD *)v64 + 4) )
              {
                v848 = 64i64;
                if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
                {
                  v865 = KeGetCurrentIrql();
                  __writecr8(2ui64);
                  v866 = v858 & 0xFFFFFFFFFFFFF000ui64;
                  v1796 = (v858 + v864 - 1) | 0xFFF;
                  v867 = (v858 & 0xFFFFFFFFFFFFF000ui64) - 1;
                  while ( 1 )
                  {
                    v868 = v865;
                    while ( 1 )
                    {
                      v869 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(v21 + 1112))(v866, 0i64);
                      v859 = 0i64;
                      if ( v869 != -1073741267 )
                        break;
                      if ( v69 )
                        goto LABEL_1392;
                      if ( v865 > 1u )
                        goto LABEL_1390;
                      v868 = v865;
                      __writecr8(v865);
                      KeGetCurrentIrql();
                      __writecr8(2ui64);
                    }
                    if ( v869 < 0 )
                      break;
LABEL_1390:
                    v866 += 4096i64;
                    v867 += 4096i64;
                    if ( v867 == v1796 )
                    {
                      __writecr8(v868);
                      v64 = (char *)v1579;
LABEL_1396:
                      v871 = *(_QWORD *)(v21 + 1304);
                      v872 = KeGetCurrentIrql();
                      __writecr8(0xFui64);
                      (*(void (__fastcall **)(__int64, __int64, __int64, __int64))(v21 + 320))(v871, v858, v859, v848);
                      v874 = **(unsigned int ***)(v21 + 1512);
                      v875 = v874 + 4;
                      v876 = *((_BYTE *)v874 + 12);
                      v877 = (unsigned __int64)&v874[6 * *v874 + 4];
                      do
                      {
                        v878 = 24i64;
                        v879 = (__int64 *)(v64 + 24);
                        v880 = v875;
                        do
                        {
                          v881 = *(_QWORD *)v880;
                          v880 += 2;
                          v882 = *v879++;
                          if ( v881 != v882 )
                            goto LABEL_1404;
                          v878 = (unsigned int)(v878 - 8);
                        }
                        while ( (unsigned int)v878 >= 8 );
                        if ( !(_DWORD)v878 )
                          break;
                        while ( 1 )
                        {
                          v873 = *(unsigned __int8 *)v880;
                          v880 = (unsigned int *)((char *)v880 + 1);
                          v883 = *(unsigned __int8 *)v879;
                          v879 = (__int64 *)((char *)v879 + 1);
                          if ( v873 != v883 )
                            break;
                          v73 = (_DWORD)v878 == 1;
                          v878 = (unsigned int)(v878 - 1);
                          if ( v73 )
                            goto LABEL_1405;
                        }
LABEL_1404:
                        v875 += 6;
                      }
                      while ( (unsigned __int64)v875 < v877 );
LABEL_1405:
                      v21 = (ULONG_PTR)v1580;
                      (*((void (__fastcall **)(_QWORD, __int64, __int64, __int64 *))v1580 + 48))(
                        *((_QWORD *)v1580 + 163),
                        v873,
                        v878,
                        v879);
                      __writecr8(v872);
                      if ( !v876 )
                        goto LABEL_2550;
                      if ( (*(_DWORD *)(v21 + 2396) & 0x10) != 0 && !*(_DWORD *)(v21 + 2240) )
                      {
                        *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                        *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                        *(_QWORD *)(v21 + 2264) = *(int *)v64;
                        *(_QWORD *)(v21 + 2272) = 1i64;
                        *(_DWORD *)(v21 + 2240) = 1;
                        __b9(v21, 0i64);
                      }
                      if ( *((_QWORD *)v64 + 3) != 1i64 )
                      {
LABEL_2550:
                        if ( v875 == (unsigned int *)v877 && !*(_DWORD *)(v21 + 2240) )
                        {
                          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                          *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                          *(_QWORD *)(v21 + 2264) = *(int *)v64;
                          *(_QWORD *)(v21 + 2272) = v875;
                          *(_DWORD *)(v21 + 2240) = 1;
                          __b9(v21, 0i64);
                        }
                      }
                      v884 = *(_QWORD *)(v21 + 1304);
                      v885 = KeGetCurrentIrql();
                      __writecr8(0xFui64);
                      (*(void (__fastcall **)(__int64))(v21 + 320))(v884);
                      v886 = **(unsigned int ***)(v21 + 1512);
                      v249 = v886 + 4;
                      v887 = 0i64;
                      v888 = (unsigned __int64)&v886[6 * *v886 + 4];
                      do
                      {
                        v249 += 6;
                        v890 = v887;
                        if ( (unsigned __int64)v249 >= v888 )
                          break;
                        v889 = *((_QWORD *)v249 + 1);
                        if ( v889 < v887 )
                          break;
                        if ( (v889 & 0xFFFFFFFFFFFFF000ui64) != v889 )
                          break;
                        v887 = v889 + v249[4];
                        if ( v887 <= v889 )
                          break;
                      }
                      while ( v887 != v890 );
                      (*(void (__fastcall **)(_QWORD, unsigned __int64))(v21 + 384))(*(_QWORD *)(v21 + 1304), v890);
                      __writecr8(v885);
                      if ( v249 == (unsigned int *)v888 || *(_DWORD *)(v21 + 2240) )
                        goto LABEL_146;
                      v258 = v21 - 0x5C5FC0A76E374B18i64;
LABEL_481:
                      *(_QWORD *)(v21 + 2248) = v258;
                      *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                      *(_QWORD *)(v21 + 2264) = *(int *)v64;
                      *(_QWORD *)(v21 + 2272) = v249;
                      goto LABEL_1131;
                    }
                  }
LABEL_1392:
                  __writecr8(v868);
                  v64 = (char *)v1579;
                }
              }
              if ( !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v863 ^ (unsigned __int64)*((unsigned int *)v64 + 5);
                v870 = *((_QWORD *)v64 + 1);
                if ( !*(_DWORD *)(v21 + 2240) )
                {
                  *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                  *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                  *(_QWORD *)(v21 + 2264) = *(int *)v64;
                  *(_QWORD *)(v21 + 2272) = v870;
                  *(_DWORD *)(v21 + 2240) = 1;
                  __b9(v21, 0i64);
                }
              }
              goto LABEL_1396;
            }
LABEL_2294:
            v1415 = v77 - 2;
            if ( v1415 )
            {
              v1416 = v1415 - 1;
              if ( !v1416 )
              {
                (*(void (__fastcall **)(char *, _QWORD))(v21 + 400))(v1756, *((unsigned int *)v64 + 10));
                (*(void (__fastcall **)(char *, char *))(v21 + 448))(v1756, v1757);
                KiGetGdtIdt(&v1649, v1772);
                v1430 = v1650;
                v1431 = *((unsigned int *)v64 + 4);
                if ( (*(_BYTE *)(v21 + 2115) & 2) != 0 )
                {
                  v1432 = *(_QWORD *)(v21 + 2216);
                  v1433 = 38i64;
                  v1434 = 304;
                  v1435 = (_QWORD *)v1432;
                  do
                  {
                    *v1435 = 0i64;
                    v1434 -= 8;
                    ++v1435;
                    --v1433;
                  }
                  while ( v1433 );
                  if ( v1434 )
                  {
                    v1433 = 0xFFFFFFFFi64;
                    do
                    {
                      *(_BYTE *)v1435 = 0;
                      v1435 = (_QWORD *)((char *)v1435 + 1);
                      --v1434;
                    }
                    while ( v1434 );
                  }
                  *(_OWORD *)(v1432 + 16) = *(_OWORD *)(v21 + 2064);
                  *(_OWORD *)(v1432 + 32) = *(_OWORD *)(v21 + 2080);
                  *(_OWORD *)(v1432 + 288) = *(_OWORD *)(v21 + 2096);
                  v1665[0] = 303;
                  *(_QWORD *)&v1665[1] = v1432;
                  *(_WORD *)(v1432 + 16) = v21 + 2112;
                  v1752 = v21 + 2112;
                  *(_WORD *)(v1432 + 22) = (unsigned int)(v21 + 2112) >> 16;
                  *(_DWORD *)(v1432 + 24) = (v21 + 2112) >> 32;
                  _disable();
                  __sidt(v1687);
                  __lidt(v1665);
                  __writedr(7u, 0i64);
                  *(_WORD *)(v1432 + 16) = v21 + 2118;
                  v1436 = (v21 + 2118) >> 16;
                  *(_WORD *)(v1432 + 22) = v1436;
                  *(_DWORD *)(v1432 + 24) = (v21 + 2118) >> 32;
                  if ( (*(_BYTE *)(v21 + 2115) & 0x20) != 0 )
                  {
                    *(_WORD *)(v21 + 2162) = KiGetSs(v1436, v1432, v1433, 1i64);
                    __writedr(0, v21 + 2162);
                    __writedr(7u, 0x70001ui64);
                    *(_QWORD *)(v21 + 2224) = KiErrataSkx55Present(v21 + 2162);
                    __writedr(7u, 0i64);
                    __writedr(0, 0i64);
                  }
                  else
                  {
                    *(_QWORD *)(v21 + 2224) = KiErrata704Present(v1436, v1432, v1433, 1i64);
                  }
                  *(_DWORD *)(v21 + 2232) = KeGetPcr()->Prcb.Number;
                  __lidt(v1687);
                  _enable();
                }
                Ldtr = (unsigned __int16)KiGetLdtr();
                Tr = KiGetTr();
                *(_DWORD *)(v21 + 2032) += v1431;
                v1439 = v1430 + v1431;
                v1440 = *(unsigned int *)(v21 + 2012);
                v1441 = Tr;
                v1442 = *(_QWORD *)(v21 + 2016);
                v1443 = (_QWORD *)v1430;
                v1808 = Tr;
                v1444 = (const char *)v1430;
                if ( v1430 < (unsigned __int64)(v1430 + v1431) )
                {
                  do
                  {
                    _mm_prefetch(v1444, 0);
                    v1444 += 64;
                  }
                  while ( (unsigned __int64)v1444 < v1439 );
                }
                v1445 = *(_QWORD *)(v21 + 2016);
                v1446 = (unsigned int)v1431 >> 7;
                if ( (unsigned int)v1431 >> 7 )
                {
                  do
                  {
                    v1447 = 8i64;
                    do
                    {
                      v1448 = v1445 ^ *v1443;
                      v1449 = v1443[1];
                      v1443 += 2;
                      v1445 = __ROL8__(__ROL8__(v1448, v1440) ^ v1449, v1440);
                      --v1447;
                    }
                    while ( v1447 );
                    v1450 = __ROL8__(v1442 ^ ((unsigned __int64)v1443 - v1430), 17) ^ v1442 ^ ((unsigned __int64)v1443
                                                                                             - v1430);
                    v1439 = (v1450 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                    v1733 = v1439;
                    v1440 = ((unsigned __int8)v1439 ^ (unsigned __int8)(v1450 ^ v1440)) & 0x3F;
                    if ( !(_DWORD)v1440 )
                      v1440 = 1i64;
                    --v1446;
                  }
                  while ( v1446 );
                  v21 = (ULONG_PTR)v1580;
                  v1441 = v1808;
                }
                v1451 = v1431 & 0x7F;
                if ( v1451 >= 8 )
                {
                  v1439 = (unsigned __int64)v1451 >> 3;
                  do
                  {
                    v1445 = __ROL8__(*v1443++ ^ v1445, v1440);
                    v1451 -= 8;
                    --v1439;
                  }
                  while ( v1439 );
                }
                if ( v1451 )
                {
                  do
                  {
                    v1452 = *(unsigned __int8 *)v1443;
                    v1443 = (_QWORD *)((char *)v1443 + 1);
                    v1445 = __ROL8__(v1452 ^ v1445, v1440);
                    --v1451;
                  }
                  while ( v1451 );
                  v21 = (ULONG_PTR)v1580;
                }
                for ( ii = v1445; ; LODWORD(v1445) = ii ^ v1445 )
                {
                  ii >>= 31;
                  if ( !ii )
                    break;
                }
                v1454 = v1445 & 0x7FFFFFFF;
                (*(void (__fastcall **)(char *, unsigned __int64, _QWORD *, __int64))(v21 + 392))(
                  v1757,
                  v1439,
                  v1443,
                  v1440);
                if ( v1454 != *((_DWORD *)v64 + 5) || v1649 != *((_WORD *)v64 + 22) || (_WORD)Ldtr || v1441 != 64 )
                {
                  if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
                  {
                    v1455 = *(_QWORD **)(v21 + 2632);
                    v1456 = 48;
                    v1457 = 6i64;
                    do
                    {
                      v1456 -= 8;
                      *v1455 = *(_QWORD *)v64;
                      v64 += 8;
                      ++v1455;
                      --v1457;
                    }
                    while ( v1457 );
                    if ( v1456 )
                    {
                      do
                      {
                        v1458 = *v64++;
                        *(_BYTE *)v1455 = v1458;
                        v1455 = (_QWORD *)((char *)v1455 + 1);
                        --v1456;
                      }
                      while ( v1456 );
                      v21 = (ULONG_PTR)v1580;
                    }
                    v64 = *(char **)(v21 + 2632);
                  }
                  *((_QWORD *)v64 + 3) = v1650;
                  *((_QWORD *)v64 + 4) = v1454;
                  if ( (_WORD)Ldtr )
                  {
                    *((_QWORD *)v64 + 3) = Ldtr;
                  }
                  else if ( v1441 != 64 )
                  {
                    *((_QWORD *)v64 + 3) = v1441;
                  }
                  v1459 = *(_DWORD *)(v21 + 2240);
                  if ( !v1459 )
                  {
                    *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = *((unsigned int *)v64 + 5) ^ (unsigned __int64)v1454;
                    v1459 = *(_DWORD *)(v21 + 2240);
                  }
                  v54 = *((_QWORD *)v64 + 1);
                  if ( !v1459 )
                  {
                    *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                    *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                    *(_QWORD *)(v21 + 2264) = *(int *)v64;
                    *(_QWORD *)(v21 + 2272) = v54;
                    *(_DWORD *)(v21 + 2240) = 1;
                    __b9(v21, 0i64);
                  }
                }
                *(_DWORD *)(v21 + 2032) += 0x8000;
                goto LABEL_146;
              }
              if ( v1416 != 20 )
              {
                if ( *(_DWORD *)(v21 + 2240) )
                  goto LABEL_146;
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = 257i64;
LABEL_1804:
                *(_QWORD *)(v21 + 2272) = 0i64;
                goto LABEL_1131;
              }
              (*(void (__fastcall **)(char *, _QWORD))(v21 + 400))(v1754, *((unsigned int *)v64 + 10));
              (*(void (__fastcall **)(char *, char *))(v21 + 448))(v1754, v1755);
              v1417 = *(_QWORD *)(v21 + 2520);
              if ( v1417 )
              {
                v1418 = *(_DWORD *)(v1417 + 800);
                v1419 = *(_QWORD *)(v21 + 2520);
                if ( v1419 )
                {
                  v1420 = *(_DWORD *)(v1419 + 832);
LABEL_2304:
                  (*(void (__fastcall **)(char *))(v21 + 392))(v1755);
                  if ( (*(_BYTE *)(v21 + 2115) & 0x10) != 0 )
                  {
                    _disable();
                    v1422 = *(_QWORD *)(v21 + 2216);
                    v1423 = 304;
                    v1424 = (_QWORD *)v1422;
                    v1425 = 38i64;
                    do
                    {
                      *v1424 = 0i64;
                      v1423 -= 8;
                      ++v1424;
                      --v1425;
                    }
                    while ( v1425 );
                    for ( ; v1423; --v1423 )
                    {
                      *(_BYTE *)v1424 = 0;
                      v1424 = (_QWORD *)((char *)v1424 + 1);
                    }
                    *(_OWORD *)(v1422 + 16) = *(_OWORD *)(v21 + 2064);
                    *(_OWORD *)(v1422 + 32) = *(_OWORD *)(v21 + 2080);
                    *(_OWORD *)(v1422 + 288) = *(_OWORD *)(v21 + 2096);
                    v1664[0] = 303;
                    *(_QWORD *)&v1664[1] = v1422;
                    *(_WORD *)(v1422 + 16) = v21 + 2112;
                    v1731 = v21 + 2112;
                    *(_WORD *)(v1422 + 22) = (unsigned int)(v21 + 2112) >> 16;
                    *(_DWORD *)(v1422 + 24) = (v21 + 2112) >> 32;
                    __sidt(v1686);
                    __lidt(v1664);
                    if ( (*(_DWORD *)(v21 + 2396) & 0x20000) == 0 )
                    {
                      CurrentPrcb = KeGetCurrentPrcb();
                      **(_QWORD **)(v21 + 1176) = v21 - 0x5C5FC0A76E374B18i64;
                      **(_QWORD **)(v21 + 1184) = CurrentPrcb;
                      **(_QWORD **)(v21 + 1192) = 0i64;
                      **(_QWORD **)(v21 + 1200) = 277i64;
                    }
                    KiErrata361Present();
                    if ( (*(_DWORD *)(v21 + 2396) & 0x20000) == 0 )
                    {
                      **(_QWORD **)(v21 + 1176) = 0xA3A03F5891C8B4E8ui64;
                      **(_QWORD **)(v21 + 1184) = 0i64;
                      **(_QWORD **)(v21 + 1192) = 0i64;
                      **(_QWORD **)(v21 + 1200) = 0i64;
                    }
                    __lidt(v1686);
                    _enable();
                  }
                  v1427 = *((unsigned int *)v64 + 6);
                  if ( (v1418 & *((_DWORD *)v64 + 7)) != (_DWORD)v1427
                    || (v1418 & 0x10000) == 0 && (_BYTE)v1418 != 0xD1 && (unsigned __int8)(v1418 + 3) > 1u )
                  {
                    v1428 = v1427 | ((unsigned __int64)*((unsigned int *)v64 + 10) << 48) | 0x32000000000i64;
                    if ( !*(_DWORD *)(v21 + 2240) )
                    {
                      *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v1418 ^ v1427;
                      if ( !*(_DWORD *)(v21 + 2240) )
                      {
                        *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                        *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                        *(_QWORD *)(v21 + 2264) = *(int *)v64;
                        *(_QWORD *)(v21 + 2272) = v1428;
                        *(_DWORD *)(v21 + 2240) = 1;
                        __b9(v21, 0i64);
                      }
                    }
                  }
                  v54 = *((unsigned int *)v64 + 8);
                  if ( (v1420 & *((_DWORD *)v64 + 9)) != (_DWORD)v54
                    || (v1420 & 0x10000) == 0 && (_BYTE)v1420 != 0xD1 && (unsigned __int8)(v1420 + 3) > 1u )
                  {
                    v1429 = v54 | ((unsigned __int64)*((unsigned int *)v64 + 10) << 48) | 0x34000000000i64;
                    if ( !*(_DWORD *)(v21 + 2240) )
                    {
                      v54 ^= v1420;
                      *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v54;
                      if ( !*(_DWORD *)(v21 + 2240) )
                      {
                        *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                        *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                        *(_QWORD *)(v21 + 2264) = *(int *)v64;
                        *(_QWORD *)(v21 + 2272) = v1429;
                        *(_DWORD *)(v21 + 2240) = 1;
                        __b9(v21, 0i64);
                      }
                    }
                  }
                  *(_DWORD *)(v21 + 2032) += 0x8000;
                  goto LABEL_146;
                }
              }
              else
              {
                v1418 = __readmsr(0x832u);
              }
              v1421 = __readmsr(0x834u);
              v1420 = v1421;
              goto LABEL_2304;
            }
            v1460 = *((unsigned int *)v64 + 10);
            v1461 = *(void (__fastcall **)(char *, __int64))(v21 + 400);
            v1586 = 0;
            v1461(v1758, v1460);
            (*(void (__fastcall **)(char *, char *))(v21 + 448))(v1758, v1759);
            KiGetGdtIdt(v1771, &v1666);
            v1462 = 0;
            v1595 = v1667;
            v1463 = (__int16 *)(v1667 + 4);
            v1583 = v1667 + 4;
            v1581 = 0;
            while ( 2 )
            {
              v1464 = 0i64;
              v1616 = *(_QWORD *)(v21 + 2192);
              v1465 = 0i64;
              v1466 = *(_QWORD *)(v21 + 2200);
              v1467 = *(unsigned int *)(v21 + 2168);
              v1582 = 0i64;
              v1468 = *(unsigned int *)(v21 + 2164);
              v1585 = 0i64;
              v1469 = KeGetCurrentIrql();
              __writecr8(0xFui64);
              v1470 = *v1463;
              LOWORD(v1625) = *(v1463 - 2);
              WORD1(v1625) = v1463[1];
              v1471 = *((_DWORD *)v1463 + 1);
              v1472 = *(_QWORD *)(v21 + 1520);
              HIDWORD(v1625) = v1471;
              v1473 = v1625;
              v1809 = v1470;
              v1474 = v1472 + 8i64 * v1462;
              if ( v1625 == v1474 )
              {
                if ( (v1470 & 0x6000) != 0 )
                {
                  __writecr8(v1469);
                  goto LABEL_2385;
                }
                v1465 = *(_QWORD *)(*(__int64 (__fastcall **)(_QWORD, __int64, _QWORD))(v21 + 1120))(v1462, v1474, 0i64);
                if ( v1465 )
                {
                  v1475 = *(_DWORD **)(v1468 + v1465);
                  v1582 = (unsigned __int64)v1475;
                  if ( v1581 < 0x30 )
                  {
                    __writecr8(v1469);
LABEL_2384:
                    v1464 = (_DWORD *)v1582;
LABEL_2385:
                    v1476 = *(_QWORD *)(v21 + 1384);
                    *(_QWORD *)v1476 = v1473;
                    *(_DWORD *)(v1476 + 16) = 128;
                    if ( v1464 )
                    {
                      v1477 = *(_QWORD *)(v21 + 1384);
                      *(_QWORD *)(v1477 + 8) = v1464;
                      *(_DWORD *)(v1477 + 20) = 128;
                    }
                    v1586 = 1;
                    goto LABEL_2404;
                  }
                  v1478 = *(_QWORD *)(v1467 + v1465);
LABEL_2392:
                  __writecr8(v1469);
                  if ( !v1465 )
                  {
                    if ( v1473 < v1616 )
                      goto LABEL_2384;
                    if ( v1473 > v1466 )
                      goto LABEL_2384;
                    v1479 = (*(__int64 (__fastcall **)(_QWORD, unsigned __int64, _QWORD))(v21 + 512))(
                              *(_QWORD *)(v21 + 2208),
                              v1616,
                              (unsigned int)(v1625 - v1616));
                    if ( !v1479 || (*(_DWORD *)(v1479 + 36) & 0x2000000) != 0 )
                      goto LABEL_2384;
                  }
                  if ( *(_WORD *)(v1583 - 2) != 16 || (*(_WORD *)v1583 & 0x1F00) != 3584 || *(__int16 *)v1583 >= 0 )
                    goto LABEL_2384;
                  v1480 = (unsigned int *)(*(__int64 (__fastcall **)(unsigned __int64, unsigned __int64 *, _QWORD))(v21 + 592))(
                                            v1473,
                                            &v1616,
                                            0i64);
                  if ( v1480 && v1616 + *v1480 == v1473 && v1616 == *(_QWORD *)(v21 + 2192) )
                  {
                    if ( !v1465 )
                      goto LABEL_2404;
                  }
                  else if ( !v1465 )
                  {
                    goto LABEL_2384;
                  }
                  if ( (v1809 & 0x6000) != 0 )
                    goto LABEL_2384;
                  if ( v1465 != -1 )
                  {
                    v1503 = (unsigned int *)(*(__int64 (__fastcall **)(_DWORD *, unsigned __int64 *, _QWORD))(v21 + 592))(
                                              v1475,
                                              &v1616,
                                              0i64);
                    if ( !v1503 )
                      goto LABEL_2384;
                    if ( (_DWORD *)(v1616 + *v1503) != v1475 )
                      goto LABEL_2384;
                    if ( v1616 != *(_QWORD *)(v21 + 2192) )
                      goto LABEL_2384;
                    v1504 = (*(__int64 (__fastcall **)(_QWORD, unsigned __int64, _QWORD))(v21 + 512))(
                              *(_QWORD *)(v21 + 2208),
                              v1616,
                              (unsigned int)((_DWORD)v1475 - v1616));
                    if ( !v1504
                      || (*(_DWORD *)(v1504 + 36) & 0x2000000) != 0
                      || v1581 == 254 && v1478 != *(_QWORD *)(v21 + 2176) )
                    {
                      goto LABEL_2384;
                    }
                  }
LABEL_2404:
                  v1462 = v1581 + 1;
                  v1463 = (__int16 *)(v1583 + 16);
                  v1581 = v1462;
                  v1583 += 16i64;
                  if ( v1462 > 0xFF )
                  {
                    if ( (*(_BYTE *)(v21 + 2115) & 1) != 0 )
                    {
                      _disable();
                      v1481 = 3221225602i64;
                      v1482 = __readmsr(0xC0000082);
                      v1483 = (v21 + 2114) >> 32;
                      __writemsr(0xC0000082, v21 + 2114);
                      if ( !_bittest((const signed __int32 *)(v21 + 2396), 0x11u) )
                      {
                        v1484 = KeGetCurrentPrcb();
                        v1483 = v21 - 0x5C5FC0A76E374B18i64;
                        **(_QWORD **)(v21 + 1176) = v21 - 0x5C5FC0A76E374B18i64;
                        **(_QWORD **)(v21 + 1184) = v1484;
                        **(_QWORD **)(v21 + 1192) = 3221225602i64;
                        v1481 = *(_QWORD *)(v21 + 1200);
                        *(_QWORD *)v1481 = 274i64;
                      }
                      ((void (__fastcall *)(__int64, unsigned __int64))(v21 + 2116))(v1481, v1483);
                      if ( !_bittest((const signed __int32 *)(v21 + 2396), 0x11u) )
                      {
                        **(_QWORD **)(v21 + 1176) = 0xA3A03F5891C8B4E8ui64;
                        **(_QWORD **)(v21 + 1184) = 0i64;
                        **(_QWORD **)(v21 + 1192) = 0i64;
                        **(_QWORD **)(v21 + 1200) = 0i64;
                      }
                      __writemsr(0xC0000082, v1482);
                      _enable();
                    }
                    v1485 = v1595;
                    *(_DWORD *)(v21 + 2032) += 848;
                    v1486 = (_QWORD *)v1485;
                    v1487 = *(_DWORD *)(v21 + 2032);
                    v1488 = (const char *)v1485;
                    v1489 = *(_DWORD *)(v21 + 2012);
                    v1490 = *(_QWORD *)(v21 + 2016);
                    if ( v1485 < (unsigned __int64)(v1485 + 848) )
                    {
                      do
                      {
                        _mm_prefetch(v1488, 0);
                        v1488 += 64;
                      }
                      while ( (unsigned __int64)v1488 < v1485 + 848 );
                    }
                    v1491 = 6;
                    v1492 = *(_QWORD *)(v21 + 2016);
                    do
                    {
                      v1493 = 8i64;
                      do
                      {
                        v1494 = v1492 ^ *v1486;
                        v1495 = v1486 + 1;
                        v1496 = *v1495;
                        v1486 = v1495 + 1;
                        v1492 = __ROL8__(__ROL8__(v1494, v1489) ^ v1496, v1489);
                        --v1493;
                      }
                      while ( v1493 );
                      v1497 = __ROL8__(v1490 ^ ((unsigned __int64)v1486 - v1485), 17) ^ v1490 ^ ((unsigned __int64)v1486
                                                                                               - v1485);
                      v1734 = (v1497 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                      v1489 = ((unsigned __int8)(v1734 ^ v1497) ^ (unsigned __int8)v1489) & 0x3F;
                      if ( !v1489 )
                        LOBYTE(v1489) = 1;
                      --v1491;
                    }
                    while ( v1491 );
                    v1498 = v1586;
                    v1499 = 80;
                    v1500 = 10i64;
                    do
                    {
                      v1492 = __ROL8__(*v1486++ ^ v1492, v1489);
                      v1499 -= 8;
                      --v1500;
                    }
                    while ( v1500 );
                    if ( v1499 )
                    {
                      do
                      {
                        v1501 = *(unsigned __int8 *)v1486;
                        v1486 = (_QWORD *)((char *)v1486 + 1);
                        v1492 = __ROL8__(v1501 ^ v1492, v1489);
                        --v1499;
                      }
                      while ( v1499 );
                      v1498 = v1586;
                    }
                    for ( jj = v1492; ; LODWORD(v1492) = jj ^ v1492 )
                    {
                      jj >>= 31;
                      if ( !jj )
                        break;
                    }
                    v1505 = v1492 & 0x7FFFFFFF;
                    *(_DWORD *)(v21 + 2032) = v1487 + 16;
                    v1506 = (_QWORD *)(v1485 + 3600);
                    v1507 = *(_DWORD *)(v21 + 2012);
                    v1508 = *(_QWORD *)(v21 + 2016);
                    v1509 = (const char *)(v1485 + 3600);
                    if ( v1485 + 3600 < (unsigned __int64)(v1485 + 3616) )
                    {
                      do
                      {
                        _mm_prefetch(v1509, 0);
                        v1509 += 64;
                      }
                      while ( (unsigned __int64)v1509 < v1485 + 3616 );
                    }
                    v1510 = 2i64;
                    v1511 = 16;
                    do
                    {
                      v1508 = __ROL8__(*v1506++ ^ v1508, v1507);
                      v1511 -= 8;
                      --v1510;
                    }
                    while ( v1510 );
                    if ( v1511 )
                    {
                      do
                      {
                        v1512 = *(unsigned __int8 *)v1506;
                        v1506 = (_QWORD *)((char *)v1506 + 1);
                        v1508 = __ROL8__(v1512 ^ v1508, v1507);
                        --v1511;
                      }
                      while ( v1511 );
                      v1498 = v1586;
                    }
                    for ( kk = v1508; ; LODWORD(v1508) = kk ^ v1508 )
                    {
                      kk >>= 31;
                      if ( !kk )
                        break;
                    }
                    v1514 = v1508 & 0x7FFFFFFF;
                    (*(void (__fastcall **)(char *, _QWORD *))(v21 + 392))(v1759, v1506);
                    v1515 = v1579;
                    v1516 = (unsigned int)v1579[5];
                    if ( v1505 != (_DWORD)v1516
                      || v1514 != *((_QWORD *)v1579 + 3)
                      || v1666 != *((_WORD *)v1579 + 22)
                      || v1498 )
                    {
                      if ( !v1498 )
                      {
                        if ( v1514 == *((_QWORD *)v1579 + 3) )
                        {
                          if ( !*(_DWORD *)(v21 + 2240) )
                          {
                            v1517 = v1516 ^ v1505;
                            goto LABEL_2458;
                          }
                        }
                        else if ( !*(_DWORD *)(v21 + 2240) )
                        {
                          v1517 = v1514 ^ (unsigned __int64)(unsigned int)v1579[6];
LABEL_2458:
                          *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v1517;
                        }
                      }
                      v54 = *((_QWORD *)v1515 + 1);
                      if ( !*(_DWORD *)(v21 + 2240) )
                      {
                        *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                        *(_QWORD *)(v21 + 2256) = (char *)v1515 - 0x4C48B4211BBACBEBi64;
                        *(_QWORD *)(v21 + 2264) = *v1515;
                        *(_QWORD *)(v21 + 2272) = v54;
                        *(_DWORD *)(v21 + 2240) = 1;
                        __b9(v21, 0i64);
                      }
                    }
                    *(_DWORD *)(v21 + 2032) += 0x10000;
                    goto LABEL_146;
                  }
                  continue;
                }
                v1465 = -1i64;
                v1478 = 0i64;
              }
              else
              {
                v1478 = v1585;
              }
              break;
            }
            v1475 = (_DWORD *)v1582;
            goto LABEL_2392;
          }
          v54 = *((_DWORD *)v64 + 10) & 1;
          if ( (*((_DWORD *)v64 + 10) & 1) == 0 )
            goto LABEL_1481;
          if ( !*(_QWORD *)(v21 + 2376) )
            goto LABEL_1745;
          v891 = *(_DWORD *)(v21 + 2396);
          if ( (v891 & 4) != 0 )
            goto LABEL_1745;
          if ( (_DWORD)v54 )
          {
            v892 = *(_DWORD *)(v21 + 2028);
            if ( v892 )
            {
              v54 = v891;
              if ( (((unsigned __int8)v891 ^ (unsigned __int8)(v891 >> 3)) & 4) != 0 )
                goto LABEL_1745;
            }
            else
            {
              LODWORD(v54) = v891 ^ ((unsigned __int8)v891 ^ (unsigned __int8)(8 * v891)) & 0x20;
              *(_DWORD *)(v21 + 2396) = v54;
            }
            if ( !*(_QWORD *)(v21 + 2376) )
              goto LABEL_1480;
            if ( !v892 )
            {
              v893 = v54 ^ ((unsigned __int8)v54 ^ (unsigned __int8)(8 * v54)) & 0x20;
              *(_DWORD *)(v21 + 2396) = v893;
              goto LABEL_1433;
            }
            LOBYTE(v893) = v54;
            if ( (((unsigned __int8)v54 ^ (unsigned __int8)((unsigned int)v54 >> 3)) & 4) != 0 )
            {
LABEL_1480:
              *(_DWORD *)(v21 + 2028) = 0;
              goto LABEL_1440;
            }
LABEL_1433:
            if ( (v893 & 4) != 0 )
            {
              v894 = *((_QWORD *)v64 + 1) & 0xFFFFFFFFFFFFF000ui64;
              v895 = ((*((_DWORD *)v64 + 2) & 0xFFF) + (unsigned __int64)*((unsigned int *)v64 + 4) + 4095) >> 12;
              while ( v895 )
              {
                --v895;
                if ( (*(unsigned __int8 (__fastcall **)(unsigned __int64))(v21 + 672))(v894) && !*(_DWORD *)(v21 + 2240) )
                {
                  *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                  *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                  *(_QWORD *)(v21 + 2264) = *(int *)v64;
                  *(_QWORD *)(v21 + 2272) = v894;
                  *(_DWORD *)(v21 + 2240) = 1;
                  __b9(v21, 0i64);
                }
                v894 += 4096i64;
                *(_DWORD *)(v21 + 2032) += 256;
              }
LABEL_1440:
              v896 = v1579;
              v54 = 2i64;
              v897 = v1579[10];
              if ( (v897 & 2) == 0 )
                goto LABEL_146;
              v898 = *((_QWORD *)v1579 + 1);
              if ( (v897 & 4) != 0 )
              {
                v899 = *((_QWORD *)v1579 + 3);
                v54 = **(_QWORD **)(v898 + 112);
                if ( v54 != v899 )
                {
                  v900 = *(_QWORD *)(v21 + 1384);
                  *(_QWORD *)v900 = v54;
                  *(_DWORD *)(v900 + 16) = 256;
                  if ( !*(_DWORD *)(v21 + 2240) )
                  {
                    *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v899 ^ v54;
                    v54 = *(_QWORD *)(v898 + 112);
                    if ( !*(_DWORD *)(v21 + 2240) )
                    {
                      *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                      *(_QWORD *)(v21 + 2256) = (char *)v896 - 0x4C48B4211BBACBEBi64;
                      *(_QWORD *)(v21 + 2264) = *v896;
                      *(_QWORD *)(v21 + 2272) = v54;
                      *(_DWORD *)(v21 + 2240) = 1;
                      __b9(v21, 0i64);
                    }
                  }
                }
              }
              if ( (v896[10] & 8) == 0 )
                goto LABEL_146;
              v951 = *((_QWORD *)v896 + 4);
              v54 = **(_QWORD **)(v898 + 120);
              if ( v54 == v951 )
                goto LABEL_146;
              v952 = *(_QWORD *)(v21 + 1384);
              *(_QWORD *)v952 = v54;
              *(_DWORD *)(v952 + 16) = 256;
              if ( *(_DWORD *)(v21 + 2240) )
                goto LABEL_146;
              *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v951 ^ v54;
              v54 = *(_QWORD *)(v898 + 120);
              if ( *(_DWORD *)(v21 + 2240) )
                goto LABEL_146;
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = (char *)v896 - 0x4C48B4211BBACBEBi64;
              v707 = *v896;
              goto LABEL_1130;
            }
            v901 = (_QWORD *)*((_QWORD *)v64 + 1);
            v902 = *((unsigned int *)v64 + 4);
            v903 = v901;
            *(_DWORD *)(v21 + 2032) += v902;
            v904 = (const char *)v901;
            v905 = *(_DWORD *)(v21 + 2012);
            v906 = *(_QWORD *)(v21 + 2016);
            if ( v901 < (_QWORD *)((char *)v901 + v902) )
            {
              do
              {
                _mm_prefetch(v904, 0);
                v904 += 64;
              }
              while ( v904 < (const char *)v901 + v902 );
            }
            v907 = *(_QWORD *)(v21 + 2016);
            v908 = (unsigned int)v902 >> 7;
            if ( (unsigned int)v902 >> 7 )
            {
              do
              {
                v909 = 8i64;
                do
                {
                  v910 = v907 ^ *v903;
                  v911 = v903[1];
                  v903 += 2;
                  v907 = __ROL8__(__ROL8__(v910, v905) ^ v911, v905);
                  --v909;
                }
                while ( v909 );
                v912 = __ROL8__(v906 ^ ((char *)v903 - (char *)v901), 17) ^ v906 ^ ((char *)v903 - (char *)v901);
                v1716 = (v912 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                v905 = ((unsigned __int8)v912 ^ (unsigned __int8)(v1716 ^ v905)) & 0x3F;
                if ( !v905 )
                  LOBYTE(v905) = 1;
                --v908;
              }
              while ( v908 );
              v21 = (ULONG_PTR)v1580;
            }
            v913 = v902 & 0x7F;
            if ( v913 >= 8 )
            {
              v914 = (unsigned __int64)v913 >> 3;
              do
              {
                v907 = __ROL8__(*v903++ ^ v907, v905);
                v913 -= 8;
                --v914;
              }
              while ( v914 );
            }
            if ( v913 )
            {
              do
              {
                v915 = *(unsigned __int8 *)v903;
                v903 = (_QWORD *)((char *)v903 + 1);
                v907 = __ROL8__(v915 ^ v907, v905);
                --v913;
              }
              while ( v913 );
              v21 = (ULONG_PTR)v1580;
            }
            for ( mm = v907; ; LODWORD(v907) = mm ^ v907 )
            {
              mm >>= 31;
              if ( !mm )
                break;
            }
            v917 = *((_DWORD *)v64 + 5);
            v918 = v907 & 0x7FFFFFFF;
            if ( v918 == v917 )
              goto LABEL_1440;
            v919 = *((unsigned int *)v64 + 4);
            v920 = *((_QWORD *)v64 + 1);
            if ( *((_DWORD *)v64 + 4) && (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
            {
              v921 = KeGetCurrentIrql();
              __writecr8(2ui64);
              v922 = v920 & 0xFFFFFFFFFFFFF000ui64;
              v923 = (v920 + v919 - 1) | 0xFFF;
              v924 = (v920 & 0xFFFFFFFFFFFFF000ui64) - 1;
              while ( 1 )
              {
                v925 = v921;
                while ( 1 )
                {
                  v926 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(v21 + 1112))(v922, 0i64);
                  if ( v926 != -1073741267 )
                    break;
                  if ( v921 > 1u )
                    goto LABEL_1473;
                  v925 = v921;
                  __writecr8(v921);
                  KeGetCurrentIrql();
                  __writecr8(2ui64);
                }
                if ( v926 < 0 )
                  break;
LABEL_1473:
                v922 += 4096i64;
                v924 += 4096i64;
                if ( v924 == v923 )
                  goto LABEL_1474;
              }
              __writecr8(v925);
              v64 = (char *)v1579;
              v917 = v1579[5];
            }
            if ( *(_DWORD *)(v21 + 2240) )
              goto LABEL_1440;
            v927 = v917;
          }
          else
          {
LABEL_1481:
            v929 = (_QWORD *)*((_QWORD *)v64 + 1);
            v930 = *((unsigned int *)v64 + 4);
            v931 = v929;
            *(_DWORD *)(v21 + 2032) += v930;
            v932 = (const char *)v929;
            v933 = *(_DWORD *)(v21 + 2012);
            v934 = *(_QWORD *)(v21 + 2016);
            if ( v929 < (_QWORD *)((char *)v929 + v930) )
            {
              do
              {
                _mm_prefetch(v932, 0);
                v932 += 64;
              }
              while ( v932 < (const char *)v929 + v930 );
            }
            v935 = *(_QWORD *)(v21 + 2016);
            v936 = (unsigned int)v930 >> 7;
            if ( (unsigned int)v930 >> 7 )
            {
              do
              {
                v937 = 8i64;
                do
                {
                  v938 = v931[1] ^ __ROL8__(*v931 ^ v935, v933);
                  v931 += 2;
                  v935 = __ROL8__(v938, v933);
                  --v937;
                }
                while ( v937 );
                v939 = (__ROL8__(v934 ^ ((char *)v931 - (char *)v929), 17) ^ v934 ^ (unsigned __int64)((char *)v931 - (char *)v929))
                     * (unsigned __int128)0x7010008004002001ui64;
                v1717 = *((_QWORD *)&v939 + 1);
                v933 = ((unsigned __int8)v939 ^ (unsigned __int8)(BYTE8(v939) ^ v933)) & 0x3F;
                if ( !v933 )
                  LOBYTE(v933) = 1;
                --v936;
              }
              while ( v936 );
              v21 = (ULONG_PTR)v1580;
            }
            v940 = v930 & 0x7F;
            if ( v940 >= 8 )
            {
              v941 = (unsigned __int64)v940 >> 3;
              do
              {
                v935 = __ROL8__(*v931++ ^ v935, v933);
                v940 -= 8;
                --v941;
              }
              while ( v941 );
            }
            for ( ; v940; --v940 )
            {
              v942 = *(unsigned __int8 *)v931;
              v931 = (_QWORD *)((char *)v931 + 1);
              v935 = __ROL8__(v942 ^ v935, v933);
            }
            for ( nn = v935; ; LODWORD(v935) = nn ^ v935 )
            {
              nn >>= 31;
              if ( !nn )
                break;
            }
            v918 = v935 & 0x7FFFFFFF;
            if ( v918 == *((_DWORD *)v64 + 5) )
              goto LABEL_1440;
            if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
              v69 = 1;
            v944 = *((unsigned int *)v64 + 4);
            v945 = *((_QWORD *)v64 + 1);
            if ( *((_DWORD *)v64 + 4) )
            {
              v946 = 64i64;
              if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
              {
                v947 = KeGetCurrentIrql();
                __writecr8(2ui64);
                v948 = v945 & 0xFFFFFFFFFFFFF000ui64;
                v1797 = (v945 + v944 - 1) | 0xFFF;
                v949 = (v945 & 0xFFFFFFFFFFFFF000ui64) - 1;
                while ( 1 )
                {
                  v925 = v947;
                  while ( 1 )
                  {
                    v950 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                             v948,
                             0i64,
                             v946,
                             v931);
                    if ( v950 != -1073741267 )
                      break;
                    if ( v69 )
                      goto LABEL_1513;
                    if ( v947 > 1u )
                      goto LABEL_1511;
                    v925 = v947;
                    __writecr8(v947);
                    KeGetCurrentIrql();
                    __writecr8(2ui64);
                  }
                  if ( v950 < 0 )
                    break;
LABEL_1511:
                  v948 += 4096i64;
                  v949 += 4096i64;
                  if ( v949 == v1797 )
                  {
LABEL_1474:
                    __writecr8(v925);
                    goto LABEL_1440;
                  }
                }
LABEL_1513:
                __writecr8(v925);
                v64 = (char *)v1579;
              }
            }
            v927 = *((unsigned int *)v64 + 5);
            if ( *(_DWORD *)(v21 + 2240) )
              goto LABEL_1440;
          }
          *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v927 ^ v918;
          v928 = *((_QWORD *)v64 + 1);
          if ( !*(_DWORD *)(v21 + 2240) )
          {
            *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
            *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
            *(_QWORD *)(v21 + 2264) = *(int *)v64;
            *(_QWORD *)(v21 + 2272) = v928;
            *(_DWORD *)(v21 + 2240) = 1;
            __b9(v21, 0i64);
          }
          goto LABEL_1440;
        }
        if ( (*(_DWORD *)(v21 + 2040) & 1) == 0 )
          goto LABEL_146;
        if ( !*(_QWORD *)(v21 + 2376) || (*(_DWORD *)(v21 + 2396) & 4) != 0 )
        {
          v954 = 0i64;
        }
        else
        {
          v953 = (*(__int64 (__fastcall **)(__int64, __int64 *, _QWORD))(v21 + 960))(26i64, &v1669, 0i64);
          v954 = v1669;
          if ( v953 < 0 )
            v954 = 0i64;
        }
        v955 = *(__int64 (__fastcall **)(_QWORD))(v21 + 928);
        v1583 = v954;
        v956 = 0;
        v1581 = 0;
        v957 = v955(0i64);
        while ( 2 )
        {
          v958 = v957;
          if ( !v957 )
          {
            v1000 = *(_QWORD *)(v21 + 1208);
            if ( (*(int (__fastcall **)(__int64))(v21 + 912))(v1000) >= 0 )
            {
              v1001 = (*(unsigned __int8 (__fastcall **)(__int64))(v21 + 976))(v1000);
              v1002 = (*(unsigned __int8 (__fastcall **)(__int64, unsigned __int8 *))(v21 + 984))(v1000, &v1590);
              v1003 = (*(__int64 (__fastcall **)(__int64))(v21 + 992))(v1000);
              v1005 = 0i64;
              v1800 = v1003;
              if ( (_BYTE)v1001 == 114 || *(_DWORD *)(v21 + 2240) )
              {
                v1006 = v1579;
              }
              else
              {
                v1006 = v1579;
                v1004 = (unsigned int)v1001 ^ 0x72i64;
                *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v1004;
                if ( !*(_DWORD *)(v21 + 2240) )
                {
                  *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                  *(_QWORD *)(v21 + 2256) = (char *)v1006 - 0x4C48B4211BBACBEBi64;
                  *(_QWORD *)(v21 + 2264) = *v1006;
                  *(_QWORD *)(v21 + 2272) = v1000;
                  *(_DWORD *)(v21 + 2240) = 1;
                  __b9(v21, 0i64);
                  v1005 = 0i64;
                }
              }
              v1007 = 0;
              v1008 = 0;
              if ( (v1001 & 7) == 1 )
              {
                v1007 = 48;
              }
              else if ( (v1001 & 7) == 2 )
              {
                v1007 = 16;
                v1008 = 16;
              }
              else if ( (v1001 & 7) != 0 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = (char *)v1006 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v1006;
                *(_QWORD *)(v21 + 2272) = v1000;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
                v1005 = 0i64;
              }
              v1009 = *(_QWORD *)(v21 + 1440);
              v1010 = v1001 >> 4;
              v1011 = v1007 | *(_BYTE *)(v1009 + 2 * v1010);
              v1012 = v1579;
              if ( v1011 != (_BYTE)v1002 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = (char *)v1012 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v1012;
                *(_QWORD *)(v21 + 2272) = v1000;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              if ( ((unsigned __int8)v1008 | *(_BYTE *)(v1009 + 2 * v1010 + 1)) != v1590 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = (char *)v1012 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v1012;
                *(_QWORD *)(v21 + 2272) = v1000;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              if ( v1000 != *(_QWORD *)(v21 + 1208) )
              {
                v1013 = (unsigned __int64 *)(*(__int64 (__fastcall **)(__int64, __int64, __int64))(v21 + 968))(
                                              v1000,
                                              1i64,
                                              v1005);
                v1014 = v1013;
                if ( v1013 )
                {
                  v1015 = *v1013;
                  v1016 = (__int64)v1013;
                  if ( *v1013 )
                  {
                    v1017 = v1800;
                    v1018 = (char *)v1579;
                    v1595 = (__int64)v1013;
                    do
                    {
                      *v1014 = v1015 & 0xFFFFFFFFFFFFFFFCui64;
                      (*(void (**)(void))(v21 + 464))();
                      v1019 = v1590;
                      v1020 = v1014[1] & 0xFFFFFFFFFFFF0000ui64;
                      if ( v1020 == v1017 )
                        v1019 = v1002;
                      v1021 = v1014[1] >> 6;
                      LOBYTE(v1021) = v1021 & 0xF;
                      if ( !(*(unsigned int (__fastcall **)(unsigned __int64, __int64))(v21 + 1000))(v1021, v1019) )
                      {
                        if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
                        {
                          v1022 = *(_QWORD **)(v21 + 2632);
                          v1023 = 48;
                          v1024 = 6i64;
                          do
                          {
                            v1023 -= 8;
                            *v1022 = *(_QWORD *)v1018;
                            v1018 += 8;
                            ++v1022;
                            --v1024;
                          }
                          while ( v1024 );
                          if ( v1023 )
                          {
                            do
                            {
                              v1025 = *v1018++;
                              *(_BYTE *)v1022 = v1025;
                              v1022 = (_QWORD *)((char *)v1022 + 1);
                              --v1023;
                            }
                            while ( v1023 );
                            v1017 = v1800;
                          }
                          v1018 = *(char **)(v21 + 2632);
                        }
                        *((_QWORD *)v1018 + 3) = v1020;
                        *((_QWORD *)v1018 + 4) = *v1014;
                        v1018[40] = ((unsigned __int64)*((unsigned int *)v1014 + 2) >> 6) & 0xF;
                        if ( !*(_DWORD *)(v21 + 2240) )
                        {
                          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                          *(_QWORD *)(v21 + 2256) = v1018 - 0x4C48B4211BBACBEBi64;
                          *(_QWORD *)(v21 + 2264) = *(int *)v1018;
                          *(_QWORD *)(v21 + 2272) = v1000;
                          *(_DWORD *)(v21 + 2240) = 1;
                          __b9(v21, 0i64);
                        }
                      }
                      v1014 += 6;
                      v1015 = *v1014;
                    }
                    while ( *v1014 );
                    v1016 = v1595;
                  }
                  (*(void (__fastcall **)(__int64))(v21 + 240))(v1016);
                }
              }
              (*(void (__fastcall **)(__int64, __int64, __int64))(v21 + 920))(v1000, v1004, v1005);
              *(_DWORD *)(v21 + 2032) += 0x8000;
              v956 = v1581;
            }
            v54 = v1583;
            if ( v1583 )
              (*(void (**)(void))(v21 + 464))();
            *(_DWORD *)(v21 + 2032) += v956 << 8;
            goto LABEL_146;
          }
          if ( v954 == v957 )
          {
            v959 = v64;
            if ( (*(int (__fastcall **)(__int64))(v21 + 912))(v957) >= 0 )
            {
              v960 = (*(unsigned __int8 (__fastcall **)(__int64))(v21 + 976))(v958);
              v1798 = (*(__int64 (__fastcall **)(__int64, char *))(v21 + 984))(v958, v1591);
              v1595 = (*(__int64 (__fastcall **)(__int64))(v21 + 992))(v958);
              if ( (_BYTE)v960 != 97 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = (unsigned int)v960 ^ 0x61i64;
                if ( !*(_DWORD *)(v21 + 2240) )
                {
                  *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                  *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                  *(_QWORD *)(v21 + 2264) = *(int *)v64;
                  *(_QWORD *)(v21 + 2272) = v958;
                  *(_DWORD *)(v21 + 2240) = 1;
                  __b9(v21, 0i64);
                }
              }
              v961 = 0;
              if ( (v960 & 7) == 1 )
              {
                LOBYTE(v69) = 48;
              }
              else if ( (v960 & 7) == 2 )
              {
                LOBYTE(v69) = 16;
                v961 = 16;
              }
              else if ( (v960 & 7) != 0 && !*(_DWORD *)(v21 + 2240) )
              {
                v962 = v1579;
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v959 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v962;
                *(_QWORD *)(v21 + 2272) = v958;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              v963 = *(_QWORD *)(v21 + 1440);
              v964 = v960 >> 4;
              v73 = (*(_BYTE *)(v963 + 2 * v964) | (unsigned __int8)v69) == v1798;
              v965 = v1579;
              if ( !v73 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v959 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v965;
                *(_QWORD *)(v21 + 2272) = v958;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              if ( ((unsigned __int8)v961 | *(_BYTE *)(v963 + 2 * v964 + 1)) != v1591[0] && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v959 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v965;
                *(_QWORD *)(v21 + 2272) = v958;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              if ( v958 != *(_QWORD *)(v21 + 1208) )
              {
                v966 = (unsigned __int64 *)(*(__int64 (__fastcall **)(__int64, __int64))(v21 + 968))(v958, 1i64);
                v967 = v966;
                if ( v966 )
                {
                  v968 = *v966;
                  v969 = (unsigned __int64)v966;
                  if ( *v966 )
                  {
                    v970 = v1798;
                    v971 = v1595;
                    v1585 = (unsigned __int64)v966;
                    do
                    {
                      *v967 = v968 & 0xFFFFFFFFFFFFFFFCui64;
                      (*(void (**)(void))(v21 + 464))();
                      v972 = (unsigned __int8)v1591[0];
                      v973 = v967[1] & 0xFFFFFFFFFFFF0000ui64;
                      if ( v973 == v971 )
                        v972 = v970;
                      v974 = v967[1] >> 6;
                      LOBYTE(v974) = v974 & 0xF;
                      if ( !(*(unsigned int (__fastcall **)(unsigned __int64, __int64))(v21 + 1000))(v974, v972) )
                      {
                        if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
                        {
                          v975 = *(_QWORD **)(v21 + 2632);
                          v976 = 48;
                          v977 = 6i64;
                          do
                          {
                            v976 -= 8;
                            *v975 = *(_QWORD *)v959;
                            v959 += 8;
                            ++v975;
                            --v977;
                          }
                          while ( v977 );
                          if ( v976 )
                          {
                            do
                            {
                              v978 = *v959++;
                              *(_BYTE *)v975 = v978;
                              v975 = (_QWORD *)((char *)v975 + 1);
                              --v976;
                            }
                            while ( v976 );
                            v970 = v1798;
                          }
                          v959 = *(char **)(v21 + 2632);
                        }
                        *((_QWORD *)v959 + 3) = v973;
                        *((_QWORD *)v959 + 4) = *v967;
                        v959[40] = ((unsigned __int64)*((unsigned int *)v967 + 2) >> 6) & 0xF;
                        if ( !*(_DWORD *)(v21 + 2240) )
                        {
                          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                          *(_QWORD *)(v21 + 2256) = v959 - 0x4C48B4211BBACBEBi64;
                          *(_QWORD *)(v21 + 2264) = *(int *)v959;
                          *(_QWORD *)(v21 + 2272) = v958;
                          *(_DWORD *)(v21 + 2240) = 1;
                          __b9(v21, 0i64);
                        }
                      }
                      v967 += 6;
                      v968 = *v967;
                    }
                    while ( *v967 );
                    goto LABEL_1605;
                  }
                  goto LABEL_1606;
                }
              }
              goto LABEL_1607;
            }
          }
          else if ( (*(unsigned int (__fastcall **)(__int64))(v21 + 952))(v957) )
          {
            v979 = v64;
            if ( (*(int (__fastcall **)(__int64))(v21 + 912))(v958) >= 0 )
            {
              v980 = (*(unsigned __int8 (__fastcall **)(__int64))(v21 + 976))(v958);
              v1799 = (*(__int64 (__fastcall **)(__int64, unsigned __int8 *))(v21 + 984))(v958, &v1589);
              v1595 = (*(__int64 (__fastcall **)(__int64))(v21 + 992))(v958);
              if ( (_BYTE)v980 != 97 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = (unsigned int)v980 ^ 0x61i64;
                if ( !*(_DWORD *)(v21 + 2240) )
                {
                  *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                  *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                  *(_QWORD *)(v21 + 2264) = *(int *)v64;
                  *(_QWORD *)(v21 + 2272) = v958;
                  *(_DWORD *)(v21 + 2240) = 1;
                  __b9(v21, 0i64);
                }
              }
              v981 = 0;
              if ( (v980 & 7) == 1 )
              {
                LOBYTE(v69) = 48;
              }
              else if ( (v980 & 7) == 2 )
              {
                LOBYTE(v69) = 16;
                v981 = 16;
              }
              else if ( (v980 & 7) != 0 && !*(_DWORD *)(v21 + 2240) )
              {
                v982 = v1579;
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v979 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v982;
                *(_QWORD *)(v21 + 2272) = v958;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              v983 = *(_QWORD *)(v21 + 1440);
              v984 = v980 >> 4;
              v985 = v69 | *(_BYTE *)(v983 + 2 * v984);
              v986 = v1579;
              if ( v985 != v1799 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v979 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v986;
                *(_QWORD *)(v21 + 2272) = v958;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              if ( ((unsigned __int8)v981 | *(_BYTE *)(v983 + 2 * v984 + 1)) != v1589 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v979 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v986;
                *(_QWORD *)(v21 + 2272) = v958;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              if ( v958 != *(_QWORD *)(v21 + 1208) )
              {
                v987 = (unsigned __int64 *)(*(__int64 (__fastcall **)(__int64, __int64))(v21 + 968))(v958, 1i64);
                v988 = v987;
                if ( v987 )
                {
                  v989 = *v987;
                  v969 = (unsigned __int64)v987;
                  if ( *v987 )
                  {
                    v990 = v1799;
                    v991 = v1595;
                    v1585 = (unsigned __int64)v987;
                    do
                    {
                      *v988 = v989 & 0xFFFFFFFFFFFFFFFCui64;
                      (*(void (**)(void))(v21 + 464))();
                      v992 = v1589;
                      v993 = v988[1] & 0xFFFFFFFFFFFF0000ui64;
                      if ( v993 == v991 )
                        v992 = v990;
                      v994 = v988[1] >> 6;
                      LOBYTE(v994) = v994 & 0xF;
                      if ( !(*(unsigned int (__fastcall **)(unsigned __int64, __int64))(v21 + 1000))(v994, v992) )
                      {
                        if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
                        {
                          v995 = *(_QWORD **)(v21 + 2632);
                          v996 = 48;
                          v997 = 6i64;
                          do
                          {
                            v996 -= 8;
                            *v995 = *(_QWORD *)v979;
                            v979 += 8;
                            ++v995;
                            --v997;
                          }
                          while ( v997 );
                          if ( v996 )
                          {
                            do
                            {
                              v998 = *v979++;
                              *(_BYTE *)v995 = v998;
                              v995 = (_QWORD *)((char *)v995 + 1);
                              --v996;
                            }
                            while ( v996 );
                            v990 = v1799;
                          }
                          v979 = *(char **)(v21 + 2632);
                        }
                        *((_QWORD *)v979 + 3) = v993;
                        *((_QWORD *)v979 + 4) = *v988;
                        v979[40] = ((unsigned __int64)*((unsigned int *)v988 + 2) >> 6) & 0xF;
                        if ( !*(_DWORD *)(v21 + 2240) )
                        {
                          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                          *(_QWORD *)(v21 + 2256) = v979 - 0x4C48B4211BBACBEBi64;
                          *(_QWORD *)(v21 + 2264) = *(int *)v979;
                          *(_QWORD *)(v21 + 2272) = v958;
                          *(_DWORD *)(v21 + 2240) = 1;
                          __b9(v21, 0i64);
                        }
                      }
                      v988 += 6;
                      v989 = *v988;
                    }
                    while ( *v988 );
LABEL_1605:
                    v969 = v1585;
                  }
LABEL_1606:
                  (*(void (__fastcall **)(unsigned __int64))(v21 + 240))(v969);
                }
              }
LABEL_1607:
              (*(void (__fastcall **)(__int64))(v21 + 920))(v958);
              *(_DWORD *)(v21 + 2032) += 0x8000;
              v64 = (char *)v1579;
              LOBYTE(v69) = 0;
              v956 = v1581;
              v954 = v1583;
            }
          }
          v999 = *(__int64 (__fastcall **)(__int64))(v21 + 928);
          v1581 = ++v956;
          v957 = v999(v958);
          continue;
        }
      }
      if ( v77 == 38 )
      {
        (*(void (__fastcall **)(char *, _QWORD))(v21 + 400))(v1760, *((unsigned int *)v64 + 11));
        v1518 = (*(__int64 (__fastcall **)(char *, char *))(v21 + 448))(v1760, v1761);
        __asm { xgetbv }
        v704 = v1761;
        v703 = v1518 | (v1519 << 32);
        goto LABEL_1125;
      }
      if ( v77 <= 42 )
      {
        *(_DWORD *)(v21 + 2032) += *((_DWORD *)v64 + 9);
        v1400 = *((unsigned int *)v64 + 9);
        v1401 = (_QWORD *)(v21 + *((unsigned int *)v64 + 8));
        v1402 = *(_DWORD *)(v21 + 2012);
        v1403 = v1401;
        v1404 = *(_QWORD *)(v21 + 2016);
        v1405 = (const char *)v1401;
        if ( v1401 < (_QWORD *)((char *)v1401 + v1400) )
        {
          do
          {
            _mm_prefetch(v1405, 0);
            v1405 += 64;
          }
          while ( v1405 < (const char *)v1401 + v1400 );
        }
        v1406 = *(_QWORD *)(v21 + 2016);
        v1407 = (unsigned int)v1400 >> 7;
        if ( (unsigned int)v1400 >> 7 )
        {
          do
          {
            v1408 = 8i64;
            do
            {
              v1409 = v1403[1] ^ __ROL8__(*v1403 ^ v1406, v1402);
              v1403 += 2;
              v1406 = __ROL8__(v1409, v1402);
              --v1408;
            }
            while ( v1408 );
            v1410 = (__ROL8__(v1404 ^ ((char *)v1403 - (char *)v1401), 17) ^ v1404 ^ (unsigned __int64)((char *)v1403 - (char *)v1401))
                  * (unsigned __int128)0x7010008004002001ui64;
            v1730 = *((_QWORD *)&v1410 + 1);
            v1402 = (BYTE8(v1410) ^ (unsigned __int8)(v1410 ^ v1402)) & 0x3F;
            if ( !v1402 )
              LOBYTE(v1402) = 1;
            --v1407;
          }
          while ( v1407 );
          v21 = (ULONG_PTR)v1580;
        }
        v1411 = v1400 & 0x7F;
        if ( v1411 >= 8 )
        {
          v1412 = (unsigned __int64)v1411 >> 3;
          do
          {
            v1406 = __ROL8__(*v1403++ ^ v1406, v1402);
            v1411 -= 8;
            --v1412;
          }
          while ( v1412 );
        }
        for ( ; v1411; --v1411 )
        {
          v1413 = *(unsigned __int8 *)v1403;
          v1403 = (_QWORD *)((char *)v1403 + 1);
          v1406 = __ROL8__(v1413 ^ v1406, v1402);
        }
        v54 = *((_QWORD *)v64 + 3);
        if ( v1406 == v54 )
          goto LABEL_146;
        v1414 = *(_DWORD *)(v21 + 2240);
        if ( !v1414 )
        {
          *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v1406 ^ v54;
          v1414 = *(_DWORD *)(v21 + 2240);
        }
        v54 = v21 + *((unsigned int *)v64 + 8);
        v104 = v1414 == 0;
        goto LABEL_232;
      }
      if ( v77 != 43 )
      {
        if ( v77 != 44 )
        {
          if ( v77 == 46 )
          {
            if ( (*(_DWORD *)(v21 + 2040) & 1) == 0 )
            {
              v1184 = 0;
              v1185 = *(_QWORD *)(v21 + 1312);
              (*(void (__fastcall **)(unsigned __int64, unsigned __int64))(v21 + 360))(v54, v52);
              if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 || (v1186 = *(_DWORD *)(v21 + 2328), v1186 >= 7) )
              {
                (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 280))(*(_QWORD *)(v21 + 2504), 0i64);
                v1187 = 0x80;
              }
              else
              {
                v1187 = 1 << v1186;
              }
              (*(void (__fastcall **)(__int64, _QWORD))(v21 + 296))(v1185, 0i64);
              if ( v1187 == (char)0x80 )
              {
                (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 288))(*(_QWORD *)(v21 + 2504), 0i64);
              }
              else
              {
                v1188 = *(volatile signed __int8 ***)(v21 + 1272);
                v1189 = *v1188;
                if ( *v1188 != (volatile signed __int8 *)v1188 )
                {
                  v1190 = ~v1187;
                  do
                  {
                    _InterlockedAnd8(&v1189[*(_QWORD *)(v21 + 1672) - *(_QWORD *)(v21 + 1696)], v1190);
                    v1189 = *(volatile signed __int8 **)v1189;
                    ++v1184;
                  }
                  while ( v1189 != (volatile signed __int8 *)v1188 );
                }
              }
              (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 304))(*(_QWORD *)(v21 + 1312), 0i64);
              (*(void (**)(void))(v21 + 368))();
              *(_DWORD *)(v21 + 2032) += v1184 << 7;
            }
            goto LABEL_146;
          }
          if ( v77 == 47 )
          {
            v1601 = *(_QWORD *)(*(_QWORD *)(v21 + 1656)
                              + *(_QWORD *)((char *)&KeGetCurrentPrcb()->MxCsr + *(_QWORD *)(v21 + 1560))
                              + *(_QWORD *)(v21 + 1624));
            v1174 = (*(__int64 (__fastcall **)(__int64, unsigned __int64))(v21 + 1152))(v1601, v52);
            if ( v1174 == 0xFFFFFFFFi64 )
            {
              v1601 = 0i64;
              v1175 = *(_QWORD *)(v21 + 2384);
              if ( !v1175 )
                goto LABEL_1907;
              v1176 = (*(__int64 (__fastcall **)(__int64, __int64 *))(v21 + 1136))(v1175, &v1601);
              v1177 = v1601;
              if ( v1176 < 0 )
                v1177 = 0i64;
              v1601 = v1177;
              if ( !v1177 )
LABEL_1907:
                v1601 = (*(__int64 (__fastcall **)(_QWORD))(v21 + 944))(0i64);
              *(_QWORD *)(v21 + 2384) = 0i64;
              v1178 = 0;
              v54 = v1601;
              for ( i1 = v1601 == 0; ; i1 = v54 == 0 )
              {
                if ( i1 )
                  goto LABEL_1915;
                ++v1178;
                if ( (*(int (**)(void))(v21 + 912))() >= 0 )
                {
                  (*(void (__fastcall **)(__int64, char *))(v21 + 1064))(v1601, v1779);
                  v1174 = (*(__int64 (**)(void))(v21 + 1152))();
                  (*(void (__fastcall **)(char *))(v21 + 1072))(v1779);
                  (*(void (__fastcall **)(__int64))(v21 + 920))(v1601);
                  if ( v1174 != 0xFFFFFFFFi64 || v1178 > 0x100 )
                    break;
                }
                v54 = (*(__int64 (__fastcall **)(__int64))(v21 + 944))(v1601);
                v1601 = v54;
              }
              *(_QWORD *)(v21 + 2384) = (*(__int64 (__fastcall **)(__int64))(v21 + 1144))(v1601);
              (*(void (__fastcall **)(__int64))(v21 + 464))(v1601);
              if ( v1174 == 0xFFFFFFFFi64 )
              {
LABEL_1915:
                *(_DWORD *)(v21 + 2032) += v1178 << 12;
                goto LABEL_146;
              }
            }
            if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
            {
              v1180 = *(_QWORD **)(v21 + 2632);
              v1181 = 48;
              v1182 = 6i64;
              do
              {
                v1181 -= 8;
                *v1180 = *(_QWORD *)v64;
                v64 += 8;
                ++v1180;
                --v1182;
              }
              while ( v1182 );
              for ( ; v1181; --v1181 )
              {
                v1183 = *v64++;
                *(_BYTE *)v1180 = v1183;
                v1180 = (_QWORD *)((char *)v1180 + 1);
              }
              v64 = *(char **)(v21 + 2632);
            }
            *((_QWORD *)v64 + 3) = v1174;
            v54 = v1601;
            goto LABEL_1128;
          }
          if ( v77 != 48 )
            goto LABEL_2294;
          if ( !*((_DWORD *)v64 + 4) )
            goto LABEL_146;
          if ( (*(_DWORD *)(v21 + 2396) & 0x4000) != 0 )
          {
            v54 = *(_QWORD *)(v21 + 1208);
            while ( 1 )
            {
              _disable();
              if ( !_interlockedbittestandset((volatile signed __int32 *)v54, (*(_DWORD *)(v21 + 2392) >> 10) & 0x1F) )
                break;
              _enable();
              _mm_pause();
            }
          }
          if ( (*((_DWORD *)v64 + 6) & 1) == 0 )
          {
            v1125 = (_QWORD *)*((_QWORD *)v64 + 1);
            v1126 = *((unsigned int *)v64 + 4);
            v1127 = v1125;
            *(_DWORD *)(v21 + 2032) += v1126;
            v1128 = (const char *)v1125;
            v1129 = *(_DWORD *)(v21 + 2012);
            v1130 = *(_QWORD *)(v21 + 2016);
            v54 = (unsigned __int64)v1125 + v1126;
            if ( v1125 < (_QWORD *)((char *)v1125 + v1126) )
            {
              do
              {
                _mm_prefetch(v1128, 0);
                v1128 += 64;
              }
              while ( (unsigned __int64)v1128 < v54 );
            }
            v1131 = *(_QWORD *)(v21 + 2016);
            v1132 = (unsigned int)v1126 >> 7;
            if ( (unsigned int)v1126 >> 7 )
            {
              do
              {
                v1133 = 8i64;
                do
                {
                  v1134 = v1127[1] ^ __ROL8__(*v1127 ^ v1131, v1129);
                  v1127 += 2;
                  v1131 = __ROL8__(v1134, v1129);
                  --v1133;
                }
                while ( v1133 );
                v54 = __ROL8__(v1130 ^ ((char *)v1127 - (char *)v1125), 17) ^ v1130 ^ ((char *)v1127 - (char *)v1125);
                v1722 = (v54 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                v1129 = ((unsigned __int8)v54 ^ (unsigned __int8)(v1722 ^ v1129)) & 0x3F;
                if ( !v1129 )
                  v1129 = 1;
                --v1132;
              }
              while ( v1132 );
              v21 = (ULONG_PTR)v1580;
            }
            v1135 = v1126 & 0x7F;
            if ( v1135 >= 8 )
            {
              v1136 = (unsigned __int64)v1135 >> 3;
              do
              {
                v54 = v1129;
                v1131 = __ROL8__(*v1127++ ^ v1131, v1129);
                v1135 -= 8;
                --v1136;
              }
              while ( v1136 );
            }
            for ( ; v1135; --v1135 )
            {
              v1137 = *(unsigned __int8 *)v1127;
              v54 = v1129;
              v1127 = (_QWORD *)((char *)v1127 + 1);
              v1131 = __ROL8__(v1137 ^ v1131, v1129);
            }
            for ( i2 = v1131; ; LODWORD(v1131) = i2 ^ v1131 )
            {
              i2 >>= 31;
              if ( !i2 )
                break;
            }
            v1139 = v1131 & 0x7FFFFFFF;
            if ( v1139 != *((_DWORD *)v64 + 5) )
            {
              if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
                v69 = 1;
              v54 = *((unsigned int *)v64 + 4);
              v1140 = *((_QWORD *)v64 + 1);
              if ( *((_DWORD *)v64 + 4) )
              {
                v1141 = 64i64;
                if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
                {
                  v1142 = KeGetCurrentIrql();
                  __writecr8(2ui64);
                  v1143 = v1140 & 0xFFFFFFFFFFFFF000ui64;
                  v1805 = (v1140 + v54 - 1) | 0xFFF;
                  v1144 = (v1140 & 0xFFFFFFFFFFFFF000ui64) - 1;
                  while ( 1 )
                  {
                    v1145 = v1142;
                    while ( 1 )
                    {
                      v1146 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                                v1143,
                                0i64,
                                v1141,
                                v1127);
                      if ( v1146 != -1073741267 )
                        break;
                      if ( v69 )
                        goto LABEL_1850;
                      if ( v1142 > 1u )
                        goto LABEL_1848;
                      v1145 = v1142;
                      __writecr8(v1142);
                      KeGetCurrentIrql();
                      __writecr8(2ui64);
                    }
                    if ( v1146 < 0 )
                      break;
LABEL_1848:
                    v1143 += 4096i64;
                    v1144 += 4096i64;
                    if ( v1144 == v1805 )
                      goto LABEL_1894;
                  }
LABEL_1850:
                  __writecr8(v1145);
                  v64 = (char *)v1579;
                }
              }
              v1147 = *((unsigned int *)v64 + 5);
              if ( !*(_DWORD *)(v21 + 2240) )
              {
                v1148 = v1139;
                goto LABEL_1853;
              }
            }
            goto LABEL_1900;
          }
          if ( *(_QWORD *)(v21 + 2376) )
          {
            v1149 = *(_DWORD *)(v21 + 2396);
            if ( !*(_DWORD *)(v21 + 2028) )
            {
              LODWORD(v54) = v1149 ^ ((unsigned __int8)v1149 ^ (unsigned __int8)(8 * v1149)) & 0x20;
              *(_DWORD *)(v21 + 2396) = v54;
              goto LABEL_1859;
            }
            v54 = v1149;
            if ( (((unsigned __int8)v1149 ^ (unsigned __int8)(v1149 >> 3)) & 4) == 0 )
            {
LABEL_1859:
              if ( (v54 & 4) != 0 )
              {
                v54 = *((_DWORD *)v64 + 2) & 0xFFF;
                v1150 = *((_QWORD *)v64 + 1) & 0xFFFFFFFFFFFFF000ui64;
                v1151 = (v54 + *((unsigned int *)v64 + 4) + 4095i64) >> 12;
                while ( v1151 )
                {
                  --v1151;
                  if ( (*(unsigned __int8 (__fastcall **)(unsigned __int64))(v21 + 672))(v1150)
                    && !*(_DWORD *)(v21 + 2240) )
                  {
                    *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                    *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                    *(_QWORD *)(v21 + 2264) = *(int *)v64;
                    *(_QWORD *)(v21 + 2272) = v1150;
                    *(_DWORD *)(v21 + 2240) = 1;
                    __b9(v21, 0i64);
                  }
                  v1150 += 4096i64;
                  *(_DWORD *)(v21 + 2032) += 256;
                }
                goto LABEL_1900;
              }
              v1152 = (_QWORD *)*((_QWORD *)v64 + 1);
              v1153 = *((unsigned int *)v64 + 4);
              v1154 = v1152;
              *(_DWORD *)(v21 + 2032) += v1153;
              v1155 = (const char *)v1152;
              v1156 = *(_DWORD *)(v21 + 2012);
              v1157 = *(_QWORD *)(v21 + 2016);
              v54 = (unsigned __int64)v1152 + v1153;
              if ( v1152 < (_QWORD *)((char *)v1152 + v1153) )
              {
                do
                {
                  _mm_prefetch(v1155, 0);
                  v1155 += 64;
                }
                while ( (unsigned __int64)v1155 < v54 );
              }
              v1158 = *(_QWORD *)(v21 + 2016);
              v1159 = (unsigned int)v1153 >> 7;
              if ( (unsigned int)v1153 >> 7 )
              {
                do
                {
                  v1160 = 8i64;
                  do
                  {
                    v1161 = v1154[1] ^ __ROL8__(*v1154 ^ v1158, v1156);
                    v1154 += 2;
                    v1158 = __ROL8__(v1161, v1156);
                    --v1160;
                  }
                  while ( v1160 );
                  v54 = __ROL8__(v1157 ^ ((char *)v1154 - (char *)v1152), 17) ^ v1157 ^ ((char *)v1154 - (char *)v1152);
                  v1723 = (v54 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                  v1156 = ((unsigned __int8)v54 ^ (unsigned __int8)(v1723 ^ v1156)) & 0x3F;
                  if ( !v1156 )
                    v1156 = 1;
                  --v1159;
                }
                while ( v1159 );
                v21 = (ULONG_PTR)v1580;
              }
              v1162 = v1153 & 0x7F;
              if ( v1162 >= 8 )
              {
                v1163 = (unsigned __int64)v1162 >> 3;
                do
                {
                  v54 = v1156;
                  v1158 = __ROL8__(*v1154++ ^ v1158, v1156);
                  v1162 -= 8;
                  --v1163;
                }
                while ( v1163 );
              }
              for ( ; v1162; --v1162 )
              {
                v1164 = *(unsigned __int8 *)v1154;
                v54 = v1156;
                v1154 = (_QWORD *)((char *)v1154 + 1);
                v1158 = __ROL8__(v1164 ^ v1158, v1156);
              }
              for ( i3 = v1158; ; LODWORD(v1158) = i3 ^ v1158 )
              {
                i3 >>= 31;
                if ( !i3 )
                  break;
              }
              v1166 = *((_DWORD *)v64 + 5);
              v1167 = v1158 & 0x7FFFFFFF;
              if ( v1167 == v1166 )
                goto LABEL_1900;
              v54 = *((unsigned int *)v64 + 4);
              v1168 = *((_QWORD *)v64 + 1);
              if ( *((_DWORD *)v64 + 4) && (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
              {
                v1169 = KeGetCurrentIrql();
                __writecr8(2ui64);
                v1170 = v1168 & 0xFFFFFFFFFFFFF000ui64;
                v1171 = (v1168 + v54 - 1) | 0xFFF;
                v1172 = (v1168 & 0xFFFFFFFFFFFFF000ui64) - 1;
                while ( 1 )
                {
                  v1145 = v1169;
                  while ( 1 )
                  {
                    v1173 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(v21 + 1112))(v1170, 0i64);
                    if ( v1173 != -1073741267 )
                      break;
                    if ( v1169 > 1u )
                      goto LABEL_1893;
                    v1145 = v1169;
                    __writecr8(v1169);
                    KeGetCurrentIrql();
                    __writecr8(2ui64);
                  }
                  if ( v1173 < 0 )
                    break;
LABEL_1893:
                  v1170 += 4096i64;
                  v1172 += 4096i64;
                  if ( v1172 == v1171 )
                  {
LABEL_1894:
                    __writecr8(v1145);
                    goto LABEL_1900;
                  }
                }
                __writecr8(v1145);
                v64 = (char *)v1579;
                v1166 = v1579[5];
              }
              if ( !*(_DWORD *)(v21 + 2240) )
              {
                v1148 = v1166;
                v1147 = v1167;
LABEL_1853:
                *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v1147 ^ v1148;
                v54 = *((_QWORD *)v64 + 1);
                if ( !*(_DWORD *)(v21 + 2240) )
                {
                  *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                  *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                  *(_QWORD *)(v21 + 2264) = *(int *)v64;
                  *(_QWORD *)(v21 + 2272) = v54;
                  *(_DWORD *)(v21 + 2240) = 1;
                  __b9(v21, 0i64);
                }
              }
LABEL_1900:
              if ( (*(_DWORD *)(v21 + 2396) & 0x4000) != 0 )
              {
                v54 = (*(_DWORD *)(v21 + 2392) >> 10) & 0x1F;
                _InterlockedAnd(
                  *(volatile signed __int32 **)(v21 + 1208),
                  ~(1 << ((*(_DWORD *)(v21 + 2392) >> 10) & 0x1F)));
                _enable();
              }
              goto LABEL_146;
            }
          }
          *(_DWORD *)(v21 + 2028) = 0;
          goto LABEL_1900;
        }
        v54 = *((unsigned int *)v64 + 8);
        BugCheckParameter2 = v21;
        if ( (v54 & 2) == 0 )
          goto LABEL_1995;
        if ( !*(_QWORD *)(v21 + 2376) )
          goto LABEL_1745;
        v1191 = *(_DWORD *)(v21 + 2396);
        if ( (v1191 & 4) != 0 )
          goto LABEL_1745;
        if ( (v54 & 2) != 0 )
        {
          v1192 = *(_DWORD *)(v21 + 2028);
          if ( v1192 )
          {
            v54 = v1191;
            if ( (((unsigned __int8)v1191 ^ (unsigned __int8)(v1191 >> 3)) & 4) != 0 )
              goto LABEL_1745;
          }
          else
          {
            LODWORD(v54) = v1191 ^ ((unsigned __int8)v1191 ^ (unsigned __int8)(8 * v1191)) & 0x20;
            *(_DWORD *)(v21 + 2396) = v54;
          }
          if ( !*(_QWORD *)(v21 + 2376) )
            goto LABEL_1994;
          if ( !v1192 )
          {
            v1193 = v54 ^ ((unsigned __int8)v54 ^ (unsigned __int8)(8 * v54)) & 0x20;
            *(_DWORD *)(v21 + 2396) = v1193;
            goto LABEL_1946;
          }
          LOBYTE(v1193) = v54;
          if ( (((unsigned __int8)v54 ^ (unsigned __int8)((unsigned int)v54 >> 3)) & 4) != 0 )
          {
LABEL_1994:
            *(_DWORD *)(v21 + 2028) = 0;
            goto LABEL_1983;
          }
LABEL_1946:
          if ( (v1193 & 4) != 0 )
          {
            v1194 = *((_QWORD *)v64 + 1) & 0xFFFFFFFFFFFFF000ui64;
            v1195 = ((*((_DWORD *)v64 + 2) & 0xFFF) + (unsigned __int64)*((unsigned int *)v64 + 4) + 4095) >> 12;
            while ( v1195 )
            {
              --v1195;
              if ( (*(unsigned __int8 (__fastcall **)(unsigned __int64))(v21 + 672))(v1194) && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *(int *)v64;
                *(_QWORD *)(v21 + 2272) = v1194;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              v1194 += 4096i64;
              *(_DWORD *)(v21 + 2032) += 256;
            }
            goto LABEL_1983;
          }
          v1196 = (_QWORD *)*((_QWORD *)v64 + 1);
          v1197 = *((unsigned int *)v64 + 4);
          v1198 = v1196;
          *(_DWORD *)(v21 + 2032) += v1197;
          v1199 = (const char *)v1196;
          v1200 = *(_DWORD *)(v21 + 2012);
          v1201 = *(_QWORD *)(v21 + 2016);
          if ( v1196 < (_QWORD *)((char *)v1196 + v1197) )
          {
            do
            {
              _mm_prefetch(v1199, 0);
              v1199 += 64;
            }
            while ( v1199 < (const char *)v1196 + v1197 );
          }
          v1202 = *(_QWORD *)(v21 + 2016);
          v1203 = (unsigned int)v1197 >> 7;
          if ( (unsigned int)v1197 >> 7 )
          {
            do
            {
              v1204 = 8i64;
              do
              {
                v1205 = v1202 ^ *v1198;
                v1206 = v1198[1];
                v1198 += 2;
                v1202 = __ROL8__(__ROL8__(v1205, v1200) ^ v1206, v1200);
                --v1204;
              }
              while ( v1204 );
              v1207 = __ROL8__(v1201 ^ ((char *)v1198 - (char *)v1196), 17) ^ v1201 ^ ((char *)v1198 - (char *)v1196);
              v1724 = (v1207 * (unsigned __int128)0x7010008004002001ui64) >> 64;
              v1200 = ((unsigned __int8)(v1207 ^ v1724) ^ (unsigned __int8)v1200) & 0x3F;
              if ( !v1200 )
                LOBYTE(v1200) = 1;
              --v1203;
            }
            while ( v1203 );
            v21 = (ULONG_PTR)v1580;
          }
          v1208 = v1197 & 0x7F;
          if ( v1208 >= 8 )
          {
            v1209 = (unsigned __int64)v1208 >> 3;
            do
            {
              v1202 = __ROL8__(*v1198++ ^ v1202, v1200);
              v1208 -= 8;
              --v1209;
            }
            while ( v1209 );
          }
          if ( v1208 )
          {
            do
            {
              v1210 = *(unsigned __int8 *)v1198;
              v1198 = (_QWORD *)((char *)v1198 + 1);
              v1202 = __ROL8__(v1210 ^ v1202, v1200);
              --v1208;
            }
            while ( v1208 );
            v21 = (ULONG_PTR)v1580;
          }
          for ( i4 = v1202; ; LODWORD(v1202) = i4 ^ v1202 )
          {
            i4 >>= 31;
            if ( !i4 )
              break;
          }
          v1212 = *((_DWORD *)v64 + 5);
          v1213 = v1202 & 0x7FFFFFFF;
          if ( v1213 != v1212 )
          {
            v1214 = *((unsigned int *)v64 + 4);
            v1215 = *((_QWORD *)v64 + 1);
            if ( *((_DWORD *)v64 + 4) && (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
            {
              v1216 = KeGetCurrentIrql();
              __writecr8(2ui64);
              v1217 = v1215 & 0xFFFFFFFFFFFFF000ui64;
              v1218 = (v1215 + v1214 - 1) | 0xFFF;
              v1219 = (v1215 & 0xFFFFFFFFFFFFF000ui64) - 1;
              while ( 1 )
              {
                v1220 = v1216;
                while ( 1 )
                {
                  v1221 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(v21 + 1112))(v1217, 0i64);
                  if ( v1221 != -1073741267 )
                    break;
                  if ( v1216 > 1u )
                    goto LABEL_1981;
                  v1220 = v1216;
                  __writecr8(v1216);
                  KeGetCurrentIrql();
                  __writecr8(2ui64);
                }
                if ( v1221 < 0 )
                  break;
LABEL_1981:
                v1217 += 4096i64;
                v1219 += 4096i64;
                if ( v1219 == v1218 )
                  goto LABEL_1982;
              }
              __writecr8(v1220);
              v64 = (char *)v1579;
              v1212 = v1579[5];
            }
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v1212 ^ (unsigned __int64)v1213;
              v1227 = *((_QWORD *)v64 + 1);
              if ( !*(_DWORD *)(v21 + 2240) )
              {
LABEL_1993:
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *(int *)v64;
                *(_QWORD *)(v21 + 2272) = v1227;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
            }
          }
        }
        else
        {
LABEL_1995:
          v1228 = (_QWORD *)*((_QWORD *)v64 + 1);
          v1229 = *((unsigned int *)v64 + 4);
          v1230 = v1228;
          *(_DWORD *)(v21 + 2032) += v1229;
          v1231 = (const char *)v1228;
          v1232 = *(_DWORD *)(v21 + 2012);
          v1233 = *(_QWORD *)(v21 + 2016);
          if ( v1228 < (_QWORD *)((char *)v1228 + v1229) )
          {
            do
            {
              _mm_prefetch(v1231, 0);
              v1231 += 64;
            }
            while ( v1231 < (const char *)v1228 + v1229 );
          }
          v1234 = *(_QWORD *)(v21 + 2016);
          v1235 = (unsigned int)v1229 >> 7;
          if ( (unsigned int)v1229 >> 7 )
          {
            do
            {
              v1236 = 8i64;
              do
              {
                v1237 = v1234 ^ *v1230;
                v1238 = v1230[1];
                v1230 += 2;
                v1234 = __ROL8__(__ROL8__(v1237, v1232) ^ v1238, v1232);
                --v1236;
              }
              while ( v1236 );
              v1239 = __ROL8__(v1233 ^ ((char *)v1230 - (char *)v1228), 17) ^ v1233 ^ ((char *)v1230 - (char *)v1228);
              v1725 = (v1239 * (unsigned __int128)0x7010008004002001ui64) >> 64;
              v1232 = ((unsigned __int8)(v1239 ^ v1725) ^ (unsigned __int8)v1232) & 0x3F;
              if ( !v1232 )
                LOBYTE(v1232) = 1;
              --v1235;
            }
            while ( v1235 );
            v21 = (ULONG_PTR)v1580;
          }
          v1240 = v1229 & 0x7F;
          if ( v1240 >= 8 )
          {
            v1241 = (unsigned __int64)v1240 >> 3;
            do
            {
              v1234 = __ROL8__(*v1230++ ^ v1234, v1232);
              v1240 -= 8;
              --v1241;
            }
            while ( v1241 );
          }
          if ( v1240 )
          {
            do
            {
              v1242 = *(unsigned __int8 *)v1230;
              v1230 = (_QWORD *)((char *)v1230 + 1);
              v1234 = __ROL8__(v1242 ^ v1234, v1232);
              --v1240;
            }
            while ( v1240 );
            v21 = (ULONG_PTR)v1580;
          }
          for ( i5 = v1234; ; LODWORD(v1234) = i5 ^ v1234 )
          {
            i5 >>= 31;
            if ( !i5 )
              break;
          }
          v1244 = v1234 & 0x7FFFFFFF;
          if ( v1244 != *((_DWORD *)v64 + 5) )
          {
            if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
              v69 = 1;
            v1245 = *((unsigned int *)v64 + 4);
            v1246 = *((_QWORD *)v64 + 1);
            if ( *((_DWORD *)v64 + 4) )
            {
              v1247 = 64i64;
              if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
              {
                v1248 = KeGetCurrentIrql();
                __writecr8(2ui64);
                v1249 = v1246 & 0xFFFFFFFFFFFFF000ui64;
                v1807 = (v1246 + v1245 - 1) | 0xFFF;
                v1250 = (v1246 & 0xFFFFFFFFFFFFF000ui64) - 1;
                while ( 1 )
                {
                  v1220 = v1248;
                  while ( 1 )
                  {
                    v1251 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                              v1249,
                              0i64,
                              v1247,
                              v1230);
                    if ( v1251 != -1073741267 )
                      break;
                    if ( v69 )
                      goto LABEL_2028;
                    if ( v1248 > 1u )
                      goto LABEL_2026;
                    v1220 = v1248;
                    __writecr8(v1248);
                    KeGetCurrentIrql();
                    __writecr8(2ui64);
                  }
                  if ( v1251 < 0 )
                    break;
LABEL_2026:
                  v1249 += 4096i64;
                  v1250 += 4096i64;
                  if ( v1250 == v1807 )
                  {
LABEL_1982:
                    __writecr8(v1220);
                    goto LABEL_1983;
                  }
                }
LABEL_2028:
                __writecr8(v1220);
                v64 = (char *)v1579;
              }
            }
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = *((unsigned int *)v64 + 5) ^ (unsigned __int64)v1244;
              v1227 = *((_QWORD *)v64 + 1);
              if ( !*(_DWORD *)(v21 + 2240) )
                goto LABEL_1993;
            }
          }
        }
LABEL_1983:
        v54 = (unsigned __int64)v1579;
        if ( (v1579[8] & 1) == 0 )
          goto LABEL_146;
        v1222 = *((_QWORD *)v1579 + 3);
        v1223 = (*(__int64 (__fastcall **)(__int64))(v21 + 488))(v1222);
        v1224 = (_DWORD *)(v1223 + *(unsigned __int16 *)(v1223 + 20) + 24i64);
        v54 = 5i64 * *(unsigned __int16 *)(v1223 + 6);
        v1585 = (unsigned __int64)&v1224[10 * *(unsigned __int16 *)(v1223 + 6)];
        if ( v1224 == (_DWORD *)v1585 )
          goto LABEL_146;
        v1225 = *(_DWORD *)(v21 + 2028);
        if ( !v1225 )
        {
          *(_DWORD *)(v21 + 2028) = 4096;
          v1225 = 4096;
        }
        if ( v1222 == *(_QWORD *)(v21 + 1472) || v1222 == *(_QWORD *)(v21 + 1480) )
        {
          v1226 = 1;
          v1806 = 1;
        }
        else
        {
          v1806 = 0;
          v1226 = 1;
        }
        while ( 2 )
        {
          v54 = (unsigned int)v1224[4];
          v1252 = v1224[2];
          v1253 = v1224[3];
          if ( (unsigned int)v54 <= v1252 )
            v54 = v1252;
          v1254 = (v54 + v1253 + 4095) & 0xFFFFF000;
          if ( v1225 >= v1254 )
            goto LABEL_2040;
          if ( (v1224[9] & 0x2000000) != 0 )
            goto LABEL_2039;
          v1255 = *v1224;
          if ( *v1224 == 1414090313 )
          {
            if ( v1224[1] == 1195525195 )
              goto LABEL_2039;
            goto LABEL_2050;
          }
          if ( v1255 == 1162297680 )
          {
            v1257 = *((_WORD *)v1224 + 2);
            v54 = 30839i64;
            if ( v1257 == 30839 )
              goto LABEL_2039;
            v54 = 29303i64;
            if ( v1257 == 29303 )
              goto LABEL_2039;
            v54 = 30583i64;
            if ( v1257 == 30583 )
              goto LABEL_2039;
          }
          else
          {
LABEL_2050:
            if ( v1255 == 1095914053 && *((_WORD *)v1224 + 2) == 16724 )
              goto LABEL_2039;
          }
          v54 = BugCheckParameter2;
          if ( BugCheckParameter2 )
          {
            v1258 = *(char **)(BugCheckParameter2 + 2296);
            *((_QWORD *)&v1661 + 1) = *(_QWORD *)(BugCheckParameter2 + 2304);
            v1662 = *(_OWORD *)(BugCheckParameter2 + 2312);
            *(_QWORD *)&v1661 = v1258;
          }
          else
          {
            v1661 = *(_OWORD *)VfExcludeSections;
            v1258 = VfExcludeSections[0];
            v1662 = *(_OWORD *)off_140C09188;
          }
          v1259 = 7;
          v1260 = (unsigned __int8 *)v1224;
          while ( 1 )
          {
            v1261 = *v1260++;
            v1262 = (unsigned __int8)*v1258++;
            if ( v1261 != v1262 )
              break;
            if ( !--v1259 )
              goto LABEL_2039;
          }
          v1263 = (__int64 *)*((_QWORD *)&v1661 + 1);
          v1264 = 8;
          v1265 = (unsigned __int64 *)v1224;
          do
          {
            v54 = *v1265++;
            v1266 = *v1263++;
            if ( v54 != v1266 )
              goto LABEL_2066;
            v1264 -= 8;
          }
          while ( v1264 >= 8 );
          if ( !v1264 )
            goto LABEL_2039;
          while ( 1 )
          {
            v1267 = *(unsigned __int8 *)v1265;
            v1265 = (unsigned __int64 *)((char *)v1265 + 1);
            v1268 = *(unsigned __int8 *)v1263;
            v1263 = (__int64 *)((char *)v1263 + 1);
            if ( v1267 != v1268 )
              break;
            if ( !--v1264 )
              goto LABEL_2039;
          }
LABEL_2066:
          v1269 = (unsigned __int8 *)v1662;
          v1270 = 4;
          v1271 = (unsigned __int8 *)v1224;
          while ( 1 )
          {
            v1272 = *v1271++;
            v1273 = *v1269++;
            if ( v1272 != v1273 )
              break;
            if ( !--v1270 )
              goto LABEL_2039;
          }
          v1274 = (unsigned __int8 *)*((_QWORD *)&v1662 + 1);
          v1275 = 6;
          v1276 = (unsigned __int8 *)v1224;
          while ( 1 )
          {
            v1277 = *v1276++;
            v1278 = *v1274++;
            if ( v1277 != v1278 )
              break;
            if ( !--v1275 )
              goto LABEL_2039;
          }
          v1279 = v1224[9];
          if ( v1279 < 0 || (v1279 & 0x20000000) == 0 )
          {
LABEL_2039:
            v1225 = v1254;
LABEL_2040:
            v1256 = BugCheckParameter2;
            goto LABEL_2041;
          }
          if ( v1806 && *v1224 != 778396769 && *v1224 != 1162297680 )
            v1226 = 0;
          v1256 = BugCheckParameter2;
          if ( v1225 < v1253 )
            v1225 = v1253;
LABEL_2083:
          v1280 = v1222 + v1225;
          if ( (*(_BYTE *)(v1256 + 2115) & 4) != 0 )
          {
            v54 = 0xFFFFFFFFi64;
            __asm
            {
              xbegin  $+6
              xend
            }
            ++*(_DWORD *)(v1256 + 2052);
            *(_DWORD *)(v1256 + 2032) += 256;
LABEL_2093:
            v1283 = *(_DWORD *)(v1256 + 2036);
            v1225 += 4096;
            if ( v1225 >= v1254 )
            {
              if ( *(_DWORD *)(v1256 + 2032) >= v1283 )
                goto LABEL_2042;
LABEL_2041:
              v1224 += 10;
              v1226 = 1;
              if ( v1224 == (_DWORD *)v1585 )
              {
LABEL_2042:
                v21 = (ULONG_PTR)v1580;
                if ( v1224 == (_DWORD *)v1585 && v1225 >= v1254 )
                  *(_DWORD *)(v1256 + 2028) = 0;
                else
                  *(_DWORD *)(v1256 + 2028) = v1225;
                goto LABEL_146;
              }
              continue;
            }
            if ( *(_DWORD *)(v1256 + 2032) >= v1283 )
              goto LABEL_2042;
            goto LABEL_2083;
          }
          break;
        }
        if ( v1226 )
        {
          v1281 = (*(__int64 (__fastcall **)(__int64 *, __int64, __int64, _QWORD))(v1256 + 1088))(
                    &v1688,
                    v1222 + v1225,
                    v1256,
                    0i64);
          v1282 = 0i64;
          if ( v1281 < 0 )
          {
            if ( v1281 == -1073741819 )
            {
              v54 = (unsigned __int64)v1579;
              if ( (v1579[8] & 4) == 0 || (int)v1224[9] < 0 )
              {
                v1256 = BugCheckParameter2;
                if ( *(_DWORD *)(BugCheckParameter2 + 2240) )
                  goto LABEL_2093;
                *(_QWORD *)(BugCheckParameter2 + 2248) = BugCheckParameter2 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v1256 + 2256) = v54 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v1256 + 2264) = *(int *)v54;
                *(_QWORD *)(v1256 + 2272) = v1280;
                *(_DWORD *)(v1256 + 2240) = 1;
                __b9(v1256, 0i64);
              }
            }
            v1256 = BugCheckParameter2;
            goto LABEL_2093;
          }
        }
        else
        {
          v1688 = 0i64;
          v1690 = 0;
          v1692 = 4096;
          v1689 = 8 * ((((unsigned __int64)(v1280 & 0xFFF) + 0x1FFF) >> 12) + 6);
          v1691 = v1280 & 0xFFFFFFFFFFFFF000ui64;
          v1693 = v1280 & 0xFFF;
          v1694 = (unsigned __int64)(*(__int64 (__fastcall **)(__int64))(v1256 + 1096))(v1222 + v1225) >> 12;
        }
        v1284 = BugCheckParameter2;
        ++*(_DWORD *)(BugCheckParameter2 + 2056);
        *(_QWORD *)(v1284 + 2608) = v1691 + v1693;
        *(_QWORD *)(v1284 + 2600) = v1579;
        v1285 = KeGetCurrentIrql();
        __writecr8(2ui64);
        RtlInitMinimalBarrier(v1284 + 2568, **(unsigned int **)(v1284 + 1488), 0i64, v1282);
        v1256 = (*(__int64 (__fastcall **)(ULONG_PTR))(BugCheckParameter2 + 1080))(BugCheckParameter2 + *(unsigned int *)(BugCheckParameter2 + 1980));
        BugCheckParameter2 = v1256;
        __writecr8(v1285);
        if ( v1226 )
        {
          (*(void (__fastcall **)(__int64 *, __int64, __int64, _QWORD))(v1256 + 1104))(&v1688, v1286, v1256, 0i64);
          v1256 = BugCheckParameter2;
        }
        *(_DWORD *)(v1256 + 2032) += 81920;
        goto LABEL_2093;
      }
LABEL_2103:
      if ( !*(_DWORD *)(v21 + 2028) )
      {
        if ( v77 == 12 )
        {
          if ( !*(_QWORD *)(v21 + 2376) )
          {
            *(_DWORD *)(v21 + 2028) = 0;
            goto LABEL_2185;
          }
          v1287 = *(_DWORD *)(v21 + 2396);
          *(_DWORD *)(v21 + 2396) = v1287 ^ ((unsigned __int8)v1287 ^ (unsigned __int8)(8 * v1287)) & 0x20;
          if ( (((unsigned __int8)v1287 ^ ((unsigned __int8)v1287 ^ (unsigned __int8)(8 * v1287)) & 0x20) & 4) != 0 )
          {
            v1288 = *((_QWORD *)v64 + 1) & 0xFFFFFFFFFFFFF000ui64;
            v1289 = ((*((_DWORD *)v64 + 2) & 0xFFF) + (unsigned __int64)*((unsigned int *)v64 + 4) + 4095) >> 12;
            if ( !v1289 )
              goto LABEL_2185;
            do
            {
              --v1289;
              if ( (*(unsigned __int8 (__fastcall **)(unsigned __int64))(v21 + 672))(v1288) && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *(int *)v64;
                *(_QWORD *)(v21 + 2272) = v1288;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              *(_DWORD *)(v21 + 2032) += 256;
              v1288 += 4096i64;
            }
            while ( v1289 );
LABEL_2184:
            v77 = v1782;
            goto LABEL_2185;
          }
          v1290 = (_QWORD *)*((_QWORD *)v64 + 1);
          v1291 = *((unsigned int *)v64 + 4);
          v1292 = v1290;
          *(_DWORD *)(v21 + 2032) += v1291;
          v1293 = (const char *)v1290;
          v1294 = *(_DWORD *)(v21 + 2012);
          v1295 = *(_QWORD *)(v21 + 2016);
          if ( v1290 < (_QWORD *)((char *)v1290 + v1291) )
          {
            do
            {
              _mm_prefetch(v1293, 0);
              v1293 += 64;
            }
            while ( v1293 < (const char *)v1290 + v1291 );
          }
          v1296 = *(_QWORD *)(v21 + 2016);
          v1297 = (unsigned int)v1291 >> 7;
          if ( (unsigned int)v1291 >> 7 )
          {
            do
            {
              v1298 = 8i64;
              do
              {
                v1299 = v1296 ^ *v1292;
                v1300 = v1292[1];
                v1292 += 2;
                v1296 = __ROL8__(__ROL8__(v1299, v1294) ^ v1300, v1294);
                --v1298;
              }
              while ( v1298 );
              v1301 = __ROL8__(v1295 ^ ((char *)v1292 - (char *)v1290), 17) ^ v1295 ^ ((char *)v1292 - (char *)v1290);
              v1726 = (v1301 * (unsigned __int128)0x7010008004002001ui64) >> 64;
              v1294 = ((unsigned __int8)(v1726 ^ v1301) ^ (unsigned __int8)v1294) & 0x3F;
              if ( !v1294 )
                LOBYTE(v1294) = 1;
              --v1297;
            }
            while ( v1297 );
            v21 = (ULONG_PTR)v1580;
          }
          v1302 = v1291 & 0x7F;
          if ( v1302 >= 8 )
          {
            v1303 = (unsigned __int64)v1302 >> 3;
            do
            {
              v1296 = __ROL8__(*v1292++ ^ v1296, v1294);
              v1302 -= 8;
              --v1303;
            }
            while ( v1303 );
          }
          if ( v1302 )
          {
            do
            {
              v1304 = *(unsigned __int8 *)v1292;
              v1292 = (_QWORD *)((char *)v1292 + 1);
              v1296 = __ROL8__(v1304 ^ v1296, v1294);
              --v1302;
            }
            while ( v1302 );
            v21 = (ULONG_PTR)v1580;
          }
          for ( i6 = v1296; ; LODWORD(v1296) = i6 ^ v1296 )
          {
            i6 >>= 31;
            if ( !i6 )
              break;
          }
          v1306 = *((_DWORD *)v64 + 5);
          v1307 = v1296 & 0x7FFFFFFF;
          if ( v1307 == v1306 )
            goto LABEL_2184;
          v1308 = *((unsigned int *)v64 + 4);
          v1309 = *((_QWORD *)v64 + 1);
          if ( *((_DWORD *)v64 + 4) && (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
          {
            v1310 = KeGetCurrentIrql();
            __writecr8(2ui64);
            v1311 = v1309 & 0xFFFFFFFFFFFFF000ui64;
            v1312 = (v1309 + v1308 - 1) | 0xFFF;
            v1313 = (v1309 & 0xFFFFFFFFFFFFF000ui64) - 1;
            while ( 1 )
            {
              v1314 = v1310;
              while ( 1 )
              {
                v1315 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(v21 + 1112))(v1311, 0i64);
                if ( v1315 != -1073741267 )
                  break;
                if ( v1310 > 1u )
                  goto LABEL_2141;
                v1314 = v1310;
                __writecr8(v1310);
                KeGetCurrentIrql();
                __writecr8(2ui64);
              }
              if ( v1315 < 0 )
                break;
LABEL_2141:
              v1311 += 4096i64;
              v1313 += 4096i64;
              if ( v1313 == v1312 )
                goto LABEL_2142;
            }
            __writecr8(v1314);
            v64 = (char *)v1579;
            v1306 = v1579[5];
          }
          if ( *(_DWORD *)(v21 + 2240) )
            goto LABEL_2184;
          v1316 = v1306;
        }
        else
        {
          v1317 = (_QWORD *)*((_QWORD *)v64 + 1);
          v1318 = *((unsigned int *)v64 + 4);
          v1319 = v1317;
          *(_DWORD *)(v21 + 2032) += v1318;
          v1320 = (const char *)v1317;
          v1321 = *(_DWORD *)(v21 + 2012);
          v1322 = *(_QWORD *)(v21 + 2016);
          if ( v1317 < (_QWORD *)((char *)v1317 + v1318) )
          {
            do
            {
              _mm_prefetch(v1320, 0);
              v1320 += 64;
            }
            while ( v1320 < (const char *)v1317 + v1318 );
          }
          v1323 = *(_QWORD *)(v21 + 2016);
          v1324 = (unsigned int)v1318 >> 7;
          if ( (unsigned int)v1318 >> 7 )
          {
            do
            {
              v1325 = 8i64;
              do
              {
                v1326 = v1323 ^ *v1319;
                v1327 = v1319[1];
                v1319 += 2;
                v1323 = __ROL8__(__ROL8__(v1326, v1321) ^ v1327, v1321);
                --v1325;
              }
              while ( v1325 );
              v1328 = __ROL8__(v1322 ^ ((char *)v1319 - (char *)v1317), 17) ^ v1322 ^ ((char *)v1319 - (char *)v1317);
              v1727 = (v1328 * (unsigned __int128)0x7010008004002001ui64) >> 64;
              v1321 = ((unsigned __int8)v1727 ^ (unsigned __int8)(v1328 ^ v1321)) & 0x3F;
              if ( !v1321 )
                LOBYTE(v1321) = 1;
              --v1324;
            }
            while ( v1324 );
            v21 = (ULONG_PTR)v1580;
          }
          v1329 = v1318 & 0x7F;
          if ( v1329 >= 8 )
          {
            v1330 = (unsigned __int64)v1329 >> 3;
            do
            {
              v1323 = __ROL8__(*v1319++ ^ v1323, v1321);
              v1329 -= 8;
              --v1330;
            }
            while ( v1330 );
          }
          if ( v1329 )
          {
            do
            {
              v1331 = *(unsigned __int8 *)v1319;
              v1319 = (_QWORD *)((char *)v1319 + 1);
              v1323 = __ROL8__(v1331 ^ v1323, v1321);
              --v1329;
            }
            while ( v1329 );
            v21 = (ULONG_PTR)v1580;
          }
          for ( i7 = v1323; ; LODWORD(v1323) = i7 ^ v1323 )
          {
            i7 >>= 31;
            if ( !i7 )
              break;
          }
          v1307 = v1323 & 0x7FFFFFFF;
          if ( v1307 == *((_DWORD *)v64 + 5) )
            goto LABEL_2184;
          if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
            v69 = 1;
          v1333 = *((unsigned int *)v64 + 4);
          v1334 = *((_QWORD *)v64 + 1);
          if ( *((_DWORD *)v64 + 4) )
          {
            v1335 = 64i64;
            if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
            {
              v1336 = KeGetCurrentIrql();
              __writecr8(2ui64);
              v1337 = v1334 & 0xFFFFFFFFFFFFF000ui64;
              v1595 = (v1334 + v1333 - 1) | 0xFFF;
              v1338 = (v1334 & 0xFFFFFFFFFFFFF000ui64) - 1;
              while ( 1 )
              {
                v1314 = v1336;
                while ( 1 )
                {
                  v1339 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                            v1337,
                            0i64,
                            v1335,
                            v1319);
                  if ( v1339 != -1073741267 )
                    break;
                  if ( v69 )
                    goto LABEL_2179;
                  if ( v1336 > 1u )
                    goto LABEL_2177;
                  v1314 = v1336;
                  __writecr8(v1336);
                  KeGetCurrentIrql();
                  __writecr8(2ui64);
                }
                if ( v1339 < 0 )
                  break;
LABEL_2177:
                v1337 += 4096i64;
                v1338 += 4096i64;
                if ( v1338 == v1595 )
                {
LABEL_2142:
                  __writecr8(v1314);
                  goto LABEL_2184;
                }
              }
LABEL_2179:
              __writecr8(v1314);
              v64 = (char *)v1579;
            }
          }
          if ( *(_DWORD *)(v21 + 2240) )
            goto LABEL_2184;
          v1316 = *((unsigned int *)v64 + 5);
        }
        *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v1307 ^ v1316;
        v1340 = *((_QWORD *)v64 + 1);
        if ( !*(_DWORD *)(v21 + 2240) )
        {
          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
          *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
          *(_QWORD *)(v21 + 2264) = *(int *)v64;
          *(_QWORD *)(v21 + 2272) = v1340;
          *(_DWORD *)(v21 + 2240) = 1;
          __b9(v21, 0i64);
        }
        goto LABEL_2184;
      }
LABEL_2185:
      v1341 = v1579;
      v1342 = *(unsigned int *)(v21 + 2028);
      v54 = (unsigned int)v1579[4];
      v1343 = &v1579[v1342 + 12];
      v1585 = *((_QWORD *)v1579 + 1);
      v1587 = (unsigned int *)v1343;
      v1344 = (unsigned int *)(v1585 + 12 * v1342);
      v1588 = v1344;
      v1345 = v1585 + 12 * (v54 / 0xC);
      v1593 = v1345;
      if ( v1344 == (unsigned int *)v1345 )
        goto LABEL_2259;
      while ( 2 )
      {
        if ( *v1343 >= 0 )
        {
          v1346 = *v1344;
          v1347 = v1346 + *((_QWORD *)v1341 + 4);
          v1348 = v1344[1] - v1346;
          v1595 = v1347;
          if ( v77 == 43 )
          {
            v1365 = sub_140ACD678(v21, v1347, v1348);
            *(_DWORD *)(v21 + 2032) += 8 * v1348;
            v1364 = v1365;
            if ( (*(_DWORD *)(v21 + 2396) & 0x800) != 0 )
            {
              v1366 = (_BYTE *)(v1347 - 6);
              v1367 = (char *)(v1347 - 6 + 5);
              v1368 = *v1367;
              if ( *(_BYTE *)(v1347 - 6) != 76
                || v1366[1] != 0x87
                || v1366[2]
                || v1366[3] != 0x98
                || v1366[4] != 0xC3
                || v1368 != -112 && v1368 != -15 )
              {
                goto LABEL_2551;
              }
              v1369 = *(volatile signed __int32 **)(v21 + 1208);
              while ( 1 )
              {
                _disable();
                if ( !_interlockedbittestandset(v1369, (*(_DWORD *)(v21 + 2392) >> 10) & 0x1F) )
                  break;
                _enable();
                _mm_pause();
              }
              v1370 = *(struct _KPRCB **)(v21 + 2216);
              v1371 = 38i64;
              v1372 = 304;
              v1373 = v1370;
              do
              {
                *(_QWORD *)&v1373->MxCsr = 0i64;
                v1372 -= 8;
                v1373 = (struct _KPRCB *)((char *)v1373 + 8);
                --v1371;
              }
              while ( v1371 );
              if ( v1372 )
              {
                v1371 = 0xFFFFFFFFi64;
                do
                {
                  LOBYTE(v1373->MxCsr) = 0;
                  v1373 = (struct _KPRCB *)((char *)v1373 + 1);
                  --v1372;
                }
                while ( v1372 );
              }
              *(_OWORD *)&v1370->NextThread = *(_OWORD *)(v21 + 2064);
              *(_OWORD *)&v1370->NestingLevel = *(_OWORD *)(v21 + 2080);
              *(_OWORD *)&v1370->ProcessorState.SpecialRegisters.KernelDr0 = *(_OWORD *)(v21 + 2096);
              v1663[0] = 303;
              *(_QWORD *)&v1663[1] = v1370;
              LOWORD(v1370->NextThread) = v21 + 2132;
              v1374 = (v21 + 2132) >> 16;
              v1729 = v21 + 2132;
              HIWORD(v1370->NextThread) = v1374;
              LODWORD(v1370->IdleThread) = (v21 + 2132) >> 32;
              __sidt(v1685);
              __lidt(v1663);
              *v1367 = -15;
              if ( *v1367 != -15 )
                goto LABEL_2230;
              if ( (*(_DWORD *)(v21 + 2396) & 0x20000) == 0 )
              {
                v1370 = KeGetCurrentPrcb();
                v1374 = v21 - 0x5C5FC0A76E374B18i64;
                **(_QWORD **)(v21 + 1176) = v21 - 0x5C5FC0A76E374B18i64;
                **(_QWORD **)(v21 + 1184) = v1370;
                **(_QWORD **)(v21 + 1192) = v1347;
                **(_QWORD **)(v21 + 1200) = 275i64;
              }
              ((void (__fastcall *)(unsigned __int64, struct _KPRCB *, __int64, __int64))(v1347 - 6 + 5))(
                v1374,
                v1370,
                v1371,
                1i64);
              if ( (*(_DWORD *)(v21 + 2396) & 0x20000) == 0 )
              {
                **(_QWORD **)(v21 + 1176) = 0xA3A03F5891C8B4E8ui64;
                **(_QWORD **)(v21 + 1184) = 0i64;
                **(_QWORD **)(v21 + 1192) = 0i64;
                **(_QWORD **)(v21 + 1200) = 0i64;
              }
              if ( *v1367 == -15 )
              {
                *v1367 = -112;
                v1375 = *v1367 == -112;
              }
              else
              {
LABEL_2230:
                v1375 = 0;
              }
              __lidt(v1685);
              _InterlockedAnd(
                *(volatile signed __int32 **)(v21 + 1208),
                ~(1 << ((*(_DWORD *)(v21 + 2392) >> 10) & 0x1F)));
              _enable();
              if ( !v1375 )
              {
LABEL_2551:
                if ( !*(_DWORD *)(v21 + 2240) )
                {
                  v1376 = v1579;
                  *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                  *(_QWORD *)(v21 + 2256) = (char *)v1376 - 0x4C48B4211BBACBEBi64;
                  *(_QWORD *)(v21 + 2264) = *v1376;
                  *(_QWORD *)(v21 + 2272) = v1366;
                  *(_DWORD *)(v21 + 2240) = 1;
                  __b9(v21, 0i64);
                }
              }
              v1344 = v1588;
              v1345 = v1593;
            }
          }
          else
          {
            *(_DWORD *)(v21 + 2032) += v1348;
            v1349 = (_QWORD *)v1347;
            v1350 = *(_DWORD *)(v21 + 2012);
            v1351 = (const char *)v1347;
            v1352 = *(_QWORD *)(v21 + 2016);
            v1353 = v1347 + v1348;
            if ( v1347 < v1353 )
            {
              do
              {
                _mm_prefetch(v1351, 0);
                v1351 += 64;
              }
              while ( (unsigned __int64)v1351 < v1353 );
            }
            v1354 = *(_QWORD *)(v21 + 2016);
            v1355 = v1348 >> 7;
            if ( v1348 >> 7 )
            {
              do
              {
                v1356 = 8i64;
                do
                {
                  v1357 = v1354 ^ *v1349;
                  v1358 = v1349[1];
                  v1349 += 2;
                  v1354 = __ROL8__(__ROL8__(v1357, v1350) ^ v1358, v1350);
                  --v1356;
                }
                while ( v1356 );
                v1359 = __ROL8__(v1352 ^ ((unsigned __int64)v1349 - v1347), 17) ^ v1352 ^ ((unsigned __int64)v1349
                                                                                         - v1347);
                v1728 = (v1359 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                v1350 = ((unsigned __int8)v1728 ^ (unsigned __int8)(v1359 ^ v1350)) & 0x3F;
                if ( !v1350 )
                  LOBYTE(v1350) = 1;
                --v1355;
              }
              while ( v1355 );
              v21 = (ULONG_PTR)v1580;
              v1343 = (int *)v1587;
            }
            v1360 = v1348 & 0x7F;
            if ( v1360 >= 8 )
            {
              v1361 = (unsigned __int64)(v1348 & 0x7F) >> 3;
              do
              {
                v1354 = __ROL8__(*v1349++ ^ v1354, v1350);
                v1360 -= 8;
                --v1361;
              }
              while ( v1361 );
              v1345 = v1593;
            }
            if ( v1360 )
            {
              do
              {
                v1362 = *(unsigned __int8 *)v1349;
                v1349 = (_QWORD *)((char *)v1349 + 1);
                v1354 = __ROL8__(v1362 ^ v1354, v1350);
                --v1360;
              }
              while ( v1360 );
              v21 = (ULONG_PTR)v1580;
              v1343 = (int *)v1587;
            }
            for ( i8 = v1354; ; LODWORD(v1354) = i8 ^ v1354 )
            {
              i8 >>= 31;
              if ( !i8 )
                break;
            }
            v1364 = v1354 & 0x7FFFFFFF;
          }
          v54 = (unsigned int)*v1343;
          if ( v1364 != (*v1343 & 0x7FFFFFFF) )
          {
            v1377 = v1348;
            if ( v1348 && (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
            {
              v1378 = KeGetCurrentIrql();
              __writecr8(2ui64);
              v1379 = v1347 & 0xFFFFFFFFFFFFF000ui64;
              v1380 = (v1377 + v1347 - 1) | 0xFFF;
              v1381 = (v1347 & 0xFFFFFFFFFFFFF000ui64) - 1;
              while ( 1 )
              {
                v1382 = v1378;
                while ( 1 )
                {
                  v1383 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(v21 + 1112))(v1379, 0i64);
                  if ( v1383 != -1073741267 )
                    break;
                  if ( v1378 > 1u )
                    goto LABEL_2245;
                  v1382 = v1378;
                  __writecr8(v1378);
                  KeGetCurrentIrql();
                  __writecr8(2ui64);
                }
                if ( v1383 < 0 )
                  break;
LABEL_2245:
                v1379 += 4096i64;
                v1381 += 4096i64;
                if ( v1381 == v1380 )
                {
                  __writecr8(v1382);
                  v1343 = (int *)v1587;
                  goto LABEL_2247;
                }
              }
              __writecr8(v1382);
              v1343 = (int *)v1587;
              v1347 = v1595;
              v54 = *v1587;
            }
            v1385 = (unsigned int)v54;
            LODWORD(v1385) = v54 & 0x7FFFFFFF;
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              v1386 = v1364;
              v1341 = v1579;
              v54 = v1385 ^ v1386;
              *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v54;
              if ( !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = (char *)v1341 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v1341;
                *(_QWORD *)(v21 + 2272) = v1347;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              v1344 = v1588;
              v1345 = v1593;
              goto LABEL_2249;
            }
LABEL_2247:
            v1345 = v1593;
            v1344 = v1588;
          }
          v1341 = v1579;
        }
LABEL_2249:
        ++v1343;
        v1344 += 3;
        v1587 = (unsigned int *)v1343;
        v1588 = v1344;
        v1384 = v1344 == (unsigned int *)v1345;
        if ( (unsigned __int64)v1344 >= v1345 )
          goto LABEL_2252;
        v77 = v1782;
        if ( *(_DWORD *)(v21 + 2032) >= *(_DWORD *)(v21 + 2036) )
        {
          v1384 = v1344 == (unsigned int *)v1345;
LABEL_2252:
          if ( !v1384 )
          {
            *(_DWORD *)(v21 + 2028) = (__int64)((__int64)v1344 - v1585) / 12;
            goto LABEL_146;
          }
LABEL_2259:
          v1387 = *(_QWORD *)(v21 + 1304);
          v1388 = KeGetCurrentIrql();
          __writecr8(0xFui64);
          (*(void (__fastcall **)(__int64))(v21 + 320))(v1387);
          v1390 = **(unsigned int ***)(v21 + 1512);
          v1391 = v1390 + 4;
          v1392 = *((_BYTE *)v1390 + 12);
          v1393 = (unsigned __int64)&v1390[6 * *v1390 + 4];
          do
          {
            v1394 = 24i64;
            v1395 = (__int64 *)(v1341 + 6);
            v1396 = v1391;
            do
            {
              v1397 = *(_QWORD *)v1396;
              v1396 += 2;
              v1398 = *v1395++;
              if ( v1397 != v1398 )
                goto LABEL_2267;
              v1394 = (unsigned int)(v1394 - 8);
            }
            while ( (unsigned int)v1394 >= 8 );
            if ( !(_DWORD)v1394 )
              break;
            while ( 1 )
            {
              v1389 = *(unsigned __int8 *)v1396;
              v1396 = (unsigned int *)((char *)v1396 + 1);
              v1399 = *(unsigned __int8 *)v1395;
              v1395 = (__int64 *)((char *)v1395 + 1);
              if ( v1389 != v1399 )
                break;
              v73 = (_DWORD)v1394 == 1;
              v1394 = (unsigned int)(v1394 - 1);
              if ( v73 )
                goto LABEL_2268;
            }
LABEL_2267:
            v1391 += 6;
          }
          while ( (unsigned __int64)v1391 < v1393 );
LABEL_2268:
          v21 = (ULONG_PTR)v1580;
          (*((void (__fastcall **)(_QWORD, __int64, __int64, __int64 *))v1580 + 48))(
            *((_QWORD *)v1580 + 163),
            v1389,
            v1394,
            v1395);
          __writecr8(v1388);
          if ( !v1392 )
            goto LABEL_2552;
          v54 = 16i64;
          if ( (*(_DWORD *)(v21 + 2396) & 0x10) != 0 && !*(_DWORD *)(v21 + 2240) )
          {
            *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
            *(_QWORD *)(v21 + 2256) = (char *)v1341 - 0x4C48B4211BBACBEBi64;
            *(_QWORD *)(v21 + 2264) = *v1341;
            *(_QWORD *)(v21 + 2272) = 1i64;
            *(_DWORD *)(v21 + 2240) = 1;
            __b9(v21, 0i64);
          }
          if ( *((_QWORD *)v1341 + 3) != 1i64 )
          {
LABEL_2552:
            if ( v1391 == (unsigned int *)v1393 && !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = (char *)v1341 - 0x4C48B4211BBACBEBi64;
              *(_QWORD *)(v21 + 2264) = *v1341;
              *(_QWORD *)(v21 + 2272) = v1391;
              *(_DWORD *)(v21 + 2240) = 1;
              __b9(v21, 0i64);
            }
          }
LABEL_1745:
          *(_DWORD *)(v21 + 2028) = 0;
          goto LABEL_146;
        }
        continue;
      }
    }
    if ( v77 == 28 )
    {
      v753 = *((unsigned int *)v64 + 4);
      if ( (_DWORD)v753 )
      {
        v805 = (_QWORD *)*((_QWORD *)v64 + 1);
        *(_DWORD *)(v21 + 2032) += v753;
        v806 = v805;
        v807 = *(_DWORD *)(v21 + 2012);
        v808 = (const char *)v805;
        v809 = *(_QWORD *)(v21 + 2016);
        if ( v805 < (_QWORD *)((char *)v805 + v753) )
        {
          do
          {
            _mm_prefetch(v808, 0);
            v808 += 64;
          }
          while ( v808 < (const char *)v805 + v753 );
        }
        v810 = *(_QWORD *)(v21 + 2016);
        v811 = (unsigned int)v753 >> 7;
        if ( (unsigned int)v753 >> 7 )
        {
          do
          {
            v812 = 8i64;
            do
            {
              v813 = v810 ^ *v806;
              v814 = v806[1];
              v806 += 2;
              v810 = __ROL8__(__ROL8__(v813, v807) ^ v814, v807);
              --v812;
            }
            while ( v812 );
            v815 = __ROL8__(v809 ^ ((char *)v806 - (char *)v805), 17) ^ v809 ^ ((char *)v806 - (char *)v805);
            v1713 = (v815 * (unsigned __int128)0x7010008004002001ui64) >> 64;
            v807 = ((unsigned __int8)(v815 ^ v1713) ^ (unsigned __int8)v807) & 0x3F;
            if ( !v807 )
              LOBYTE(v807) = 1;
            --v811;
          }
          while ( v811 );
          v21 = (ULONG_PTR)v1580;
        }
        v816 = v753 & 0x7F;
        if ( v816 >= 8 )
        {
          v817 = (unsigned __int64)v816 >> 3;
          do
          {
            v810 = __ROL8__(*v806++ ^ v810, v807);
            v816 -= 8;
            --v817;
          }
          while ( v817 );
        }
        if ( v816 )
        {
          do
          {
            v818 = *(unsigned __int8 *)v806;
            v806 = (_QWORD *)((char *)v806 + 1);
            v810 = __ROL8__(v818 ^ v810, v807);
            --v816;
          }
          while ( v816 );
          v21 = (ULONG_PTR)v1580;
        }
        for ( i9 = v810; ; LODWORD(v810) = i9 ^ v810 )
        {
          i9 >>= 31;
          if ( !i9 )
            break;
        }
        v820 = v810 & 0x7FFFFFFF;
        if ( v820 == *((_DWORD *)v64 + 5) )
          goto LABEL_1324;
        if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
          v69 = 1;
        v821 = *((unsigned int *)v64 + 4);
        v822 = *((_QWORD *)v64 + 1);
        if ( *((_DWORD *)v64 + 4) )
        {
          v823 = 64i64;
          if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
          {
            v824 = KeGetCurrentIrql();
            __writecr8(2ui64);
            v825 = v822 & 0xFFFFFFFFFFFFF000ui64;
            v1795 = (v822 + v821 - 1) | 0xFFF;
            v826 = (v822 & 0xFFFFFFFFFFFFF000ui64) - 1;
            while ( 1 )
            {
              v827 = v824;
              while ( 1 )
              {
                v828 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                         v825,
                         0i64,
                         v823,
                         v806);
                if ( v828 != -1073741267 )
                  break;
                if ( v69 )
                  goto LABEL_1341;
                if ( v824 > 1u )
                  goto LABEL_1322;
                v827 = v824;
                __writecr8(v824);
                KeGetCurrentIrql();
                __writecr8(2ui64);
              }
              if ( v828 < 0 )
                break;
LABEL_1322:
              v825 += 4096i64;
              v826 += 4096i64;
              if ( v826 == v1795 )
              {
                __writecr8(v827);
                v64 = (char *)v1579;
LABEL_1324:
                v829 = 0;
                v1609 = *((_QWORD *)v64 + 1) - 112i64;
                v784 = *(unsigned int **)(v1609 + 80);
                if ( v784 )
                  v829 = *v784;
                *(_DWORD *)(v21 + 2032) += v829;
                v830 = v784;
                v831 = *(_DWORD *)(v21 + 2012);
                v832 = (const char *)v784;
                v833 = *(_QWORD *)(v21 + 2016);
                v54 = (unsigned __int64)v784 + v829;
                if ( (unsigned __int64)v784 < v54 )
                {
                  do
                  {
                    _mm_prefetch(v832, 0);
                    v832 += 64;
                  }
                  while ( (unsigned __int64)v832 < v54 );
                }
                v834 = *(_QWORD *)(v21 + 2016);
                v835 = v829 >> 7;
                if ( v829 >> 7 )
                {
                  do
                  {
                    v836 = 8i64;
                    do
                    {
                      v837 = v834 ^ *(_QWORD *)v830;
                      v838 = *((_QWORD *)v830 + 1);
                      v830 += 4;
                      v834 = __ROL8__(__ROL8__(v837, v831) ^ v838, v831);
                      --v836;
                    }
                    while ( v836 );
                    v54 = __ROL8__(v833 ^ ((char *)v830 - (char *)v784), 17) ^ v833 ^ ((char *)v830 - (char *)v784);
                    v1714 = (v54 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                    v831 = ((unsigned __int8)v54 ^ (unsigned __int8)(v1714 ^ v831)) & 0x3F;
                    if ( !v831 )
                      v831 = 1;
                    --v835;
                  }
                  while ( v835 );
                  v21 = (ULONG_PTR)v1580;
                }
                v839 = v829 & 0x7F;
                if ( v839 >= 8 )
                {
                  v840 = (unsigned __int64)v839 >> 3;
                  do
                  {
                    v54 = v831;
                    v834 = __ROL8__(*(_QWORD *)v830 ^ v834, v831);
                    v830 += 2;
                    v839 -= 8;
                    --v840;
                  }
                  while ( v840 );
                }
                for ( ; v839; --v839 )
                {
                  v841 = *(unsigned __int8 *)v830;
                  v54 = v831;
                  v830 = (unsigned int *)((char *)v830 + 1);
                  v834 = __ROL8__(v841 ^ v834, v831);
                }
                for ( i10 = v834 >> 31; i10; i10 >>= 31 )
                  LODWORD(v834) = i10 ^ v834;
                v844 = *((unsigned int *)v64 + 11);
                v845 = v834 & 0x7FFFFFFF;
                if ( v845 == (_DWORD)v844 || *(_DWORD *)(v21 + 2240) )
                  goto LABEL_146;
                v54 = v844 ^ v845;
                *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v54;
                goto LABEL_1278;
              }
            }
LABEL_1341:
            __writecr8(v827);
            v64 = (char *)v1579;
          }
        }
        if ( !*(_DWORD *)(v21 + 2240) )
        {
          *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = *((unsigned int *)v64 + 5) ^ (unsigned __int64)v820;
          v843 = *((_QWORD *)v64 + 1);
          if ( !*(_DWORD *)(v21 + 2240) )
          {
            *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
            *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
            *(_QWORD *)(v21 + 2264) = *(int *)v64;
            *(_QWORD *)(v21 + 2272) = v843;
            *(_DWORD *)(v21 + 2240) = 1;
            __b9(v21, 0i64);
          }
        }
        goto LABEL_1324;
      }
      v1677 = v64 + 48;
      v754 = *((_WORD *)v64 + 20);
      v1578 = &v1609;
      v1676[0] = v754;
      v1676[1] = v754;
      v755 = *(_QWORD *)(v21 + 1256);
      v756 = *(int (__fastcall **)(__int16 *, _QWORD, _QWORD, _QWORD, __int64, _DWORD, _QWORD, __int64 *))(v21 + 472);
      LOBYTE(v1577) = 0;
      if ( v756(v1676, 0i64, 0i64, 0i64, v755, v1577, 0i64, &v1609) < 0 )
        goto LABEL_146;
      if ( (*(_DWORD *)(v1609 + 16) & 0x10) == 0 )
      {
        v757 = v1609;
        goto LABEL_1215;
      }
      (*(void (__fastcall **)(_QWORD, char *))(v21 + 496))(*(_QWORD *)(v21 + 472), v1773);
      if ( v1774 )
      {
        v758 = *(__int64 (**)(void))(v21 + 488);
        v55 = v1774;
        v1615 = v1774;
        v759 = v758();
        if ( v759 )
        {
          v58 = *(_DWORD *)(v759 + 80);
          v1606 = v58;
        }
      }
      (*(void (__fastcall **)(_QWORD, char *))(v21 + 496))(*((_QWORD *)v64 + 3), v1775);
      if ( v1776 && (v760 = *(__int64 (**)(void))(v21 + 488), v57 = v1776, v1623 = v1776, (v761 = v760()) != 0) )
      {
        v762 = *(_DWORD *)(v761 + 80);
        v1603 = v762;
      }
      else
      {
        v762 = v1603;
      }
      if ( !_bittest((const signed __int32 *)(v21 + 2392), 0x1Eu) )
      {
        *((_QWORD *)v64 + 1) = v1609 + 112;
        *((_DWORD *)v64 + 4) = 224;
      }
      v757 = v1609;
      v763 = 0;
      v764 = v58;
      while ( 1 )
      {
        v765 = *(_QWORD *)(v1609 + 8i64 * v763 + 112);
        if ( (!v58 || v765 < v55 || v765 > v58 + v55 - 1) && (!v762 || v765 < v57 || v765 > v57 + v762 - 1i64) )
          break;
        if ( ++v763 >= 0x1Cu )
        {
          if ( !_bittest((const signed __int32 *)(v21 + 2392), 0x1Eu) )
          {
            v766 = (_QWORD *)*((_QWORD *)v64 + 1);
            v767 = *((unsigned int *)v64 + 4);
            v768 = v766;
            *(_DWORD *)(v21 + 2032) += v767;
            v769 = (const char *)v766;
            v770 = *(_DWORD *)(v21 + 2012);
            v771 = *(_QWORD *)(v21 + 2016);
            if ( v766 < (_QWORD *)((char *)v766 + v767) )
            {
              do
              {
                _mm_prefetch(v769, 0);
                v769 += 64;
              }
              while ( v769 < (const char *)v766 + v767 );
            }
            v772 = *(_QWORD *)(v21 + 2016);
            v773 = (unsigned int)v767 >> 7;
            if ( (unsigned int)v767 >> 7 )
            {
              do
              {
                v774 = 8i64;
                do
                {
                  v775 = v772 ^ *v768;
                  v776 = v768[1];
                  v768 += 2;
                  v772 = __ROL8__(__ROL8__(v775, v770) ^ v776, v770);
                  --v774;
                }
                while ( v774 );
                v777 = __ROL8__(v771 ^ ((char *)v768 - (char *)v766), 17) ^ v771 ^ ((char *)v768 - (char *)v766);
                v1711 = (v777 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                v770 = ((unsigned __int8)(v777 ^ v1711) ^ (unsigned __int8)v770) & 0x3F;
                if ( !v770 )
                  LOBYTE(v770) = 1;
                --v773;
              }
              while ( v773 );
              v21 = (ULONG_PTR)v1580;
              v55 = v1615;
            }
            v778 = v767 & 0x7F;
            if ( v778 >= 8 )
            {
              v779 = (unsigned __int64)v778 >> 3;
              do
              {
                v772 = __ROL8__(*v768++ ^ v772, v770);
                v778 -= 8;
                --v779;
              }
              while ( v779 );
            }
            v780 = 0;
            if ( v778 )
            {
              do
              {
                v781 = *(unsigned __int8 *)v768;
                v768 = (_QWORD *)((char *)v768 + 1);
                v772 = __ROL8__(v781 ^ v772, v770);
                --v778;
              }
              while ( v778 );
              v55 = v1615;
            }
            for ( i11 = v772; ; LODWORD(v772) = i11 ^ v772 )
            {
              i11 >>= 31;
              if ( !i11 )
                break;
            }
            v783 = 0;
            *((_DWORD *)v64 + 5) = v772 & 0x7FFFFFFF;
            v784 = *(unsigned int **)(v1609 + 80);
            if ( !v784 || (v783 = *v784, (v785 = (*v784 - 8) >> 3) == 0) )
            {
LABEL_1262:
              *(_DWORD *)(v21 + 2032) += v783;
              v786 = v784;
              v787 = *(_DWORD *)(v21 + 2012);
              v788 = (const char *)v784;
              v789 = *(_QWORD *)(v21 + 2016);
              v54 = (unsigned __int64)v784 + v783;
              if ( (unsigned __int64)v784 < v54 )
              {
                do
                {
                  _mm_prefetch(v788, 0);
                  v788 += 64;
                }
                while ( (unsigned __int64)v788 < v54 );
              }
              v790 = *(_QWORD *)(v21 + 2016);
              v791 = v783 >> 7;
              if ( v783 >> 7 )
              {
                do
                {
                  v792 = 8i64;
                  do
                  {
                    v793 = v790 ^ *(_QWORD *)v786;
                    v794 = *((_QWORD *)v786 + 1);
                    v786 += 4;
                    v790 = __ROL8__(__ROL8__(v793, v787) ^ v794, v787);
                    --v792;
                  }
                  while ( v792 );
                  v54 = __ROL8__(v789 ^ ((char *)v786 - (char *)v784), 17) ^ v789 ^ ((char *)v786 - (char *)v784);
                  v1712 = (v54 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                  v787 = ((unsigned __int8)(v54 ^ v1712) ^ (unsigned __int8)v787) & 0x3F;
                  if ( !v787 )
                    v787 = 1;
                  --v791;
                }
                while ( v791 );
                v21 = (ULONG_PTR)v1580;
              }
              v795 = v783 & 0x7F;
              if ( v795 >= 8 )
              {
                v796 = (unsigned __int64)v795 >> 3;
                do
                {
                  v54 = v787;
                  v790 = __ROL8__(*(_QWORD *)v786 ^ v790, v787);
                  v786 += 2;
                  v795 -= 8;
                  --v796;
                }
                while ( v796 );
              }
              for ( ; v795; --v795 )
              {
                v797 = *(unsigned __int8 *)v786;
                v54 = v787;
                v786 = (unsigned int *)((char *)v786 + 1);
                v790 = __ROL8__(v797 ^ v790, v787);
              }
              for ( i12 = v790 >> 31; i12; i12 >>= 31 )
                LODWORD(v790) = i12 ^ v790;
              *((_DWORD *)v64 + 11) = v790 & 0x7FFFFFFF;
              goto LABEL_146;
            }
            while ( 1 )
            {
              v54 = *(_QWORD *)&v784[2 * v780 + 2];
              if ( v54
                && (!v764 || v54 < v55 || v54 > v55 + v764 - 1)
                && (!v1603 || v54 < v1623 || v54 > v1603 + v1623 - 1) )
              {
                break;
              }
              if ( ++v780 >= v785 )
                goto LABEL_1262;
            }
            *((_QWORD *)v64 + 4) = v54;
            v799 = *(_QWORD *)(v21 + 1384);
            *(_QWORD *)v799 = v64;
            *(_DWORD *)(v799 + 16) = 48;
LABEL_1278:
            if ( *(_DWORD *)(v21 + 2240) )
              goto LABEL_146;
            *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
            *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
            *(_QWORD *)(v21 + 2264) = *(int *)v64;
            *(_QWORD *)(v21 + 2272) = v784;
LABEL_1131:
            *(_DWORD *)(v21 + 2240) = 1;
            __b9(v21, 0i64);
            goto LABEL_146;
          }
LABEL_1215:
          (*(void (__fastcall **)(__int64))(v21 + 464))(v757);
          goto LABEL_146;
        }
      }
      if ( _bittest((const signed __int32 *)(v21 + 2392), 0x1Eu) )
      {
        v800 = *(_QWORD **)(v21 + 2632);
        v801 = 48;
        v802 = 6i64;
        do
        {
          v801 -= 8;
          *v800 = *(_QWORD *)v64;
          v64 += 8;
          ++v800;
          --v802;
        }
        while ( v802 );
        if ( v801 )
        {
          do
          {
            v803 = *v64++;
            *(_BYTE *)v800 = v803;
            v800 = (_QWORD *)((char *)v800 + 1);
            --v801;
          }
          while ( v801 );
          v21 = (ULONG_PTR)v1580;
        }
        v64 = *(char **)(v21 + 2632);
      }
      *((_QWORD *)v64 + 4) = v765;
      v804 = *(_QWORD *)(v21 + 1384);
      *(_QWORD *)v804 = v64;
      *(_DWORD *)(v804 + 16) = 48;
LABEL_442:
      v54 = *((_QWORD *)v64 + 1);
      if ( *(_DWORD *)(v21 + 2240) )
        goto LABEL_146;
      *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
      *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
      *(_QWORD *)(v21 + 2264) = *(int *)v64;
      *(_QWORD *)(v21 + 2272) = v54;
      goto LABEL_1131;
    }
    if ( v77 > 12 )
    {
      if ( v77 <= 14 )
      {
        if ( v77 == 14 )
        {
          if ( !*(_QWORD *)(v21 + 2376) )
            goto LABEL_1745;
          v54 = *(unsigned int *)(v21 + 2396);
          if ( ((*(_DWORD *)(v21 + 2396) >> 2) & 1) != 0 )
            goto LABEL_1745;
          if ( *(_DWORD *)(v21 + 2028) )
          {
            v54 = ((unsigned int)v54 >> 5) & 1;
            if ( (_DWORD)v54 )
              goto LABEL_1745;
          }
          else
          {
            *(_DWORD *)(v21 + 2396) = v54 ^ ((unsigned __int8)v54 ^ (unsigned __int8)(8 * v54)) & 0x20;
          }
        }
        v714 = (_QWORD *)*((_QWORD *)v64 + 1);
        v715 = *((unsigned int *)v64 + 4);
        v716 = v714;
        *(_DWORD *)(v21 + 2032) += v715;
        v717 = (const char *)v714;
        v718 = *(_DWORD *)(v21 + 2012);
        v719 = *(_QWORD *)(v21 + 2016);
        v54 = (unsigned __int64)v714 + v715;
        if ( v714 < (_QWORD *)((char *)v714 + v715) )
        {
          do
          {
            _mm_prefetch(v717, 0);
            v717 += 64;
          }
          while ( (unsigned __int64)v717 < v54 );
        }
        v720 = *(_QWORD *)(v21 + 2016);
        v721 = (unsigned int)v715 >> 7;
        if ( (unsigned int)v715 >> 7 )
        {
          do
          {
            v722 = 8i64;
            do
            {
              v723 = v720 ^ *v716;
              v724 = v716[1];
              v716 += 2;
              v720 = __ROL8__(__ROL8__(v723, v718) ^ v724, v718);
              --v722;
            }
            while ( v722 );
            v54 = __ROL8__(v719 ^ ((char *)v716 - (char *)v714), 17) ^ v719 ^ ((char *)v716 - (char *)v714);
            v1710 = (v54 * (unsigned __int128)0x7010008004002001ui64) >> 64;
            v718 = ((unsigned __int8)(v54 ^ v1710) ^ (unsigned __int8)v718) & 0x3F;
            if ( !v718 )
              v718 = 1;
            --v721;
          }
          while ( v721 );
          v21 = (ULONG_PTR)v1580;
        }
        v725 = v715 & 0x7F;
        if ( v725 >= 8 )
        {
          v726 = (unsigned __int64)v725 >> 3;
          do
          {
            v54 = v718;
            v720 = __ROL8__(*v716++ ^ v720, v718);
            v725 -= 8;
            --v726;
          }
          while ( v726 );
        }
        if ( v725 )
        {
          do
          {
            v727 = *(unsigned __int8 *)v716;
            v54 = v718;
            v716 = (_QWORD *)((char *)v716 + 1);
            v720 = __ROL8__(v727 ^ v720, v718);
            --v725;
          }
          while ( v725 );
          v21 = (ULONG_PTR)v1580;
        }
        for ( i13 = v720; ; LODWORD(v720) = i13 ^ v720 )
        {
          i13 >>= 31;
          if ( !i13 )
            break;
        }
        v729 = v720 & 0x7FFFFFFF;
        if ( v729 == *((_DWORD *)v64 + 5) )
          goto LABEL_1186;
        _InterlockedOr(v1576, 0);
        if ( (*((_DWORD *)v64 + 6) & 1) != 0 )
        {
          LOBYTE(v54) = **(_BYTE **)(v21 + 1368);
          if ( (_BYTE)v54 )
            goto LABEL_1186;
        }
        v54 = *((unsigned int *)v64 + 4);
        v730 = *((_QWORD *)v64 + 1);
        if ( *((_DWORD *)v64 + 4) )
        {
          v731 = 64i64;
          if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
          {
            v732 = KeGetCurrentIrql();
            __writecr8(2ui64);
            v733 = v730 & 0xFFFFFFFFFFFFF000ui64;
            v734 = (v730 + v54 - 1) | 0xFFF;
            v735 = (v730 & 0xFFFFFFFFFFFFF000ui64) - 1;
            while ( 1 )
            {
              v736 = v732;
              while ( 1 )
              {
                v737 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                         v733,
                         0i64,
                         v731,
                         v716);
                if ( v737 != -1073741267 )
                  break;
                if ( v732 > 1u )
                  goto LABEL_1180;
                v736 = v732;
                __writecr8(v732);
                KeGetCurrentIrql();
                __writecr8(2ui64);
              }
              if ( v737 < 0 )
                break;
LABEL_1180:
              v733 += 4096i64;
              v735 += 4096i64;
              if ( v735 == v734 )
              {
                __writecr8(v736);
                v64 = (char *)v1579;
LABEL_1186:
                if ( !_bittest((const signed __int32 *)(v21 + 2392), 0x1Eu) )
                  goto LABEL_146;
                v738 = *((unsigned int *)v64 + 4);
                if ( !(_DWORD)v738 )
                  goto LABEL_146;
                sub_1403F2EEC(v21, *((_QWORD *)v64 + 1), v738, v1753);
                v739 = 16;
                v740 = (__int64 *)(v64 + 28);
                v741 = (unsigned __int64 *)v1753;
                do
                {
                  v54 = *v741++;
                  v742 = *v740++;
                  if ( v54 != v742 )
                    goto LABEL_1195;
                  v739 -= 8;
                }
                while ( v739 >= 8 );
                if ( !v739 )
                  goto LABEL_1210;
                while ( 1 )
                {
                  v743 = *(unsigned __int8 *)v741;
                  v741 = (unsigned __int64 *)((char *)v741 + 1);
                  v744 = *(unsigned __int8 *)v740;
                  v740 = (__int64 *)((char *)v740 + 1);
                  if ( v743 != v744 )
                    break;
                  if ( !--v739 )
                    goto LABEL_1210;
                }
LABEL_1195:
                _InterlockedOr(v1576, 0);
                if ( (*((_DWORD *)v64 + 6) & 1) == 0 || (LOBYTE(v54) = **(_BYTE **)(v21 + 1368), !(_BYTE)v54) )
                {
                  v745 = *((unsigned int *)v64 + 4);
                  v54 = *((_QWORD *)v64 + 1);
                  if ( *((_DWORD *)v64 + 4) )
                  {
                    v746 = 64i64;
                    if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
                    {
                      v747 = KeGetCurrentIrql();
                      __writecr8(2ui64);
                      v748 = v54 & 0xFFFFFFFFFFFFF000ui64;
                      v749 = (v54 + v745 - 1) | 0xFFF;
                      v750 = (v54 & 0xFFFFFFFFFFFFF000ui64) - 1;
                      while ( 1 )
                      {
                        v751 = v747;
                        while ( 1 )
                        {
                          v752 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, __int64 *))(v21 + 1112))(
                                   v748,
                                   0i64,
                                   v746,
                                   v740);
                          if ( v752 != -1073741267 )
                            break;
                          if ( v747 > 1u )
                            goto LABEL_1205;
                          v751 = v747;
                          __writecr8(v747);
                          KeGetCurrentIrql();
                          __writecr8(2ui64);
                        }
                        if ( v752 < 0 )
                          break;
LABEL_1205:
                        v748 += 4096i64;
                        v750 += 4096i64;
                        if ( v750 == v749 )
                        {
                          __writecr8(v751);
                          goto LABEL_1210;
                        }
                      }
                      __writecr8(v751);
                      v54 = *((_QWORD *)v64 + 1);
                    }
                  }
                  if ( !*(_DWORD *)(v21 + 2240) )
                  {
                    *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                    *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                    *(_QWORD *)(v21 + 2264) = *(int *)v64;
                    *(_QWORD *)(v21 + 2272) = v54;
                    *(_DWORD *)(v21 + 2240) = 1;
                    __b9(v21, 0i64);
                  }
                }
LABEL_1210:
                v171 = 16 * *((_DWORD *)v64 + 4);
LABEL_348:
                *(_DWORD *)(v21 + 2032) += v171;
                goto LABEL_146;
              }
            }
            __writecr8(v736);
            v64 = (char *)v1579;
          }
        }
        if ( !*(_DWORD *)(v21 + 2240) )
        {
          *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = *((unsigned int *)v64 + 5) ^ (unsigned __int64)v729;
          v54 = *((_QWORD *)v64 + 1);
          if ( !*(_DWORD *)(v21 + 2240) )
          {
            *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
            *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
            *(_QWORD *)(v21 + 2264) = *(int *)v64;
            *(_QWORD *)(v21 + 2272) = v54;
            *(_DWORD *)(v21 + 2240) = 1;
            __b9(v21, 0i64);
          }
        }
        goto LABEL_1186;
      }
      if ( v77 == 15 )
      {
        if ( *(_DWORD *)(v21 + 2336) == 11 )
        {
          *(_DWORD *)(v21 + 2032) += 256;
          v708 = *(_QWORD *)(v21 + 1376);
          v709 = (*(__int64 (__fastcall **)(__int64))(v21 + 712))(v708);
          if ( v709 )
          {
            v710 = (*(__int64 (__fastcall **)(__int64))(v21 + 720))(v709);
            v711 = *((_QWORD *)v64 + 3);
            v712 = v710;
            if ( v711 )
            {
              if ( v711 != v710 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *(int *)v64;
                *(_QWORD *)(v21 + 2272) = v710;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
            }
            else
            {
              v713 = *(_QWORD *)(v21 + 2368);
              if ( (!*(_DWORD *)(v21 + 2364) || v710 < v713 || v710 > v713 + *(unsigned int *)(v21 + 2364) - 1i64)
                && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *(int *)v64;
                *(_QWORD *)(v21 + 2272) = v710;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              *((_QWORD *)v64 + 3) = v712;
            }
            (*(void (__fastcall **)(__int64, __int64))(v21 + 728))(v708, v709);
          }
        }
        goto LABEL_146;
      }
      if ( v77 != 21 )
      {
        if ( v77 != 24 )
        {
          if ( v77 != 25 )
          {
            if ( v77 == 26 )
            {
              if ( (*(_DWORD *)(v21 + 2040) & 1) == 0 )
              {
                v281 = 0;
                v282 = *(unsigned int **)(v21 + 1408);
                v283 = *(_QWORD *)(v21 + 1312);
                v1583 = *(_QWORD *)(v21 + 1416);
                v284 = *(void (**)(void))(v21 + 360);
                v1789 = 0;
                v1587 = v282;
                v284();
                if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 || (v285 = *(_DWORD *)(v21 + 2328), v285 >= 7) )
                {
                  (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 280))(*(_QWORD *)(v21 + 2504), 0i64);
                  v286 = 0x80;
                }
                else
                {
                  v286 = 1 << v285;
                }
                (*(void (__fastcall **)(__int64, _QWORD))(v21 + 296))(v283, 0i64);
                v287 = *(volatile signed __int8 ***)(v21 + 1272);
                v288 = *v287;
                if ( *v287 != (volatile signed __int8 *)v287 )
                {
                  do
                  {
                    _InterlockedOr8(&v288[*(_QWORD *)(v21 + 1672) - *(_QWORD *)(v21 + 1696)], v286);
                    v288 = *(volatile signed __int8 **)v288;
                    ++v281;
                  }
                  while ( v288 != (volatile signed __int8 *)v287 );
                  v282 = v1587;
                  v1789 = v281;
                }
                (*(void (__fastcall **)(unsigned int *, _QWORD))(v21 + 296))(v282, 0i64);
                v289 = *(_QWORD ***)(v21 + 1400);
                v290 = *v289;
                if ( *v289 != v289 )
                {
                  v291 = v1583;
                  v292 = v1579;
                  do
                  {
                    v293 = (char *)v290 - *(_QWORD *)(v21 + 1808);
                    if ( v293 != (char *)v291 )
                    {
                      v294 = *(_QWORD *)(v21 + 1672);
                      v295 = *(_QWORD *)&v293[*(_QWORD *)(v21 + 1800)];
                      if ( (v286 & *(_BYTE *)(v295 + v294)) == 0
                        && (*(_DWORD *)(v295 + *(_QWORD *)(v21 + 1680)) & *(_DWORD *)(v21 + 1704)) != 0
                        && !*(_DWORD *)(v21 + 2240) )
                      {
                        *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                        *(_QWORD *)(v21 + 2256) = (char *)v292 - 0x4C48B4211BBACBEBi64;
                        *(_QWORD *)(v21 + 2264) = *v292;
                        *(_QWORD *)(v21 + 2272) = v295;
                        *(_DWORD *)(v21 + 2240) = 1;
                        __b9(v21, 0i64);
                        v294 = *(_QWORD *)(v21 + 1672);
                      }
                      _InterlockedAnd8((volatile signed __int8 *)(v295 + v294), ~v286);
                      v291 = v1583;
                    }
                    v290 = (_QWORD *)*v290;
                  }
                  while ( v290 != v289 );
                  v281 = v1789;
                  v282 = v1587;
                }
                (*(void (__fastcall **)(unsigned int *, _QWORD))(v21 + 304))(v282, 0i64);
                if ( v286 == 0x80 )
                  (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 288))(*(_QWORD *)(v21 + 2504), 0i64);
                (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 304))(*(_QWORD *)(v21 + 1312), 0i64);
                (*(void (**)(void))(v21 + 368))();
                *(_DWORD *)(v21 + 2032) += v281 << 8;
              }
              goto LABEL_146;
            }
            if ( v77 == 27 )
            {
              if ( (*(_DWORD *)(v21 + 2040) & 1) == 0 )
                goto LABEL_146;
              v259 = *(_QWORD *)(v21 + 1408);
              v260 = *(unsigned int **)(v21 + 1416);
              v261 = *(void (**)(void))(v21 + 360);
              v262 = *(_QWORD *)(v21 + 1312);
              v1585 = v259;
              v1587 = v260;
              v1581 = 0;
              v261();
              if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 || (v263 = *(_DWORD *)(v21 + 2328), v263 >= 7) )
              {
                (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 280))(*(_QWORD *)(v21 + 2504), 0i64);
                LOBYTE(v7) = 0x80;
              }
              else
              {
                LOBYTE(v7) = 1 << v263;
              }
              v264 = *(void (__fastcall **)(__int64, _QWORD))(v21 + 296);
              LODWORD(v1582) = v7;
              v264(v262, 0i64);
              (*(void (__fastcall **)(unsigned __int64, _QWORD))(v21 + 296))(v259, 0i64);
              v265 = *(unsigned __int64 **)(v21 + 1400);
              v266 = 0i64;
              v1583 = 0i64;
              v267 = *v265;
              if ( (unsigned __int64 *)*v265 != v265 )
              {
                do
                {
                  if ( (unsigned int *)(v267 - 24) != v260 )
                  {
                    v268 = *(_QWORD *)(v267 - 24 + *(_QWORD *)(v21 + 1800));
                    if ( (*(_DWORD *)(v268 + *(_QWORD *)(v21 + 1680)) & *(_DWORD *)(v21 + 1704)) == 0 )
                    {
                      v269 = *(_QWORD *)(v267 - 24 + *(_QWORD *)(v21 + 1800));
                      if ( v266 )
                        v269 = 1i64;
                      v266 = v269;
                    }
                    _InterlockedOr8((volatile signed __int8 *)(v268 + *(_QWORD *)(v21 + 1672)), v7);
                  }
                  v267 = *(_QWORD *)v267;
                }
                while ( (unsigned __int64 *)v267 != v265 );
                v1583 = v266;
              }
              v270 = *(_QWORD ***)(v21 + 1272);
              v271 = *v270;
              if ( *v270 != v270 )
              {
                v272 = v1581;
                v267 = (unsigned __int8)v7;
                v273 = ~(_BYTE)v7;
                v274 = v1587;
                v1788 = v267;
                do
                {
                  v275 = (char *)v271 - *(_QWORD *)(v21 + 1696);
                  v276 = *(_QWORD *)(v21 + 1672);
                  if ( (v275[v276] & (unsigned int)v267) == 0 )
                  {
                    v277 = *(unsigned int **)&v275[*(_QWORD *)(v21 + 1688)];
                    if ( v277 && v277 != v274 && !*(_DWORD *)(v21 + 2240) )
                    {
                      v278 = v1579;
                      *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                      *(_QWORD *)(v21 + 2256) = (char *)v278 - 0x4C48B4211BBACBEBi64;
                      *(_QWORD *)(v21 + 2264) = *v278;
                      *(_QWORD *)(v21 + 2272) = v275;
                      *(_DWORD *)(v21 + 2240) = 1;
                      __b9(v21, 0i64);
                      v276 = *(_QWORD *)(v21 + 1672);
                    }
                    v267 = v1788;
                  }
                  _InterlockedAnd8(&v275[v276], v273);
                  v271 = (_QWORD *)*v271;
                  ++v272;
                }
                while ( v271 != v270 );
                LOBYTE(v7) = v1582;
                v260 = v1587;
                v1581 = v272;
                v266 = v1583;
              }
              if ( v266 )
              {
                if ( v266 == 1 )
                {
                  v279 = *(_QWORD ***)(v21 + 1400);
                  for ( i14 = *v279; i14 != v279; i14 = (_QWORD *)*i14 )
                  {
                    v267 = (unsigned __int64)(i14 - 3);
                    if ( i14 - 3 != (_QWORD *)v260 )
                    {
                      v267 = *(_QWORD *)(v267 + *(_QWORD *)(v21 + 1800));
                      _InterlockedAnd8((volatile signed __int8 *)(v267 + *(_QWORD *)(v21 + 1672)), ~(_BYTE)v7);
                    }
                  }
                }
                else
                {
                  _InterlockedAnd8((volatile signed __int8 *)(*(_QWORD *)(v21 + 1672) + v266), ~(_BYTE)v7);
                }
              }
              (*(void (__fastcall **)(unsigned __int64, _QWORD, unsigned __int64))(v21 + 304))(v1585, 0i64, v267);
              if ( (_BYTE)v7 == 0x80 )
                (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 288))(*(_QWORD *)(v21 + 2504), 0i64);
              (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 304))(*(_QWORD *)(v21 + 1312), 0i64);
              (*(void (**)(void))(v21 + 368))();
              v196 = v1581;
LABEL_383:
              v171 = v196 << 8;
              goto LABEL_348;
            }
            goto LABEL_2294;
          }
          v296 = *(_QWORD ***)(v21 + 1288);
          v297 = *(__int64 (**)(void))(v21 + 872);
          v1585 = (unsigned __int64)v296;
          v1790 = 0;
          v1597 = v297();
          _disable();
          v298 = *(_QWORD *)((char *)&KeGetCurrentPrcb()->MxCsr + *(_QWORD *)(v21 + 1560));
          _enable();
          (*(void (__fastcall **)(__int64))(v21 + 344))(v298);
          LOBYTE(v299) = 1;
          (*(void (__fastcall **)(_QWORD, __int64))(v21 + 224))(*(_QWORD *)(v21 + 1296), v299);
          v300 = 0;
          v301 = **(unsigned int ***)(v21 + 1512);
          v302 = *v301;
          v1583 = (__int64)(v301 + 4);
          v1587 = &v301[6 * v302 + 4];
          if ( *((_BYTE *)v301 + 12) )
          {
            v303 = *v296;
            LODWORD(v302) = 0;
            while ( v303 != v296 )
            {
              v303 = (_QWORD *)*v303;
              LODWORD(v302) = v302 + 1;
            }
          }
          v304 = *(unsigned int *)(v21 + 2008);
          v305 = __rdtsc();
          v306 = __ROR8__(v305, 3);
          v1747 = ((v306 ^ v305) * (unsigned __int128)0x7010008004002001ui64) >> 64;
          v307 = ((unsigned __int16)v1747 ^ (unsigned __int16)(8193 * (v306 ^ v305))) & 0x7FF;
          v308 = __rdtsc();
          v309 = (__ROR8__(v308, 3) ^ v308) * (unsigned __int128)0x7010008004002001ui64;
          v1748 = *((_QWORD *)&v309 + 1);
          v310 = (*((_QWORD *)&v309 + 1) ^ (unsigned __int64)v309) % (unsigned int)(v307 + 1);
          v311 = (*(__int64 (__fastcall **)(__int64, _QWORD, __int64))(v21 + 232))(
                   66i64,
                   (unsigned int)(v307 + 8 * v302),
                   v304);
          v314 = 0i64;
          v315 = v311;
          if ( !v311 )
          {
            ++*(_DWORD *)(v21 + 2528);
LABEL_565:
            v1643 = 0i64;
            goto LABEL_586;
          }
          v316 = v310;
          v317 = (unsigned __int64 *)v311;
          if ( (unsigned int)v310 >= 8 )
          {
            v318 = (unsigned __int64)(unsigned int)v310 >> 3;
            do
            {
              v319 = __rdtsc();
              v316 -= 8;
              v320 = (__ROR8__(v319, 3) ^ v319) * (unsigned __int128)0x7010008004002001ui64;
              v1763 = *((_QWORD *)&v320 + 1);
              v312 = v320 ^ *((_QWORD *)&v320 + 1);
              *v317++ = v312;
              --v318;
            }
            while ( v318 );
            v21 = (ULONG_PTR)v1580;
            v296 = (_QWORD **)v1585;
          }
          if ( v316 )
          {
            v321 = __rdtsc();
            v322 = (__ROR8__(v321, 3) ^ v321) * (unsigned __int128)0x7010008004002001ui64;
            v1768 = *((_QWORD *)&v322 + 1);
            v312 = v322 ^ *((_QWORD *)&v322 + 1);
            do
            {
              *(_BYTE *)v317 = v312;
              v317 = (unsigned __int64 *)((char *)v317 + 1);
              v312 >>= 8;
              --v316;
            }
            while ( v316 );
          }
          v323 = v307 - v310;
          v313 = v315 + (unsigned int)v310 + (unsigned __int64)(unsigned int)(8 * v302);
          if ( v323 >= 8 )
          {
            v324 = (unsigned __int64)v323 >> 3;
            do
            {
              v325 = __rdtsc();
              v323 -= 8;
              v326 = (__ROR8__(v325, 3) ^ v325) * (unsigned __int128)0x7010008004002001ui64;
              v1769 = *((_QWORD *)&v326 + 1);
              v312 = v326 ^ *((_QWORD *)&v326 + 1);
              *(_QWORD *)v313 = v312;
              v313 += 8i64;
              --v324;
            }
            while ( v324 );
          }
          v314 = 0i64;
          if ( v323 )
          {
            v327 = __rdtsc();
            v328 = (__ROR8__(v327, 3) ^ v327) * (unsigned __int128)0x7010008004002001ui64;
            v1696 = *((_QWORD *)&v328 + 1);
            v312 = v328 ^ *((_QWORD *)&v328 + 1);
            do
            {
              *(_BYTE *)v313++ = v312;
              v312 >>= 8;
              --v323;
            }
            while ( v323 );
          }
          v329 = (unsigned int)v310 + v315;
          v1643 = v315;
          if ( !v329 )
            goto LABEL_565;
          v330 = *v296;
          while ( v330 != v296 )
          {
            v331 = *(_QWORD *)((char *)v330 + *(_QWORD *)(v21 + 1824) - *(_QWORD *)(v21 + 1816));
            if ( !(*(unsigned int (__fastcall **)(__int64))(v21 + 664))(v331) && v300 < (unsigned int)v302 )
            {
              v332 = v300++;
              *(_QWORD *)(v329 + 8 * v332) = v331;
            }
            v330 = (_QWORD *)*v330;
            ++v1790;
          }
          (*(void (__fastcall **)(__int64, _QWORD, unsigned __int64, __int64))(v21 + 904))(v329, v300, v313, v314);
          v333 = v1583;
          v334 = v1587;
LABEL_573:
          v335 = *(_QWORD *)(v333 + 8);
          if ( (*(unsigned int (__fastcall **)(unsigned __int64))(v21 + 664))(v335) )
            goto LABEL_585;
          v312 = v300 - 1;
          v313 = 0i64;
          if ( (v312 & 0x80000000) != 0i64 )
          {
LABEL_583:
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              v337 = v1579;
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = (char *)v337 - 0x4C48B4211BBACBEBi64;
              *(_QWORD *)(v21 + 2264) = *v337;
              *(_QWORD *)(v21 + 2272) = v335;
              *(_DWORD *)(v21 + 2240) = 1;
              __b9(v21, 0i64);
            }
            goto LABEL_585;
          }
          while ( 1 )
          {
            v336 = ((int)v312 + (int)v313) >> 1;
            if ( v335 >= *(_QWORD *)(v329 + 8i64 * v336) )
            {
              if ( v335 <= *(_QWORD *)(v329 + 8i64 * v336) )
              {
                if ( (int)v312 < (int)v313 )
                  goto LABEL_583;
LABEL_585:
                v333 += 24i64;
                if ( v333 >= (unsigned __int64)v334 )
                {
LABEL_586:
                  (*(void (__fastcall **)(_QWORD, unsigned __int64, unsigned __int64, __int64))(v21 + 264))(
                    *(_QWORD *)(v21 + 1296),
                    v312,
                    v313,
                    v314);
                  (*(void (**)(void))(v21 + 352))();
                  (*(void (__fastcall **)(__int64))(v21 + 880))(v1597);
                  if ( v1643 )
                  {
                    *(_DWORD *)(v21 + 2032) += v1790 << 9;
                    (*(void (__fastcall **)(__int64))(v21 + 240))(v1643);
                  }
                  goto LABEL_146;
                }
                goto LABEL_573;
              }
              v313 = (unsigned int)(v336 + 1);
            }
            else
            {
              if ( !v336 )
                goto LABEL_583;
              v312 = (unsigned int)(v336 - 1);
            }
            if ( (int)v312 < (int)v313 )
              goto LABEL_583;
          }
        }
        if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 && (*(_DWORD *)(v21 + 2396) & 0x1000) == 0 )
        {
          v338 = __rdtsc();
          v339 = (__ROR8__(v338, 3) ^ v338) * (unsigned __int128)0x7010008004002001ui64;
          v1697 = *((_QWORD *)&v339 + 1);
          *(_DWORD *)(v21 + 2028) = ((unsigned __int64)v339 ^ *((_QWORD *)&v339 + 1)) % 5;
        }
LABEL_591:
        v340 = *(_DWORD *)(v21 + 2028);
        if ( !v340 )
        {
          v693 = v64;
          v1656 = 0i64;
          for ( i15 = 0; ; ++i15 )
          {
            v700 = (*(__int64 (__fastcall **)(__int64 *))(v21 + 752))(&v1656);
            if ( !v700 )
              break;
            if ( !(*(__int64 (__fastcall **)(__int64, char *))(v21 + 504))(v700, v1709) )
            {
              if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
              {
                v694 = *(_QWORD **)(v21 + 2632);
                v695 = 48;
                v696 = 6i64;
                do
                {
                  v695 -= 8;
                  *v694 = *(_QWORD *)v693;
                  v693 += 8;
                  ++v694;
                  --v696;
                }
                while ( v696 );
                if ( v695 )
                {
                  do
                  {
                    v697 = *v693++;
                    *(_BYTE *)v694 = v697;
                    v694 = (_QWORD *)((char *)v694 + 1);
                    --v695;
                  }
                  while ( v695 );
                  v21 = (ULONG_PTR)v1580;
                }
                v693 = *(char **)(v21 + 2632);
              }
              *((_QWORD *)v693 + 3) = v700;
              v698 = *(_QWORD *)(v21 + 1384);
              *(_QWORD *)v698 = v693;
              *(_DWORD *)(v698 + 16) = 48;
              v699 = *(_QWORD *)(v21 + 1384);
              *(_QWORD *)(v699 + 8) = v700;
              *(_DWORD *)(v699 + 20) = 4096;
              if ( !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v693 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *(int *)v693;
                *(_QWORD *)(v21 + 2272) = 3i64;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
            }
          }
          goto LABEL_1118;
        }
        v341 = v340 - 1;
        if ( !v341 )
        {
          v684 = v64;
          v1652 = 0i64;
          i15 = 0;
          v685 = KeGetCurrentIrql();
          __writecr8(0xCui64);
          for ( i16 = (*(__int64 (__fastcall **)(__int64 *))(v21 + 760))(&v1652);
                i16;
                i16 = (*(__int64 (__fastcall **)(__int64 *))(v21 + 760))(&v1652) )
          {
            ++i15;
            if ( !(*(__int64 (__fastcall **)(__int64, char *))(v21 + 504))(i16, v1708) )
            {
              if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
              {
                v687 = *(_QWORD **)(v21 + 2632);
                v688 = 48;
                v689 = 6i64;
                do
                {
                  v688 -= 8;
                  *v687 = *(_QWORD *)v684;
                  v684 += 8;
                  ++v687;
                  --v689;
                }
                while ( v689 );
                if ( v688 )
                {
                  do
                  {
                    v690 = *v684++;
                    *(_BYTE *)v687 = v690;
                    v687 = (_QWORD *)((char *)v687 + 1);
                    --v688;
                  }
                  while ( v688 );
                  v21 = (ULONG_PTR)v1580;
                }
                v684 = *(char **)(v21 + 2632);
              }
              *((_QWORD *)v684 + 3) = i16;
              v691 = *(_QWORD *)(v21 + 1384);
              *(_QWORD *)v691 = v684;
              *(_DWORD *)(v691 + 16) = 48;
              v692 = *(_QWORD *)(v21 + 1384);
              *(_QWORD *)(v692 + 8) = i16;
              *(_DWORD *)(v692 + 20) = 4096;
              if ( !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v684 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *(int *)v684;
                *(_QWORD *)(v21 + 2272) = 4i64;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
            }
          }
          __writecr8(v685);
          goto LABEL_1118;
        }
        v342 = v341 - 1;
        if ( !v342 )
        {
          v672 = v64;
          v673 = 0i64;
          i15 = 0;
          while ( 1 )
          {
            v1618 = 0;
            while ( 1 )
            {
              do
              {
                if ( !(*(unsigned int (__fastcall **)(_QWORD, int *, __int64 *))(v21 + 744))(v69, &v1618, &v1644) )
                  goto LABEL_1090;
                v676 = (*(__int64 (__fastcall **)(__int64, __int64, __int64, _QWORD))(v21 + 712))(
                         v1644,
                         v674,
                         v675,
                         0i64);
              }
              while ( !v676 );
              ++i15;
              v677 = (*(__int64 (__fastcall **)(__int64))(v21 + 720))(v676);
              if ( !(*(__int64 (__fastcall **)(__int64, char *))(v21 + 504))(v677, v1707) )
                break;
              (*(void (__fastcall **)(__int64, __int64, __int64, _QWORD))(v21 + 728))(v1644, v676, v678, 0i64);
            }
            if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
            {
              v54 = *(_QWORD *)(v21 + 2632);
              v679 = 48;
              v680 = 6i64;
              do
              {
                v679 -= 8;
                *(_QWORD *)v54 = *(_QWORD *)v672;
                v672 += 8;
                v54 += 8i64;
                --v680;
              }
              while ( v680 );
              if ( v679 )
              {
                do
                {
                  v681 = *v672++;
                  *(_BYTE *)v54++ = v681;
                  --v679;
                }
                while ( v679 );
                v21 = (ULONG_PTR)v1580;
              }
              v672 = *(char **)(v21 + 2632);
            }
            *((_QWORD *)v672 + 3) = v677;
            v682 = *(_QWORD *)(v21 + 1384);
            *(_QWORD *)v682 = v672;
            *(_DWORD *)(v682 + 16) = 48;
            v683 = *(_QWORD *)(v21 + 1384);
            *(_QWORD *)(v683 + 8) = v677;
            *(_DWORD *)(v683 + 20) = 4096;
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = v672 - 0x4C48B4211BBACBEBi64;
              *(_QWORD *)(v21 + 2264) = *(int *)v672;
              *(_QWORD *)(v21 + 2272) = v673;
              *(_DWORD *)(v21 + 2240) = 1;
              __b9(v21, 0i64);
            }
LABEL_1090:
            ++v69;
            ++v673;
            if ( v69 >= 3 )
              goto LABEL_1118;
          }
        }
        v54 = (unsigned int)(v342 - 1);
        if ( (_DWORD)v54 )
        {
          v54 = (unsigned int)(v54 - 1);
          if ( !(_DWORD)v54 )
          {
            v353 = *(__int64 (__fastcall **)(_QWORD))(v21 + 776);
            i15 = 0;
            v1586 = 0;
            v354 = v353(0i64);
            if ( v354 )
            {
              v355 = (__int64)v1579;
              do
              {
                v1660 = 0i64;
                v356 = (char *)v355;
                v357 = 1;
                v358 = (*(__int64 (__fastcall **)(__int64, __int64 *))(v21 + 768))(v354, &v1660);
                if ( v358 )
                {
                  do
                  {
                    ++v357;
                    if ( !(*(__int64 (__fastcall **)(__int64, char *))(v21 + 504))(v358, v1699) )
                    {
                      if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
                      {
                        v359 = *(_QWORD **)(v21 + 2632);
                        v360 = 48;
                        v361 = 6i64;
                        do
                        {
                          v360 -= 8;
                          *v359 = *(_QWORD *)v356;
                          v356 += 8;
                          ++v359;
                          --v361;
                        }
                        while ( v361 );
                        if ( v360 )
                        {
                          do
                          {
                            v362 = *v356++;
                            *(_BYTE *)v359 = v362;
                            v359 = (_QWORD *)((char *)v359 + 1);
                            --v360;
                          }
                          while ( v360 );
                          v21 = (ULONG_PTR)v1580;
                        }
                        v356 = *(char **)(v21 + 2632);
                      }
                      *((_QWORD *)v356 + 3) = v358;
                      *((_QWORD *)v356 + 4) = v354;
                      v363 = *(_QWORD *)(v21 + 1384);
                      *(_QWORD *)v363 = v356;
                      *(_DWORD *)(v363 + 16) = 48;
                      v364 = *(_QWORD *)(v21 + 1384);
                      *(_QWORD *)(v364 + 8) = v358;
                      *(_DWORD *)(v364 + 20) = 4096;
                      if ( !*(_DWORD *)(v21 + 2240) )
                      {
                        *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                        *(_QWORD *)(v21 + 2256) = v356 - 0x4C48B4211BBACBEBi64;
                        *(_QWORD *)(v21 + 2264) = *(int *)v356;
                        *(_QWORD *)(v21 + 2272) = 6i64;
                        *(_DWORD *)(v21 + 2240) = 1;
                        __b9(v21, 0i64);
                      }
                    }
                    v358 = (*(__int64 (__fastcall **)(__int64, __int64 *))(v21 + 768))(v354, &v1660);
                  }
                  while ( v358 );
                  i15 = v1586;
                  v355 = (__int64)v1579;
                }
                v365 = *(__int64 (__fastcall **)(__int64))(v21 + 776);
                i15 += v357;
                v1586 = i15;
                v354 = v365(v354);
              }
              while ( v354 );
            }
            goto LABEL_1118;
          }
          if ( (_DWORD)v54 == 1 )
          {
            v343 = v64;
            v1810 = -1;
            i15 = 0;
            v345 = 0;
            v346 = 0i64;
            do
            {
              v1659 = 0i64;
              while ( (*(unsigned int (__fastcall **)(_QWORD, __int64 *, char *, __int64 *))(v21 + 1056))(
                        v345,
                        &v1659,
                        &v1810,
                        &v1621) )
              {
                ++i15;
                if ( !(*(__int64 (__fastcall **)(__int64, char *))(v21 + 504))(v1621, v1698) )
                {
                  if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
                  {
                    v347 = *(_QWORD **)(v21 + 2632);
                    v348 = 48;
                    v349 = 6i64;
                    do
                    {
                      v348 -= 8;
                      *v347 = *(_QWORD *)v343;
                      v343 += 8;
                      ++v347;
                      --v349;
                    }
                    while ( v349 );
                    if ( v348 )
                    {
                      do
                      {
                        v350 = *v343++;
                        *(_BYTE *)v347 = v350;
                        v347 = (_QWORD *)((char *)v347 + 1);
                        --v348;
                      }
                      while ( v348 );
                      v21 = (ULONG_PTR)v1580;
                    }
                    v343 = *(char **)(v21 + 2632);
                  }
                  *((_QWORD *)v343 + 3) = v1621;
                  v351 = *(_QWORD *)(v21 + 1384);
                  *(_QWORD *)v351 = v343;
                  *(_DWORD *)(v351 + 16) = 48;
                  v352 = *(_QWORD *)(v21 + 1384);
                  *(_QWORD *)(v352 + 8) = v1621;
                  *(_DWORD *)(v352 + 20) = 4096;
                  if ( !*(_DWORD *)(v21 + 2240) )
                  {
                    *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                    *(_QWORD *)(v21 + 2256) = v343 - 0x4C48B4211BBACBEBi64;
                    *(_QWORD *)(v21 + 2264) = *(int *)v343;
                    *(_QWORD *)(v21 + 2272) = v346;
                    *(_DWORD *)(v21 + 2240) = 1;
                    __b9(v21, 0i64);
                  }
                }
              }
              ++v345;
              ++v346;
            }
            while ( v345 < 3 );
            goto LABEL_1118;
          }
          *(_DWORD *)(v21 + 2028) = 0;
          goto LABEL_1121;
        }
        v366 = *(ULONG_PTR **)(v21 + 1224);
        v1607 = (_BYTE *)v21;
        v1586 = 0;
        v367 = *v366;
        v1587 = (unsigned int *)*v366;
        if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
        {
          i15 = 0;
          goto LABEL_1118;
        }
        v368 = v1579;
        v369 = *((_QWORD *)v1579 + 5);
        if ( v369 )
        {
          v1586 = 1;
          if ( v367 != v369 )
          {
            *((_QWORD *)v1579 + 3) = v367;
            v370 = *(_QWORD *)(v21 + 1384);
            *(_QWORD *)v370 = v368;
            *(_DWORD *)(v370 + 16) = 48;
            v371 = *(_QWORD *)(v21 + 1384);
            *(_QWORD *)(v371 + 8) = v367;
            *(_DWORD *)(v371 + 20) = 4096;
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = (char *)v368 - 0x4C48B4211BBACBEBi64;
              *(_QWORD *)(v21 + 2264) = *v368;
              *(_QWORD *)(v21 + 2272) = 5i64;
              *(_DWORD *)(v21 + 2240) = 1;
              __b9(v21, 0i64);
            }
          }
          goto LABEL_1074;
        }
        if ( !v367 )
          goto LABEL_1074;
        v372 = *(__int64 (__fastcall **)(ULONG_PTR, char *))(v21 + 496);
        v1586 = 1;
        v1604 = (_BYTE *)v21;
        v373 = (unsigned int *)v372(v367, v1765);
        v374 = v1766;
        v375 = 0;
        v376 = v1767;
        v377 = v373;
        v1588 = v373;
        v1791 = v1767;
        v1594 = v1767;
        BugCheckParameter2 = v1766;
        if ( !v1766 )
        {
          if ( (*(_DWORD *)(v21 + 2392) & 0x200000) == 0 )
          {
            v1640 = 664797184;
            KeBugCheckEx(__ROR4__(664797184, 149), 0xAui64, v367, 5ui64, 0i64);
          }
          v54 = 3221225595i64;
          goto LABEL_1071;
        }
        v378 = 4;
        v1619 = 0i64;
        v379 = &v1620;
        v380 = 0xFFFFFFFFi64;
        v381 = 1i64;
        do
        {
          *(_BYTE *)v379 = 0;
          v379 = (int *)((char *)v379 + 1);
          --v378;
        }
        while ( v378 );
        v382 = 0;
        if ( !*(_DWORD *)(v21 + 2004) )
        {
LABEL_679:
          v1605 = 0i64;
          goto LABEL_680;
        }
        LODWORD(v381) = v1620;
        v383 = HIDWORD(v1619);
        v384 = v1619;
        while ( 1 )
        {
          v385 = v21;
          if ( *(_QWORD *)(v21 + 2624) )
            v385 = *(_QWORD *)(v21 + 2624);
          v380 = v385 + *(unsigned int *)(v385 + 2000);
          if ( v384 && v383 <= v382 )
          {
            v375 = v383;
            v380 = v385 + (unsigned int)v381;
          }
          if ( v375 != v382 )
            break;
LABEL_672:
          LODWORD(v1619) = 1;
          v381 = (unsigned int)(v380 - v385);
          HIDWORD(v1619) = v375;
          v1620 = v380 - v385;
          v384 = 1;
          v393 = *(int *)v380;
          v383 = v375;
          if ( (unsigned int)v393 <= 0x2B
            && (v394 = 0x80000001002i64, _bittest64(&v394, v393))
            && *(unsigned int **)(v380 + 8) == v377
            && *(_DWORD *)(v380 + 16) == v376
            || (unsigned int)(v393 - 33) <= 1 && *(_QWORD *)(v380 + 32) == v374 )
          {
            v1605 = (_DWORD *)v380;
            if ( v380 )
            {
              v54 = 3221225742i64;
              goto LABEL_1071;
            }
LABEL_680:
            v395 = (*(__int64 (__fastcall **)(ULONG_PTR, __int64, __int64))(v21 + 664))(v367, v381, v380);
            v396 = *(char ***)(v21 + 1288);
            v397 = v395;
            v1592 = v395;
            LODWORD(v1582) = v1594;
            _disable();
            v398 = *(_QWORD *)((char *)&KeGetCurrentPrcb()->MxCsr + *(_QWORD *)(v21 + 1560));
            _enable();
            (*(void (__fastcall **)(__int64))(v21 + 344))(v398);
            LOBYTE(v399) = 1;
            (*(void (__fastcall **)(_QWORD, __int64))(v21 + 224))(*(_QWORD *)(v21 + 1296), v399);
            v400 = *v396;
            if ( *v396 != (char *)v396 )
            {
              v401 = *(_QWORD *)(v21 + 1816);
              while ( 1 )
              {
                v402 = *(_QWORD *)&v400[*(_QWORD *)(v21 + 1824) - v401];
                if ( v374 >= v402 && v374 < v402 + *(unsigned int *)&v400[*(_QWORD *)(v21 + 1832) - v401] )
                  break;
                v400 = *(char **)v400;
                if ( v400 == (char *)v396 )
                  goto LABEL_689;
              }
              (*(void (__fastcall **)(char *, __int64))(v21 + 208))(&v400[-v401], 1i64);
            }
LABEL_689:
            (*(void (__fastcall **)(_QWORD))(v21 + 264))(*(_QWORD *)(v21 + 1296));
            (*(void (**)(void))(v21 + 352))();
            if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 )
            {
              v54 = (unsigned int)sub_140AD3FD0(&v1607, v374, 9i64);
              goto LABEL_1071;
            }
            v404 = *(__int64 (__fastcall **)(unsigned __int64, __int64, _QWORD, int *))(v21 + 480);
            v1683 = 0i64;
            v1648[4] = 0;
            LOBYTE(v403) = 1;
            v1680 = v404(v374, v403, 0i64, &v1594);
            v405 = v1594 & (unsigned int)-(v1680 != 0);
            v1594 = v405;
            v406 = *(__int64 (__fastcall **)(unsigned __int64, __int64, __int64, int *))(v21 + 480);
            v1648[1] = v405;
            LOBYTE(v405) = 1;
            v407 = v406(v374, v405, 12i64, &v1594);
            v408 = v407;
            v1593 = v407;
            v1681 = v407;
            LOBYTE(v408) = 1;
            v1594 &= -(v407 != 0);
            v409 = *(__int64 (__fastcall **)(unsigned __int64, __int64, __int64, int *))(v21 + 480);
            LODWORD(v1596) = v1594;
            v1648[2] = v1594;
            v1682 = v409(v374, v408, 10i64, &v1594);
            v1594 &= -(v1682 != 0);
            v410 = *(__int64 (__fastcall **)(unsigned __int64))(v21 + 488);
            v1648[3] = v1594;
            v411 = v410(v374);
            if ( !v411 )
            {
              if ( (*(_DWORD *)(v21 + 2392) & 0x200000) == 0 )
              {
                v1645 = 664797184;
                KeBugCheckEx(__ROR4__(664797184, 149), 0xAui64, v374, 7ui64, 0i64);
              }
              if ( !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = 0i64;
                *(_QWORD *)(v21 + 2264) = 271i64;
                *(_QWORD *)(v21 + 2272) = v374;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              v54 = 3221225595i64;
              goto LABEL_1071;
            }
            v412 = (*(__int64 (__fastcall **)(unsigned __int64, int *))(v21 + 1160))(v374, &v1671);
            v413 = *(unsigned int *)(v21 + 2284);
            v1684 = v412;
            v1648[5] = v1671;
            v1648[0] = *(_DWORD *)(v411 + 84);
            LODWORD(v412) = v397;
            v414 = *(unsigned int *)(v21 + 1964);
            v1679 = v374;
            v415 = (_DWORD)v412 != 0 ? 0xB : 0;
            v416 = v414 + 288;
            v1792 = v415;
            if ( (unsigned int)(v414 + 288) <= *(_DWORD *)(v21 + 2532) )
            {
              v417 = v21;
              v1583 = v21;
              *(_DWORD *)(v21 + 1964) = v416;
            }
            else
            {
              v1583 = sub_140ACCC24(v21, v416, v413);
              v417 = v1583;
              if ( !v1583 )
              {
                v1604 = 0i64;
                v54 = 3221225626i64;
                goto LABEL_1071;
              }
              v418 = *(_DWORD *)(v21 + 2392);
              if ( (v418 & 4) == 0 )
              {
                v419 = *(_DWORD *)(v21 + 1964);
                v420 = *(_QWORD *)(v21 + 1936);
                v596 = (v418 & 0x20000000) != 0;
                v421 = (_QWORD *)v21;
                v422 = v596 ? *(_DWORD *)(v21 + 2284) : 0;
                if ( v419 >= 8 )
                {
                  v423 = (unsigned __int64)v419 >> 3;
                  do
                  {
                    *v421 = 0i64;
                    v419 -= 8;
                    ++v421;
                    --v423;
                  }
                  while ( v423 );
                }
                for ( ; v419; --v419 )
                {
                  *(_BYTE *)v421 = 0;
                  v421 = (_QWORD *)((char *)v421 + 1);
                }
                v424 = *(_DWORD *)(v417 + 2284);
                *(_DWORD *)(v417 + 2284) = v422;
                if ( v422 == 3 )
                {
                  (*(void (__fastcall **)(__int64))(v417 + 856))(v420);
                }
                else if ( (*(_DWORD *)(v417 + 2392) & 0x10000000) != 0 || !v422 )
                {
                  (*(void (__fastcall **)(__int64))(v417 + 240))(v420);
                }
                else
                {
                  (*(void (__fastcall **)(__int64, _QWORD))(v417 + 536))(v420 - 8, *(_QWORD *)(v420 - 8));
                }
                *(_DWORD *)(v417 + 2284) = v424;
              }
              *(_DWORD *)(v417 + 2392) &= ~4u;
              v415 = v1792;
            }
            v425 = v417 + v414;
            *(_DWORD *)(v417 + 2004) += 6;
            v426 = (__int64 *)&v1679;
            v1651 = v417 + v414;
            v427 = (unsigned int *)v1648;
            v1605 = (_DWORD *)(v417 + v414);
            v1597 = 6i64;
            do
            {
              v428 = *v427;
              v429 = 6i64;
              v430 = (_QWORD *)*v426;
              v431 = 48;
              v1581 = *v427;
              v432 = (_QWORD *)v425;
              do
              {
                *v432 = 0i64;
                v431 -= 8;
                ++v432;
                --v429;
              }
              while ( v429 );
              for ( ; v431; --v431 )
              {
                *(_BYTE *)v432 = 0;
                v432 = (_QWORD *)((char *)v432 + 1);
              }
              *(_DWORD *)v425 = v415;
              *(_QWORD *)(v425 + 8) = v430;
              v433 = v430;
              *(_DWORD *)(v425 + 16) = v428;
              v434 = (const char *)v430;
              *(_DWORD *)(v417 + 2032) += v428;
              v435 = *(_DWORD *)(v417 + 2012);
              v436 = *(_QWORD *)(v417 + 2016);
              if ( v430 < (_QWORD *)((char *)v430 + v428) )
              {
                do
                {
                  _mm_prefetch(v434, 0);
                  v434 += 64;
                }
                while ( v434 < (const char *)v430 + v428 );
              }
              v437 = *(_QWORD *)(v417 + 2016);
              v438 = (unsigned int)v428 >> 7;
              if ( (unsigned int)v428 >> 7 )
              {
                do
                {
                  v439 = 8i64;
                  do
                  {
                    v440 = v437 ^ *v433;
                    v441 = v433[1];
                    v433 += 2;
                    v437 = __ROL8__(__ROL8__(v440, v435) ^ v441, v435);
                    --v439;
                  }
                  while ( v439 );
                  v442 = __ROL8__(v436 ^ ((char *)v433 - (char *)v430), 17) ^ v436 ^ ((char *)v433 - (char *)v430);
                  v1700 = (v442 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                  v435 = ((unsigned __int8)v1700 ^ (unsigned __int8)(v442 ^ v435)) & 0x3F;
                  if ( !v435 )
                    LOBYTE(v435) = 1;
                  --v438;
                }
                while ( v438 );
                v417 = v1583;
                LODWORD(v428) = v1581;
              }
              v443 = v428 & 0x7F;
              if ( v443 >= 8 )
              {
                v444 = (unsigned __int64)(v428 & 0x7F) >> 3;
                do
                {
                  v437 = __ROL8__(*v433++ ^ v437, v435);
                  v443 -= 8;
                  --v444;
                }
                while ( v444 );
              }
              if ( v443 )
              {
                do
                {
                  v445 = *(unsigned __int8 *)v433;
                  v433 = (_QWORD *)((char *)v433 + 1);
                  v437 = __ROL8__(v445 ^ v437, v435);
                  --v443;
                }
                while ( v443 );
                v417 = v1583;
              }
              for ( i17 = v437 >> 31; i17; i17 >>= 31 )
                v437 = (unsigned int)i17 ^ (unsigned int)v437;
              v415 = v1792;
              LODWORD(v437) = v437 & 0x7FFFFFFF;
              *(_DWORD *)(v425 + 20) = v437;
              ++v427;
              *(_DWORD *)(v417 + 2032) += v428;
              ++v426;
              v425 = v1651 + 48;
              v73 = v1597-- == 1;
              v1651 += 48i64;
            }
            while ( !v73 );
            v447 = v1605;
            v448 = BugCheckParameter2;
            v21 = (ULONG_PTR)v1580;
            v449 = v1592;
            *v1605 = 44;
            *((_QWORD *)v447 + 3) = v448;
            if ( (*(_DWORD *)(v417 + 2392) & 0x10200000) != 0 )
            {
              if ( !v449 )
                goto LABEL_745;
            }
            else if ( !v449 )
            {
              if ( (*(_DWORD *)(v417 + 2396) & 0x8000) != 0 )
              {
                v447[8] |= 1u;
                if ( (unsigned int)sub_140ACDCE4(v417, v448, v437, v1792) )
                  v447[8] |= 4u;
              }
LABEL_745:
              v1604 = (_BYTE *)v417;
              v1607 = (_BYTE *)v417;
              v450 = sub_140ACC0E0(
                       (unsigned int)&v1604,
                       (_DWORD)v1588,
                       v1582,
                       v448,
                       v449,
                       9,
                       (__int64)&v1611,
                       (__int64)&v1647);
              v54 = (unsigned int)v450;
              if ( v450 < 0 )
                goto LABEL_1070;
              v451 = v1604;
              v452 = v1647 - v1611;
              v1605 = &v1604[(_QWORD)v1605 - v417];
              v453 = (_QWORD *)(v448 + v1611);
              v454 = v1605 + 48;
              v455 = 48;
              v456 = v1605 + 48;
              v457 = 6i64;
              do
              {
                *v456 = 0i64;
                v455 -= 8;
                ++v456;
                --v457;
              }
              while ( v457 );
              for ( ; v455; --v455 )
              {
                *(_BYTE *)v456 = 0;
                v456 = (_QWORD *)((char *)v456 + 1);
              }
              v458 = v453;
              *v454 = v1792;
              v459 = (const char *)v453;
              *((_QWORD *)v454 + 1) = v453;
              v454[4] = v452;
              *((_DWORD *)v451 + 508) += v452;
              v460 = *((_DWORD *)v451 + 503);
              v461 = *((_QWORD *)v451 + 252);
              v462 = (unsigned __int64)v453 + v452;
              if ( (unsigned __int64)v453 < v462 )
              {
                do
                {
                  _mm_prefetch(v459, 0);
                  v459 += 64;
                }
                while ( (unsigned __int64)v459 < v462 );
              }
              v463 = *((_QWORD *)v451 + 252);
              v464 = v452 >> 7;
              if ( v452 >> 7 )
              {
                do
                {
                  v465 = 8i64;
                  do
                  {
                    v466 = v463 ^ *v458;
                    v467 = v458[1];
                    v458 += 2;
                    v463 = __ROL8__(__ROL8__(v466, v460) ^ v467, v460);
                    --v465;
                  }
                  while ( v465 );
                  v468 = __ROL8__(v461 ^ ((char *)v458 - (char *)v453), 17) ^ v461 ^ ((char *)v458 - (char *)v453);
                  v1701 = (v468 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                  v460 = ((unsigned __int8)v1701 ^ (unsigned __int8)(v468 ^ v460)) & 0x3F;
                  if ( !v460 )
                    LOBYTE(v460) = 1;
                  --v464;
                }
                while ( v464 );
                v21 = (ULONG_PTR)v1580;
                v449 = v1592;
              }
              v469 = v452 & 0x7F;
              if ( (unsigned int)v469 >= 8 )
              {
                v470 = (unsigned __int64)(unsigned int)v469 >> 3;
                do
                {
                  v463 = __ROL8__(*v458++ ^ v463, v460);
                  v469 = (unsigned int)(v469 - 8);
                  --v470;
                }
                while ( v470 );
                v21 = (ULONG_PTR)v1580;
              }
              if ( (_DWORD)v469 )
              {
                do
                {
                  v471 = *(unsigned __int8 *)v458;
                  v458 = (_QWORD *)((char *)v458 + 1);
                  v463 = __ROL8__(v471 ^ v463, v460);
                  v469 = (unsigned int)(v469 - 1);
                }
                while ( (_DWORD)v469 );
                v21 = (ULONG_PTR)v1580;
              }
              for ( i18 = v463; ; v463 = (unsigned int)i18 ^ (unsigned int)v463 )
              {
                i18 >>= 31;
                if ( !i18 )
                  break;
              }
              LODWORD(v463) = v463 & 0x7FFFFFFF;
              v454[5] = v463;
              v473 = v1605;
              v1605[60] = 48;
              if ( v473[64] )
              {
                v463 = 4294967294i64;
                v473[66] = v473[66] & 0xFFFFFFFE | (v449 != 0);
              }
              v1607 = v451;
              v1622 = v1605 + 24;
              v474 = (v449 != 0) + 13;
              if ( v1605 == (_DWORD *)-96i64 )
              {
                v475 = *((unsigned int *)v451 + 491);
                v476 = v475 + 48;
                if ( (unsigned int)(v475 + 48) <= *((_DWORD *)v451 + 633) )
                {
                  v477 = v451;
                  *((_DWORD *)v451 + 491) = v476;
                }
                else
                {
                  v477 = (_BYTE *)sub_140ACCC24(v451, v476, *((unsigned int *)v451 + 571));
                  if ( !v477 )
                    goto LABEL_774;
                  v478 = *((_DWORD *)v451 + 598);
                  if ( (v478 & 4) == 0 )
                  {
                    v479 = *((_DWORD *)v451 + 491);
                    v480 = *((_QWORD *)v451 + 242);
                    v481 = (v478 & 0x20000000) != 0 ? *((_DWORD *)v451 + 571) : 0;
                    if ( v479 >= 8 )
                    {
                      v482 = (unsigned __int64)v479 >> 3;
                      do
                      {
                        *(_QWORD *)v451 = 0i64;
                        v479 -= 8;
                        v451 += 8;
                        --v482;
                      }
                      while ( v482 );
                    }
                    for ( ; v479; --v479 )
                      *v451++ = 0;
                    v483 = *((_DWORD *)v477 + 571);
                    *((_DWORD *)v477 + 571) = v481;
                    if ( v481 == 3 )
                    {
                      (*((void (__fastcall **)(__int64))v477 + 107))(v480);
                    }
                    else if ( (*((_DWORD *)v477 + 598) & 0x10000000) != 0 || !v481 )
                    {
                      (*((void (__fastcall **)(__int64))v477 + 30))(v480);
                    }
                    else
                    {
                      (*((void (__fastcall **)(__int64, _QWORD))v477 + 67))(v480 - 8, *(_QWORD *)(v480 - 8));
                    }
                    *((_DWORD *)v477 + 571) = v483;
                  }
                  *((_DWORD *)v477 + 598) &= ~4u;
                }
                ++*((_DWORD *)v477 + 501);
                v484 = (__int64)&v477[v475];
                v1673 = (_DWORD *)v484;
                v485 = (_QWORD *)v484;
                v486 = 48;
                v487 = 6i64;
                do
                {
                  *v485 = 0i64;
                  v486 -= 8;
                  ++v485;
                  --v487;
                }
                while ( v487 );
                for ( ; v486; --v486 )
                {
                  *(_BYTE *)v485 = 0;
                  v485 = (_QWORD *)((char *)v485 + 1);
                }
                v488 = v1593;
                *(_DWORD *)v484 = v474;
                v469 = v488;
                v489 = (unsigned int)v1596;
                *(_QWORD *)(v484 + 8) = v488;
                *(_DWORD *)(v484 + 16) = v489;
                *((_DWORD *)v477 + 508) += v489;
                v490 = *((_DWORD *)v477 + 503);
                v491 = *((_QWORD *)v477 + 252);
                if ( v488 < v488 + v489 )
                {
                  v492 = (const char *)v488;
                  do
                  {
                    _mm_prefetch(v492, 0);
                    v492 += 64;
                  }
                  while ( (unsigned __int64)v492 < v488 + v489 );
                }
                v463 = *((_QWORD *)v477 + 252);
                v493 = (unsigned int)v489 >> 7;
                if ( (unsigned int)v489 >> 7 )
                {
                  do
                  {
                    v494 = 8i64;
                    do
                    {
                      v495 = v463 ^ *(_QWORD *)v469;
                      v496 = *(_QWORD *)(v469 + 8);
                      v469 += 16i64;
                      v463 = __ROL8__(__ROL8__(v495, v490) ^ v496, v490);
                      --v494;
                    }
                    while ( v494 );
                    v497 = __ROL8__(v491 ^ (v469 - v488), 17) ^ v491 ^ (v469 - v488);
                    v1702 = (v497 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                    v490 = ((unsigned __int8)v1702 ^ (unsigned __int8)(v497 ^ v490)) & 0x3F;
                    if ( !v490 )
                      LOBYTE(v490) = 1;
                    --v493;
                  }
                  while ( v493 );
                  v21 = (ULONG_PTR)v1580;
                  v449 = v1592;
                }
                v498 = v489 & 0x7F;
                if ( v498 >= 8 )
                {
                  v499 = (unsigned __int64)(v489 & 0x7F) >> 3;
                  do
                  {
                    v463 = __ROL8__(*(_QWORD *)v469 ^ v463, v490);
                    v469 += 8i64;
                    v498 -= 8;
                    --v499;
                  }
                  while ( v499 );
                }
                if ( v498 )
                {
                  do
                  {
                    v500 = *(unsigned __int8 *)v469++;
                    v463 = __ROL8__(v500 ^ v463, v490);
                    --v498;
                  }
                  while ( v498 );
                  v21 = (ULONG_PTR)v1580;
                }
                for ( i19 = v463; ; v463 = (unsigned int)i19 ^ (unsigned int)v463 )
                {
                  i19 >>= 31;
                  if ( !i19 )
                    break;
                }
                LODWORD(v463) = v463 & 0x7FFFFFFF;
                *(_DWORD *)(v484 + 20) = v463;
                v1622 = v1673;
                *((_DWORD *)v477 + 508) += v489;
              }
              else
              {
                v488 = v1593;
                v477 = v451;
                v1605[24] = v474;
                LODWORD(v489) = (_DWORD)v1596;
              }
              if ( (*((_DWORD *)v477 + 598) & 0x40000000) != 0 && (_DWORD)v489 )
                sub_1403F2EEC(v477, v488, (unsigned int)v489, v1622 + 7);
              v502 = 4294967294i64;
              v1607 = v477;
              v1622[6] = 0;
              v1622[6] |= 1u;
              v503 = v1605;
              v1605[36] = 35;
              v503[46] = v503[46] & 0xFFFFFFFE | (v449 != 0);
              if ( v503[40] >= 0x94u )
              {
                v504 = BugCheckParameter2;
                v505 = *((_QWORD *)v503 + 19);
                v506 = (*((__int64 (__fastcall **)(ULONG_PTR, __int64, unsigned __int64, unsigned __int64))v477 + 61))(
                         BugCheckParameter2,
                         4294967294i64,
                         v463,
                         v469);
                if ( v506 )
                {
                  v463 = v504 + *(unsigned int *)(v506 + 80);
                  v502 = v503[46] | 2u;
                  v503[46] = v502;
                  v507 = v502;
                  v508 = *(_QWORD **)(v505 + 112);
                  if ( (unsigned __int64)v508 >= v504 && (unsigned __int64)v508 < v463 )
                  {
                    v507 = v502 | 4;
                    *((_QWORD *)v503 + 21) = *v508;
                    v503[46] = v502 | 4;
                  }
                  v509 = *(_QWORD **)(v505 + 120);
                  if ( (unsigned __int64)v509 >= v504 && (unsigned __int64)v509 < v463 )
                  {
                    *((_QWORD *)v503 + 22) = *v509;
                    v503[46] = v507 | 8;
                  }
                  goto LABEL_827;
                }
LABEL_774:
                v1604 = 0i64;
LABEL_775:
                v54 = 3221225626i64;
                goto LABEL_1070;
              }
LABEL_827:
              v73 = (*((_DWORD *)v477 + 598) & 0x400000) == 0;
              v1604 = v477;
              if ( v73 )
                goto LABEL_1069;
              v510 = BugCheckParameter2;
              v511 = (*((__int64 (__fastcall **)(ULONG_PTR, __int64, unsigned __int64, unsigned __int64))v477 + 61))(
                       BugCheckParameter2,
                       v502,
                       v463,
                       v469);
              v1595 = v511;
              v512 = v511;
              if ( !v511 )
                goto LABEL_829;
              v513 = *(unsigned __int16 *)(v511 + 6);
              v1793 = v513;
              v1585 = (unsigned int)v1582 / 0xCui64;
              if ( !(_WORD)v513 )
              {
                if ( (*((_DWORD *)v477 + 598) & 0x200000) == 0 )
                {
                  v1646 = 664797184;
                  KeBugCheckEx(__ROR4__(664797184, 149), 0xAui64, v510, 0i64, 0i64);
                }
                goto LABEL_832;
              }
              v514 = v1588;
              v1581 = v513;
              v515 = v513;
              v516 = 0;
              v1593 = (unsigned __int64)&v1588[3 * ((unsigned int)v1582 / 0xC)];
              v517 = *(unsigned __int16 *)(v511 + 20);
              LODWORD(v1600) = 0;
              v1583 = v517 + v512 + 24;
              v518 = (_DWORD *)v1583;
              v519 = 1i64;
              v1597 = v1583;
              do
              {
                v520 = v518[4];
                v521 = (unsigned int)v518[3];
                if ( v520 <= v518[2] )
                  v520 = v518[2];
                LODWORD(v1596) = v518[3];
                v522 = v521 + v520;
                if ( v516 )
                {
                  if ( v522 < *(_DWORD *)(v1583 + 40i64 * (v516 - 1) + 12) )
                  {
                    if ( (*((_DWORD *)v477 + 598) & 0x200000) == 0 )
                    {
                      v1641 = 664797184;
                      KeBugCheckEx(__ROR4__(664797184, 149), 0xAui64, v510, 1ui64, 0i64);
                    }
                    if ( !*((_DWORD *)v477 + 560) )
                    {
                      *((_QWORD *)v477 + 281) = v477 - 0x5C5FC0A76E374B18i64;
                      *((_QWORD *)v477 + 282) = 0i64;
                      *((_QWORD *)v477 + 283) = 271i64;
                      *((_QWORD *)v477 + 284) = v510;
                      *((_DWORD *)v477 + 560) = 1;
LABEL_834:
                      __b9(v477, 0i64);
                    }
LABEL_829:
                    v54 = 3221225595i64;
                    goto LABEL_1070;
                  }
                  v516 = (unsigned int)v1600;
                }
                if ( v514 != (unsigned int *)v1593 )
                {
                  do
                  {
                    v523 = v514[1];
                    if ( *v514 >= v522 || v523 <= (unsigned int)v521 )
                      break;
                    if ( *v514 < (unsigned int)v521 || v523 > v522 )
                    {
                      if ( (*((_DWORD *)v477 + 598) & 0x200000) == 0 )
                      {
                        v1636 = 664797184;
                        KeBugCheckEx(__ROR4__(664797184, 149), 0xAui64, v510, 2ui64, 0i64);
                      }
LABEL_832:
                      if ( !*((_DWORD *)v477 + 560) )
                      {
                        *((_QWORD *)v477 + 281) = v477 - 0x5C5FC0A76E374B18i64;
                        *((_QWORD *)v477 + 282) = 0i64;
                        *((_QWORD *)v477 + 283) = 271i64;
                        *((_QWORD *)v477 + 284) = v510;
                        *((_DWORD *)v477 + 560) = 1;
                        goto LABEL_834;
                      }
                      goto LABEL_829;
                    }
                    v524 = v514[2];
                    v1703 = v514;
                    if ( (v524 & 1) != 0 || (*(_BYTE *)(v524 + v510) & 0x20) != 0 )
                    {
                      v525 = v518[4];
                      v526 = v518[3];
                      if ( v525 <= v518[2] )
                        v525 = v518[2];
                      v527 = v526 + v525;
                      v528 = (unsigned int *)(*((__int64 (__fastcall **)(unsigned int *, ULONG_PTR, __int64, __int64))v477
                                              + 129))(
                                               v514,
                                               BugCheckParameter2,
                                               v521,
                                               v519);
                      v529 = v528;
                      if ( *v528 < v526 || v528[1] > v527 )
                      {
                        v530 = BugCheckParameter2;
                        if ( (*((_DWORD *)v477 + 598) & 0x200000) == 0 )
                        {
                          v1637 = 664797184;
                          KeBugCheckEx(
                            __ROR4__(664797184, 149),
                            0xAui64,
                            BugCheckParameter2,
                            ((_DWORD)v528 - (_DWORD)BugCheckParameter2) | 0x80000000,
                            0i64);
                        }
                        if ( !*((_DWORD *)v477 + 560) )
                        {
                          *((_QWORD *)v477 + 281) = v477 - 0x5C5FC0A76E374B18i64;
                          *((_QWORD *)v477 + 282) = 0i64;
                          *((_QWORD *)v477 + 283) = 271i64;
                          *((_QWORD *)v477 + 284) = v530;
                          *((_DWORD *)v477 + 560) = 1;
                          __b9(v477, 0i64);
                        }
                      }
                      v531 = (unsigned int *)(*((__int64 (__fastcall **)(unsigned int *, ULONG_PTR, ULONG_PTR))v477 + 130))(
                                               v529,
                                               BugCheckParameter2,
                                               BugCheckParameter2 + *v529);
                      if ( *v531 >= v526 && v531[1] <= v527 )
                      {
                        v510 = BugCheckParameter2;
                      }
                      else
                      {
                        v510 = BugCheckParameter2;
                        v532 = ((_DWORD)v531 - BugCheckParameter2) | 0x80000000;
                        if ( (*((_DWORD *)v477 + 598) & 0x200000) == 0 )
                        {
                          v1638 = 664797184;
                          KeBugCheckEx(__ROR4__(664797184, 149), 0xAui64, BugCheckParameter2, v532, 0i64);
                        }
                        if ( !*((_DWORD *)v477 + 560) )
                        {
                          *((_QWORD *)v477 + 281) = v477 - 0x5C5FC0A76E374B18i64;
                          *((_QWORD *)v477 + 282) = 0i64;
                          *((_QWORD *)v477 + 283) = 271i64;
                          *((_QWORD *)v477 + 284) = v510;
                          *((_DWORD *)v477 + 560) = 1;
                          __b9(v477, 0i64);
                        }
                      }
                      v518 = (_DWORD *)v1597;
                      v521 = (unsigned int)v1596;
                    }
                    v514 += 3;
                  }
                  while ( v514 != (unsigned int *)v1593 );
                  v516 = (unsigned int)v1600;
                  v519 = 1i64;
                  v515 = v1581;
                }
                ++v516;
                v518 += 10;
                LODWORD(v1600) = v516;
                v1597 = (__int64)v518;
              }
              while ( v516 < v515 );
              v533 = v1585;
              v534 = v1595;
              v535 = (_DWORD *)v1583;
              if ( v514 != (unsigned int *)v1593 )
              {
                if ( (*((_DWORD *)v477 + 598) & 0x200000) == 0 )
                {
                  v1635 = 664797184;
                  KeBugCheckEx(__ROR4__(664797184, 149), 0xAui64, v510, 3ui64, 0i64);
                }
                goto LABEL_832;
              }
              if ( (_DWORD)v1585 )
                v536 = (v1585 + 6) & 0xFFFFFFF8;
              else
                v536 = 0;
              v537 = *((unsigned int *)v477 + 491);
              v538 = v537 + v536 + 24 * (v515 + 2);
              if ( v538 <= *((_DWORD *)v477 + 633) )
              {
                v539 = (__int64)v477;
                v1596 = v477;
                *((_DWORD *)v477 + 491) = v538;
                goto LABEL_893;
              }
              v1596 = (_BYTE *)sub_140ACCC24(v477, v538, *((unsigned int *)v477 + 571));
              v539 = (__int64)v1596;
              if ( !v1596 )
                goto LABEL_775;
              v540 = *((_DWORD *)v477 + 598);
              if ( (v540 & 4) == 0 )
              {
                v541 = *((_DWORD *)v477 + 491);
                v542 = *((_QWORD *)v477 + 242);
                v543 = (v540 & 0x20000000) != 0 ? *((_DWORD *)v477 + 571) : 0;
                if ( v541 >= 8 )
                {
                  v544 = (unsigned __int64)v541 >> 3;
                  do
                  {
                    *(_QWORD *)v477 = 0i64;
                    v541 -= 8;
                    v477 += 8;
                    --v544;
                  }
                  while ( v544 );
                }
                for ( ; v541; --v541 )
                  *v477++ = 0;
                v545 = *(_DWORD *)(v539 + 2284);
                *(_DWORD *)(v539 + 2284) = v543;
                if ( v543 == 3 )
                {
                  (*(void (__fastcall **)(__int64))(v539 + 856))(v542);
                }
                else if ( (*(_DWORD *)(v539 + 2392) & 0x10000000) != 0 || !v543 )
                {
                  (*(void (__fastcall **)(__int64))(v539 + 240))(v542);
                }
                else
                {
                  (*(void (__fastcall **)(__int64, _QWORD))(v539 + 536))(v542 - 8, *(_QWORD *)(v542 - 8));
                }
                v539 = (__int64)v1596;
                *((_DWORD *)v1596 + 571) = v545;
              }
              *(_DWORD *)(v539 + 2392) &= ~4u;
              v533 = v1585;
              v515 = v1581;
LABEL_893:
              v546 = v539 + v537;
              ++*(_DWORD *)(v539 + 2004);
              v547 = (_QWORD *)(v539 + v537);
              v1668 = v539 + v537;
              v548 = 48;
              v549 = 6i64;
              do
              {
                *v547 = 0i64;
                v548 -= 8;
                ++v547;
                --v549;
              }
              while ( v549 );
              for ( ; v548; --v548 )
              {
                *(_BYTE *)v547 = 0;
                v547 = (_QWORD *)((char *)v547 + 1);
              }
              v550 = v1588;
              *(_DWORD *)v546 = 30;
              *(_QWORD *)(v546 + 8) = v550;
              *(_DWORD *)(v546 + 16) = 0;
              v551 = *(_QWORD *)(v539 + 2016);
              for ( i20 = v551; ; LODWORD(v551) = i20 ^ v551 )
              {
                i20 >>= 31;
                if ( !i20 )
                  break;
              }
              *(_DWORD *)(v546 + 20) = v551 & 0x7FFFFFFF;
              v477 = (_BYTE *)v539;
              v1617 = v1668;
              v1604 = (_BYTE *)v539;
              *(_QWORD *)(v1668 + 24) = BugCheckParameter2;
              *(_DWORD *)(v1617 + 32) = *(_DWORD *)(v534 + 80);
              *(_DWORD *)(v1617 + 36) = v1582;
              v553 = v1592 != 0;
              *(_WORD *)(v1617 + 40) = v1793;
              *(_WORD *)(v1617 + 42) = *(_WORD *)(v1617 + 42) & 0xFFFE | v553;
              v1600 = (char *)(v1617 + 48);
              if ( v533 )
                v554 = (_DWORD *)(v1617 + 48 + (((unsigned int)(v533 - 1) + 7i64) & 0xFFFFFFFFFFFFFFF8ui64));
              else
                v554 = (_DWORD *)(v1617 + 48);
              v555 = *(unsigned __int16 *)(v1617 + 40);
              v1582 = (unsigned __int64)v554;
              v556 = (__int64)&v554[6 * v555];
              v1595 = v556;
              if ( v533 )
                v557 = (__int64)(v1588 + 3);
              else
                v557 = v1593;
              v1597 = v557;
              if ( v515 )
              {
                v558 = v515;
                v559 = v554 + 2;
                v560 = 0;
                do
                {
                  v561 = 2i64;
                  do
                  {
                    *(v559 - 2) = 0;
                    *(v559 - 1) = 0;
                    *v559 = 0x80000000;
                    v559 += 3;
                    --v561;
                  }
                  while ( v561 );
                  --v558;
                }
                while ( v558 );
                v21 = (ULONG_PTR)v1580;
              }
              else
              {
                v560 = 0;
              }
              if ( v554 != (_DWORD *)v556 )
              {
                while ( 2 )
                {
                  v562 = 0;
                  v1794 = 0;
                  if ( (v535[9] & 0x2000000) != 0 )
                    goto LABEL_917;
                  v563 = *v535;
                  if ( *v535 == 1414090313 )
                  {
                    if ( v535[1] == 1195525195 )
                      goto LABEL_917;
LABEL_923:
                    if ( v563 != 1095914053 || *((_WORD *)v535 + 2) != 16724 )
                      goto LABEL_925;
LABEL_917:
                    v562 = 1;
                    v1794 = 1;
                  }
                  else
                  {
                    if ( v563 != 1162297680 )
                      goto LABEL_923;
                    v564 = *((_WORD *)v535 + 2);
                    if ( v564 == 30839 || v564 == 29303 || v564 == 30583 )
                      goto LABEL_917;
LABEL_925:
                    v565 = 7;
                    v566 = *(unsigned __int8 **)(v539 + 2296);
                    v567 = (unsigned __int8 *)v535;
                    v568 = *(__int64 **)(v539 + 2304);
                    v1780 = v566;
                    v569 = (unsigned __int8 *)*((_QWORD *)v1596 + 289);
                    v570 = (unsigned __int8 *)*((_QWORD *)v1596 + 290);
                    while ( 1 )
                    {
                      v571 = *v567++;
                      v572 = *v566++;
                      if ( v571 != v572 )
                        break;
                      if ( !--v565 )
                        goto LABEL_944;
                    }
                    v573 = 8;
                    v574 = (__int64 *)v535;
                    do
                    {
                      v575 = *v574++;
                      v576 = *v568++;
                      if ( v575 != v576 )
                      {
                        v560 = 0;
                        goto LABEL_937;
                      }
                      v573 -= 8;
                    }
                    while ( v573 >= 8 );
                    v560 = 0;
                    if ( v573 )
                    {
                      while ( 1 )
                      {
                        v577 = *(unsigned __int8 *)v574;
                        v574 = (__int64 *)((char *)v574 + 1);
                        v578 = *(unsigned __int8 *)v568;
                        v568 = (__int64 *)((char *)v568 + 1);
                        if ( v577 != v578 )
                          break;
                        if ( !--v573 )
                          goto LABEL_944;
                      }
LABEL_937:
                      v579 = 4;
                      v580 = (unsigned __int8 *)v535;
                      while ( 1 )
                      {
                        v581 = *v580++;
                        v582 = *v569++;
                        if ( v581 != v582 )
                          break;
                        if ( !--v579 )
                          goto LABEL_944;
                      }
                      v583 = 6;
                      v584 = (unsigned __int8 *)v535;
                      while ( 1 )
                      {
                        v585 = *v584++;
                        v586 = *v570++;
                        if ( v585 != v586 )
                          break;
                        if ( !--v583 )
                          goto LABEL_944;
                      }
                    }
                    else
                    {
LABEL_944:
                      v562 = 1;
                      v1794 = 1;
                      v560 = 0;
                    }
                    v539 = (__int64)v1596;
                  }
                  v587 = v535[9];
                  if ( v587 < 0 )
                  {
                    v562 = 1;
                    v1794 = 1;
                    goto LABEL_949;
                  }
                  if ( v562 )
                  {
LABEL_949:
                    if ( *v535 == 1414090313 && v535[1] == 1195525195 )
                    {
                      if ( (*(_DWORD *)(v539 + 2396) & 0x2000) != 0 )
                        v562 = 0;
                      v1794 = v562;
                    }
                  }
                  if ( (*(_DWORD *)(v539 + 2396) & 0x4000) != 0
                    && (v587 & 0x20000000) != 0
                    && (BugCheckParameter2 == *(_QWORD *)(v539 + 1472) || BugCheckParameter2 == *(_QWORD *)(v539 + 1480)) )
                  {
                    v562 = 1;
                    v1794 = 1;
                  }
                  v588 = v535[4];
                  v589 = (unsigned int)v535[3];
                  v590 = v1593;
                  if ( v588 <= v535[2] )
                    v588 = v535[2];
                  v591 = v1588;
                  v592 = v589 + v588;
                  v1592 = v535[3];
                  v593 = v589;
                  v1581 = v592;
                  if ( v1588 == (unsigned int *)v1593 )
                  {
                    v595 = 0;
                    v596 = (_DWORD)v589 != 0;
                  }
                  else
                  {
                    v594 = *v1588;
                    v595 = v1588[1];
                    v596 = *v1588 < (unsigned int)v589;
                    if ( *v1588 > (unsigned int)v589 )
                    {
                      if ( v1588[1] > v592 )
                        goto LABEL_993;
                      if ( v562 )
                        goto LABEL_995;
                      v597 = (_DWORD *)v1582;
                      v598 = BugCheckParameter2 + v589;
                      v599 = (__int64 *)&v1679;
                      v600 = v594 - v589;
                      v593 = *v1588;
                      *(_DWORD *)v1582 = v589;
                      v601 = v598 + v594 - (unsigned int)v589;
                      v597[1] = v594;
                      v602 = v1648;
                      do
                      {
                        if ( v598 < *v599 + (unsigned __int64)(unsigned int)*v602 && v601 > *v599 )
                        {
                          v560 = 0;
                          goto LABEL_992;
                        }
                        ++v560;
                        ++v599;
                        ++v602;
                      }
                      while ( v560 < 6 );
                      v603 = (__int64)v1596;
                      v604 = (_QWORD *)v598;
                      *((_DWORD *)v1596 + 508) += v600;
                      v605 = *(_DWORD *)(v603 + 2012);
                      v606 = *(_QWORD *)(v603 + 2016);
                      v607 = (const char *)v598;
                      if ( v598 < v601 )
                      {
                        do
                        {
                          _mm_prefetch(v607, 0);
                          v607 += 64;
                        }
                        while ( (unsigned __int64)v607 < v601 );
                      }
                      v608 = v606;
                      v609 = v600 >> 7;
                      if ( v600 >> 7 )
                      {
                        do
                        {
                          v610 = 8i64;
                          do
                          {
                            v611 = v608 ^ *v604;
                            v612 = v604[1];
                            v604 += 2;
                            v608 = __ROL8__(__ROL8__(v611, v605) ^ v612, v605);
                            --v610;
                          }
                          while ( v610 );
                          v613 = __ROL8__(v606 ^ ((unsigned __int64)v604 - v598), 17) ^ v606 ^ ((unsigned __int64)v604
                                                                                              - v598);
                          v1704 = (v613 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                          v605 = ((unsigned __int8)v1704 ^ (unsigned __int8)(v613 ^ v605)) & 0x3F;
                          if ( !v605 )
                            LOBYTE(v605) = 1;
                          --v609;
                        }
                        while ( v609 );
                        v21 = (ULONG_PTR)v1580;
                        LODWORD(v589) = v1592;
                      }
                      v614 = v600 & 0x7F;
                      if ( v614 >= 8 )
                      {
                        v615 = (unsigned __int64)v614 >> 3;
                        do
                        {
                          v608 = __ROL8__(*v604++ ^ v608, v605);
                          v614 -= 8;
                          --v615;
                        }
                        while ( v615 );
                      }
                      if ( v614 )
                      {
                        do
                        {
                          v616 = *(unsigned __int8 *)v604;
                          v604 = (_QWORD *)((char *)v604 + 1);
                          v608 = __ROL8__(v616 ^ v608, v605);
                          --v614;
                        }
                        while ( v614 );
                        v21 = (ULONG_PTR)v1580;
                      }
                      v617 = v608 >> 31;
                      v560 = 0;
                      while ( v617 )
                      {
                        LODWORD(v608) = v617 ^ v608;
                        v617 >>= 31;
                      }
                      v592 = v1581;
                      v562 = v1794;
                      *(_DWORD *)(v1582 + 8) = v608 & 0x7FFFFFFF;
LABEL_992:
                      v591 = v1588;
                      v590 = v1593;
                      v539 = (__int64)v1596;
LABEL_993:
                      if ( v595 <= v592 && v591 != (unsigned int *)v590 )
                      {
LABEL_995:
                        v618 = (unsigned int *)v1597;
                        v619 = *(_DWORD *)(v1597 + 4);
                        if ( v619 <= v592 )
                        {
                          v620 = v1600;
                          while ( v618 != (unsigned int *)v590 )
                          {
                            if ( v562 )
                            {
                              v621 = 0x80;
                            }
                            else
                            {
                              v622 = v591[1];
                              v593 = *v618;
                              if ( *v618 < (unsigned int)v622 )
                              {
                                if ( (*(_DWORD *)(v539 + 2392) & 0x200000) == 0 )
                                {
                                  v1642 = 664797184;
                                  KeBugCheckEx(__ROR4__(664797184, 149), 0xAui64, BugCheckParameter2, 6ui64, 0i64);
                                }
                                if ( !*(_DWORD *)(v539 + 2240) )
                                {
                                  v623 = BugCheckParameter2;
                                  *(_QWORD *)(v539 + 2248) = v539 - 0x5C5FC0A76E374B18i64;
                                  *(_QWORD *)(v539 + 2256) = 0i64;
                                  *(_QWORD *)(v539 + 2264) = 271i64;
                                  *(_QWORD *)(v539 + 2272) = v623;
                                  *(_DWORD *)(v539 + 2240) = 1;
                                  __b9(v539, 0i64);
                                  v560 = 0;
                                }
                              }
                              v624 = v1648;
                              v625 = BugCheckParameter2 + v622;
                              v626 = (__int64 *)&v1679;
                              v627 = v593 - v622;
                              v628 = BugCheckParameter2 + v622 + v593 - (unsigned int)v622;
                              do
                              {
                                if ( v625 < *v626 + (unsigned __int64)(unsigned int)*v624 && v628 > *v626 )
                                  goto LABEL_1029;
                                ++v560;
                                ++v626;
                                ++v624;
                              }
                              while ( v560 < 6 );
                              if ( v627 < 4 )
                              {
LABEL_1029:
                                v560 = 0;
                                v621 = 0x80;
                              }
                              else
                              {
                                v629 = (__int64)v1596;
                                v630 = (_QWORD *)v625;
                                *((_DWORD *)v1596 + 508) += v627;
                                v631 = *(_DWORD *)(v629 + 2012);
                                v632 = *(_QWORD *)(v629 + 2016);
                                v633 = (const char *)v625;
                                if ( v625 < v628 )
                                {
                                  do
                                  {
                                    _mm_prefetch(v633, 0);
                                    v633 += 64;
                                  }
                                  while ( (unsigned __int64)v633 < v628 );
                                }
                                v634 = v632;
                                v635 = v627 >> 7;
                                if ( v627 >> 7 )
                                {
                                  do
                                  {
                                    v636 = 8i64;
                                    do
                                    {
                                      v637 = v634 ^ *v630;
                                      v638 = v630[1];
                                      v630 += 2;
                                      v634 = __ROL8__(__ROL8__(v637, v631) ^ v638, v631);
                                      --v636;
                                    }
                                    while ( v636 );
                                    v639 = __ROL8__(v632 ^ ((unsigned __int64)v630 - v625), 17) ^ v632 ^ ((unsigned __int64)v630 - v625);
                                    v1705 = (v639 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                                    v631 = ((unsigned __int8)v1705 ^ (unsigned __int8)(v639 ^ v631)) & 0x3F;
                                    if ( !v631 )
                                      LOBYTE(v631) = 1;
                                    --v635;
                                  }
                                  while ( v635 );
                                  v21 = (ULONG_PTR)v1580;
                                }
                                v640 = v627 & 0x7F;
                                if ( v640 >= 8 )
                                {
                                  v641 = (unsigned __int64)v640 >> 3;
                                  do
                                  {
                                    v634 = __ROL8__(*v630++ ^ v634, v631);
                                    v640 -= 8;
                                    --v641;
                                  }
                                  while ( v641 );
                                }
                                v560 = 0;
                                if ( v640 )
                                {
                                  do
                                  {
                                    v642 = *(unsigned __int8 *)v630;
                                    v630 = (_QWORD *)((char *)v630 + 1);
                                    v634 = __ROL8__(v642 ^ v634, v631);
                                    --v640;
                                  }
                                  while ( v640 );
                                  v21 = (ULONG_PTR)v1580;
                                }
                                for ( i21 = v634; ; LOBYTE(v634) = i21 ^ v634 )
                                {
                                  i21 >>= 7;
                                  if ( !i21 )
                                    break;
                                }
                                v562 = v1794;
                                v621 = v634 & 0x7F;
                                v618 = (unsigned int *)v1597;
                              }
                              v591 = v1588;
                              v592 = v1581;
                              v620 = v1600;
                            }
                            *v620 = v621;
                            v591 += 3;
                            v618 += 3;
                            v1588 = v591;
                            v590 = v1593;
                            v620 = ++v1600;
                            v1597 = (__int64)v618;
                            if ( v618 != (unsigned int *)v1593 )
                              v619 = v618[1];
                            if ( v619 > v592 )
                              break;
                            v539 = (__int64)v1596;
                          }
                        }
                        LODWORD(v589) = v1592;
                      }
LABEL_1035:
                      v644 = (unsigned int *)v1582;
                      if ( !v562 && v593 != v592 )
                      {
                        v645 = BugCheckParameter2;
                        v646 = v1648;
                        *(_DWORD *)(v1582 + 12) = v593;
                        v647 = (__int64 *)&v1679;
                        v644[4] = v592;
                        v648 = v644[3];
                        v649 = v592 - v648;
                        v650 = v648 + v645;
                        v651 = v650 + v592 - (unsigned int)v648;
                        do
                        {
                          if ( v650 < *v647 + (unsigned __int64)(unsigned int)*v646 && v651 > *v647 )
                          {
                            v560 = 0;
                            goto LABEL_1061;
                          }
                          ++v560;
                          ++v647;
                          ++v646;
                        }
                        while ( v560 < 6 );
                        v652 = (__int64)v1596;
                        v653 = (_QWORD *)v650;
                        *((_DWORD *)v1596 + 508) += v649;
                        v654 = *(_DWORD *)(v652 + 2012);
                        v655 = *(_QWORD *)(v652 + 2016);
                        v656 = (const char *)v650;
                        if ( v650 < v651 )
                        {
                          do
                          {
                            _mm_prefetch(v656, 0);
                            v656 += 64;
                          }
                          while ( (unsigned __int64)v656 < v651 );
                        }
                        v657 = v655;
                        v658 = v649 >> 7;
                        if ( v649 >> 7 )
                        {
                          do
                          {
                            v659 = 8i64;
                            do
                            {
                              v660 = v657 ^ *v653;
                              v661 = v653[1];
                              v653 += 2;
                              v657 = __ROL8__(__ROL8__(v660, v654) ^ v661, v654);
                              --v659;
                            }
                            while ( v659 );
                            v662 = __ROL8__(v655 ^ ((unsigned __int64)v653 - v650), 17) ^ v655 ^ ((unsigned __int64)v653
                                                                                                - v650);
                            v1706 = (v662 * (unsigned __int128)0x7010008004002001ui64) >> 64;
                            v654 = ((unsigned __int8)(v662 ^ v1706) ^ (unsigned __int8)v654) & 0x3F;
                            if ( !v654 )
                              LOBYTE(v654) = 1;
                            --v658;
                          }
                          while ( v658 );
                          v21 = (ULONG_PTR)v1580;
                          v644 = (unsigned int *)v1582;
                        }
                        v663 = v649 & 0x7F;
                        if ( v663 >= 8 )
                        {
                          v664 = (unsigned __int64)v663 >> 3;
                          do
                          {
                            v657 = __ROL8__(*v653++ ^ v657, v654);
                            v663 -= 8;
                            --v664;
                          }
                          while ( v664 );
                        }
                        if ( v663 )
                        {
                          do
                          {
                            v665 = *(unsigned __int8 *)v653;
                            v653 = (_QWORD *)((char *)v653 + 1);
                            v657 = __ROL8__(v665 ^ v657, v654);
                            --v663;
                          }
                          while ( v663 );
                          LODWORD(v589) = v1592;
                        }
                        v666 = v657 >> 31;
                        v560 = 0;
                        while ( v666 )
                        {
                          LODWORD(v657) = v666 ^ v657;
                          v666 >>= 31;
                        }
                        v592 = v1581;
                        v644[5] = v657 & 0x7FFFFFFF;
                      }
LABEL_1061:
                      v667 = v1588;
                      if ( v1588 != (unsigned int *)v1593 && *v1588 >= (unsigned int)v589 && v1588[1] <= v592 )
                      {
                        v668 = v1597;
                        if ( v1597 != v1593 )
                        {
                          v669 = v1600;
                          *v1600 = 0x80;
                          v1600 = v669 + 1;
                          v1597 = v668 + 12;
                        }
                        v1588 = v667 + 3;
                      }
                      v539 = (__int64)v1596;
                      v535 = (_DWORD *)(v1583 + 40);
                      v1582 = (unsigned __int64)(v644 + 6);
                      v1583 += 40i64;
                      if ( v644 + 6 == (unsigned int *)v1595 )
                      {
                        v477 = v1604;
                        goto LABEL_1069;
                      }
                      continue;
                    }
                  }
                  break;
                }
                if ( !v596 )
                  goto LABEL_993;
                goto LABEL_1035;
              }
LABEL_1069:
              v1607 = v477;
              v54 = 0i64;
LABEL_1070:
              v367 = (ULONG_PTR)v1587;
LABEL_1071:
              v670 = &v1607[-v21];
              v21 = (ULONG_PTR)v1607;
              v671 = (char *)v1579 + (_QWORD)v670;
              v1580 = v1607;
              v1579 = (int *)((char *)v1579 + (_QWORD)v670);
              if ( (int)(v54 + 0x80000000) < 0 || (_DWORD)v54 == -1073741554 )
                *((_QWORD *)v671 + 5) = v367;
LABEL_1074:
              i15 = v1586;
LABEL_1118:
              *(_DWORD *)(v21 + 2032) += i15 << 12;
              v701 = *(_DWORD *)(v21 + 2032);
              ++*(_DWORD *)(v21 + 2028);
              if ( v701 < *(_DWORD *)(v21 + 2036) )
              {
                v64 = (char *)v1579;
                v69 = 0;
                goto LABEL_591;
              }
LABEL_1121:
              v1580 = (_BYTE *)v21;
              goto LABEL_146;
            }
            v447[8] |= 2u;
            goto LABEL_745;
          }
          ++v382;
          v375 = 0;
          if ( v382 >= *(_DWORD *)(v21 + 2004) )
            goto LABEL_679;
        }
        v386 = v382 - v375;
        v375 = v382;
        while ( 2 )
        {
          v387 = *(_DWORD *)v380;
          if ( *(int *)v380 > 12 )
          {
            if ( v387 == 28 )
            {
              v392 = *(unsigned __int16 *)(v380 + 40);
              goto LABEL_669;
            }
            if ( v387 == 30 )
            {
              v391 = (((*(_DWORD *)(v380 + 36) != 0 ? *(_DWORD *)(v380 + 36) - 1 : 0) / 0xCu + 7) & 0xFFFFFFF8)
                   + 24 * (*(unsigned __int16 *)(v380 + 40) + 2);
              goto LABEL_670;
            }
            if ( v387 <= 32 )
              goto LABEL_666;
            if ( v387 <= 34 )
            {
              v391 = 20
                   * (unsigned int)(((*(_DWORD *)(v380 + 32) & 0xFFF)
                                   + (unsigned __int64)*(unsigned int *)(v380 + 40)
                                   + 4095) >> 12)
                   + 48;
              goto LABEL_670;
            }
            if ( v387 != 43 )
              goto LABEL_666;
          }
          else if ( v387 != 12 )
          {
            v388 = v387 - 1;
            if ( v388 )
            {
              v389 = v388 - 6;
              if ( !v389 )
              {
                v391 = (unsigned int)(24 * (*(_DWORD *)(v380 + 24) + 2));
                goto LABEL_670;
              }
              v390 = v389 - 1;
              if ( v390 )
              {
                if ( v390 == 2 )
                {
                  v391 = (unsigned int)(16 * (*(_DWORD *)(v380 + 28) + 3));
                  goto LABEL_670;
                }
LABEL_666:
                v391 = 48i64;
LABEL_670:
                v380 += v391;
                if ( !--v386 )
                {
                  v21 = (ULONG_PTR)v1580;
                  v376 = v1791;
                  v374 = BugCheckParameter2;
                  v377 = v1588;
                  v367 = (ULONG_PTR)v1587;
                  goto LABEL_672;
                }
                continue;
              }
              v392 = *(unsigned __int16 *)(v380 + 32);
LABEL_669:
              v391 = (v392 + 55) & 0xFFFFFFF8;
              goto LABEL_670;
            }
          }
          break;
        }
        v391 = 4 * (*(_DWORD *)(v380 + 16) / 0xCu) + 48;
        goto LABEL_670;
      }
      v702 = *((_DWORD *)v64 + 10);
      (*(void (__fastcall **)(char *, _QWORD))(v21 + 400))(v1751, *((unsigned int *)v64 + 11));
      (*(void (__fastcall **)(char *, char *))(v21 + 448))(v1751, v1770);
      v73 = v702 == 0;
      v703 = __readcr4();
      if ( v73 )
        v703 = __readcr0();
      v704 = v1770;
LABEL_1125:
      (*(void (__fastcall **)(char *))(v21 + 392))(v704);
      v705 = *((_QWORD *)v64 + 4);
      v706 = v703 & *((_QWORD *)v64 + 3);
      if ( v706 == v705 )
        goto LABEL_146;
      v54 = *((_QWORD *)v64 + 5);
      if ( *(_DWORD *)(v21 + 2240) )
        goto LABEL_146;
      *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v706 ^ v705;
LABEL_1128:
      if ( *(_DWORD *)(v21 + 2240) )
        goto LABEL_146;
      *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
      *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
      v707 = *(int *)v64;
LABEL_1130:
      *(_QWORD *)(v21 + 2264) = v707;
      *(_QWORD *)(v21 + 2272) = v54;
      goto LABEL_1131;
    }
    switch ( v77 )
    {
      case 12:
        if ( !*(_QWORD *)(v21 + 2376) )
          goto LABEL_1745;
        v236 = *(unsigned int *)(v21 + 2028);
        v237 = *(_DWORD *)(v21 + 2396);
        if ( (_DWORD)v236 )
        {
          v54 = v237;
          if ( (((unsigned __int8)v237 ^ (unsigned __int8)(v237 >> 3)) & 4) != 0 )
            goto LABEL_1745;
        }
        else
        {
          LODWORD(v54) = v237 ^ ((unsigned __int8)v237 ^ (unsigned __int8)(8 * v237)) & 0x20;
          *(_DWORD *)(v21 + 2396) = v54;
        }
        if ( (v54 & 4) != 0 )
        {
          v238 = *((_QWORD *)v64 + 4);
          if ( v238 )
          {
            LOWORD(v239) = v236 + v238;
            v240 = (unsigned int)(*((_DWORD *)v64 + 10) - v236);
            v241 = v238 + v236;
          }
          else
          {
            v239 = *((_DWORD *)v64 + 2);
            v240 = *((unsigned int *)v64 + 4);
            v241 = *((_QWORD *)v64 + 1);
          }
          v54 = v239 & 0xFFF;
          v242 = (v54 + v240 + 4095) >> 12;
          v243 = v241 & 0xFFFFFFFFFFFFF000ui64;
          while ( v242 )
          {
            --v242;
            if ( (*(unsigned __int8 (__fastcall **)(unsigned __int64))(v21 + 672))(v243) && !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
              *(_QWORD *)(v21 + 2264) = *(int *)v64;
              *(_QWORD *)(v21 + 2272) = v243;
              *(_DWORD *)(v21 + 2240) = 1;
              __b9(v21, 0i64);
            }
            v243 += 4096i64;
            v244 = *(_DWORD *)(v21 + 2032) + 256;
            *(_DWORD *)(v21 + 2032) = v244;
            if ( v238 )
            {
              *(_DWORD *)(v21 + 2028) += 4096;
              if ( v244 >= *(_DWORD *)(v21 + 2036) )
                goto LABEL_461;
            }
          }
          if ( v238 )
          {
LABEL_461:
            if ( !v242 )
              *(_DWORD *)(v21 + 2028) = 0;
          }
          if ( *(_DWORD *)(v21 + 2028) )
            goto LABEL_146;
          v245 = *(_QWORD *)(v21 + 1304);
          v246 = KeGetCurrentIrql();
          __writecr8(0xFui64);
          (*(void (__fastcall **)(__int64))(v21 + 320))(v245);
          v248 = **(unsigned int ***)(v21 + 1512);
          v249 = v248 + 4;
          v250 = *((_BYTE *)v248 + 12);
          v251 = (unsigned __int64)&v248[6 * *v248 + 4];
          do
          {
            v252 = 24i64;
            v253 = (__int64 *)(v64 + 24);
            v254 = v249;
            do
            {
              v255 = *(_QWORD *)v254;
              v254 += 2;
              v256 = *v253++;
              if ( v255 != v256 )
                goto LABEL_472;
              v252 = (unsigned int)(v252 - 8);
            }
            while ( (unsigned int)v252 >= 8 );
            if ( !(_DWORD)v252 )
              break;
            while ( 1 )
            {
              v247 = *(unsigned __int8 *)v254;
              v254 = (unsigned int *)((char *)v254 + 1);
              v257 = *(unsigned __int8 *)v253;
              v253 = (__int64 *)((char *)v253 + 1);
              if ( v247 != v257 )
                break;
              v73 = (_DWORD)v252 == 1;
              v252 = (unsigned int)(v252 - 1);
              if ( v73 )
                goto LABEL_473;
            }
LABEL_472:
            v249 += 6;
          }
          while ( (unsigned __int64)v249 < v251 );
LABEL_473:
          v21 = (ULONG_PTR)v1580;
          (*((void (__fastcall **)(_QWORD, __int64, __int64, __int64 *))v1580 + 48))(
            *((_QWORD *)v1580 + 163),
            v247,
            v252,
            v253);
          __writecr8(v246);
          if ( v250 )
          {
            v54 = 16i64;
            if ( (*(_DWORD *)(v21 + 2396) & 0x10) != 0 && !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
              *(_QWORD *)(v21 + 2264) = *(int *)v64;
              *(_QWORD *)(v21 + 2272) = 1i64;
              *(_DWORD *)(v21 + 2240) = 1;
              __b9(v21, 0i64);
            }
            if ( *((_QWORD *)v64 + 3) == 1i64 )
              goto LABEL_146;
          }
          if ( v249 != (unsigned int *)v251 || *(_DWORD *)(v21 + 2240) )
            goto LABEL_146;
          v258 = v21 - 0x5C5FC0A76E374B18i64;
          goto LABEL_481;
        }
        goto LABEL_2103;
      case 0:
        v215 = (_QWORD *)*((_QWORD *)v64 + 1);
        v216 = *((unsigned int *)v64 + 4);
        v217 = v215;
        *(_DWORD *)(v21 + 2032) += v216;
        v218 = (const char *)v215;
        v219 = *(_DWORD *)(v21 + 2012);
        v220 = *(_QWORD *)(v21 + 2016);
        v54 = (unsigned __int64)v215 + v216;
        if ( v215 < (_QWORD *)((char *)v215 + v216) )
        {
          do
          {
            _mm_prefetch(v218, 0);
            v218 += 64;
          }
          while ( (unsigned __int64)v218 < v54 );
        }
        v221 = *(_QWORD *)(v21 + 2016);
        v222 = (unsigned int)v216 >> 7;
        if ( (unsigned int)v216 >> 7 )
        {
          do
          {
            v223 = 8i64;
            do
            {
              v224 = v217[1] ^ __ROL8__(*v217 ^ v221, v219);
              v217 += 2;
              v221 = __ROL8__(v224, v219);
              --v223;
            }
            while ( v223 );
            v54 = __ROL8__(v220 ^ ((char *)v217 - (char *)v215), 17) ^ v220 ^ ((char *)v217 - (char *)v215);
            v1746 = (v54 * (unsigned __int128)0x7010008004002001ui64) >> 64;
            v219 = ((unsigned __int8)v1746 ^ (unsigned __int8)(v54 ^ v219)) & 0x3F;
            if ( !v219 )
              v219 = 1;
            --v222;
          }
          while ( v222 );
          v21 = (ULONG_PTR)v1580;
        }
        v225 = v216 & 0x7F;
        if ( v225 >= 8 )
        {
          v226 = (unsigned __int64)v225 >> 3;
          do
          {
            v54 = v219;
            v221 = __ROL8__(*v217++ ^ v221, v219);
            v225 -= 8;
            --v226;
          }
          while ( v226 );
        }
        for ( ; v225; --v225 )
        {
          v227 = *(unsigned __int8 *)v217;
          v54 = v219;
          v217 = (_QWORD *)((char *)v217 + 1);
          v221 = __ROL8__(v227 ^ v221, v219);
        }
        for ( i22 = v221; ; LODWORD(v221) = i22 ^ v221 )
        {
          i22 >>= 31;
          if ( !i22 )
            break;
        }
        v229 = v221 & 0x7FFFFFFF;
        if ( v229 == *((_DWORD *)v64 + 5) )
          goto LABEL_146;
        if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
          v69 = 1;
        v54 = *((unsigned int *)v64 + 4);
        v230 = *((_QWORD *)v64 + 1);
        if ( *((_DWORD *)v64 + 4) )
        {
          v231 = 64i64;
          if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
          {
            v232 = KeGetCurrentIrql();
            __writecr8(2ui64);
            v233 = v230 & 0xFFFFFFFFFFFFF000ui64;
            v1787 = (v230 + v54 - 1) | 0xFFF;
            v234 = (v230 & 0xFFFFFFFFFFFFF000ui64) - 1;
            while ( 1 )
            {
              v102 = v232;
              while ( 1 )
              {
                v235 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                         v233,
                         0i64,
                         v231,
                         v217);
                if ( v235 != -1073741267 )
                  break;
                if ( v69 )
                  goto LABEL_439;
                if ( v232 > 1u )
                  goto LABEL_437;
                v102 = v232;
                __writecr8(v232);
                KeGetCurrentIrql();
                __writecr8(2ui64);
              }
              if ( v235 < 0 )
                break;
LABEL_437:
              v233 += 4096i64;
              v234 += 4096i64;
              if ( v234 == v1787 )
                goto LABEL_228;
            }
LABEL_439:
            __writecr8(v102);
            v64 = (char *)v1579;
          }
        }
        if ( *(_DWORD *)(v21 + 2240) )
          goto LABEL_146;
        *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = *((unsigned int *)v64 + 5) ^ (unsigned __int64)v229;
        goto LABEL_442;
      case 1:
        goto LABEL_2103;
    }
    v54 = (unsigned int)(v77 - 4);
    switch ( v77 )
    {
      case 4:
        if ( (*(_DWORD *)(v21 + 2040) & 1) == 0 )
        {
          v197 = *(void (**)(void))(v21 + 360);
          v198 = 0;
          v199 = *(_QWORD *)(v21 + 1312);
          LODWORD(v1582) = 0;
          v197();
          if ( (*(_DWORD *)(v21 + 2392) & 0x40000000) != 0 || (v200 = *(_DWORD *)(v21 + 2328), v200 >= 7) )
          {
            (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 280))(*(_QWORD *)(v21 + 2504), 0i64);
            v201 = 0x80;
          }
          else
          {
            v201 = 1 << v200;
          }
          v1786 = v201;
          (*(void (__fastcall **)(__int64, _QWORD))(v21 + 296))(v199, 0i64);
          v202 = *(_QWORD ***)(v21 + 1272);
          v203 = *v202;
          if ( *v202 != v202 )
          {
            do
            {
              v204 = (unsigned __int64)v203 - *(_QWORD *)(v21 + 1696);
              if ( v201 != 0x80
                && (v201 & *(_BYTE *)(v204 + *(_QWORD *)(v21 + 1672))) != 0
                && (*(_DWORD *)(v204 + *(_QWORD *)(v21 + 1680)) & *(_DWORD *)(v21 + 1704)) != 0
                && !*(_DWORD *)(v21 + 2240) )
              {
                v205 = v1579;
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = (char *)v205 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v205;
                *(_QWORD *)(v21 + 2272) = v204 | 1;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
              _InterlockedOr8((volatile signed __int8 *)(v204 + *(_QWORD *)(v21 + 1672)), v201);
              v203 = (_QWORD *)*v203;
              ++v198;
            }
            while ( v203 != v202 );
            LODWORD(v1582) = v198;
          }
          v206 = *(_QWORD *)(v21 + 1240);
          v1585 = KeGetCurrentIrql();
          __writecr8(0xCui64);
          (*(void (__fastcall **)(__int64, char *))(v21 + 312))(v206, v1778);
          v207 = *(_QWORD ***)(v21 + 1232);
          v208 = *v207;
          if ( *v207 != v207 )
          {
            v209 = v201;
            v210 = v201;
            v211 = v1579;
            v212 = ~v209;
            do
            {
              v213 = *(_QWORD *)(v21 + 1672);
              v214 = (char *)v208 - *(_QWORD *)(v21 + 1664);
              if ( (v214[v213] & v210) == 0 && !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = (char *)v211 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *v211;
                *(_QWORD *)(v21 + 2272) = v214;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
                v213 = *(_QWORD *)(v21 + 1672);
              }
              _InterlockedAnd8(&v214[v213], v212);
              v208 = (_QWORD *)*v208;
            }
            while ( v208 != v207 );
            v201 = v1786;
            v198 = v1582;
          }
          (*(void (__fastcall **)(char *))(v21 + 376))(v1778);
          __writecr8((unsigned __int8)v1585);
          if ( v201 == 0x80 )
            (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 288))(*(_QWORD *)(v21 + 2504), 0i64);
          (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 304))(*(_QWORD *)(v21 + 1312), 0i64);
          (*(void (**)(void))(v21 + 368))();
          *(_DWORD *)(v21 + 2032) += v198 << 8;
        }
        goto LABEL_146;
      case 5:
        v54 = *(unsigned int *)(v21 + 2040);
        if ( (v54 & 1) == 0 )
          goto LABEL_146;
        if ( _bittest((const signed __int32 *)(v21 + 2392), 0x1Eu) )
        {
          v172 = __rdtsc();
          v173 = (__ROR8__(v172, 3) ^ v172) * (unsigned __int128)0x7010008004002001ui64;
          v1745 = *((_QWORD *)&v173 + 1);
          v1785 = ((unsigned __int64)v173 ^ *((_QWORD *)&v173 + 1)) == 3
                                                                     * (((unsigned __int64)v173 ^ *((_QWORD *)&v173 + 1))
                                                                      / 3);
        }
        else
        {
          v1785 = (v54 & 3) == 3;
        }
        v174 = *(void (**)(void))(v21 + 360);
        v175 = 0;
        v176 = *(_QWORD *)(v21 + 1312);
        LODWORD(v1582) = 0;
        v174();
        if ( _bittest((const signed __int32 *)(v21 + 2392), 0x1Eu) || (v177 = *(_DWORD *)(v21 + 2328), v177 >= 7) )
        {
          (*(void (__fastcall **)(_QWORD, _QWORD))(v21 + 280))(*(_QWORD *)(v21 + 2504), 0i64);
          v178 = 0x80;
        }
        else
        {
          v178 = 1 << v177;
        }
        (*(void (__fastcall **)(__int64, _QWORD))(v21 + 296))(v176, 0i64);
        v179 = *(volatile signed __int8 ***)(v21 + 1272);
        v180 = *v179;
        if ( *v179 != (volatile signed __int8 *)v179 )
        {
          do
          {
            _InterlockedOr8(&v180[*(_QWORD *)(v21 + 1672) - *(_QWORD *)(v21 + 1696)], v178);
            v180 = *(volatile signed __int8 **)v180;
            ++v175;
          }
          while ( v180 != (volatile signed __int8 *)v179 );
          LODWORD(v1582) = v175;
        }
        v181 = 4i64;
        v182 = **(_QWORD **)(v21 + 1320);
        v183 = *(unsigned int *)(*(_QWORD *)(v21 + 1792) + v182);
        while ( 1 )
        {
          v184 = (__int64 *)(*(__int64 (__fastcall **)(__int64, unsigned __int64))(v21 + 248))(v182, v181);
          v186 = 0i64;
          v187 = v184;
          if ( v184 )
            break;
LABEL_379:
          v181 += 4i64;
          if ( v181 >= v183 )
          {
            if ( v178 == 0x80 )
              (*(void (__fastcall **)(_QWORD, _QWORD, __int64, __int64))(v21 + 288))(
                *(_QWORD *)(v21 + 2504),
                0i64,
                v185,
                v186);
            (*(void (__fastcall **)(_QWORD, _QWORD, __int64, __int64))(v21 + 304))(
              *(_QWORD *)(v21 + 1312),
              0i64,
              v185,
              v186);
            (*(void (**)(void))(v21 + 368))();
            v196 = (v183 >> 2) + v1582;
            goto LABEL_383;
          }
        }
        v188 = (_BYTE *)((*v184 >> 16) & 0xFFFFFFFFFFFFFFF0ui64);
        v189 = *v188 & 0x7F;
        if ( v189 == 3 )
        {
          v185 = *(_QWORD *)(v21 + 1672);
          v190 = v185;
          if ( (v178 & v188[v185]) == 0
            && (*(_DWORD *)&v188[*(_QWORD *)(v21 + 1680)] & *(_DWORD *)(v21 + 1704)) != 0
            && !*(_DWORD *)(v21 + 2240) )
          {
            v191 = v1579;
            *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
            *(_QWORD *)(v21 + 2256) = (char *)v191 - 0x4C48B4211BBACBEBi64;
            *(_QWORD *)(v21 + 2264) = *v191;
            *(_QWORD *)(v21 + 2272) = v188;
            *(_DWORD *)(v21 + 2240) = 1;
            __b9(v21, 0i64);
            v190 = *(_QWORD *)(v21 + 1672);
          }
          _InterlockedAnd8(&v188[v190], ~v178);
          goto LABEL_378;
        }
        if ( v189 == 6 )
        {
          if ( v1785 )
          {
            v192 = *(_QWORD *)(v21 + 1616);
            v193 = *(_QWORD *)&v188[v192 + 32];
            if ( (v193 == *(_QWORD *)(v21 + 784) || v193 == *(_QWORD *)(v21 + 792))
              && *(_QWORD *)&v188[v192 + 48] == *(_QWORD *)(v21 + 800) )
            {
              v194 = *(_QWORD *)&v188[v192 + 40] == *(_QWORD *)(v21 + 808);
              goto LABEL_375;
            }
            goto LABEL_376;
          }
        }
        else
        {
          v194 = v189 == 0;
LABEL_375:
          if ( !v194 )
          {
LABEL_376:
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              v195 = v1579;
              *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
              *(_QWORD *)(v21 + 2256) = (char *)v195 - 0x4C48B4211BBACBEBi64;
              *(_QWORD *)(v21 + 2264) = *v195;
              *(_QWORD *)(v21 + 2272) = v188;
              *(_DWORD *)(v21 + 2240) = 1;
              __b9(v21, 0i64);
            }
          }
        }
LABEL_378:
        (*(void (__fastcall **)(__int64, __int64 *, __int64, __int64))(v21 + 272))(v182, v187, v185, v186);
        goto LABEL_379;
      case 7:
        (*(void (__fastcall **)(char *, _QWORD))(v21 + 400))(v1749, *((unsigned int *)v64 + 7));
        (*(void (__fastcall **)(char *, char *))(v21 + 448))(v1749, v1750);
        for ( i23 = 0; i23 < *((_DWORD *)v64 + 6); ++i23 )
        {
          v165 = *(unsigned int *)&v64[24 * i23 + 64];
          if ( (*(_BYTE *)(v21 + 2115) & 2) != 0
            && (_DWORD)v165 == -1073741694
            && KeGetPcr()->Prcb.Number == *(_DWORD *)(v21 + 2232) )
          {
            v166 = *(_QWORD *)(v21 + 2224);
          }
          else
          {
            v166 = __readmsr(v165);
          }
          v167 = *(_QWORD *)&v64[24 * i23 + 48];
          v168 = *(_QWORD *)&v64[24 * i23 + 56];
          v169 = v167 & v166;
          if ( v169 == v168 )
          {
            if ( (*(_DWORD *)(v21 + 2396) & 0x200) != 0 && v167 == -1 )
              __writemsr(v165, v169);
          }
          else
          {
            v170 = v165 | ((unsigned __int64)*((unsigned int *)v64 + 7) << 32);
            if ( !*(_DWORD *)(v21 + 2240) )
            {
              *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v169 ^ v168;
              if ( !*(_DWORD *)(v21 + 2240) )
              {
                *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                *(_QWORD *)(v21 + 2264) = *(int *)v64;
                *(_QWORD *)(v21 + 2272) = v170;
                *(_DWORD *)(v21 + 2240) = 1;
                __b9(v21, 0i64);
              }
            }
          }
        }
        (*(void (__fastcall **)(char *))(v21 + 392))(v1750);
        v171 = *((_DWORD *)v64 + 6) << 15;
        goto LABEL_348;
      case 8:
        v136 = *((_QWORD *)v64 + 3);
        v137 = *((_WORD *)v64 + 17);
        if ( *(_WORD *)(v136 + *(_QWORD *)(v21 + 1728) + *(_QWORD *)(v21 + 1776)) != v137 && !*(_DWORD *)(v21 + 2240) )
        {
          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
          *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
          *(_QWORD *)(v21 + 2264) = *(int *)v64;
          *(_QWORD *)(v21 + 2272) = v136;
          *(_DWORD *)(v21 + 2240) = 1;
          __b9(v21, 0i64);
          v137 = *((_WORD *)v64 + 17);
        }
        if ( (v137 & *(_WORD *)(v21 + 1784)) == 0
          && *(_QWORD *)(v136 + *(_QWORD *)(v21 + 1736)) != v136 + *(_QWORD *)(v21 + 1736)
          && !*(_DWORD *)(v21 + 2240) )
        {
          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
          *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
          *(_QWORD *)(v21 + 2264) = *(int *)v64;
          *(_QWORD *)(v21 + 2272) = v136;
          *(_DWORD *)(v21 + 2240) = 1;
          __b9(v21, 0i64);
        }
        v138 = (_QWORD *)*((_QWORD *)v64 + 1);
        v139 = *((unsigned int *)v64 + 4);
        v140 = v138;
        *(_DWORD *)(v21 + 2032) += v139;
        v141 = (const char *)v138;
        v142 = *(_DWORD *)(v21 + 2012);
        v143 = *(_QWORD *)(v21 + 2016);
        if ( v138 < (_QWORD *)((char *)v138 + v139) )
        {
          do
          {
            _mm_prefetch(v141, 0);
            v141 += 64;
          }
          while ( v141 < (const char *)v138 + v139 );
        }
        v144 = *(_QWORD *)(v21 + 2016);
        v145 = (unsigned int)v139 >> 7;
        if ( (unsigned int)v139 >> 7 )
        {
          do
          {
            v146 = 8i64;
            do
            {
              v147 = v140[1] ^ __ROL8__(*v140 ^ v144, v142);
              v140 += 2;
              v144 = __ROL8__(v147, v142);
              --v146;
            }
            while ( v146 );
            v148 = (__ROL8__(v143 ^ ((char *)v140 - (char *)v138), 17) ^ v143 ^ (unsigned __int64)((char *)v140
                                                                                                 - (char *)v138))
                 * (unsigned __int128)0x7010008004002001ui64;
            v1744 = *((_QWORD *)&v148 + 1);
            v142 = (BYTE8(v148) ^ (unsigned __int8)(v148 ^ v142)) & 0x3F;
            if ( !v142 )
              LOBYTE(v142) = 1;
            --v145;
          }
          while ( v145 );
          v21 = (ULONG_PTR)v1580;
        }
        v149 = v139 & 0x7F;
        if ( v149 >= 8 )
        {
          v150 = (unsigned __int64)v149 >> 3;
          do
          {
            v144 = __ROL8__(*v140++ ^ v144, v142);
            v149 -= 8;
            --v150;
          }
          while ( v150 );
        }
        for ( ; v149; --v149 )
        {
          v151 = *(unsigned __int8 *)v140;
          v140 = (_QWORD *)((char *)v140 + 1);
          v144 = __ROL8__(v151 ^ v144, v142);
        }
        for ( i24 = v144; ; LODWORD(v144) = i24 ^ v144 )
        {
          i24 >>= 31;
          if ( !i24 )
            break;
        }
        v153 = v144 & 0x7FFFFFFF;
        if ( v153 == *((_DWORD *)v64 + 5) )
          goto LABEL_324;
        if ( !*(_DWORD *)v64 && *((_DWORD *)v64 + 6) )
          v69 = 1;
        v154 = *((unsigned int *)v64 + 4);
        v155 = *((_QWORD *)v64 + 1);
        if ( *((_DWORD *)v64 + 4) )
        {
          v156 = 64i64;
          if ( (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
          {
            v157 = KeGetCurrentIrql();
            __writecr8(2ui64);
            v158 = v155 & 0xFFFFFFFFFFFFF000ui64;
            v1784 = (v155 + v154 - 1) | 0xFFF;
            v159 = (v155 & 0xFFFFFFFFFFFFF000ui64) - 1;
            while ( 1 )
            {
              v160 = v157;
              while ( 1 )
              {
                v161 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                         v158,
                         0i64,
                         v156,
                         v140);
                if ( v161 != -1073741267 )
                  break;
                if ( v69 )
                  goto LABEL_329;
                if ( v157 > 1u )
                  goto LABEL_322;
                v160 = v157;
                __writecr8(v157);
                KeGetCurrentIrql();
                __writecr8(2ui64);
              }
              if ( v161 < 0 )
                break;
LABEL_322:
              v158 += 4096i64;
              v159 += 4096i64;
              if ( v159 == v1784 )
              {
                __writecr8(v160);
                v64 = (char *)v1579;
LABEL_324:
                v1675 = v64 + 48;
                v1674[0] = *((_WORD *)v64 + 16);
                LOBYTE(v1577) = 0;
                v1674[1] = v1674[0];
                if ( (*(int (__fastcall **)(__int16 *, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, __int64 *))(v21 + 472))(
                       v1674,
                       0i64,
                       0i64,
                       0i64,
                       *(_QWORD *)(v21 + 1248),
                       v1577,
                       0i64,
                       &v1653) >= 0 )
                {
                  v162 = v1653;
                  if ( v1653 != *((_QWORD *)v64 + 3) && !*(_DWORD *)(v21 + 2240) )
                  {
                    *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
                    *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
                    *(_QWORD *)(v21 + 2264) = *(int *)v64;
                    *(_QWORD *)(v21 + 2272) = v162;
                    *(_DWORD *)(v21 + 2240) = 1;
                    __b9(v21, 0i64);
                  }
                  (*(void (**)(void))(v21 + 464))();
                }
                goto LABEL_146;
              }
            }
LABEL_329:
            __writecr8(v160);
            v64 = (char *)v1579;
          }
        }
        if ( !*(_DWORD *)(v21 + 2240) )
        {
          *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = *((unsigned int *)v64 + 5) ^ (unsigned __int64)v153;
          v163 = *((_QWORD *)v64 + 1);
          if ( !*(_DWORD *)(v21 + 2240) )
          {
            *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
            *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
            *(_QWORD *)(v21 + 2264) = *(int *)v64;
            *(_QWORD *)(v21 + 2272) = v163;
            *(_DWORD *)(v21 + 2240) = 1;
            __b9(v21, 0i64);
          }
        }
        goto LABEL_324;
    }
    v54 = (unsigned int)(v77 - 10);
    if ( v77 == 10 )
    {
      if ( *((_DWORD *)v64 + 6) )
      {
        if ( !*(_QWORD *)(v21 + 2376) )
          goto LABEL_241;
        v54 = *(unsigned int *)(v21 + 2396);
        if ( (v54 & 4) != 0 )
          goto LABEL_241;
        v105 = *(_DWORD *)(v21 + 2028);
        if ( v105 )
        {
          if ( (v54 & 0x20) != 0 )
            goto LABEL_241;
        }
        else
        {
          *(_DWORD *)(v21 + 2396) = v54 ^ ((unsigned __int8)v54 ^ (unsigned __int8)(8 * v54)) & 0x20;
        }
      }
      else
      {
        v105 = *(_DWORD *)(v21 + 2028);
      }
      v107 = (unsigned int *)&v64[16 * v105 + 48];
      v108 = (unsigned __int64)&v64[16 * *((unsigned int *)v64 + 7) + 48];
      v1783 = v108;
      do
      {
        if ( (*v107 & 0x80000000) != 0 )
          goto LABEL_274;
        v109 = *((_QWORD *)v107 + 1);
        v110 = v107[1];
        v111 = (_QWORD *)v109;
        *(_DWORD *)(v21 + 2032) += v110;
        v112 = (const char *)v109;
        v113 = *(_DWORD *)(v21 + 2012);
        v114 = (unsigned int)v110;
        v115 = *(_QWORD *)(v21 + 2016);
        v1583 = v109;
        if ( v109 < (unsigned __int64)(v110 + v109) )
        {
          do
          {
            _mm_prefetch(v112, 0);
            v112 += 64;
          }
          while ( (unsigned __int64)v112 < v110 + v109 );
        }
        v116 = v115;
        v117 = (unsigned int)v110 >> 7;
        if ( (unsigned int)v110 >> 7 )
        {
          do
          {
            v118 = 8i64;
            do
            {
              v119 = v116 ^ *v111;
              v120 = v111[1];
              v111 += 2;
              v116 = __ROL8__(__ROL8__(v119, v113) ^ v120, v113);
              --v118;
            }
            while ( v118 );
            v121 = __ROL8__(v115 ^ ((unsigned __int64)v111 - v109), 17) ^ v115 ^ ((unsigned __int64)v111 - v109);
            v1743 = (v121 * (unsigned __int128)0x7010008004002001ui64) >> 64;
            v113 = ((unsigned __int8)v1743 ^ (unsigned __int8)(v121 ^ v113)) & 0x3F;
            if ( !v113 )
              LOBYTE(v113) = 1;
            --v117;
          }
          while ( v117 );
          v21 = (ULONG_PTR)v1580;
          v108 = v1783;
        }
        v122 = v110 & 0x7F;
        if ( (unsigned int)v122 >= 8 )
        {
          v123 = (unsigned __int64)(unsigned int)v122 >> 3;
          do
          {
            v116 = __ROL8__(*v111++ ^ v116, v113);
            v122 = (unsigned int)(v122 - 8);
            --v123;
          }
          while ( v123 );
        }
        if ( (_DWORD)v122 )
        {
          do
          {
            v124 = *(unsigned __int8 *)v111;
            v111 = (_QWORD *)((char *)v111 + 1);
            v116 = __ROL8__(v124 ^ v116, v113);
            v122 = (unsigned int)(v122 - 1);
          }
          while ( (_DWORD)v122 );
          v21 = (ULONG_PTR)v1580;
        }
        for ( i25 = v116; ; LODWORD(v116) = i25 ^ v116 )
        {
          i25 >>= 31;
          if ( !i25 )
            break;
        }
        v54 = *v107;
        v126 = v116 & 0x7FFFFFFF;
        if ( v126 == (*v107 & 0x7FFFFFFF) )
          goto LABEL_274;
        if ( v114 && (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
        {
          v127 = KeGetCurrentIrql();
          __writecr8(2ui64);
          v128 = v109 & 0xFFFFFFFFFFFFF000ui64;
          v1585 = (v114 + v109 - 1) | 0xFFF;
          v129 = (v109 & 0xFFFFFFFFFFFFF000ui64) - 1;
          while ( 1 )
          {
            v130 = v127;
            while ( 1 )
            {
              v131 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, __int64, _QWORD *))(v21 + 1112))(
                       v128,
                       0i64,
                       v122,
                       v111);
              if ( v131 != -1073741267 )
                break;
              if ( v127 > 1u )
                goto LABEL_272;
              v130 = v127;
              __writecr8(v127);
              KeGetCurrentIrql();
              __writecr8(2ui64);
            }
            if ( v131 < 0 )
              break;
LABEL_272:
            v128 += 4096i64;
            v129 += 4096i64;
            if ( v129 == v1585 )
            {
              __writecr8(v130);
              v108 = v1783;
              goto LABEL_274;
            }
          }
          __writecr8(v130);
          v54 = *v107;
          v109 = v1583;
          v108 = v1783;
        }
        v134 = (unsigned int)v54;
        LODWORD(v134) = v54 & 0x7FFFFFFF;
        if ( *(_DWORD *)(v21 + 2240) )
        {
LABEL_274:
          v132 = v1579;
        }
        else
        {
          v135 = v126;
          v132 = v1579;
          v54 = v134 ^ v135;
          *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v54;
          if ( !*(_DWORD *)(v21 + 2240) )
          {
            *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
            *(_QWORD *)(v21 + 2256) = (char *)v132 - 0x4C48B4211BBACBEBi64;
            *(_QWORD *)(v21 + 2264) = *v132;
            *(_QWORD *)(v21 + 2272) = v109;
            *(_DWORD *)(v21 + 2240) = 1;
            __b9(v21, 0i64);
          }
        }
        v107 += 4;
        v133 = v107 == (unsigned int *)v108;
        if ( (unsigned __int64)v107 >= v108 )
          goto LABEL_278;
      }
      while ( *(_DWORD *)(v21 + 2032) < *(_DWORD *)(v21 + 2036) );
      v133 = v107 == (unsigned int *)v108;
LABEL_278:
      if ( !v133 )
      {
        v106 = ((char *)v107 - (char *)(v132 + 12)) >> 4;
        goto LABEL_280;
      }
LABEL_241:
      LODWORD(v106) = 0;
LABEL_280:
      *(_DWORD *)(v21 + 2028) = v106;
      goto LABEL_146;
    }
    if ( v77 != 11 )
      goto LABEL_2294;
    if ( !*(_QWORD *)(v21 + 2376) )
      goto LABEL_1745;
    if ( *(_DWORD *)(v21 + 2028) )
    {
      v54 = *(unsigned int *)(v21 + 2396);
      if ( (((unsigned __int8)v54 ^ (unsigned __int8)(*(_DWORD *)(v21 + 2396) >> 3)) & 4) != 0 )
        goto LABEL_1745;
    }
    else
    {
      LODWORD(v54) = *(_DWORD *)(v21 + 2396) ^ ((unsigned __int8)*(_DWORD *)(v21 + 2396) ^ (unsigned __int8)(8 * *(_DWORD *)(v21 + 2396))) & 0x20;
      *(_DWORD *)(v21 + 2396) = v54;
    }
    if ( (v54 & 4) != 0 )
    {
      v54 = *((_DWORD *)v64 + 2) & 0xFFF;
      v78 = *((_QWORD *)v64 + 1) & 0xFFFFFFFFFFFFF000ui64;
      v79 = (v54 + *((unsigned int *)v64 + 4) + 4095i64) >> 12;
      while ( v79 )
      {
        --v79;
        if ( (*(unsigned __int8 (__fastcall **)(unsigned __int64))(v21 + 672))(v78) && !*(_DWORD *)(v21 + 2240) )
        {
          *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
          *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
          *(_QWORD *)(v21 + 2264) = *(int *)v64;
          *(_QWORD *)(v21 + 2272) = v78;
          *(_DWORD *)(v21 + 2240) = 1;
          __b9(v21, 0i64);
        }
        v78 += 4096i64;
        *(_DWORD *)(v21 + 2032) += 256;
      }
      goto LABEL_146;
    }
    v80 = (_QWORD *)*((_QWORD *)v64 + 1);
    v81 = *((unsigned int *)v64 + 4);
    v82 = v80;
    *(_DWORD *)(v21 + 2032) += v81;
    v83 = (const char *)v80;
    v84 = *(_DWORD *)(v21 + 2012);
    v85 = *(_QWORD *)(v21 + 2016);
    v54 = (unsigned __int64)v80 + v81;
    if ( v80 < (_QWORD *)((char *)v80 + v81) )
    {
      do
      {
        _mm_prefetch(v83, 0);
        v83 += 64;
      }
      while ( (unsigned __int64)v83 < v54 );
    }
    v86 = *(_QWORD *)(v21 + 2016);
    v87 = (unsigned int)v81 >> 7;
    if ( (unsigned int)v81 >> 7 )
    {
      do
      {
        v88 = 8i64;
        do
        {
          v89 = v86 ^ *v82;
          v90 = v82[1];
          v82 += 2;
          v86 = __ROL8__(__ROL8__(v89, v84) ^ v90, v84);
          --v88;
        }
        while ( v88 );
        v54 = __ROL8__(v85 ^ ((char *)v82 - (char *)v80), 17) ^ v85 ^ ((char *)v82 - (char *)v80);
        v1742 = (v54 * (unsigned __int128)0x7010008004002001ui64) >> 64;
        v84 = ((unsigned __int8)v1742 ^ (unsigned __int8)(v54 ^ v84)) & 0x3F;
        if ( !v84 )
          v84 = 1;
        --v87;
      }
      while ( v87 );
      v21 = (ULONG_PTR)v1580;
    }
    v91 = v81 & 0x7F;
    if ( v91 >= 8 )
    {
      v92 = (unsigned __int64)v91 >> 3;
      do
      {
        v54 = v84;
        v86 = __ROL8__(*v82++ ^ v86, v84);
        v91 -= 8;
        --v92;
      }
      while ( v92 );
    }
    if ( v91 )
    {
      do
      {
        v93 = *(unsigned __int8 *)v82;
        v54 = v84;
        v82 = (_QWORD *)((char *)v82 + 1);
        v86 = __ROL8__(v93 ^ v86, v84);
        --v91;
      }
      while ( v91 );
      v21 = (ULONG_PTR)v1580;
    }
    for ( i26 = v86; ; LODWORD(v86) = i26 ^ v86 )
    {
      i26 >>= 31;
      if ( !i26 )
        break;
    }
    v95 = *((_DWORD *)v64 + 5);
    v96 = v86 & 0x7FFFFFFF;
    if ( v96 != v95 )
    {
      v54 = *((unsigned int *)v64 + 4);
      v97 = *((_QWORD *)v64 + 1);
      if ( *((_DWORD *)v64 + 4) && (*(_DWORD *)(v21 + 2396) & 0x40) != 0 )
      {
        v98 = KeGetCurrentIrql();
        __writecr8(2ui64);
        v99 = v97 & 0xFFFFFFFFFFFFF000ui64;
        v100 = (v97 + v54 - 1) | 0xFFF;
        v101 = (v97 & 0xFFFFFFFFFFFFF000ui64) - 1;
        while ( 2 )
        {
          v102 = v98;
          while ( 1 )
          {
            v103 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD))(v21 + 1112))(v99, 0i64);
            if ( v103 != -1073741267 )
              break;
            if ( v98 > 1u )
              goto LABEL_227;
            v102 = v98;
            __writecr8(v98);
            KeGetCurrentIrql();
            __writecr8(2ui64);
          }
          if ( v103 < 0 )
          {
            __writecr8(v102);
            v64 = (char *)v1579;
            v95 = v1579[5];
            goto LABEL_230;
          }
LABEL_227:
          v99 += 4096i64;
          v101 += 4096i64;
          if ( v101 != v100 )
            continue;
          break;
        }
LABEL_228:
        __writecr8(v102);
        goto LABEL_146;
      }
LABEL_230:
      if ( *(_DWORD *)(v21 + 2240) )
        goto LABEL_146;
      *(_QWORD *)(*(_QWORD *)(v21 + 1384) + 24i64) = v95 ^ (unsigned __int64)v96;
      v54 = *((_QWORD *)v64 + 1);
      v104 = *(_DWORD *)(v21 + 2240) == 0;
LABEL_232:
      if ( v104 )
      {
        *(_QWORD *)(v21 + 2248) = v21 - 0x5C5FC0A76E374B18i64;
        *(_QWORD *)(v21 + 2256) = v64 - 0x4C48B4211BBACBEBi64;
        *(_QWORD *)(v21 + 2264) = *(int *)v64;
        *(_QWORD *)(v21 + 2272) = v54;
        *(_DWORD *)(v21 + 2240) = 1;
        __b9(v21, 0i64);
      }
    }
LABEL_146:
    v52 = 0xFFFFFFFFi64;
    v72 = v1598;
    if ( *(_DWORD *)(v21 + 2028) )
      v72 = v1598 - 1;
    v56 = v72 + 1;
    v73 = *(_DWORD *)(v21 + 2240) == 0;
    v7 = 1;
    v1598 = v56;
    if ( !v73 || *(_DWORD *)(v21 + 2032) >= *(_DWORD *)(v21 + 2036) )
    {
      LODWORD(v54) = v1598;
      goto LABEL_2471;
    }
    v55 = v1615;
    v57 = v1623;
    v58 = v1606;
  }
  ++*(_DWORD *)(v21 + 2040);
  LODWORD(v54) = 0;
  if ( *(_DWORD *)(v21 + 2336) != 11 || (v1520 = *(_DWORD *)(v21 + 2392), (v1520 & 1) != 0) )
  {
LABEL_2471:
    v17 = (__int64)v1602;
    v2 = a2;
    v18 = v1608;
  }
  else
  {
    v18 = v1608;
    v2 = a2;
    v17 = (__int64)v1602;
    if ( *(_DWORD *)(v21 + 2360) == -1 )
      *(_DWORD *)(v21 + 2360) = 0;
    else
      *(_DWORD *)(v21 + 2392) = v1520 | 1;
  }
LABEL_2472:
  *(_DWORD *)(v21 + 2024) = v54;
  if ( v1599 )
  {
    v1521 = *(_QWORD *)(*(_QWORD *)(v21 + 1656)
                      + *(_QWORD *)((char *)&KeGetCurrentPrcb()->MxCsr + *(_QWORD *)(v21 + 1560))
                      + *(_QWORD *)(v21 + 1624));
    (*(void (__fastcall **)(char *))(v21 + 392))(v1762);
    (*(void (__fastcall **)(char *))(v21 + 1072))(v1777);
    (*(void (__fastcall **)(__int64))(v21 + 920))(v1521);
    (*(void (__fastcall **)(__int64))(v21 + 936))(v1521);
  }
  if ( v1614 && ((*(_DWORD *)(v21 + 2392) & 0x8000) != 0 || !*(_DWORD *)(v21 + 2240)) )
  {
    v1522 = *(_QWORD *)(v21 + 2376);
    *(_QWORD *)(v21 + 2376) = 0i64;
    (*(void (__fastcall **)(__int64, char *))(v21 + 648))(v1522, v1777);
    v1523 = *(_DWORD *)(v21 + 2392);
    if ( (v1523 & 1) != 0 )
    {
      *(_DWORD *)(v21 + 2392) = v1523 & 0xFFFFFFFE;
      v1522 = (*(__int64 (__fastcall **)(__int64))(v21 + 624))(v1522);
      if ( v1522 )
      {
        *(_DWORD *)(v21 + 2360) = (*(__int64 (__fastcall **)(__int64))(v21 + 656))(v1522);
        goto LABEL_2482;
      }
      *(_DWORD *)(v21 + 2360) = -1;
    }
    else if ( v1522 )
    {
LABEL_2482:
      (*(void (__fastcall **)(__int64))(v21 + 632))(v1522);
    }
  }
  if ( *(_DWORD *)(v18 + 2240) )
  {
    v1524 = *(_QWORD *)(v18 + 2264);
    v1525 = *(_QWORD *)(v18 + 2272);
    v1526 = *(_QWORD *)(v18 + 2256);
    v1527 = *(_QWORD *)(v18 + 2248);
    v1585 = v1525;
    v1595 = v1526;
    v1624 = v1527;
    if ( KeGetCurrentIrql() < 2u )
    {
      KeGetCurrentIrql();
      __writecr8(2ui64);
    }
    v1528 = KeGetCurrentPrcb();
    v1529 = 0i64;
    v1530 = *(_QWORD *)((char *)&v1528->MxCsr + *(_QWORD *)(v18 + 1544));
    v1531 = *(_QWORD *)((char *)&v1528->MxCsr + *(_QWORD *)(v18 + 1560));
    if ( !*((_BYTE *)&v1528->MxCsr + *(_QWORD *)(v18 + 1552))
      || (unsigned __int64)&v1655 > v1530
      || (unsigned __int64)&v1655 < v1530 - 24576 )
    {
      v1530 = *(_QWORD *)(v1531 + *(_QWORD *)(v18 + 1608));
    }
    if ( (*(_DWORD *)(v18 + 2392) & 0x8000000) == 0 )
    {
      v1532 = __readcr0();
      __writecr0(v1532 & 0xFFFFFFFFFFFEFFFFui64);
      v1533 = (__int64)v1602;
      v1534 = 0;
      v1535 = v1602 + 169;
      v1536 = (unsigned __int64)&v1602[*((unsigned int *)&v1602[168].Next + 2) + 169];
      v1537 = (_QWORD *)v1536;
      if ( *((_DWORD *)&v1602[168].Next + 3) )
      {
        do
        {
          *(_QWORD *)*v1537 = v1537[1];
          v1538 = __readcr4();
          if ( (v1538 & 0x20080) != 0 )
          {
            __writecr4(v1538 ^ 0x80);
            __writecr4(v1538);
          }
          else
          {
            v1539 = __readcr3();
            __writecr3(v1539);
          }
          v1537 += 2;
          ++v1534;
        }
        while ( v1534 < *(_DWORD *)(v1533 + 2700) );
        LODWORD(v1525) = v1585;
      }
      if ( (unsigned __int64)v1535 < v1536 )
      {
        do
        {
          v1540 = *((unsigned int *)&v1535->Next + 2);
          v1541 = v1537;
          Next = (char *)v1535->Next;
          v1543 = v1540;
          if ( (unsigned int)v1540 >= 8 )
          {
            v1529 = (unsigned __int64)(unsigned int)v1540 >> 3;
            do
            {
              v1543 -= 8;
              *(_QWORD *)Next = *v1541++;
              Next += 8;
              --v1529;
            }
            while ( v1529 );
          }
          if ( v1543 )
          {
            v1544 = Next - (char *)v1541;
            do
            {
              *((_BYTE *)v1541 + v1544) = *(_BYTE *)v1541;
              v1541 = (_QWORD *)((char *)v1541 + 1);
              --v1543;
            }
            while ( v1543 );
          }
          v1537 = (_QWORD *)((char *)v1537 + v1540);
          ++v1535;
        }
        while ( (unsigned __int64)v1535 < v1536 );
        LODWORD(v1525) = v1585;
        LODWORD(v1526) = v1595;
        v1533 = (__int64)v1602;
      }
      **(_BYTE **)(v1533 + 552) = -61;
      __writecr0(v1532);
      LODWORD(v1527) = v1624;
      v18 = v1608;
    }
    v1564 = *(_DWORD *)(v18 + 2288);
    if ( v1564 )
    {
      if ( KeGetCurrentIrql() < 2u )
      {
        KeGetCurrentIrql();
        __writecr8(2ui64);
        v1564 = *(_DWORD *)(v18 + 2288);
      }
      if ( v1564 )
      {
        v1565 = v1564 - 1;
        if ( v1565 )
        {
          v1566 = v1565 - 1;
          if ( v1566 )
          {
            v1567 = v1566 - 1;
            if ( v1567 )
            {
              v1568 = v1567 - 1;
              if ( v1568 )
              {
                if ( v1568 == 1 )
                  _interlockedbittestandset(
                    *(volatile signed __int32 **)((char *)&KeGetCurrentPrcb()->MxCsr + *(_QWORD *)(v18 + 1560)),
                    (*(_DWORD *)(v18 + 2392) >> 10) & 0x1F);
                else
                  _InterlockedOr64((volatile signed __int64 *)(*(_QWORD *)(v18 + 1424) + 832i64), 1ui64);
              }
              else
              {
                _interlockedbittestandset(
                  *(volatile signed __int32 **)(*(_QWORD *)(v18 + 1656)
                                              + *(_QWORD *)((char *)&KeGetCurrentPrcb()->MxCsr + *(_QWORD *)(v18 + 1560))
                                              + *(_QWORD *)(v18 + 1624)),
                  (*(_DWORD *)(v18 + 2392) >> 10) & 0x1F);
              }
              goto LABEL_2546;
            }
            v1569 = *(volatile signed __int32 **)(v18 + 1336);
          }
          else
          {
            v1569 = *(volatile signed __int32 **)(v18 + 1328);
          }
        }
        else
        {
          v1569 = *(volatile signed __int32 **)(v18 + 1312);
        }
        _interlockedbittestandset64(v1569, 0i64);
      }
    }
LABEL_2546:
    *(_QWORD *)(v1531 + *(_QWORD *)(v18 + 1632)) = v1529;
    *(_QWORD *)(v1531 + *(_QWORD *)(v18 + 1648)) = v1529;
    SdbpCheckDll(265, v1527, v1526, v1525, v1524, *(_QWORD *)(v18 + 328), v1530);
    __debugbreak();
  }
  if ( *(_DWORD *)(v18 + 2028) || *(_DWORD *)(v18 + 2024) )
  {
    v1545 = -1073741802;
    *(_DWORD *)v2 = *(_DWORD *)(v18 + 2024);
    *(_DWORD *)(v2 + 4) = *(_DWORD *)(v18 + 2028);
  }
  else
  {
    v1545 = *(_QWORD *)(v2 + 8) == 0i64 ? 0xC0000225 : 0;
  }
  if ( v1624 == 2744 )
    ExFreeToNPagedLookasideList(&Lookaside, (PVOID)v17);
  else
    ExFreePoolWithTag((PVOID)v17, v52);
  return v1545;
}
