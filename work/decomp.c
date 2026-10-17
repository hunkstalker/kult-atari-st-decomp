// Decompiled export of KULT.PRG
// 406 functions

// ===== FUNCTION INDEX =====
//   00010000  _start                        424 bytes
//   000101be  game_loop                     350 bytes
//   0001031c  handle_frame_input            116 bytes
//   00010390  FUN_00010390                  24 bytes
//   000103a8  run_command                   6 bytes
//   000103ae  run_command_keep_sp           126 bytes
//   0001042c  draw_text_box                 20 bytes
//   00010440  draw_text_box_variant         180 bytes
//   000104f4  FUN_000104f4                  46 bytes
//   00010522  FUN_00010522                  4 bytes
//   00010526  FUN_00010526                  228 bytes
//   0001060a  FUN_0001060a                  38 bytes
//   00010630  FUN_00010630                  56 bytes
//   00010668  FUN_00010668                  6 bytes
//   0001066e  FUN_0001066e                  20 bytes
//   00010682  FUN_00010682                  96 bytes
//   000106e2  FUN_000106e2                  8 bytes
//   000106ea  FUN_000106ea                  8 bytes
//   000106f8  load_resource_list            114 bytes
//   0001076a  load_resource                 20 bytes
//   0001077e  save_clear_bin                36 bytes
//   000107a2  write_named_file              20 bytes
//   000107b6  gemdos_fopen                  26 bytes
//   000107d0  gemdos_fcreate                24 bytes
//   000107e8  gemdos_fread                  32 bytes
//   00010808  gemdos_fwrite                 32 bytes
//   00010828  gemdos_fclose                 16 bytes
//   00010838  print_char                    106 bytes
//   000108a2  print_word                    108 bytes
//   0001090e  FUN_0001090e                  56 bytes
//   00010946  FUN_00010946                  82 bytes
//   00010998  FUN_00010998                  36 bytes
//   000109bc  FUN_000109bc                  66 bytes
//   000109fe  FUN_000109fe                  86 bytes
//   00010a54  FUN_00010a54                  52 bytes
//   00010a88  FUN_00010a88                  68 bytes
//   00010acc  FUN_00010acc                  34 bytes
//   00010aee  FUN_00010aee                  54 bytes
//   00010b24  FUN_00010b24                  34 bytes
//   00010b46  FUN_00010b46                  12 bytes
//   00010b52  FUN_00010b52                  26 bytes
//   00010b6c  FUN_00010b6c                  42 bytes
//   00010dfa  FUN_00010dfa                  108 bytes
//   00010e66  FUN_00010e66                  296 bytes
//   00010f8e  FUN_00010f8e                  38 bytes
//   00010fb4  FUN_00010fb4                  16 bytes
//   00010fc4  FUN_00010fc4                  40 bytes
//   00010fec  FUN_00010fec                  2 bytes
//   00010fee  FUN_00010fee                  6 bytes
//   00010ff4  FUN_00010ff4                  32 bytes
//   00011014  FUN_00011014                  2 bytes
//   00011016  FUN_00011016                  10 bytes
//   00011020  FUN_00011020                  16 bytes
//   00011030  FUN_00011030                  14 bytes
//   0001103e  FUN_0001103e                  12 bytes
//   0001104a  FUN_0001104a                  6 bytes
//   00011050  FUN_00011050                  138 bytes
//   00011102  FUN_00011102                  148 bytes
//   00011196  FUN_00011196                  22 bytes
//   000111ac  FUN_000111ac                  10 bytes
//   000111b6  FUN_000111b6                  762 bytes
//   000114b0  FUN_000114b0                  10 bytes
//   000114ba  FUN_000114ba                  804 bytes
//   000117de  FUN_000117de                  30 bytes
//   000117fe  FUN_000117fe                  732 bytes
//   00011ada  FUN_00011ada                  30 bytes
//   00011afa  FUN_00011afa                  756 bytes
//   00011dee  FUN_00011dee                  110 bytes
//   00011e5e  FUN_00011e5e                  26 bytes
//   00011e7a  FUN_00011e7a                  72 bytes
//   00011ec4  FUN_00011ec4                  10 bytes
//   00011ece  FUN_00011ece                  26 bytes
//   00011ee8  FUN_00011ee8                  26 bytes
//   00011f02  FUN_00011f02                  44 bytes
//   00011f2e  FUN_00011f2e                  54 bytes
//   00011f64  FUN_00011f64                  52 bytes
//   00011f98  FUN_00011f98                  64 bytes
//   00011fd8  FUN_00011fd8                  50 bytes
//   0001200a  FUN_0001200a                  58 bytes
//   00012044  FUN_00012044                  50 bytes
//   00012076  FUN_00012076                  50 bytes
//   000120a8  FUN_000120a8                  52 bytes
//   000120dc  FUN_000120dc                  8 bytes
//   000120e4  FUN_000120e4                  86 bytes
//   0001213a  FUN_0001213a                  36 bytes
//   0001215e  FUN_0001215e                  50 bytes
//   00012190  FUN_00012190                  38 bytes
//   000121b6  FUN_000121b6                  14 bytes
//   000121c4  FUN_000121c4                  2 bytes
//   000121c6  copy_screen                   24 bytes
//   000121de  swap_screens                  28 bytes
//   000121fa  FUN_000121fa                  52 bytes
//   0001222e  FUN_0001222e                  18 bytes
//   00012240  FUN_00012240                  14 bytes
//   0001224e  FUN_0001224e                  60 bytes
//   0001228a  FUN_0001228a                  8 bytes
//   00012292  prompt_wait                   92 bytes
//   000122ee  FUN_000122ee                  54 bytes
//   00012324  FUN_00012324                  10 bytes
//   0001232e  FUN_0001232e                  58 bytes
//   00012368  FUN_00012368                  28 bytes
//   00012384  FUN_00012384                  28 bytes
//   000123a0  FUN_000123a0                  32 bytes
//   000123c0  FUN_000123c0                  118 bytes
//   00012436  FUN_00012436                  48 bytes
//   00012466  FUN_00012466                  116 bytes
//   000124da  FUN_000124da                  24 bytes
//   000124f2  FUN_000124f2                  6 bytes
//   000124f8  blit_sprite                   24 bytes
//   00012510  FUN_00012510                  122 bytes
//   0001258a  FUN_0001258a                  6 bytes
//   00012590  FUN_00012590                  138 bytes
//   00012698  FUN_00012698                  72 bytes
//   000126e0  FUN_000126e0                  140 bytes
//   0001276c  FUN_0001276c                  116 bytes
//   000127e0  FUN_000127e0                  16 bytes
//   000127f0  FUN_000127f0                  10 bytes
//   000127fa  FUN_000127fa                  96 bytes
//   0001285a  FUN_0001285a                  74 bytes
//   000128a4  FUN_000128a4                  172 bytes
//   00012950  FUN_00012950                  28 bytes
//   0001296c  FUN_0001296c                  92 bytes
//   000129c8  FUN_000129c8                  14 bytes
//   000129d6  FUN_000129d6                  116 bytes
//   00012a4a  FUN_00012a4a                  140 bytes
//   00012ad6  FUN_00012ad6                  46 bytes
//   00012b04  FUN_00012b04                  60 bytes
//   00012b40  FUN_00012b40                  38 bytes
//   00012ce4  FUN_00012ce4                  560 bytes
//   00012d96  FUN_00012d96                  66 bytes
//   00012dd8  FUN_00012dd8                  48 bytes
//   00012e08  FUN_00012e08                  38 bytes
//   00012e2e  FUN_00012e2e                  116 bytes
//   00012ea2  FUN_00012ea2                  58 bytes
//   00012ef6  FUN_00012ef6                  50 bytes
//   00012f28  FUN_00012f28                  142 bytes
//   00012fb6  FUN_00012fb6                  52 bytes
//   00012fea  FUN_00012fea                  4 bytes
//   00012fee  FUN_00012fee                  12 bytes
//   00012ffa  FUN_00012ffa                  170 bytes
//   000130a4  FUN_000130a4                  190 bytes
//   00013162  FUN_00013162                  168 bytes
//   0001320a  FUN_0001320a                  12 bytes
//   00013216  FUN_00013216                  148 bytes
//   000132aa  FUN_000132aa                  66 bytes
//   000132ec  FUN_000132ec                  66 bytes
//   0001332e  FUN_0001332e                  66 bytes
//   00013370  FUN_00013370                  260 bytes
//   00013474  FUN_00013474                  28 bytes
//   00013490  FUN_00013490                  34 bytes
//   000134b2  FUN_000134b2                  40 bytes
//   000134da  FUN_000134da                  10 bytes
//   0001350c  FUN_0001350c                  22 bytes
//   00013522  FUN_00013522                  48 bytes
//   00013552  FUN_00013552                  22 bytes
//   00013568  load_fond                     10 bytes
//   00013572  load_named_screen             34 bytes
//   00013594  FUN_00013594                  18 bytes
//   000135ba  FUN_000135ba                  1 bytes
//   000135da  set_palette                   6 bytes
//   000135e0  FUN_000135e0                  2 bytes
//   000135e2  crt0_init                     164 bytes
//   00013686  FUN_00013686                  18 bytes
//   00013698  wait_frame                    106 bytes
//   00013702  FUN_00013702                  62 bytes
//   00013740  FUN_00013740                  358 bytes
//   000138a6  FUN_000138a6                  232 bytes
//   0001398e  FUN_0001398e                  138 bytes
//   00013a18  FUN_00013a18                  426 bytes
//   00013bc2  FUN_00013bc2                  332 bytes
//   00013d0e  FUN_00013d0e                  262 bytes
//   00013e14  FUN_00013e14                  154 bytes
//   00013eae  FUN_00013eae                  124 bytes
//   00013f2a  FUN_00013f2a                  34 bytes
//   00013f4c  FUN_00013f4c                  10 bytes
//   00013f56  FUN_00013f56                  48 bytes
//   00013f86  FUN_00013f86                  434 bytes
//   00014138  FUN_00014138                  164 bytes
//   000141dc  FUN_000141dc                  14 bytes
//   000141ea  FUN_000141ea                  10 bytes
//   000141f4  FUN_000141f4                  6 bytes
//   000141fa  FUN_000141fa                  76 bytes
//   00014246  FUN_00014246                  6 bytes
//   0001424c  FUN_0001424c                  128 bytes
//   000142cc  FUN_000142cc                  278 bytes
//   000143e2  FUN_000143e2                  74 bytes
//   0001442c  FUN_0001442c                  18 bytes
//   0001443e  FUN_0001443e                  88 bytes
//   00014496  FUN_00014496                  242 bytes
//   00014588  FUN_00014588                  122 bytes
//   00014602  FUN_00014602                  8 bytes
//   0001460a  FUN_0001460a                  198 bytes
//   000146d0  FUN_000146d0                  120 bytes
//   00014748  FUN_00014748                  66 bytes
//   0001478a  FUN_0001478a                  14 bytes
//   00014798  FUN_00014798                  42 bytes
//   000147c2  FUN_000147c2                  12 bytes
//   000147ce  FUN_000147ce                  100 bytes
//   00014832  FUN_00014832                  84 bytes
//   00014886  hit_test_objects              160 bytes
//   00014926  FUN_00014926                  64 bytes
//   00014966  FUN_00014966                  116 bytes
//   000149da  FUN_000149da                  190 bytes
//   00014a98  FUN_00014a98                  46 bytes
//   00014ac6  FUN_00014ac6                  278 bytes
//   00014bdc  FUN_00014bdc                  30 bytes
//   00014bfa  FUN_00014bfa                  380 bytes
//   00014d76  FUN_00014d76                  26 bytes
//   00014d90  FUN_00014d90                  34 bytes
//   00014db2  FUN_00014db2                  180 bytes
//   00014e66  FUN_00014e66                  130 bytes
//   00014ee8  FUN_00014ee8                  60 bytes
//   00014f24  FUN_00014f24                  58 bytes
//   00014f5e  FUN_00014f5e                  22 bytes
//   00014f74  FUN_00014f74                  222 bytes
//   00015052  FUN_00015052                  92 bytes
//   000150ae  FUN_000150ae                  228 bytes
//   00015192  FUN_00015192                  30 bytes
//   000151b0  FUN_000151b0                  318 bytes
//   000152ee  FUN_000152ee                  148 bytes
//   00015382  FUN_00015382                  166 bytes
//   00015428  FUN_00015428                  106 bytes
//   00015492  FUN_00015492                  126 bytes
//   00015510  FUN_00015510                  32 bytes
//   00015530  FUN_00015530                  88 bytes
//   00015588  FUN_00015588                  12 bytes
//   00015594  FUN_00015594                  36 bytes
//   000155b8  FUN_000155b8                  12 bytes
//   000155c4  FUN_000155c4                  24 bytes
//   000155dc  FUN_000155dc                  142 bytes
//   0001566a  FUN_0001566a                  542 bytes
//   00015888  FUN_00015888                  172 bytes
//   00015934  FUN_00015934                  16 bytes
//   00015944  FUN_00015944                  120 bytes
//   000159bc  FUN_000159bc                  22 bytes
//   000159d2  FUN_000159d2                  16 bytes
//   000159e2  FUN_000159e2                  174 bytes
//   00015ac8  FUN_00015ac8                  156 bytes
//   00015da6  FUN_00015da6                  454 bytes
//   00015f6c  FUN_00015f6c                  104 bytes
//   00015fd4  FUN_00015fd4                  154 bytes
//   0001606e  FUN_0001606e                  26 bytes
//   00016088  FUN_00016088                  34 bytes
//   000160aa  FUN_000160aa                  22 bytes
//   000160c0  FUN_000160c0                  2 bytes
//   00016210  FUN_00016210                  32 bytes
//   00016230  FUN_00016230                  32 bytes
//   00016250  FUN_00016250                  42 bytes
//   0001627a  FUN_0001627a                  84 bytes
//   000162ce  FUN_000162ce                  10 bytes
//   000162d8  FUN_000162d8                  2 bytes
//   000162da  FUN_000162da                  8 bytes
//   000162e2  FUN_000162e2                  30 bytes
//   00016300  xbios_setpalette              16 bytes
//   00016310  FUN_00016310                  336 bytes
//   00016460  FUN_00016460                  68 bytes
//   000164a4  FUN_000164a4                  48 bytes
//   000164d4  FUN_000164d4                  34 bytes
//   000164f6  FUN_000164f6                  28 bytes
//   00016512  FUN_00016512                  2 bytes
//   00016514  FUN_00016514                  26 bytes
//   0001652e  FUN_0001652e                  38 bytes
//   00016554  FUN_00016554                  2 bytes
//   00016556  draw_hint_icons               32 bytes
//   00016576  FUN_00016576                  12 bytes
//   00016582  update_icon_list              172 bytes
//   00016636  FUN_00016636                  164 bytes
//   000166da  FUN_000166da                  18 bytes
//   000166ec  FUN_000166ec                  190 bytes
//   000167aa  FUN_000167aa                  20 bytes
//   000167be  FUN_000167be                  78 bytes
//   0001680c  FUN_0001680c                  30 bytes
//   0001682a  reset_clear                   84 bytes
//   0001687e  FUN_0001687e                  34 bytes
//   000168a0  FUN_000168a0                  52 bytes
//   000168d4  FUN_000168d4                  46 bytes
//   00016902  FUN_00016902                  88 bytes
//   0001695a  FUN_0001695a                  66 bytes
//   0001699c  FUN_0001699c                  8 bytes
//   000169a4  FUN_000169a4                  8 bytes
//   000169ac  FUN_000169ac                  8 bytes
//   000169b4  FUN_000169b4                  108 bytes
//   00016a20  FUN_00016a20                  150 bytes
//   00016ab6  FUN_00016ab6                  8 bytes
//   00016abe  FUN_00016abe                  112 bytes
//   00016b2e  FUN_00016b2e                  72 bytes
//   00016b76  FUN_00016b76                  38 bytes
//   00016b9c  FUN_00016b9c                  100 bytes
//   00016c00  FUN_00016c00                  72 bytes
//   00016c48  FUN_00016c48                  36 bytes
//   00016c6c  FUN_00016c6c                  58 bytes
//   00016ca6  FUN_00016ca6                  60 bytes
//   00016ce2  FUN_00016ce2                  60 bytes
//   00016d1e  FUN_00016d1e                  30 bytes
//   00016d3c  FUN_00016d3c                  60 bytes
//   00016d78  FUN_00016d78                  66 bytes
//   00016dba  FUN_00016dba                  2 bytes
//   00016dbc  FUN_00016dbc                  48 bytes
//   00016dec  FUN_00016dec                  236 bytes
//   00016ed8  FUN_00016ed8                  184 bytes
//   00016f90  FUN_00016f90                  36 bytes
//   00016fb4  FUN_00016fb4                  224 bytes
//   00017094  FUN_00017094                  288 bytes
//   000171b4  FUN_000171b4                  70 bytes
//   000171fa  FUN_000171fa                  192 bytes
//   000172ba  FUN_000172ba                  16 bytes
//   000172ca  FUN_000172ca                  228 bytes
//   000173ae  FUN_000173ae                  68 bytes
//   000173f2  FUN_000173f2                  128 bytes
//   00017472  FUN_00017472                  14 bytes
//   00017480  FUN_00017480                  374 bytes
//   000175f6  FUN_000175f6                  130 bytes
//   00017678  FUN_00017678                  72 bytes
//   000176c0  FUN_000176c0                  206 bytes
//   0001778e  FUN_0001778e                  4 bytes
//   00017792  FUN_00017792                  42 bytes
//   000177bc  FUN_000177bc                  40 bytes
//   000177e4  FUN_000177e4                  40 bytes
//   0001780c  FUN_0001780c                  74 bytes
//   00017856  FUN_00017856                  118 bytes
//   000178cc  FUN_000178cc                  100 bytes
//   00017930  FUN_00017930                  114 bytes
//   000179a2  FUN_000179a2                  120 bytes
//   00017a1a  FUN_00017a1a                  552 bytes
//   00017c42  FUN_00017c42                  98 bytes
//   00017ca4  FUN_00017ca4                  408 bytes
//   00017e3c  script_step                   748 bytes
//   00018128  FUN_00018128                  70 bytes
//   0001816e  FUN_0001816e                  12 bytes
//   0001817a  FUN_0001817a                  24 bytes
//   00018192  FUN_00018192                  94 bytes
//   000181f0  FUN_000181f0                  256 bytes
//   000182f0  FUN_000182f0                  38 bytes
//   00018316  FUN_00018316                  30 bytes
//   00018334  FUN_00018334                  14 bytes
//   0001834a  FUN_0001834a                  226 bytes
//   0001842c  FUN_0001842c                  160 bytes
//   000184cc  FUN_000184cc                  10 bytes
//   000184d6  FUN_000184d6                  68 bytes
//   0001851a  FUN_0001851a                  30 bytes
//   00018538  FUN_00018538                  66 bytes
//   0001857a  FUN_0001857a                  2 bytes
//   0001857c  FUN_0001857c                  106 bytes
//   000185e6  FUN_000185e6                  208 bytes
//   000186b6  FUN_000186b6                  56 bytes
//   000186ee  FUN_000186ee                  28 bytes
//   0001870a  FUN_0001870a                  54 bytes
//   00018740  FUN_00018740                  222 bytes
//   0001881e  FUN_0001881e                  106 bytes
//   00018888  FUN_00018888                  8 bytes
//   00018890  FUN_00018890                  62 bytes
//   000188ce  FUN_000188ce                  118 bytes
//   00018944  FUN_00018944                  102 bytes
//   000189aa  FUN_000189aa                  102 bytes
//   00018a10  FUN_00018a10                  32 bytes
//   00018a30  FUN_00018a30                  104 bytes
//   00018a98  FUN_00018a98                  502 bytes
//   00018c8e  FUN_00018c8e                  36 bytes
//   00018cb2  FUN_00018cb2                  46 bytes
//   00018ce0  FUN_00018ce0                  28 bytes
//   00018cfc  FUN_00018cfc                  42 bytes
//   00018d26  FUN_00018d26                  2 bytes
//   00018d28  FUN_00018d28                  152 bytes
//   00018dc0  FUN_00018dc0                  70 bytes
//   00018e06  FUN_00018e06                  12 bytes
//   00018e12  FUN_00018e12                  250 bytes
//   00018f0c  FUN_00018f0c                  98 bytes
//   00018f6e  FUN_00018f6e                  12 bytes
//   00018f7a  FUN_00018f7a                  10 bytes
//   00018f84  FUN_00018f84                  10 bytes
//   00018f8e  FUN_00018f8e                  10 bytes
//   00018f98  FUN_00018f98                  10 bytes
//   00018fa2  FUN_00018fa2                  2 bytes
//   00018fa4  xbios_supexec                 32 bytes
//   00018fc4  sound_timer_start             152 bytes
//   0001906a  FUN_0001906a                  26 bytes
//   00019084  sound_timer_stop              26 bytes
//   0001909e  FUN_0001909e                  26 bytes
//   00019282  FUN_00019282                  24 bytes
//   0001929a  ym_write                      36 bytes
//   00019312  FUN_00019312                  2 bytes
//   00019316  FUN_00019316                  68 bytes
//   0001935a  FUN_0001935a                  138 bytes
//   000193e4  FUN_000193e4                  84 bytes
//   00019438  FUN_00019438                  42 bytes
//   00019462  FUN_00019462                  18 bytes
//   00019474  FUN_00019474                  10 bytes
//   0003a556  init_hardware                 38 bytes
//   0003a57c  FUN_0003a57c                  32 bytes
//   0003a5c2  FUN_0003a5c2                  66 bytes
//   0003a604  mfp_setup                     42 bytes
//   0003a62e  FUN_0003a62e                  198 bytes
//   0003a6f4  xbios_supexec                 30 bytes
//   0003a712  FUN_0003a712                  34 bytes
//   0003a734  FUN_0003a734                  298 bytes
//   0003a85e  FUN_0003a85e                  20 bytes
//   0003a992  FUN_0003a992                  166 bytes
//   0003aa38  FUN_0003aa38                  68 bytes
//   0003aa7c  FUN_0003aa7c                  14 bytes
//   0003aa8a  FUN_0003aa8a                  44 bytes
//   0003aab6  FUN_0003aab6                  676 bytes
//   0003ad5a  FUN_0003ad5a                  16 bytes
//   0003ad6a  FUN_0003ad6a                  74 bytes
//   0003adb4  FUN_0003adb4                  76 bytes
//   0003ae00  FUN_0003ae00                  104 bytes
//   0003ae68  FUN_0003ae68                  20 bytes

// ---------------------------------------------------------------
// _start @ 00010000

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _start(int param_1)

{
  int iVar1;
  short sVar3;
  byte bVar4;
  undefined4 uVar2;
  int iVar5;
  int unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  int *piVar6;
  undefined4 extraout_A0;
  undefined4 extraout_A1;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A6;
  bool bVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  
  DAT_0001d1f6 = param_1;
  DAT_0001d1f2 = CONCAT22(0x4a,(short)*(undefined4 *)(param_1 + 0x1c) +
                               (short)*(undefined4 *)(param_1 + 0x14) +
                               (short)*(undefined4 *)(param_1 + 0xc) + 0x100);
  __m68k_trap(1);
  DAT_0001d1fa = (int *)0x1003a;
  crt0_init();
  DAT_0001d1fa = (int *)0x10040;
  init_hardware();
  cur_filename = "PRES.PI1";
  bVar7 = false;
  DAT_0001d1fa = (int *)0x1004e;
  load_named_screen();
  if (!bVar7) {
    DAT_0001d1fa = (int *)0x10056;
    FUN_000135ba();
    DAT_0001d1fa = (int *)0x1005a;
    copy_screen();
    DAT_0001d1fa = (int *)0x10060;
    FUN_00019316();
    do {
    } while (_DAT_0001947e != 0);
    cur_filename = "DRAP.PI1";
    bVar7 = false;
    DAT_0001d1fa = (int *)0x10078;
    load_named_screen();
    if (!bVar7) {
      DAT_0001d1fa = (int *)0x10080;
      prompt_wait();
      DAT_0001d1fa = (int *)0x10084;
      set_palette();
      DAT_0001d1fa = (int *)0x10088;
      sVar3 = swap_screens();
      while (__m68k_trap(1), sVar3 != 0) {
        DAT_0001d1fa = (int *)0x1009a;
        sVar3 = FUN_00012324();
      }
      do {
        DAT_0001d1fa = (int *)0x100a2;
        bVar4 = FUN_00012324();
        if (0x46 < bVar4) {
          bVar4 = bVar4 - 0x20;
        }
      } while ((bVar4 < 0x44) || (0x46 < bVar4));
      uVar8 = (char)bVar4 < '\0';
      DAT_0001d1fa = (int *)0x100d8;
      s_8__DIALI_BIN_0001a3a7[7] = bVar4;
      s_4DESCI_BIN_0001a3b7[5] = bVar4;
      s_VERBI_BIN_0001a3c6[4] = bVar4;
      s_MOTSI_BIN_0001a3d4[4] = bVar4;
      copy_screen();
      DAT_0001d1fa = (int *)0x100dc;
      FUN_000106e2();
      if (!(bool)uVar8) {
        do {
          do {
            the_command = 0x918e;
            uVar8 = 1;
            DAT_0001d1fa = (int *)0x100ec;
            run_command_keep_sp();
            DAT_0001d1fa = (int *)0x100f0;
            load_fond();
          } while ((bool)uVar8);
          DAT_0001d1fa = (int *)0x100f8;
          uVar2 = FUN_000106ea();
        } while ((bool)uVar8);
        if (0x78000 < screen_ptr_a) {
          unaff_D2 = CONCAT22((short)((uint)unaff_D2 >> 0x10),7);
          piVar6 = &DAT_0001a4e8;
          iVar5 = 0x64c8e;
          do {
            DAT_0001d1ea = 0x10128;
            DAT_0001d1ee = uVar2;
            DAT_0001d1f2 = iVar5;
            DAT_0001d1f6 = unaff_D2;
            DAT_0001d1fa = piVar6;
            FUN_00010682();
            iVar1 = DAT_0001d1f6;
            iVar5 = DAT_0001d1f2;
            uVar2 = DAT_0001d1ee;
            piVar6 = DAT_0001d1fa + 1;
            *DAT_0001d1fa = DAT_0001d1f2;
            iVar5 = load_length + iVar5;
            sVar3 = (short)iVar1 + -1;
            unaff_D2 = CONCAT22((short)((uint)iVar1 >> 0x10),sVar3);
          } while (sVar3 != -1);
          DAT_0001a57c = 0xff;
        }
        DAT_0001d1fa = (int *)0x10144;
        set_palette();
        DAT_0001d1fa = (int *)0x10148;
        copy_screen();
        DAT_0001d1fa = (int *)0x1014c;
        save_clear_bin();
        DAT_0001d1fa = (int *)0x10152;
        xbios_supexec();
        DAT_0001d1fa = (int *)0x10158;
        FUN_00018f84();
        do {
          DAT_0001d1fa = (int *)0x1015c;
          wait_frame();
        } while ((input_buttons & 4) != 0);
        DAT_0001acc6 = 7;
        DAT_0001ad0d = 0;
        the_command = 0xc001;
        DAT_0001d1fa = (int *)0x10182;
        run_command_keep_sp();
        DAT_0001d1fa = (int *)0x10186;
        draw_hint_icons();
        DAT_0001d1fa = (int *)0x1018a;
        FUN_00010522();
        DAT_0001d1fa = (int *)0x1018e;
        game_loop();
      }
    }
  }
  DAT_0001d1fa = (int *)0x10192;
  uVar9 = FUN_000135e0();
  DAT_0001d1be = (undefined4)((ulonglong)uVar9 >> 0x20);
  DAT_0001d1c2 = (undefined4)uVar9;
  DAT_0001d1fa = (int *)0x0;
  __m68k_trap(1);
  DAT_0001d1f2 = param_1;
  DAT_0001d1ba = 0x101a2;
  DAT_0001d1c6 = unaff_D2;
  DAT_0001d1ca = unaff_D3;
  DAT_0001d1ce = unaff_D4;
  DAT_0001d1d2 = unaff_D5;
  DAT_0001d1d6 = unaff_D6;
  DAT_0001d1da = unaff_D7;
  DAT_0001d1de = extraout_A0;
  DAT_0001d1e2 = extraout_A1;
  DAT_0001d1e6 = unaff_A2;
  DAT_0001d1ea = unaff_A3;
  DAT_0001d1ee = unaff_A4;
  DAT_0001d1f6 = unaff_A6;
  FUN_00012324();
  return CONCAT44(DAT_0001d1be,DAT_0001d1c2);
}


// ---------------------------------------------------------------
// game_loop @ 000101be

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void game_loop(void)

{
  bool bVar1;
  
  do {
    FUN_000166da();
    FUN_00018dc0();
    script_step();
    FUN_00018740();
    FUN_0001627a();
    wait_frame();
    the_command = 0;
    bVar1 = false;
    FUN_0001478a();
    if (bVar1) {
      FUN_00014a98();
      DAT_0001ab46 = 'd';
      FUN_00014832();
    }
    else {
      FUN_00014a98();
      DAT_0001ab45 = 'u';
      FUN_000147ce();
    }
    if (DAT_0001ab45 != DAT_0001ab44) {
      FUN_000109fe();
    }
    if (DAT_0001ab46 != DAT_0001ab47) {
      FUN_00010a88();
    }
    handle_frame_input();
    if (((input_buttons & 4) == 0) || (the_command == 0)) {
      if (((DAT_0001acf2 < DAT_0001ace7) && (the_command = DAT_0001abf8, DAT_0001abf8 != 0)) ||
         ((DAT_0001ad0b == '\0' &&
          (((the_command = DAT_0001ac06, DAT_0001ac06 != 0 ||
            ((DAT_0001acac < DAT_0001ab60 && (the_command = DAT_0001acaa, DAT_0001acaa != 0)))) ||
           ((DAT_0001acb0 < DAT_0001ab60 && (the_command = DAT_0001acae, DAT_0001acae != 0)))))))) {
        FUN_0001060a();
        FUN_00016514();
        run_command_keep_sp();
        goto LAB_00010304;
      }
    }
    else {
      FUN_0001060a();
      FUN_00016514();
      run_command();
      DAT_0001ace7 = DAT_0001ace7 + 1;
      if ((DAT_0001acd3 != '\0') && (DAT_0001ace8 = DAT_0001ace8 + -1, DAT_0001ace8 == '\0')) {
        FUN_00015192();
      }
LAB_00010304:
      draw_hint_icons();
      FUN_00010522();
      FUN_000166ec();
    }
    if (_DAT_0001a4d2 != 0) {
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------
// handle_frame_input @ 0001031c

void handle_frame_input(void)

{
  do {
    FUN_00013594();
    if ((DAT_0001ab4f == '\0') || (cursor_y < 0x96)) break;
  } while ((DAT_0001acd4 & 1) != 0);
  FUN_0001060a();
  if (DAT_0001ab45 != DAT_0001ab44) {
    FUN_00010a54();
    DAT_0001ab44 = DAT_0001ab45;
  }
  if (DAT_0001ab46 != DAT_0001ab47) {
    FUN_00010acc();
    DAT_0001ab47 = DAT_0001ab46;
  }
  FUN_00010526();
  return;
}


// ---------------------------------------------------------------
// FUN_00010390 @ 00010390

void FUN_00010390(void)

{
  int unaff_A6;
  
  the_command = CONCAT11(*(undefined1 *)(unaff_A6 + 2),*(undefined1 *)(unaff_A6 + 1)) | 0xf000;
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// run_command @ 000103a8

void run_command(void)

{
  ushort uVar1;
  short unaff_D5w;
  short unaff_D6w;
  
  DAT_0001a826 = &stack0x00000000;
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  DAT_0001a826 = (undefined1 *)register0x0000003c;
  if (uVar1 != 0) {
    if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
      if (uVar1 != 0x9000) {
        FUN_00012950();
        templ_ptr = &TEMPL_data;
        FUN_00010630();
        return;
      }
      FUN_00010fc4();
      FUN_00010998();
      DAT_0001a512 = unaff_D6w + 2;
      if (4 < (byte)unaff_D5w) {
        DAT_0001a512 = 0x14;
      }
      FUN_000109bc();
      DAT_0001a514 = unaff_D5w * 6 + 7;
      DAT_0001a532 = cursor_x >> 2;
      if (DAT_0001a532 < 9) {
        DAT_0001a532 = 9;
      }
      if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
        DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
      }
      DAT_0001a530 = cursor_y;
      if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
        DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
      }
      FUN_00010fec();
      FUN_0001258a();
      FUN_00010e66();
      prompt_wait();
      FUN_000124f2();
      return;
    }
    (**(code **)(&cmd_jump_table +
                (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),
                                  (char)(the_command & 0x3ff) + -1) << 2)))();
    return;
  }
  FUN_00010630();
  return;
}


// ---------------------------------------------------------------
// run_command_keep_sp @ 000103ae

void run_command_keep_sp(void)

{
  ushort uVar1;
  short unaff_D5w;
  short unaff_D6w;
  
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  if (uVar1 != 0) {
    if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
      if (uVar1 != 0x9000) {
        if (uVar1 == 0xf000) {
          register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
        }
        *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
        FUN_00012950();
        templ_ptr = &TEMPL_data;
        FUN_00010630();
        return;
      }
      FUN_00010fc4();
      FUN_00010998();
      DAT_0001a512 = unaff_D6w + 2;
      if (4 < (byte)unaff_D5w) {
        DAT_0001a512 = 0x14;
      }
      FUN_000109bc();
      DAT_0001a514 = unaff_D5w * 6 + 7;
      DAT_0001a532 = cursor_x >> 2;
      if (DAT_0001a532 < 9) {
        DAT_0001a532 = 9;
      }
      if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
        DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
      }
      DAT_0001a530 = cursor_y;
      if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
        DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
      }
      FUN_00010fec();
      FUN_0001258a();
      FUN_00010e66();
      prompt_wait();
      FUN_000124f2();
      return;
    }
    (**(code **)(&cmd_jump_table +
                (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),
                                  (char)(the_command & 0x3ff) + -1) << 2)))();
    return;
  }
  FUN_00010630();
  return;
}


// ---------------------------------------------------------------
// draw_text_box @ 0001042c

void draw_text_box(void)

{
  short unaff_D5w;
  short unaff_D6w;
  
  FUN_00010fb4();
  FUN_00010998();
  DAT_0001a512 = unaff_D6w + 2;
  if (4 < (byte)unaff_D5w) {
    DAT_0001a512 = 0x14;
  }
  FUN_000109bc();
  DAT_0001a514 = unaff_D5w * 6 + 7;
  DAT_0001a532 = cursor_x >> 2;
  if (DAT_0001a532 < 9) {
    DAT_0001a532 = 9;
  }
  if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
    DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
  }
  DAT_0001a530 = cursor_y;
  if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
    DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
  }
  FUN_00010fec();
  FUN_0001258a();
  FUN_00010e66();
  prompt_wait();
  FUN_000124f2();
  return;
}


// ---------------------------------------------------------------
// draw_text_box_variant @ 00010440

void draw_text_box_variant(void)

{
  short unaff_D5w;
  short unaff_D6w;
  
  FUN_00010fc4();
  FUN_00010998();
  DAT_0001a512 = unaff_D6w + 2;
  if (4 < (byte)unaff_D5w) {
    DAT_0001a512 = 0x14;
  }
  FUN_000109bc();
  DAT_0001a514 = unaff_D5w * 6 + 7;
  DAT_0001a532 = cursor_x >> 2;
  if (DAT_0001a532 < 9) {
    DAT_0001a532 = 9;
  }
  if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
    DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
  }
  DAT_0001a530 = cursor_y;
  if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
    DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
  }
  FUN_00010fec();
  FUN_0001258a();
  FUN_00010e66();
  prompt_wait();
  FUN_000124f2();
  return;
}


// ---------------------------------------------------------------
// FUN_000104f4 @ 000104f4

void FUN_000104f4(void)

{
  int unaff_A6;
  
  the_command = CONCAT11(*(undefined1 *)(unaff_A6 + 2),*(undefined1 *)(unaff_A6 + 1));
  FUN_00012950();
  templ_ptr = &TEMPL_data;
  return;
}


// ---------------------------------------------------------------
// FUN_00010522 @ 00010522

void FUN_00010522(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  short sVar5;
  uint unaff_D7;
  int extraout_A0;
  ushort *puVar6;
  undefined2 *extraout_A1;
  undefined2 *puVar7;
  ushort *puVar9;
  ushort *puVar8;
  
  wait_frame();
  puVar9 = (ushort *)&DAT_000199d6;
  FUN_00010fee();
  puVar6 = (ushort *)(extraout_A0 + 8);
  sVar5 = 0xf;
  puVar7 = extraout_A1;
  DAT_00019ace = extraout_A0;
  do {
    puVar8 = puVar7 + 1;
    uVar1 = CONCAT22(*puVar7,0xffff) << 0x20 - (unaff_D7 & 0x3f) |
            CONCAT22(*puVar7,0xffff) >> (unaff_D7 & 0x3f);
    puVar7 = puVar7 + 2;
    uVar3 = ((uint)*puVar8 << 0x10) << 0x20 - (unaff_D7 & 0x3f) |
            ((uint)*puVar8 << 0x10) >> (unaff_D7 & 0x3f);
    *puVar9 = *puVar6;
    uVar2 = (ushort)uVar1;
    *puVar6 = uVar2 & *puVar6;
    uVar4 = (ushort)uVar3;
    *puVar6 = uVar4 | *puVar6;
    puVar9[1] = puVar6[1];
    puVar6[1] = uVar2 & puVar6[1];
    puVar6[1] = uVar4 | puVar6[1];
    puVar9[2] = puVar6[2];
    puVar6[2] = uVar2 & puVar6[2];
    puVar6[2] = uVar4 | puVar6[2];
    puVar9[3] = puVar6[3];
    puVar6[3] = uVar2 & puVar6[3];
    if (DAT_0001a48a != '\0') {
      puVar6[3] = uVar4 | puVar6[3];
    }
    puVar9[-4] = puVar6[-4];
    uVar2 = (ushort)(uVar1 >> 0x10);
    puVar6[-4] = uVar2 & puVar6[-4];
    uVar4 = (ushort)(uVar3 >> 0x10);
    puVar6[-4] = uVar4 | puVar6[-4];
    puVar9[-3] = puVar6[-3];
    puVar6[-3] = uVar2 & puVar6[-3];
    puVar6[-3] = uVar4 | puVar6[-3];
    puVar9[-2] = puVar6[-2];
    puVar6[-2] = uVar2 & puVar6[-2];
    puVar6[-2] = uVar4 | puVar6[-2];
    puVar9[-1] = puVar6[-1];
    puVar6[-1] = uVar2 & puVar6[-1];
    if (DAT_0001a48a != '\0') {
      puVar6[-1] = uVar4 | puVar6[-1];
    }
    puVar6 = puVar6 + 0x50;
    puVar9 = puVar9 + 8;
    sVar5 = sVar5 + -1;
  } while (sVar5 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00010526 @ 00010526

void FUN_00010526(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  short sVar5;
  uint unaff_D7;
  int extraout_A0;
  ushort *puVar6;
  undefined2 *extraout_A1;
  undefined2 *puVar7;
  ushort *puVar9;
  ushort *puVar8;
  
  puVar9 = (ushort *)&DAT_000199d6;
  FUN_00010fee();
  puVar6 = (ushort *)(extraout_A0 + 8);
  sVar5 = 0xf;
  puVar7 = extraout_A1;
  DAT_00019ace = extraout_A0;
  do {
    puVar8 = puVar7 + 1;
    uVar1 = CONCAT22(*puVar7,0xffff) << 0x20 - (unaff_D7 & 0x3f) |
            CONCAT22(*puVar7,0xffff) >> (unaff_D7 & 0x3f);
    puVar7 = puVar7 + 2;
    uVar3 = ((uint)*puVar8 << 0x10) << 0x20 - (unaff_D7 & 0x3f) |
            ((uint)*puVar8 << 0x10) >> (unaff_D7 & 0x3f);
    *puVar9 = *puVar6;
    uVar2 = (ushort)uVar1;
    *puVar6 = uVar2 & *puVar6;
    uVar4 = (ushort)uVar3;
    *puVar6 = uVar4 | *puVar6;
    puVar9[1] = puVar6[1];
    puVar6[1] = uVar2 & puVar6[1];
    puVar6[1] = uVar4 | puVar6[1];
    puVar9[2] = puVar6[2];
    puVar6[2] = uVar2 & puVar6[2];
    puVar6[2] = uVar4 | puVar6[2];
    puVar9[3] = puVar6[3];
    puVar6[3] = uVar2 & puVar6[3];
    if (DAT_0001a48a != '\0') {
      puVar6[3] = uVar4 | puVar6[3];
    }
    puVar9[-4] = puVar6[-4];
    uVar2 = (ushort)(uVar1 >> 0x10);
    puVar6[-4] = uVar2 & puVar6[-4];
    uVar4 = (ushort)(uVar3 >> 0x10);
    puVar6[-4] = uVar4 | puVar6[-4];
    puVar9[-3] = puVar6[-3];
    puVar6[-3] = uVar2 & puVar6[-3];
    puVar6[-3] = uVar4 | puVar6[-3];
    puVar9[-2] = puVar6[-2];
    puVar6[-2] = uVar2 & puVar6[-2];
    puVar6[-2] = uVar4 | puVar6[-2];
    puVar9[-1] = puVar6[-1];
    puVar6[-1] = uVar2 & puVar6[-1];
    if (DAT_0001a48a != '\0') {
      puVar6[-1] = uVar4 | puVar6[-1];
    }
    puVar6 = puVar6 + 0x50;
    puVar9 = puVar9 + 8;
    sVar5 = sVar5 + -1;
  } while (sVar5 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001060a @ 0001060a

void FUN_0001060a(void)

{
  short sVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = &DAT_000199ce;
  sVar1 = 0xf;
  puVar3 = DAT_00019ace;
  do {
    sVar2 = 3;
    puVar6 = puVar5;
    do {
      puVar4 = puVar3;
      puVar5 = puVar6 + 1;
      *puVar4 = *puVar6;
      sVar2 = sVar2 + -1;
      puVar3 = puVar4 + 1;
      puVar6 = puVar5;
    } while (sVar2 != -1);
    puVar3 = puVar4 + 0x25;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00010630 @ 00010630

void FUN_00010630(void)

{
  byte *unaff_A6;
  
  while (((unaff_A6 != templ_ptr && (*unaff_A6 < 0x6b)) && (*unaff_A6 != 0))) {
    (**(code **)(&DAT_00019f62 + (uint)(byte)(*unaff_A6 - 1) * 4))();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00010668 @ 00010668

undefined8 FUN_00010668(void)

{
  undefined1 uVar1;
  undefined4 in_D0;
  undefined4 in_D1;
  int unaff_A6;
  
  uVar1 = *(undefined1 *)(unaff_A6 + 1);
  FUN_00010682();
  return CONCAT44(CONCAT31((int3)((uint)in_D0 >> 8),uVar1),in_D1);
}


// ---------------------------------------------------------------
// FUN_0001066e @ 0001066e

undefined8 FUN_0001066e(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  FUN_00010682();
  return CONCAT44(in_D0,in_D1);
}


// ---------------------------------------------------------------
// FUN_00010682 @ 00010682

void FUN_00010682(void)

{
  char cVar1;
  undefined4 uVar2;
  char in_D0b;
  undefined4 in_D1;
  undefined1 uVar3;
  
  uVar2 = templ_ptr;
  if ((DAT_0001a57c != -1) && (cVar1 = in_D0b + '0', cVar1 != DAT_0001a57c)) {
    uVar3 = cVar1 < '\0';
    s_0_BIN_0001a408[0] = cVar1;
    DAT_0001a40e = in_D1;
    DAT_0001a57c = cVar1;
    while (load_resource_list(), (bool)uVar3) {
      the_command = 0x918e;
      uVar3 = 1;
      run_command_keep_sp();
    }
  }
  templ_ptr = uVar2;
  return;
}


// ---------------------------------------------------------------
// FUN_000106e2 @ 000106e2

void FUN_000106e2(void)

{
  load_resource_list();
  return;
}


// ---------------------------------------------------------------
// FUN_000106ea @ 000106ea

void FUN_000106ea(void)

{
  load_resource_list();
  return;
}


// ---------------------------------------------------------------
// load_resource_list @ 000106f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 load_resource_list(void)

{
  short in_D0w;
  short *psVar1;
  char *unaff_A5;
  bool bVar2;
  
  __m68k_trap(1);
  while( true ) {
    if (*unaff_A5 == '$') {
      psVar1 = (short *)0x1567d;
      do {
        psVar1 = (short *)((int)psVar1 + -0x5623);
      } while (*psVar1 != 0x4eb9);
      return 0;
    }
    __m68k_trap(1);
    if (in_D0w != 0) break;
    load_buffer = *(undefined4 *)(unaff_A5 + 10);
    load_length = _DAT_00055af0;
    bVar2 = _DAT_00055af0 < 0;
    cur_filename = unaff_A5;
    in_D0w = load_resource();
    if (bVar2) {
      return 0xffff;
    }
    unaff_A5 = unaff_A5 + 0xe;
  }
  cur_filename = unaff_A5;
  return 0xffff;
}


// ---------------------------------------------------------------
// load_resource @ 0001076a

void load_resource(void)

{
  short sVar1;
  
  sVar1 = gemdos_fopen();
  if (-1 < sVar1) {
    gemdos_fread();
    gemdos_fclose();
  }
  return;
}


// ---------------------------------------------------------------
// save_clear_bin @ 0001077e

void save_clear_bin(void)

{
  load_buffer = &PTR_DAT_0001a752;
  load_length = 0x291c;
  cur_filename = "A:CLEAR.BIN";
  write_named_file();
  return;
}


// ---------------------------------------------------------------
// write_named_file @ 000107a2

void write_named_file(void)

{
  short sVar1;
  
  sVar1 = gemdos_fcreate();
  if (-1 < sVar1) {
    gemdos_fwrite();
    gemdos_fclose();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// gemdos_fopen @ 000107b6

void gemdos_fopen(void)

{
  undefined2 in_D0w;
  
  __m68k_trap(1);
  DAT_0001a47e = in_D0w;
  return;
}


// ---------------------------------------------------------------
// gemdos_fcreate @ 000107d0

void gemdos_fcreate(void)

{
  undefined2 in_D0w;
  
  __m68k_trap(1);
  DAT_0001a47e = in_D0w;
  return;
}


// ---------------------------------------------------------------
// gemdos_fread @ 000107e8

void gemdos_fread(void)

{
  __m68k_trap(1);
  return;
}


// ---------------------------------------------------------------
// gemdos_fwrite @ 00010808

void gemdos_fwrite(void)

{
  __m68k_trap(1);
  return;
}


// ---------------------------------------------------------------
// gemdos_fclose @ 00010828

void gemdos_fclose(void)

{
  __m68k_trap(1);
  return;
}


// ---------------------------------------------------------------
// print_char @ 00010838

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void print_char(void)

{
  undefined *puVar1;
  byte in_D0b;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  uint unaff_D7;
  int extraout_A0;
  ushort *puVar6;
  ushort *puVar7;
  byte *pbVar8;
  
  DAT_0001a50a = DAT_0001a50a + 1;
  FUN_00010fec();
  puVar1 = PTR_DAT_0001a4d8;
  puVar6 = (ushort *)(extraout_A0 - _DAT_0001a46a);
  uVar2 = 0xfff << 0x10 - (unaff_D7 & 0x3f) | 0xfffU >> (unaff_D7 & 0x3f);
  sVar5 = 5;
  pbVar8 = &font_data + (uint)in_D0b * 6;
  do {
    uVar3 = *(ushort *)(puVar1 + *pbVar8) << 0x10 - (unaff_D7 & 0x3f) |
            *(ushort *)(puVar1 + *pbVar8) >> (unaff_D7 & 0x3f);
    sVar4 = 3;
    do {
      puVar7 = puVar6;
      *puVar7 = uVar2 & *puVar7;
      *puVar7 = ~uVar2 & uVar3 | *puVar7;
      uVar3 = uVar3 << 4 | uVar3 >> 0xc;
      sVar4 = sVar4 + -1;
      puVar6 = puVar7 + 1;
    } while (sVar4 != -1);
    puVar6 = puVar7 + 0x4d;
    sVar5 = sVar5 + -1;
    pbVar8 = pbVar8 + 1;
  } while (sVar5 != -1);
  return;
}


// ---------------------------------------------------------------
// print_word @ 000108a2

undefined4 print_word(void)

{
  byte bVar1;
  byte *unaff_A5;
  byte *pbVar2;
  
  pbVar2 = unaff_A5;
  if ((*unaff_A5 & 0x3f) == 0) goto LAB_000108c4;
  while( true ) {
    if (unaff_A5 == cur_str_end) {
      DAT_0001a508 = 0xff;
      return 1;
    }
    if ((*unaff_A5 & 0x3f) == 0) break;
    print_char();
    pbVar2 = unaff_A5;
LAB_000108c4:
    unaff_A5 = pbVar2 + 1;
    bVar1 = *pbVar2 & 0xc0;
    if (bVar1 != 0) {
      if ((bVar1 != 0x80) && (bVar1 == 0x40)) {
        return 0;
      }
      print_char();
    }
  }
  return 0;
}


// ---------------------------------------------------------------
// FUN_0001090e @ 0001090e

undefined8 FUN_0001090e(void)

{
  short sVar1;
  short in_D0w;
  ushort uVar2;
  short in_D1w;
  ushort uVar3;
  bool bVar4;
  
  uVar3 = DAT_0001a512;
  while( true ) {
    uVar2 = FUN_00010946();
    if (uVar3 < uVar2) break;
    sVar1 = uVar3 - uVar2;
    bVar4 = sVar1 == 0;
    print_word();
    if ((!bVar4) || (sVar1 == 0)) break;
    uVar3 = sVar1 - 1;
    print_char();
  }
  return CONCAT44((int)in_D0w,(int)in_D1w);
}


// ---------------------------------------------------------------
// FUN_00010946 @ 00010946

short FUN_00010946(void)

{
  short sVar1;
  short sVar2;
  byte *unaff_A5;
  
  sVar2 = 0;
  if ((*unaff_A5 & 0x3f) == 0) {
    sVar2 = 1;
    unaff_A5 = unaff_A5 + 1;
    if (unaff_A5 == cur_str_end) {
      return 1;
    }
  }
  do {
    if ((*unaff_A5 & 0x3f) == 0) {
      return sVar2;
    }
    sVar1 = sVar2 + 1;
    if ((*unaff_A5 & 0xc0) != 0) {
      if ((*unaff_A5 & 0xc0) == 0x40) {
        return sVar2 + 1;
      }
      sVar1 = sVar2 + 2;
    }
    sVar2 = sVar1;
    unaff_A5 = unaff_A5 + 1;
  } while (unaff_A5 != cur_str_end);
  return sVar2;
}


// ---------------------------------------------------------------
// FUN_00010998 @ 00010998

void FUN_00010998(void)

{
  ushort uVar1;
  ushort uVar2;
  int unaff_A4;
  
  uVar2 = 0;
  do {
    uVar1 = FUN_00010946();
    if (uVar2 < uVar1) {
      uVar2 = uVar1;
    }
  } while (unaff_A4 != cur_str_end);
  return;
}


// ---------------------------------------------------------------
// FUN_000109bc @ 000109bc

void FUN_000109bc(void)

{
  ushort uVar1;
  ushort uVar2;
  int unaff_A5;
  
  uVar2 = DAT_0001a512;
  while (unaff_A5 != cur_str_end) {
    uVar1 = FUN_00010946();
    if ((uVar2 < uVar1) || ((ushort)(uVar2 - uVar1) == 0)) {
      uVar2 = (DAT_0001a512 - uVar1) - 1;
    }
    else {
      uVar2 = (uVar2 - uVar1) - 1;
    }
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000109fe @ 000109fe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000109fe(void)

{
  if (DAT_0001acc6 != -0x79) {
    DAT_0001a512._1_1_ = DAT_0001ab49;
    _DAT_0001a46a = 0x8000;
    DAT_0001a50a = DAT_0001aa6a;
    DAT_0001a50c = DAT_0001aa6c;
    PTR_DAT_0001a4d8 = &UNK_0001d3c2;
    FUN_00010fb4();
    FUN_00010aee();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00010a54 @ 00010a54

void FUN_00010a54(void)

{
  if (DAT_0001acc6 != -0x79) {
    FUN_00010fec();
    FUN_0001215e();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00010a88 @ 00010a88

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010a88(void)

{
  DAT_0001a512._1_1_ = 0x20;
  _DAT_0001a46a = 0x8000;
  DAT_0001a50a = 0x2f;
  DAT_0001a50c = 0xc1;
  PTR_DAT_0001a4d8 = &UNK_0001d3c2;
  FUN_00010fb4();
  FUN_00010aee();
  return;
}


// ---------------------------------------------------------------
// FUN_00010acc @ 00010acc

void FUN_00010acc(void)

{
  FUN_00010fec();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_00010aee @ 00010aee

void FUN_00010aee(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int unaff_A4;
  
  sVar3 = 0;
  do {
    sVar2 = FUN_00010946();
    sVar3 = sVar2 + sVar3;
  } while (unaff_A4 != cur_str_end);
  uVar4 = (ushort)(DAT_0001a512 - sVar3) >> 1;
  if (uVar4 != 0) {
    DAT_0001a512 = DAT_0001a512 - uVar4;
    FUN_00010b46();
  }
  FUN_00010998();
  uVar1 = uVar4 + 1;
  if (DAT_0001a512 <= uVar1) {
    DAT_0001a512 = uVar1;
  }
  FUN_0001090e();
  if (uVar1 != 0) {
    do {
      print_char();
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0xffff);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00010b24 @ 00010b24

void FUN_00010b24(void)

{
  ushort uVar1;
  short unaff_D6w;
  short sVar2;
  
  FUN_00010998();
  uVar1 = unaff_D6w + 2;
  if (DAT_0001a512 <= uVar1) {
    DAT_0001a512 = uVar1;
  }
  FUN_0001090e();
  if (uVar1 != 0) {
    sVar2 = unaff_D6w + 1;
    do {
      print_char();
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00010b46 @ 00010b46

void FUN_00010b46(void)

{
  short unaff_D6w;
  
  do {
    print_char();
    unaff_D6w = unaff_D6w + -1;
  } while (unaff_D6w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00010b52 @ 00010b52

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010b52(void)

{
  byte bVar1;
  undefined2 extraout_D0u;
  ushort uVar2;
  undefined2 extraout_D1u;
  short sVar3;
  undefined4 extraout_A0;
  int unaff_A6;
  short sVar4;
  
  FUN_00010fb4();
  DAT_0001a484 = DAT_0001a482;
  PTR_DAT_0001a4d8 = &UNK_0001d382;
  _DAT_0001a46a = 0;
  DAT_0001a512 = *(byte *)(unaff_A6 + 4) & 0x1f;
  DAT_0001a52e = (DAT_0001a512 + 2) * 4 + -2;
  DAT_0001a532 = (ushort)*(byte *)(unaff_A6 + 2);
  DAT_0001a530 = (ushort)*(byte *)(unaff_A6 + 3);
  FUN_00012ffa();
  sVar3 = 2;
  do {
    FUN_00012ffa();
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  FUN_00013216();
  FUN_00013216();
  FUN_00013216();
  FUN_00013216();
  DAT_0001a50c = DAT_0001a530 + 4;
  DAT_0001a508 = '\0';
  DAT_0001a50a = DAT_0001a532;
  do {
    sVar4 = DAT_0001a50c;
    uVar2 = DAT_0001a50a;
    print_char();
    FUN_00010b24();
    print_char();
    DAT_0001a50a = uVar2;
    sVar3 = DAT_0001a52e;
    DAT_0001a50c = sVar4 + 6;
  } while (DAT_0001a508 == '\0');
  FUN_00012ffa();
  FUN_00013216();
  FUN_00012ffa();
  FUN_00013216();
  FUN_00013216();
  FUN_00010fec();
  DAT_0001a49e = sVar3;
  DAT_0001a532 = DAT_0001a512 + 2;
  DAT_0001a530 = (DAT_0001a50c - DAT_0001a530) + 2;
  bVar1 = *(byte *)(unaff_A6 + 4) & 0xe0;
  uVar2 = (ushort)*(byte *)(unaff_A6 + 2);
  DAT_0001a528 = extraout_A0;
  if (bVar1 == 0) {
    FUN_00011020(CONCAT22(extraout_D0u,uVar2 + 1),CONCAT22(extraout_D1u,*(byte *)(unaff_A6 + 3) - 7)
                );
  }
  else if (bVar1 == 0x20) {
    func_0x000110da(CONCAT22(extraout_D0u,DAT_0001a512 + uVar2),
                    CONCAT22(extraout_D1u,*(byte *)(unaff_A6 + 3) - 7));
  }
  else if (bVar1 == 0x80) {
    func_0x000110da(CONCAT22(extraout_D0u,DAT_0001a512 + uVar2),
                    CONCAT22(extraout_D1u,DAT_0001a50c + 1));
  }
  else if (bVar1 == 0xa0) {
    FUN_00011020(CONCAT22(extraout_D0u,uVar2 + 1),CONCAT22(extraout_D1u,DAT_0001a50c + 1));
  }
  else if (bVar1 == 0xc0) {
    FUN_00011020(CONCAT22(extraout_D0u,DAT_0001a512 + uVar2),CONCAT22(extraout_D1u,DAT_0001a50c + 4)
                );
  }
  else if (bVar1 == 0xe0) {
    FUN_00011020(CONCAT22(extraout_D0u,uVar2 + 1),CONCAT22(extraout_D1u,DAT_0001a50c + 4));
  }
  FUN_000120a8();
  return;
}


// ---------------------------------------------------------------
// FUN_00010b6c @ 00010b6c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010b6c(void)

{
  byte bVar1;
  undefined2 extraout_D0u;
  ushort uVar2;
  undefined2 extraout_D1u;
  short sVar3;
  undefined4 extraout_A0;
  int unaff_A6;
  short sVar4;
  
  PTR_DAT_0001a4d8 = &UNK_0001d382;
  _DAT_0001a46a = 0;
  DAT_0001a512 = *(byte *)(unaff_A6 + 3) & 0x1f;
  DAT_0001a52e = (DAT_0001a512 + 2) * 4 + -2;
  DAT_0001a532 = (ushort)*(byte *)(unaff_A6 + 1);
  DAT_0001a530 = (ushort)*(byte *)(unaff_A6 + 2);
  FUN_00012ffa();
  sVar3 = 2;
  do {
    FUN_00012ffa();
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  FUN_00013216();
  FUN_00013216();
  FUN_00013216();
  FUN_00013216();
  DAT_0001a50c = DAT_0001a530 + 4;
  DAT_0001a508 = '\0';
  DAT_0001a50a = DAT_0001a532;
  do {
    sVar4 = DAT_0001a50c;
    uVar2 = DAT_0001a50a;
    print_char();
    FUN_00010b24();
    print_char();
    DAT_0001a50a = uVar2;
    sVar3 = DAT_0001a52e;
    DAT_0001a50c = sVar4 + 6;
  } while (DAT_0001a508 == '\0');
  FUN_00012ffa();
  FUN_00013216();
  FUN_00012ffa();
  FUN_00013216();
  FUN_00013216();
  FUN_00010fec();
  DAT_0001a49e = sVar3;
  DAT_0001a532 = DAT_0001a512 + 2;
  DAT_0001a530 = (DAT_0001a50c - DAT_0001a530) + 2;
  bVar1 = *(byte *)(unaff_A6 + 3) & 0xe0;
  uVar2 = (ushort)*(byte *)(unaff_A6 + 1);
  DAT_0001a528 = extraout_A0;
  if (bVar1 == 0) {
    FUN_00011020(CONCAT22(extraout_D0u,uVar2 + 1),CONCAT22(extraout_D1u,*(byte *)(unaff_A6 + 2) - 7)
                );
  }
  else if (bVar1 == 0x20) {
    func_0x000110da(CONCAT22(extraout_D0u,DAT_0001a512 + uVar2),
                    CONCAT22(extraout_D1u,*(byte *)(unaff_A6 + 2) - 7));
  }
  else if (bVar1 == 0x80) {
    func_0x000110da(CONCAT22(extraout_D0u,DAT_0001a512 + uVar2),
                    CONCAT22(extraout_D1u,DAT_0001a50c + 1));
  }
  else if (bVar1 == 0xa0) {
    FUN_00011020(CONCAT22(extraout_D0u,uVar2 + 1),CONCAT22(extraout_D1u,DAT_0001a50c + 1));
  }
  else if (bVar1 == 0xc0) {
    FUN_00011020(CONCAT22(extraout_D0u,DAT_0001a512 + uVar2),CONCAT22(extraout_D1u,DAT_0001a50c + 4)
                );
  }
  else if (bVar1 == 0xe0) {
    FUN_00011020(CONCAT22(extraout_D0u,uVar2 + 1),CONCAT22(extraout_D1u,DAT_0001a50c + 4));
  }
  FUN_000120a8();
  return;
}


// ---------------------------------------------------------------
// FUN_00010dfa @ 00010dfa

void FUN_00010dfa(void)

{
  undefined1 extraout_var;
  int unaff_A6;
  
  FUN_00010fb4();
  DAT_0001a512 = CONCAT11(extraout_var,*(undefined1 *)(unaff_A6 + 4));
  DAT_0001a532 = (ushort)*(byte *)(unaff_A6 + 2);
  DAT_0001a530 = (ushort)*(byte *)(unaff_A6 + 3);
  FUN_00010e66();
  FUN_00010fec();
  FUN_000120a8();
  return;
}


// ---------------------------------------------------------------
// FUN_00010e66 @ 00010e66

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00010e66(void)

{
  undefined2 uVar1;
  short sVar2;
  
  PTR_DAT_0001a4d8 = &DAT_0001d3a2;
  _DAT_0001a46a = 0;
  DAT_0001a52e = (DAT_0001a512 + 2) * 4 + -2;
  FUN_00012ffa();
  sVar2 = 2;
  do {
    FUN_00012ffa();
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  FUN_00013216();
  FUN_00013216();
  FUN_00013216();
  FUN_00013216();
  uVar1 = DAT_0001a532;
  sVar2 = DAT_0001a530 + 4;
  DAT_0001a508 = '\0';
  do {
    DAT_0001a50a = uVar1;
    DAT_0001a50c = sVar2;
    print_char();
    FUN_00010b24();
    print_char();
    sVar2 = sVar2 + 6;
  } while (DAT_0001a508 == '\0');
  DAT_0001a50a = uVar1;
  DAT_0001a50c = sVar2;
  FUN_00012ffa();
  FUN_00013216();
  FUN_00012ffa();
  FUN_00013216();
  FUN_00013216();
  return;
}


// ---------------------------------------------------------------
// FUN_00010f8e @ 00010f8e

void FUN_00010f8e(void)

{
  short unaff_D4w;
  short sVar1;
  ushort *in_A1;
  
  if (unaff_D4w != 0) {
    sVar1 = unaff_D4w + -1;
    do {
      in_A1 = (ushort *)((uint)*in_A1 + (int)in_A1);
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
  }
  cur_str_end = (uint)*in_A1 + (int)in_A1;
  return;
}


// ---------------------------------------------------------------
// FUN_00010fb4 @ 00010fb4

void FUN_00010fb4(void)

{
  ushort unaff_D4w;
  short sVar1;
  byte *unaff_A5;
  int unaff_A6;
  
  if (unaff_D4w < 4) {
    unaff_D4w = CONCAT11((char)unaff_D4w,*(undefined1 *)(unaff_A6 + 1));
  }
  DAT_0001a482 = unaff_D4w;
  sVar1 = unaff_D4w - 5;
  if (4 < unaff_D4w) {
    do {
      unaff_A5 = unaff_A5 + *unaff_A5;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
  }
  cur_str_end = unaff_A5 + *unaff_A5;
  return;
}


// ---------------------------------------------------------------
// FUN_00010fc4 @ 00010fc4

void FUN_00010fc4(void)

{
  ushort unaff_D4w;
  short sVar1;
  byte *unaff_A5;
  
  DAT_0001a482 = unaff_D4w;
  sVar1 = unaff_D4w - 5;
  if (4 < unaff_D4w) {
    do {
      unaff_A5 = unaff_A5 + *unaff_A5;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
  }
  cur_str_end = unaff_A5 + *unaff_A5;
  return;
}


// ---------------------------------------------------------------
// FUN_00010fec @ 00010fec

ulonglong FUN_00010fec(void)

{
  ushort in_D0w;
  ushort in_D1w;
  
  return (ulonglong)CONCAT24((in_D0w & 0x3ffc) << 1,(uint)in_D1w * 0xa0);
}


// ---------------------------------------------------------------
// FUN_00010fee @ 00010fee

ulonglong FUN_00010fee(void)

{
  ushort in_D0w;
  ushort in_D1w;
  
  return (ulonglong)CONCAT24((in_D0w & 0xfff0) >> 1,(uint)in_D1w * 0xa0);
}


// ---------------------------------------------------------------
// FUN_00010ff4 @ 00010ff4

ulonglong FUN_00010ff4(void)

{
  ushort in_D0w;
  ushort in_D1w;
  
  return (ulonglong)CONCAT24((in_D0w & 0xfff0) >> 1,(uint)in_D1w * 0xa0);
}


// ---------------------------------------------------------------
// FUN_00011014 @ 00011014

void FUN_00011014(void)

{
  return;
}


// ---------------------------------------------------------------
// FUN_00011016 @ 00011016

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011016(void)

{
  short sVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  ushort unaff_D7w;
  int extraout_A0;
  byte *pbVar12;
  byte *extraout_A1;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  
  FUN_00010f8e();
  FUN_00010fec();
  pbVar12 = (byte *)(extraout_A0 + -0x8000);
  bVar2 = *extraout_A1;
  iVar9 = (uint)extraout_A1[1] * 2;
  sVar8 = extraout_A1[1] - 1;
  pbVar13 = extraout_A1;
  DAT_0001a534 = iVar9;
  do {
    pbVar13 = pbVar13 + 2;
    iVar10 = 0;
    pbVar14 = pbVar12;
    if ((unaff_D7w & 8) != 0) {
      pbVar14 = pbVar12 + 1;
    }
    pbVar15 = pbVar13;
    sVar7 = bVar2 - 1;
    if ((unaff_D7w & 4) != 0) {
      iVar10 = 4;
    }
    do {
      sVar1 = *(short *)pbVar15;
      bVar4 = (byte)((ushort)sVar1 >> 8);
      _DAT_00055b02 = CONCAT13(bVar4,CONCAT12((char)((ushort)(sVar1 << 4) >> 8),sVar1 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar1 << 4) | bVar4 >> 4);
      uVar11 = _DAT_00055b02 << 0x20 - iVar10 | _DAT_00055b02 >> iVar10;
      uVar5 = uVar11 << 0x10 | uVar11 >> 0x10;
      uVar6 = uVar5 << 8 | (uVar11 & 0xffff) >> 8;
      uVar5 = (uVar6 << 0x10 | (uVar11 << 0x10 & 0xffffff | uVar11 >> 0x10) >> 8 |
              uVar6 | uVar5 | uVar11) & 0xf0f0f0f0;
      uVar5 = uVar5 << 0x20 - iVar10 | uVar5 >> iVar10;
      uVar5 = uVar5 & uVar11 |
              ~uVar5 & ((uint)*pbVar14 << 0x18 | (uint)pbVar14[2] << 0x10 | (uint)pbVar14[4] << 8 |
                       (uint)pbVar14[6]);
      *pbVar14 = (byte)(uVar5 >> 0x18);
      pbVar14[2] = (byte)(uVar5 >> 0x10);
      pbVar14[4] = (byte)(uVar5 >> 8);
      pbVar14[6] = (byte)uVar5;
      pbVar14 = pbVar14 + 0xa0;
      pbVar15 = pbVar15 + iVar9;
      sVar7 = sVar7 + -1;
    } while (sVar7 != -1);
    uVar3 = unaff_D7w + 4;
    unaff_D7w = uVar3 & 0xf;
    if ((uVar3 & 0xf) == 0) {
      pbVar12 = pbVar12 + 8;
    }
    sVar8 = sVar8 + -1;
  } while (sVar8 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011020 @ 00011020

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011020(void)

{
  short sVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  ushort unaff_D7w;
  byte *extraout_A0;
  byte *pbVar12;
  byte *extraout_A1;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  
  FUN_00010f8e();
  FUN_00010fec();
  bVar2 = *extraout_A1;
  iVar9 = (uint)extraout_A1[1] * 2;
  sVar8 = extraout_A1[1] - 1;
  pbVar12 = extraout_A0;
  pbVar13 = extraout_A1;
  DAT_0001a534 = iVar9;
  do {
    pbVar13 = pbVar13 + 2;
    iVar10 = 0;
    pbVar14 = pbVar12;
    if ((unaff_D7w & 8) != 0) {
      pbVar14 = pbVar12 + 1;
    }
    pbVar15 = pbVar13;
    sVar7 = bVar2 - 1;
    if ((unaff_D7w & 4) != 0) {
      iVar10 = 4;
    }
    do {
      sVar1 = *(short *)pbVar15;
      bVar4 = (byte)((ushort)sVar1 >> 8);
      _DAT_00055b02 = CONCAT13(bVar4,CONCAT12((char)((ushort)(sVar1 << 4) >> 8),sVar1 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar1 << 4) | bVar4 >> 4);
      uVar11 = _DAT_00055b02 << 0x20 - iVar10 | _DAT_00055b02 >> iVar10;
      uVar5 = uVar11 << 0x10 | uVar11 >> 0x10;
      uVar6 = uVar5 << 8 | (uVar11 & 0xffff) >> 8;
      uVar5 = (uVar6 << 0x10 | (uVar11 << 0x10 & 0xffffff | uVar11 >> 0x10) >> 8 |
              uVar6 | uVar5 | uVar11) & 0xf0f0f0f0;
      uVar5 = uVar5 << 0x20 - iVar10 | uVar5 >> iVar10;
      uVar5 = uVar5 & uVar11 |
              ~uVar5 & ((uint)*pbVar14 << 0x18 | (uint)pbVar14[2] << 0x10 | (uint)pbVar14[4] << 8 |
                       (uint)pbVar14[6]);
      *pbVar14 = (byte)(uVar5 >> 0x18);
      pbVar14[2] = (byte)(uVar5 >> 0x10);
      pbVar14[4] = (byte)(uVar5 >> 8);
      pbVar14[6] = (byte)uVar5;
      pbVar14 = pbVar14 + 0xa0;
      pbVar15 = pbVar15 + iVar9;
      sVar7 = sVar7 + -1;
    } while (sVar7 != -1);
    uVar3 = unaff_D7w + 4;
    unaff_D7w = uVar3 & 0xf;
    if ((uVar3 & 0xf) == 0) {
      pbVar12 = pbVar12 + 8;
    }
    sVar8 = sVar8 + -1;
  } while (sVar8 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011030 @ 00011030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011030(void)

{
  short sVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  ushort unaff_D7w;
  int extraout_A0;
  byte *pbVar12;
  byte *extraout_A1;
  byte *pbVar13;
  byte *pbVar14;
  int unaff_A4;
  byte *pbVar15;
  
  FUN_00010fec();
  pbVar12 = (byte *)(extraout_A0 - unaff_A4);
  bVar2 = *extraout_A1;
  iVar9 = (uint)extraout_A1[1] * 2;
  sVar8 = extraout_A1[1] - 1;
  pbVar13 = extraout_A1;
  DAT_0001a534 = iVar9;
  do {
    pbVar13 = pbVar13 + 2;
    iVar10 = 0;
    pbVar14 = pbVar12;
    if ((unaff_D7w & 8) != 0) {
      pbVar14 = pbVar12 + 1;
    }
    pbVar15 = pbVar13;
    sVar7 = bVar2 - 1;
    if ((unaff_D7w & 4) != 0) {
      iVar10 = 4;
    }
    do {
      sVar1 = *(short *)pbVar15;
      bVar4 = (byte)((ushort)sVar1 >> 8);
      _DAT_00055b02 = CONCAT13(bVar4,CONCAT12((char)((ushort)(sVar1 << 4) >> 8),sVar1 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar1 << 4) | bVar4 >> 4);
      uVar11 = _DAT_00055b02 << 0x20 - iVar10 | _DAT_00055b02 >> iVar10;
      uVar5 = uVar11 << 0x10 | uVar11 >> 0x10;
      uVar6 = uVar5 << 8 | (uVar11 & 0xffff) >> 8;
      uVar5 = (uVar6 << 0x10 | (uVar11 << 0x10 & 0xffffff | uVar11 >> 0x10) >> 8 |
              uVar6 | uVar5 | uVar11) & 0xf0f0f0f0;
      uVar5 = uVar5 << 0x20 - iVar10 | uVar5 >> iVar10;
      uVar5 = uVar5 & uVar11 |
              ~uVar5 & ((uint)*pbVar14 << 0x18 | (uint)pbVar14[2] << 0x10 | (uint)pbVar14[4] << 8 |
                       (uint)pbVar14[6]);
      *pbVar14 = (byte)(uVar5 >> 0x18);
      pbVar14[2] = (byte)(uVar5 >> 0x10);
      pbVar14[4] = (byte)(uVar5 >> 8);
      pbVar14[6] = (byte)uVar5;
      pbVar14 = pbVar14 + 0xa0;
      pbVar15 = pbVar15 + iVar9;
      sVar7 = sVar7 + -1;
    } while (sVar7 != -1);
    uVar3 = unaff_D7w + 4;
    unaff_D7w = uVar3 & 0xf;
    if ((uVar3 & 0xf) == 0) {
      pbVar12 = pbVar12 + 8;
    }
    sVar8 = sVar8 + -1;
  } while (sVar8 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001103e @ 0001103e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001103e(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  short unaff_D2w;
  short sVar6;
  short sVar7;
  short unaff_D3w;
  int iVar8;
  uint uVar9;
  ushort unaff_D7w;
  byte *in_A0;
  short *in_A1;
  byte *pbVar10;
  short *psVar11;
  
  sVar7 = unaff_D2w + -1;
  DAT_0001a534 = (uint)(ushort)(unaff_D2w << 1);
  do {
    iVar8 = 0;
    pbVar10 = in_A0;
    if ((unaff_D7w & 8) != 0) {
      pbVar10 = in_A0 + 1;
    }
    psVar11 = in_A1;
    sVar6 = unaff_D3w + -1;
    if ((unaff_D7w & 4) != 0) {
      iVar8 = 4;
    }
    do {
      sVar1 = *psVar11;
      bVar3 = (byte)((ushort)sVar1 >> 8);
      _DAT_00055b02 = CONCAT13(bVar3,CONCAT12((char)((ushort)(sVar1 << 4) >> 8),sVar1 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar1 << 4) | bVar3 >> 4);
      uVar9 = _DAT_00055b02 << 0x20 - iVar8 | _DAT_00055b02 >> iVar8;
      uVar4 = uVar9 << 0x10 | uVar9 >> 0x10;
      uVar5 = uVar4 << 8 | (uVar9 & 0xffff) >> 8;
      uVar4 = (uVar5 << 0x10 | (uVar9 << 0x10 & 0xffffff | uVar9 >> 0x10) >> 8 |
              uVar5 | uVar4 | uVar9) & 0xf0f0f0f0;
      uVar4 = uVar4 << 0x20 - iVar8 | uVar4 >> iVar8;
      uVar4 = uVar4 & uVar9 |
              ~uVar4 & ((uint)*pbVar10 << 0x18 | (uint)pbVar10[2] << 0x10 | (uint)pbVar10[4] << 8 |
                       (uint)pbVar10[6]);
      *pbVar10 = (byte)(uVar4 >> 0x18);
      pbVar10[2] = (byte)(uVar4 >> 0x10);
      pbVar10[4] = (byte)(uVar4 >> 8);
      pbVar10[6] = (byte)uVar4;
      pbVar10 = pbVar10 + 0xa0;
      psVar11 = (short *)((uint)(ushort)(unaff_D2w << 1) + (int)psVar11);
      sVar6 = sVar6 + -1;
    } while (sVar6 != -1);
    in_A1 = in_A1 + 1;
    uVar2 = unaff_D7w + 4;
    unaff_D7w = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      in_A0 = in_A0 + 8;
    }
    sVar7 = sVar7 + -1;
  } while (sVar7 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001104a @ 0001104a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001104a(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  short unaff_D2w;
  short sVar7;
  short sVar8;
  short unaff_D3w;
  int iVar9;
  uint uVar10;
  ushort unaff_D7w;
  byte *in_A0;
  short *in_A1;
  byte *pbVar11;
  short *psVar12;
  
  iVar4 = DAT_0001a534;
  sVar8 = unaff_D2w + -1;
  do {
    iVar9 = 0;
    pbVar11 = in_A0;
    if ((unaff_D7w & 8) != 0) {
      pbVar11 = in_A0 + 1;
    }
    psVar12 = in_A1;
    sVar7 = unaff_D3w + -1;
    if ((unaff_D7w & 4) != 0) {
      iVar9 = 4;
    }
    do {
      sVar1 = *psVar12;
      bVar3 = (byte)((ushort)sVar1 >> 8);
      _DAT_00055b02 = CONCAT13(bVar3,CONCAT12((char)((ushort)(sVar1 << 4) >> 8),sVar1 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar1 << 4) | bVar3 >> 4);
      uVar10 = _DAT_00055b02 << 0x20 - iVar9 | _DAT_00055b02 >> iVar9;
      uVar5 = uVar10 << 0x10 | uVar10 >> 0x10;
      uVar6 = uVar5 << 8 | (uVar10 & 0xffff) >> 8;
      uVar5 = (uVar6 << 0x10 | (uVar10 << 0x10 & 0xffffff | uVar10 >> 0x10) >> 8 |
              uVar6 | uVar5 | uVar10) & 0xf0f0f0f0;
      uVar5 = uVar5 << 0x20 - iVar9 | uVar5 >> iVar9;
      uVar5 = uVar5 & uVar10 |
              ~uVar5 & ((uint)*pbVar11 << 0x18 | (uint)pbVar11[2] << 0x10 | (uint)pbVar11[4] << 8 |
                       (uint)pbVar11[6]);
      *pbVar11 = (byte)(uVar5 >> 0x18);
      pbVar11[2] = (byte)(uVar5 >> 0x10);
      pbVar11[4] = (byte)(uVar5 >> 8);
      pbVar11[6] = (byte)uVar5;
      pbVar11 = pbVar11 + 0xa0;
      psVar12 = (short *)(iVar4 + (int)psVar12);
      sVar7 = sVar7 + -1;
    } while (sVar7 != -1);
    in_A1 = in_A1 + 1;
    uVar2 = unaff_D7w + 4;
    unaff_D7w = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      in_A0 = in_A0 + 8;
    }
    sVar8 = sVar8 + -1;
  } while (sVar8 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011050 @ 00011050

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011050(void)

{
  short sVar1;
  ushort uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  short unaff_D2w;
  short sVar6;
  short sVar7;
  short unaff_D3w;
  int iVar8;
  uint uVar9;
  ushort unaff_D7w;
  byte *in_A0;
  short *in_A1;
  byte *pbVar10;
  int unaff_A3;
  short *psVar11;
  
  sVar7 = unaff_D2w + -1;
  do {
    iVar8 = 0;
    pbVar10 = in_A0;
    if ((unaff_D7w & 8) != 0) {
      pbVar10 = in_A0 + 1;
    }
    psVar11 = in_A1;
    sVar6 = unaff_D3w + -1;
    if ((unaff_D7w & 4) != 0) {
      iVar8 = 4;
    }
    do {
      sVar1 = *psVar11;
      bVar3 = (byte)((ushort)sVar1 >> 8);
      _DAT_00055b02 = CONCAT13(bVar3,CONCAT12((char)((ushort)(sVar1 << 4) >> 8),sVar1 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar1 << 4) | bVar3 >> 4);
      uVar9 = _DAT_00055b02 << 0x20 - iVar8 | _DAT_00055b02 >> iVar8;
      uVar4 = uVar9 << 0x10 | uVar9 >> 0x10;
      uVar5 = uVar4 << 8 | (uVar9 & 0xffff) >> 8;
      uVar4 = (uVar5 << 0x10 | (uVar9 << 0x10 & 0xffffff | uVar9 >> 0x10) >> 8 |
              uVar5 | uVar4 | uVar9) & 0xf0f0f0f0;
      uVar4 = uVar4 << 0x20 - iVar8 | uVar4 >> iVar8;
      uVar4 = uVar4 & uVar9 |
              ~uVar4 & ((uint)*pbVar10 << 0x18 | (uint)pbVar10[2] << 0x10 | (uint)pbVar10[4] << 8 |
                       (uint)pbVar10[6]);
      *pbVar10 = (byte)(uVar4 >> 0x18);
      pbVar10[2] = (byte)(uVar4 >> 0x10);
      pbVar10[4] = (byte)(uVar4 >> 8);
      pbVar10[6] = (byte)uVar4;
      pbVar10 = pbVar10 + 0xa0;
      psVar11 = (short *)(unaff_A3 + (int)psVar11);
      sVar6 = sVar6 + -1;
    } while (sVar6 != -1);
    in_A1 = in_A1 + 1;
    uVar2 = unaff_D7w + 4;
    unaff_D7w = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      in_A0 = in_A0 + 8;
    }
    sVar7 = sVar7 + -1;
  } while (sVar7 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011102 @ 00011102

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011102(void)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  short unaff_D2w;
  uint uVar5;
  short unaff_D3w;
  int iVar6;
  short sVar7;
  short sVar8;
  ushort unaff_D7w;
  byte *in_A0;
  byte *extraout_A0;
  bool bVar9;
  
  sVar8 = unaff_D2w + -1;
  do {
    iVar6 = 0;
    if ((unaff_D7w & 8) != 0) {
      in_A0 = in_A0 + 1;
    }
    sVar7 = unaff_D3w + -1;
    if ((unaff_D7w & 4) != 0) {
      iVar6 = 4;
    }
    do {
      sVar2 = FUN_00011196();
      bVar1 = (byte)((ushort)sVar2 >> 8);
      _DAT_00055b02 = CONCAT13(bVar1,CONCAT12((char)((ushort)(sVar2 << 4) >> 8),sVar2 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar2 << 4) | bVar1 >> 4);
      uVar5 = _DAT_00055b02 << 0x20 - iVar6 | _DAT_00055b02 >> iVar6;
      uVar3 = uVar5 << 0x10 | uVar5 >> 0x10;
      uVar4 = uVar3 << 8 | (uVar5 & 0xffff) >> 8;
      uVar3 = (uVar4 << 0x10 | (uVar5 << 0x10 & 0xffffff | uVar5 >> 0x10) >> 8 |
              uVar4 | uVar3 | uVar5) & 0xf0f0f0f0;
      uVar3 = uVar3 << 0x20 - iVar6 | uVar3 >> iVar6;
      uVar3 = uVar3 & uVar5 |
              ~uVar3 & ((uint)*in_A0 << 0x18 | (uint)in_A0[2] << 0x10 | (uint)in_A0[4] << 8 |
                       (uint)in_A0[6]);
      *in_A0 = (byte)(uVar3 >> 0x18);
      in_A0[2] = (byte)(uVar3 >> 0x10);
      in_A0[4] = (byte)(uVar3 >> 8);
      in_A0[6] = (byte)uVar3;
      in_A0 = in_A0 + 0xa0;
      sVar7 = sVar7 + -1;
    } while (sVar7 != -1);
    bVar9 = unaff_D7w < 4;
    unaff_D7w = unaff_D7w - 4;
    in_A0 = extraout_A0;
    if (bVar9) {
      in_A0 = extraout_A0 + -8;
      unaff_D7w = 0xc;
    }
    sVar8 = sVar8 + -1;
  } while (sVar8 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011196 @ 00011196

ushort FUN_00011196(void)

{
  ushort uVar1;
  byte bVar2;
  undefined2 in_D0w;
  ushort uVar3;
  ushort in_D1w;
  short sVar4;
  byte in_XF;
  
  bVar2 = (byte)((ushort)in_D0w >> 8);
  uVar3 = CONCAT11((byte)in_D0w << 4 | (byte)in_D0w >> 4,bVar2 << 4 | bVar2 >> 4);
  sVar4 = 0xf;
  do {
    uVar1 = uVar3 & 1;
    uVar3 = (ushort)in_XF << 0xf | uVar3 >> 1;
    in_XF = (in_D1w & 0x8000) != 0;
    in_D1w = in_D1w << 1 | (ushort)(uVar1 != 0);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  return in_D1w;
}


// ---------------------------------------------------------------
// FUN_000111ac @ 000111ac

void FUN_000111ac(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint in_D0;
  short in_D1w;
  ushort uVar11;
  short unaff_D3w;
  uint uVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  short sVar16;
  ushort uVar17;
  short sVar18;
  undefined2 *in_A0;
  undefined2 *puVar19;
  undefined2 *puVar20;
  undefined2 *extraout_A0;
  ushort *in_A1;
  ushort *puVar21;
  ushort *extraout_A1;
  ushort *puVar22;
  ushort *puVar23;
  bool bVar24;
  bool bVar25;
  ulonglong uVar26;
  ushort uVar27;
  
  uVar12 = (uint)(ushort)(unaff_D3w - 1);
  uVar27 = 5;
  uVar11 = in_D1w * 4 - 1;
  do {
    uVar13 = 0xffffffff >> (in_D0 & 0x3f);
    uVar8 = ~uVar13;
    uVar4 = 0x10 - (short)in_D0;
    uVar14 = 1;
    bVar25 = true;
    uVar17 = uVar27 - uVar4;
    if (uVar4 <= uVar27 && uVar17 != 0) {
      do {
        uVar14 = uVar14 + 1;
        bVar25 = (bool)(bVar25 ^ 1);
        bVar24 = 0xf < uVar17;
        uVar17 = uVar17 - 0x10;
      } while (bVar24 && uVar17 != 0);
    }
    uVar15 = ~(-1 << (-uVar17 & 0x3f));
    uVar14 = uVar14 >> 1;
    if (bVar25) {
      uVar14 = uVar14 + 1;
      uVar15 = uVar15 << 0x10 | uVar15 >> 0x10 | 0xffff;
    }
    sVar18 = (short)uVar12;
    uVar4 = uVar11 & 3;
    puVar22 = (ushort *)&DAT_0000d8f0;
    bVar25 = false;
    puVar19 = in_A0;
    puVar21 = in_A1;
    if (uVar14 == 4) {
      do {
        uVar14 = *puVar21 << (uint)uVar4 | *puVar21 >> 0x10 - (uint)uVar4;
        uVar17 = uVar14 << 0x10 - (in_D0 & 0x3f) | uVar14 >> (in_D0 & 0x3f);
        uVar14 = -0x8000 << 0x10 - (in_D0 & 0x3f) | 0x8000U >> (in_D0 & 0x3f);
        sVar16 = 3;
        do {
          puVar23 = puVar22;
          puVar20 = puVar19;
          uVar3 = puVar20[4];
          uVar9 = CONCAT22(*puVar20,uVar3);
          uVar2 = puVar20[0xc];
          uVar1 = puVar20[0x14];
          uVar10 = CONCAT22(puVar20[0x18],puVar20[0x1c]);
          uVar5 = (uint)bVar25;
          uVar7 = CONCAT22(puVar20[8],uVar2) >> 1;
          uVar6 = CONCAT22(puVar20[0x10],uVar1) >> 1;
          bVar25 = (puVar20[0x1c] & 1) != 0;
          puVar23[0xc] = (ushort)uVar7;
          puVar23[8] = (ushort)(((uint)((uVar3 & 1) != 0) << 0x1f | uVar7) >> 0x10);
          puVar23[0x14] = (ushort)uVar6;
          puVar23[0x10] = (ushort)(((uint)((uVar2 & 1) != 0) << 0x1f | uVar6) >> 0x10);
          uVar5 = uVar13 & (uVar5 << 0x1f | uVar9 >> 1) | uVar8 & uVar9;
          puVar23[4] = (ushort)uVar5;
          *puVar23 = uVar14 & uVar17 | ~uVar14 & (ushort)(uVar5 >> 0x10);
          uVar5 = ~uVar15 & ((uint)((uVar1 & 1) != 0) << 0x1f | uVar10 >> 1) | uVar15 & uVar10;
          puVar23[0x1c] = (ushort)uVar5;
          puVar23[0x18] = (ushort)(uVar5 >> 0x10);
          uVar17 = uVar17 << 4 | uVar17 >> 0xc;
          sVar16 = sVar16 + -1;
          puVar19 = puVar20 + 1;
          puVar22 = puVar23 + 1;
        } while (sVar16 != -1);
        puVar19 = puVar20 + 0x4d;
        puVar21 = (ushort *)(DAT_0001a534 + (int)puVar21);
        puVar22 = puVar23 + 0x1d;
        sVar18 = sVar18 + -1;
      } while (sVar18 != -1);
    }
    else {
      bVar25 = false;
      if (uVar14 == 3) {
        do {
          uVar14 = *puVar21 << (uint)uVar4 | *puVar21 >> 0x10 - (uint)uVar4;
          uVar17 = uVar14 << 0x10 - (in_D0 & 0x3f) | uVar14 >> (in_D0 & 0x3f);
          uVar14 = -0x8000 << 0x10 - (in_D0 & 0x3f) | 0x8000U >> (in_D0 & 0x3f);
          sVar16 = 3;
          do {
            puVar23 = puVar22;
            puVar20 = puVar19;
            uVar3 = puVar20[4];
            uVar6 = CONCAT22(*puVar20,uVar3);
            uVar2 = puVar20[0xc];
            uVar9 = CONCAT22(puVar20[0x10],puVar20[0x14]);
            uVar5 = (uint)bVar25;
            uVar7 = CONCAT22(puVar20[8],uVar2) >> 1;
            bVar25 = (puVar20[0x14] & 1) != 0;
            puVar23[0xc] = (ushort)uVar7;
            puVar23[8] = (ushort)(((uint)((uVar3 & 1) != 0) << 0x1f | uVar7) >> 0x10);
            uVar5 = uVar13 & (uVar5 << 0x1f | uVar6 >> 1) | uVar8 & uVar6;
            puVar23[4] = (ushort)uVar5;
            *puVar23 = uVar14 & uVar17 | ~uVar14 & (ushort)(uVar5 >> 0x10);
            uVar5 = ~uVar15 & ((uint)((uVar2 & 1) != 0) << 0x1f | uVar9 >> 1) | uVar15 & uVar9;
            puVar23[0x14] = (ushort)uVar5;
            puVar23[0x10] = (ushort)(uVar5 >> 0x10);
            uVar17 = uVar17 << 4 | uVar17 >> 0xc;
            sVar16 = sVar16 + -1;
            puVar19 = puVar20 + 1;
            puVar22 = puVar23 + 1;
          } while (sVar16 != -1);
          puVar19 = puVar20 + 0x4d;
          puVar21 = (ushort *)(DAT_0001a534 + (int)puVar21);
          puVar22 = puVar23 + 0x15;
          sVar18 = sVar18 + -1;
        } while (sVar18 != -1);
      }
      else {
        bVar25 = uVar14 < 2;
        bVar24 = false;
        if (uVar14 == 2) {
          do {
            uVar14 = *puVar21 << (uint)uVar4 | *puVar21 >> 0x10 - (uint)uVar4;
            uVar17 = uVar14 << 0x10 - (in_D0 & 0x3f) | uVar14 >> (in_D0 & 0x3f);
            uVar14 = -0x8000 << 0x10 - (in_D0 & 0x3f) | 0x8000U >> (in_D0 & 0x3f);
            sVar16 = 3;
            do {
              puVar23 = puVar22;
              puVar20 = puVar19;
              uVar3 = puVar20[4];
              uVar7 = CONCAT22(*puVar20,uVar3);
              uVar6 = CONCAT22(puVar20[8],puVar20[0xc]);
              uVar5 = (uint)bVar24;
              bVar24 = (puVar20[0xc] & 1) != 0;
              uVar5 = uVar13 & (uVar5 << 0x1f | uVar7 >> 1) | uVar8 & uVar7;
              puVar23[4] = (ushort)uVar5;
              *puVar23 = uVar14 & uVar17 | ~uVar14 & (ushort)(uVar5 >> 0x10);
              uVar5 = ~uVar15 & ((uint)((uVar3 & 1) != 0) << 0x1f | uVar6 >> 1) | uVar15 & uVar6;
              puVar23[0xc] = (ushort)uVar5;
              puVar23[8] = (ushort)(uVar5 >> 0x10);
              uVar17 = uVar17 << 4 | uVar17 >> 0xc;
              sVar16 = sVar16 + -1;
              puVar19 = puVar20 + 1;
              puVar22 = puVar23 + 1;
            } while (sVar16 != -1);
            puVar19 = puVar20 + 0x4d;
            puVar21 = (ushort *)(DAT_0001a534 + (int)puVar21);
            puVar22 = puVar23 + 0xd;
            sVar18 = sVar18 + -1;
          } while (sVar18 != -1);
        }
        else {
          do {
            uVar14 = *puVar21 << (uint)uVar4 | *puVar21 >> 0x10 - (uint)uVar4;
            uVar17 = uVar14 << 0x10 - (in_D0 & 0x3f) | uVar14 >> (in_D0 & 0x3f);
            uVar14 = -0x8000 << 0x10 - (in_D0 & 0x3f) | 0x8000U >> (in_D0 & 0x3f);
            sVar16 = 3;
            bVar24 = bVar25;
            do {
              puVar23 = puVar22;
              puVar20 = puVar19;
              uVar13 = CONCAT22(*puVar20,puVar20[4]);
              bVar25 = (puVar20[4] & 1) != 0;
              uVar13 = ~(uVar15 | uVar8) & ((uint)bVar24 << 0x1f | uVar13 >> 1) |
                       (uVar15 | uVar8) & uVar13;
              puVar23[4] = (ushort)uVar13;
              *puVar23 = uVar14 & uVar17 | ~uVar14 & (ushort)(uVar13 >> 0x10);
              uVar17 = uVar17 << 4 | uVar17 >> 0xc;
              sVar16 = sVar16 + -1;
              puVar19 = puVar20 + 1;
              puVar22 = puVar23 + 1;
              bVar24 = bVar25;
            } while (sVar16 != -1);
            puVar19 = puVar20 + 0x4d;
            puVar21 = (ushort *)(DAT_0001a534 + (int)puVar21);
            puVar22 = puVar23 + 5;
            sVar18 = sVar18 + -1;
          } while (sVar18 != -1);
        }
      }
    }
    FUN_00013594(in_D0,uVar11,uVar27,uVar12,in_A0,in_A1);
    uVar26 = FUN_000123a0();
    in_D0 = (uint)(uVar26 >> 0x20);
    in_A1 = extraout_A1;
    if ((uVar26 & 3) == 0) {
      in_A1 = extraout_A1 + -1;
    }
    uVar27 = uVar27 + 1;
    uVar11 = (short)uVar26 - 1;
    in_A0 = extraout_A0;
  } while (uVar11 != 0xffff);
  return;
}


// ---------------------------------------------------------------
// FUN_000111b6 @ 000111b6

void FUN_000111b6(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint in_D0;
  ushort in_D1w;
  ushort unaff_D2w;
  undefined4 unaff_D3;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  short sVar14;
  ushort uVar15;
  short sVar16;
  undefined2 *in_A0;
  undefined2 *puVar17;
  undefined2 *puVar18;
  undefined2 *extraout_A0;
  ushort *in_A1;
  ushort *puVar19;
  ushort *extraout_A1;
  ushort *puVar20;
  ushort *puVar21;
  bool bVar22;
  bool bVar23;
  ulonglong uVar24;
  
  do {
    uVar11 = 0xffffffff >> (in_D0 & 0x3f);
    uVar8 = ~uVar11;
    uVar4 = 0x10 - (short)in_D0;
    uVar12 = 1;
    bVar23 = true;
    uVar15 = unaff_D2w - uVar4;
    if (uVar4 <= unaff_D2w && uVar15 != 0) {
      do {
        uVar12 = uVar12 + 1;
        bVar23 = (bool)(bVar23 ^ 1);
        bVar22 = 0xf < uVar15;
        uVar15 = uVar15 - 0x10;
      } while (bVar22 && uVar15 != 0);
    }
    uVar13 = ~(-1 << (-uVar15 & 0x3f));
    uVar12 = uVar12 >> 1;
    if (bVar23) {
      uVar12 = uVar12 + 1;
      uVar13 = uVar13 << 0x10 | uVar13 >> 0x10 | 0xffff;
    }
    sVar16 = (short)unaff_D3;
    uVar4 = in_D1w & 3;
    puVar20 = (ushort *)&DAT_0000d8f0;
    bVar23 = false;
    puVar17 = in_A0;
    puVar19 = in_A1;
    if (uVar12 == 4) {
      do {
        uVar12 = *puVar19 << (uint)uVar4 | *puVar19 >> 0x10 - (uint)uVar4;
        uVar15 = uVar12 << 0x10 - (in_D0 & 0x3f) | uVar12 >> (in_D0 & 0x3f);
        uVar12 = -0x8000 << 0x10 - (in_D0 & 0x3f) | 0x8000U >> (in_D0 & 0x3f);
        sVar14 = 3;
        do {
          puVar21 = puVar20;
          puVar18 = puVar17;
          uVar3 = puVar18[4];
          uVar9 = CONCAT22(*puVar18,uVar3);
          uVar2 = puVar18[0xc];
          uVar1 = puVar18[0x14];
          uVar10 = CONCAT22(puVar18[0x18],puVar18[0x1c]);
          uVar5 = (uint)bVar23;
          uVar7 = CONCAT22(puVar18[8],uVar2) >> 1;
          uVar6 = CONCAT22(puVar18[0x10],uVar1) >> 1;
          bVar23 = (puVar18[0x1c] & 1) != 0;
          puVar21[0xc] = (ushort)uVar7;
          puVar21[8] = (ushort)(((uint)((uVar3 & 1) != 0) << 0x1f | uVar7) >> 0x10);
          puVar21[0x14] = (ushort)uVar6;
          puVar21[0x10] = (ushort)(((uint)((uVar2 & 1) != 0) << 0x1f | uVar6) >> 0x10);
          uVar5 = uVar11 & (uVar5 << 0x1f | uVar9 >> 1) | uVar8 & uVar9;
          puVar21[4] = (ushort)uVar5;
          *puVar21 = uVar12 & uVar15 | ~uVar12 & (ushort)(uVar5 >> 0x10);
          uVar5 = ~uVar13 & ((uint)((uVar1 & 1) != 0) << 0x1f | uVar10 >> 1) | uVar13 & uVar10;
          puVar21[0x1c] = (ushort)uVar5;
          puVar21[0x18] = (ushort)(uVar5 >> 0x10);
          uVar15 = uVar15 << 4 | uVar15 >> 0xc;
          sVar14 = sVar14 + -1;
          puVar17 = puVar18 + 1;
          puVar20 = puVar21 + 1;
        } while (sVar14 != -1);
        puVar17 = puVar18 + 0x4d;
        puVar19 = (ushort *)(DAT_0001a534 + (int)puVar19);
        puVar20 = puVar21 + 0x1d;
        sVar16 = sVar16 + -1;
      } while (sVar16 != -1);
    }
    else {
      bVar23 = false;
      if (uVar12 == 3) {
        do {
          uVar12 = *puVar19 << (uint)uVar4 | *puVar19 >> 0x10 - (uint)uVar4;
          uVar15 = uVar12 << 0x10 - (in_D0 & 0x3f) | uVar12 >> (in_D0 & 0x3f);
          uVar12 = -0x8000 << 0x10 - (in_D0 & 0x3f) | 0x8000U >> (in_D0 & 0x3f);
          sVar14 = 3;
          do {
            puVar21 = puVar20;
            puVar18 = puVar17;
            uVar3 = puVar18[4];
            uVar6 = CONCAT22(*puVar18,uVar3);
            uVar2 = puVar18[0xc];
            uVar9 = CONCAT22(puVar18[0x10],puVar18[0x14]);
            uVar5 = (uint)bVar23;
            uVar7 = CONCAT22(puVar18[8],uVar2) >> 1;
            bVar23 = (puVar18[0x14] & 1) != 0;
            puVar21[0xc] = (ushort)uVar7;
            puVar21[8] = (ushort)(((uint)((uVar3 & 1) != 0) << 0x1f | uVar7) >> 0x10);
            uVar5 = uVar11 & (uVar5 << 0x1f | uVar6 >> 1) | uVar8 & uVar6;
            puVar21[4] = (ushort)uVar5;
            *puVar21 = uVar12 & uVar15 | ~uVar12 & (ushort)(uVar5 >> 0x10);
            uVar5 = ~uVar13 & ((uint)((uVar2 & 1) != 0) << 0x1f | uVar9 >> 1) | uVar13 & uVar9;
            puVar21[0x14] = (ushort)uVar5;
            puVar21[0x10] = (ushort)(uVar5 >> 0x10);
            uVar15 = uVar15 << 4 | uVar15 >> 0xc;
            sVar14 = sVar14 + -1;
            puVar17 = puVar18 + 1;
            puVar20 = puVar21 + 1;
          } while (sVar14 != -1);
          puVar17 = puVar18 + 0x4d;
          puVar19 = (ushort *)(DAT_0001a534 + (int)puVar19);
          puVar20 = puVar21 + 0x15;
          sVar16 = sVar16 + -1;
        } while (sVar16 != -1);
      }
      else {
        bVar23 = uVar12 < 2;
        bVar22 = false;
        if (uVar12 == 2) {
          do {
            uVar12 = *puVar19 << (uint)uVar4 | *puVar19 >> 0x10 - (uint)uVar4;
            uVar15 = uVar12 << 0x10 - (in_D0 & 0x3f) | uVar12 >> (in_D0 & 0x3f);
            uVar12 = -0x8000 << 0x10 - (in_D0 & 0x3f) | 0x8000U >> (in_D0 & 0x3f);
            sVar14 = 3;
            do {
              puVar21 = puVar20;
              puVar18 = puVar17;
              uVar3 = puVar18[4];
              uVar7 = CONCAT22(*puVar18,uVar3);
              uVar6 = CONCAT22(puVar18[8],puVar18[0xc]);
              uVar5 = (uint)bVar22;
              bVar22 = (puVar18[0xc] & 1) != 0;
              uVar5 = uVar11 & (uVar5 << 0x1f | uVar7 >> 1) | uVar8 & uVar7;
              puVar21[4] = (ushort)uVar5;
              *puVar21 = uVar12 & uVar15 | ~uVar12 & (ushort)(uVar5 >> 0x10);
              uVar5 = ~uVar13 & ((uint)((uVar3 & 1) != 0) << 0x1f | uVar6 >> 1) | uVar13 & uVar6;
              puVar21[0xc] = (ushort)uVar5;
              puVar21[8] = (ushort)(uVar5 >> 0x10);
              uVar15 = uVar15 << 4 | uVar15 >> 0xc;
              sVar14 = sVar14 + -1;
              puVar17 = puVar18 + 1;
              puVar20 = puVar21 + 1;
            } while (sVar14 != -1);
            puVar17 = puVar18 + 0x4d;
            puVar19 = (ushort *)(DAT_0001a534 + (int)puVar19);
            puVar20 = puVar21 + 0xd;
            sVar16 = sVar16 + -1;
          } while (sVar16 != -1);
        }
        else {
          do {
            uVar12 = *puVar19 << (uint)uVar4 | *puVar19 >> 0x10 - (uint)uVar4;
            uVar15 = uVar12 << 0x10 - (in_D0 & 0x3f) | uVar12 >> (in_D0 & 0x3f);
            uVar12 = -0x8000 << 0x10 - (in_D0 & 0x3f) | 0x8000U >> (in_D0 & 0x3f);
            sVar14 = 3;
            bVar22 = bVar23;
            do {
              puVar21 = puVar20;
              puVar18 = puVar17;
              uVar11 = CONCAT22(*puVar18,puVar18[4]);
              bVar23 = (puVar18[4] & 1) != 0;
              uVar11 = ~(uVar13 | uVar8) & ((uint)bVar22 << 0x1f | uVar11 >> 1) |
                       (uVar13 | uVar8) & uVar11;
              puVar21[4] = (ushort)uVar11;
              *puVar21 = uVar12 & uVar15 | ~uVar12 & (ushort)(uVar11 >> 0x10);
              uVar15 = uVar15 << 4 | uVar15 >> 0xc;
              sVar14 = sVar14 + -1;
              puVar17 = puVar18 + 1;
              puVar20 = puVar21 + 1;
              bVar22 = bVar23;
            } while (sVar14 != -1);
            puVar17 = puVar18 + 0x4d;
            puVar19 = (ushort *)(DAT_0001a534 + (int)puVar19);
            puVar20 = puVar21 + 5;
            sVar16 = sVar16 + -1;
          } while (sVar16 != -1);
        }
      }
    }
    FUN_00013594(in_D0,in_D1w,unaff_D2w,unaff_D3,in_A0,in_A1);
    uVar24 = FUN_000123a0();
    in_D0 = (uint)(uVar24 >> 0x20);
    in_A1 = extraout_A1;
    if ((uVar24 & 3) == 0) {
      in_A1 = extraout_A1 + -1;
    }
    unaff_D2w = unaff_D2w + 1;
    in_D1w = (short)uVar24 - 1;
    in_A0 = extraout_A0;
  } while (in_D1w != 0xffff);
  return;
}


// ---------------------------------------------------------------
// FUN_000114b0 @ 000114b0

void FUN_000114b0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint in_D0;
  ushort uVar7;
  ushort uVar8;
  short in_D1w;
  ushort uVar9;
  short unaff_D3w;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  short sVar15;
  uint unaff_D6;
  uint uVar16;
  short sVar17;
  ushort *in_A0;
  ushort *puVar18;
  ushort *puVar19;
  ushort *extraout_A0;
  undefined2 *in_A1;
  undefined2 *puVar20;
  undefined2 *extraout_A1;
  undefined2 *puVar21;
  undefined2 *puVar22;
  bool bVar23;
  bool bVar24;
  ulonglong uVar25;
  ushort uVar26;
  
  uVar10 = (uint)(ushort)(unaff_D3w - 1);
  uVar26 = 5;
  uVar8 = in_D1w * 4 - 1;
  do {
    uVar11 = 0xffffffff >> (in_D0 & 0x3f);
    uVar4 = ~uVar11;
    uVar7 = 0x10 - (short)in_D0;
    uVar12 = 1;
    bVar24 = true;
    uVar9 = uVar26 - uVar7;
    if (uVar7 <= uVar26 && uVar9 != 0) {
      do {
        uVar12 = uVar12 + 1;
        bVar24 = (bool)(bVar24 ^ 1);
        bVar23 = 0xf < uVar9;
        uVar9 = uVar9 - 0x10;
      } while (bVar23 && uVar9 != 0);
    }
    uVar13 = ~(-1 << (-uVar9 & 0x3f));
    uVar7 = uVar9 + 0x1f;
    uVar12 = uVar12 >> 1;
    if (bVar24) {
      uVar12 = uVar12 + 1;
      uVar7 = uVar9 + 0xf;
      uVar13 = uVar13 << 0x10 | uVar13 >> 0x10 | 0xffff;
    }
    uVar9 = 3 - (uVar8 & 3);
    sVar17 = (short)uVar10;
    uVar14 = (uint)uVar7;
    puVar21 = (undefined2 *)&DAT_0000d8f0;
    bVar24 = false;
    puVar18 = in_A0;
    puVar20 = in_A1;
    if (uVar12 == 4) {
      do {
        uVar12 = (ushort)(unaff_D6 >> 0x10);
        uVar16 = CONCAT22(uVar12,*puVar20) << 0x10 | (uint)uVar12;
        uVar16 = uVar16 << 0x20 - (uVar14 & 0x3f) | uVar16 >> (uVar14 & 0x3f);
        unaff_D6 = uVar16 << (uVar9 & 0x3f) | uVar16 >> 0x20 - (uVar9 & 0x3f);
        uVar16 = -0x80000000 << 0x20 - (uVar14 & 0x3f) | 0x80000000U >> (uVar14 & 0x3f);
        sVar15 = 3;
        do {
          puVar22 = puVar21;
          puVar19 = puVar18;
          uVar5 = CONCAT22(*puVar19,puVar19[4]);
          uVar12 = puVar19[8];
          uVar7 = puVar19[0x18];
          uVar6 = CONCAT22(uVar7,puVar19[0x1c]);
          uVar2 = (uint)bVar24;
          uVar1 = CONCAT22(puVar19[0x10],puVar19[0x14]) << 1;
          uVar3 = CONCAT22(uVar12,puVar19[0xc]) << 1;
          bVar24 = (*puVar19 & 0x8000) != 0;
          puVar22[0xc] = (short)(uVar3 | (puVar19[0x10] & 0x8000) != 0);
          puVar22[8] = (short)(uVar3 >> 0x10);
          puVar22[0x14] = (short)(uVar1 | (uVar7 & 0x8000) != 0);
          puVar22[0x10] = (short)(uVar1 >> 0x10);
          uVar1 = uVar11 & (uVar5 << 1 | (uint)((uVar12 & 0x8000) != 0)) | uVar4 & uVar5;
          puVar22[4] = (short)uVar1;
          *puVar22 = (short)(uVar1 >> 0x10);
          uVar1 = uVar16 & unaff_D6 | ~uVar16 & (~uVar13 & (uVar6 << 1 | uVar2) | uVar13 & uVar6);
          puVar22[0x1c] = (short)uVar1;
          puVar22[0x18] = (short)(uVar1 >> 0x10);
          unaff_D6 = unaff_D6 << 4 | unaff_D6 >> 0x1c;
          sVar15 = sVar15 + -1;
          puVar18 = puVar19 + 1;
          puVar21 = puVar22 + 1;
        } while (sVar15 != -1);
        puVar18 = puVar19 + 0x4d;
        puVar20 = (undefined2 *)(DAT_0001a534 + (int)puVar20);
        puVar21 = puVar22 + 0x1d;
        sVar17 = sVar17 + -1;
      } while (sVar17 != -1);
    }
    else {
      bVar24 = false;
      if (uVar12 == 3) {
        do {
          uVar12 = (ushort)(unaff_D6 >> 0x10);
          uVar16 = CONCAT22(uVar12,*puVar20) << 0x10 | (uint)uVar12;
          uVar16 = uVar16 << 0x20 - (uVar14 & 0x3f) | uVar16 >> (uVar14 & 0x3f);
          unaff_D6 = uVar16 << (uVar9 & 0x3f) | uVar16 >> 0x20 - (uVar9 & 0x3f);
          uVar16 = -0x80000000 << 0x20 - (uVar14 & 0x3f) | 0x80000000U >> (uVar14 & 0x3f);
          sVar15 = 3;
          do {
            puVar22 = puVar21;
            puVar19 = puVar18;
            uVar2 = CONCAT22(*puVar19,puVar19[4]);
            uVar12 = puVar19[8];
            uVar5 = CONCAT22(puVar19[0x10],puVar19[0x14]);
            uVar3 = (uint)bVar24;
            uVar1 = CONCAT22(uVar12,puVar19[0xc]) << 1;
            bVar24 = (*puVar19 & 0x8000) != 0;
            puVar22[0xc] = (short)(uVar1 | (puVar19[0x10] & 0x8000) != 0);
            puVar22[8] = (short)(uVar1 >> 0x10);
            uVar1 = uVar11 & (uVar2 << 1 | (uint)((uVar12 & 0x8000) != 0)) | uVar4 & uVar2;
            puVar22[4] = (short)uVar1;
            *puVar22 = (short)(uVar1 >> 0x10);
            uVar1 = uVar16 & unaff_D6 | ~uVar16 & (~uVar13 & (uVar5 << 1 | uVar3) | uVar13 & uVar5);
            puVar22[0x14] = (short)uVar1;
            puVar22[0x10] = (short)(uVar1 >> 0x10);
            unaff_D6 = unaff_D6 << 4 | unaff_D6 >> 0x1c;
            sVar15 = sVar15 + -1;
            puVar18 = puVar19 + 1;
            puVar21 = puVar22 + 1;
          } while (sVar15 != -1);
          puVar18 = puVar19 + 0x4d;
          puVar20 = (undefined2 *)(DAT_0001a534 + (int)puVar20);
          puVar21 = puVar22 + 0x15;
          sVar17 = sVar17 + -1;
        } while (sVar17 != -1);
      }
      else {
        bVar24 = uVar12 < 2;
        bVar23 = false;
        if (uVar12 == 2) {
          do {
            uVar12 = (ushort)(unaff_D6 >> 0x10);
            uVar16 = CONCAT22(uVar12,*puVar20) << 0x10 | (uint)uVar12;
            uVar16 = uVar16 << 0x20 - (uVar14 & 0x3f) | uVar16 >> (uVar14 & 0x3f);
            unaff_D6 = uVar16 << (uVar9 & 0x3f) | uVar16 >> 0x20 - (uVar9 & 0x3f);
            uVar16 = -0x80000000 << 0x20 - (uVar14 & 0x3f) | 0x80000000U >> (uVar14 & 0x3f);
            sVar15 = 3;
            do {
              puVar22 = puVar21;
              puVar19 = puVar18;
              uVar1 = CONCAT22(*puVar19,puVar19[4]);
              uVar2 = CONCAT22(puVar19[8],puVar19[0xc]);
              uVar3 = (uint)bVar23;
              bVar23 = (*puVar19 & 0x8000) != 0;
              uVar1 = uVar11 & (uVar1 << 1 | (uint)((puVar19[8] & 0x8000) != 0)) | uVar4 & uVar1;
              puVar22[4] = (short)uVar1;
              *puVar22 = (short)(uVar1 >> 0x10);
              uVar1 = uVar16 & unaff_D6 |
                      ~uVar16 & (~uVar13 & (uVar2 << 1 | uVar3) | uVar13 & uVar2);
              puVar22[0xc] = (short)uVar1;
              puVar22[8] = (short)(uVar1 >> 0x10);
              unaff_D6 = unaff_D6 << 4 | unaff_D6 >> 0x1c;
              sVar15 = sVar15 + -1;
              puVar18 = puVar19 + 1;
              puVar21 = puVar22 + 1;
            } while (sVar15 != -1);
            puVar18 = puVar19 + 0x4d;
            puVar20 = (undefined2 *)(DAT_0001a534 + (int)puVar20);
            puVar21 = puVar22 + 0xd;
            sVar17 = sVar17 + -1;
          } while (sVar17 != -1);
        }
        else {
          do {
            uVar12 = (ushort)(unaff_D6 >> 0x10);
            uVar11 = CONCAT22(uVar12,*puVar20) << 0x10 | (uint)uVar12;
            uVar11 = uVar11 << 0x20 - (uVar14 & 0x3f) | uVar11 >> (uVar14 & 0x3f);
            unaff_D6 = uVar11 << (uVar9 & 0x3f) | uVar11 >> 0x20 - (uVar9 & 0x3f);
            uVar11 = -0x80000000 << 0x20 - (uVar14 & 0x3f) | 0x80000000U >> (uVar14 & 0x3f);
            sVar15 = 3;
            bVar23 = bVar24;
            do {
              puVar22 = puVar21;
              puVar19 = puVar18;
              uVar16 = CONCAT22(*puVar19,puVar19[4]);
              bVar24 = (*puVar19 & 0x8000) != 0;
              uVar16 = uVar11 & unaff_D6 |
                       ~uVar11 & (~(uVar13 | uVar4) & (uVar16 << 1 | (uint)bVar23) |
                                 (uVar13 | uVar4) & uVar16);
              puVar22[4] = (short)uVar16;
              *puVar22 = (short)(uVar16 >> 0x10);
              unaff_D6 = unaff_D6 << 4 | unaff_D6 >> 0x1c;
              sVar15 = sVar15 + -1;
              puVar18 = puVar19 + 1;
              puVar21 = puVar22 + 1;
              bVar23 = bVar24;
            } while (sVar15 != -1);
            puVar18 = puVar19 + 0x4d;
            puVar20 = (undefined2 *)(DAT_0001a534 + (int)puVar20);
            puVar21 = puVar22 + 5;
            sVar17 = sVar17 + -1;
          } while (sVar17 != -1);
        }
      }
    }
    FUN_00013594(in_D0,uVar8,uVar26,uVar10,in_A0,in_A1);
    uVar25 = FUN_000123a0();
    in_A1 = extraout_A1;
    if ((uVar25 & 3) == 0) {
      in_A1 = extraout_A1 + 1;
    }
    uVar26 = uVar26 + 1;
    sVar17 = (short)(uVar25 >> 0x20);
    uVar8 = sVar17 - 1;
    in_A0 = extraout_A0;
    if (sVar17 == 0) {
      uVar8 = 0xf;
      in_A0 = extraout_A0 + -4;
    }
    in_D0 = (uint)uVar8;
    uVar8 = (short)uVar25 - 1;
  } while (uVar8 != 0xffff);
  return;
}


// ---------------------------------------------------------------
// FUN_000114ba @ 000114ba

void FUN_000114ba(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint in_D0;
  ushort uVar7;
  ushort in_D1w;
  ushort unaff_D2w;
  ushort uVar8;
  undefined4 unaff_D3;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  short sVar13;
  uint unaff_D6;
  uint uVar14;
  short sVar15;
  ushort *in_A0;
  ushort *puVar16;
  ushort *puVar17;
  ushort *extraout_A0;
  undefined2 *in_A1;
  undefined2 *puVar18;
  undefined2 *extraout_A1;
  undefined2 *puVar19;
  undefined2 *puVar20;
  bool bVar21;
  bool bVar22;
  ulonglong uVar23;
  
  do {
    uVar9 = 0xffffffff >> (in_D0 & 0x3f);
    uVar4 = ~uVar9;
    uVar7 = 0x10 - (short)in_D0;
    uVar10 = 1;
    bVar22 = true;
    uVar8 = unaff_D2w - uVar7;
    if (uVar7 <= unaff_D2w && uVar8 != 0) {
      do {
        uVar10 = uVar10 + 1;
        bVar22 = (bool)(bVar22 ^ 1);
        bVar21 = 0xf < uVar8;
        uVar8 = uVar8 - 0x10;
      } while (bVar21 && uVar8 != 0);
    }
    uVar11 = ~(-1 << (-uVar8 & 0x3f));
    uVar7 = uVar8 + 0x1f;
    uVar10 = uVar10 >> 1;
    if (bVar22) {
      uVar10 = uVar10 + 1;
      uVar7 = uVar8 + 0xf;
      uVar11 = uVar11 << 0x10 | uVar11 >> 0x10 | 0xffff;
    }
    uVar8 = 3 - (in_D1w & 3);
    sVar15 = (short)unaff_D3;
    uVar12 = (uint)uVar7;
    puVar19 = (undefined2 *)&DAT_0000d8f0;
    bVar22 = false;
    puVar16 = in_A0;
    puVar18 = in_A1;
    if (uVar10 == 4) {
      do {
        uVar10 = (ushort)(unaff_D6 >> 0x10);
        uVar14 = CONCAT22(uVar10,*puVar18) << 0x10 | (uint)uVar10;
        uVar14 = uVar14 << 0x20 - (uVar12 & 0x3f) | uVar14 >> (uVar12 & 0x3f);
        unaff_D6 = uVar14 << (uVar8 & 0x3f) | uVar14 >> 0x20 - (uVar8 & 0x3f);
        uVar14 = -0x80000000 << 0x20 - (uVar12 & 0x3f) | 0x80000000U >> (uVar12 & 0x3f);
        sVar13 = 3;
        do {
          puVar20 = puVar19;
          puVar17 = puVar16;
          uVar5 = CONCAT22(*puVar17,puVar17[4]);
          uVar10 = puVar17[8];
          uVar7 = puVar17[0x18];
          uVar6 = CONCAT22(uVar7,puVar17[0x1c]);
          uVar2 = (uint)bVar22;
          uVar1 = CONCAT22(puVar17[0x10],puVar17[0x14]) << 1;
          uVar3 = CONCAT22(uVar10,puVar17[0xc]) << 1;
          bVar22 = (*puVar17 & 0x8000) != 0;
          puVar20[0xc] = (short)(uVar3 | (puVar17[0x10] & 0x8000) != 0);
          puVar20[8] = (short)(uVar3 >> 0x10);
          puVar20[0x14] = (short)(uVar1 | (uVar7 & 0x8000) != 0);
          puVar20[0x10] = (short)(uVar1 >> 0x10);
          uVar1 = uVar9 & (uVar5 << 1 | (uint)((uVar10 & 0x8000) != 0)) | uVar4 & uVar5;
          puVar20[4] = (short)uVar1;
          *puVar20 = (short)(uVar1 >> 0x10);
          uVar1 = uVar14 & unaff_D6 | ~uVar14 & (~uVar11 & (uVar6 << 1 | uVar2) | uVar11 & uVar6);
          puVar20[0x1c] = (short)uVar1;
          puVar20[0x18] = (short)(uVar1 >> 0x10);
          unaff_D6 = unaff_D6 << 4 | unaff_D6 >> 0x1c;
          sVar13 = sVar13 + -1;
          puVar16 = puVar17 + 1;
          puVar19 = puVar20 + 1;
        } while (sVar13 != -1);
        puVar16 = puVar17 + 0x4d;
        puVar18 = (undefined2 *)(DAT_0001a534 + (int)puVar18);
        puVar19 = puVar20 + 0x1d;
        sVar15 = sVar15 + -1;
      } while (sVar15 != -1);
    }
    else {
      bVar22 = false;
      if (uVar10 == 3) {
        do {
          uVar10 = (ushort)(unaff_D6 >> 0x10);
          uVar14 = CONCAT22(uVar10,*puVar18) << 0x10 | (uint)uVar10;
          uVar14 = uVar14 << 0x20 - (uVar12 & 0x3f) | uVar14 >> (uVar12 & 0x3f);
          unaff_D6 = uVar14 << (uVar8 & 0x3f) | uVar14 >> 0x20 - (uVar8 & 0x3f);
          uVar14 = -0x80000000 << 0x20 - (uVar12 & 0x3f) | 0x80000000U >> (uVar12 & 0x3f);
          sVar13 = 3;
          do {
            puVar20 = puVar19;
            puVar17 = puVar16;
            uVar2 = CONCAT22(*puVar17,puVar17[4]);
            uVar10 = puVar17[8];
            uVar5 = CONCAT22(puVar17[0x10],puVar17[0x14]);
            uVar3 = (uint)bVar22;
            uVar1 = CONCAT22(uVar10,puVar17[0xc]) << 1;
            bVar22 = (*puVar17 & 0x8000) != 0;
            puVar20[0xc] = (short)(uVar1 | (puVar17[0x10] & 0x8000) != 0);
            puVar20[8] = (short)(uVar1 >> 0x10);
            uVar1 = uVar9 & (uVar2 << 1 | (uint)((uVar10 & 0x8000) != 0)) | uVar4 & uVar2;
            puVar20[4] = (short)uVar1;
            *puVar20 = (short)(uVar1 >> 0x10);
            uVar1 = uVar14 & unaff_D6 | ~uVar14 & (~uVar11 & (uVar5 << 1 | uVar3) | uVar11 & uVar5);
            puVar20[0x14] = (short)uVar1;
            puVar20[0x10] = (short)(uVar1 >> 0x10);
            unaff_D6 = unaff_D6 << 4 | unaff_D6 >> 0x1c;
            sVar13 = sVar13 + -1;
            puVar16 = puVar17 + 1;
            puVar19 = puVar20 + 1;
          } while (sVar13 != -1);
          puVar16 = puVar17 + 0x4d;
          puVar18 = (undefined2 *)(DAT_0001a534 + (int)puVar18);
          puVar19 = puVar20 + 0x15;
          sVar15 = sVar15 + -1;
        } while (sVar15 != -1);
      }
      else {
        bVar22 = uVar10 < 2;
        bVar21 = false;
        if (uVar10 == 2) {
          do {
            uVar10 = (ushort)(unaff_D6 >> 0x10);
            uVar14 = CONCAT22(uVar10,*puVar18) << 0x10 | (uint)uVar10;
            uVar14 = uVar14 << 0x20 - (uVar12 & 0x3f) | uVar14 >> (uVar12 & 0x3f);
            unaff_D6 = uVar14 << (uVar8 & 0x3f) | uVar14 >> 0x20 - (uVar8 & 0x3f);
            uVar14 = -0x80000000 << 0x20 - (uVar12 & 0x3f) | 0x80000000U >> (uVar12 & 0x3f);
            sVar13 = 3;
            do {
              puVar20 = puVar19;
              puVar17 = puVar16;
              uVar1 = CONCAT22(*puVar17,puVar17[4]);
              uVar2 = CONCAT22(puVar17[8],puVar17[0xc]);
              uVar3 = (uint)bVar21;
              bVar21 = (*puVar17 & 0x8000) != 0;
              uVar1 = uVar9 & (uVar1 << 1 | (uint)((puVar17[8] & 0x8000) != 0)) | uVar4 & uVar1;
              puVar20[4] = (short)uVar1;
              *puVar20 = (short)(uVar1 >> 0x10);
              uVar1 = uVar14 & unaff_D6 |
                      ~uVar14 & (~uVar11 & (uVar2 << 1 | uVar3) | uVar11 & uVar2);
              puVar20[0xc] = (short)uVar1;
              puVar20[8] = (short)(uVar1 >> 0x10);
              unaff_D6 = unaff_D6 << 4 | unaff_D6 >> 0x1c;
              sVar13 = sVar13 + -1;
              puVar16 = puVar17 + 1;
              puVar19 = puVar20 + 1;
            } while (sVar13 != -1);
            puVar16 = puVar17 + 0x4d;
            puVar18 = (undefined2 *)(DAT_0001a534 + (int)puVar18);
            puVar19 = puVar20 + 0xd;
            sVar15 = sVar15 + -1;
          } while (sVar15 != -1);
        }
        else {
          do {
            uVar10 = (ushort)(unaff_D6 >> 0x10);
            uVar9 = CONCAT22(uVar10,*puVar18) << 0x10 | (uint)uVar10;
            uVar9 = uVar9 << 0x20 - (uVar12 & 0x3f) | uVar9 >> (uVar12 & 0x3f);
            unaff_D6 = uVar9 << (uVar8 & 0x3f) | uVar9 >> 0x20 - (uVar8 & 0x3f);
            uVar9 = -0x80000000 << 0x20 - (uVar12 & 0x3f) | 0x80000000U >> (uVar12 & 0x3f);
            sVar13 = 3;
            bVar21 = bVar22;
            do {
              puVar20 = puVar19;
              puVar17 = puVar16;
              uVar14 = CONCAT22(*puVar17,puVar17[4]);
              bVar22 = (*puVar17 & 0x8000) != 0;
              uVar14 = uVar9 & unaff_D6 |
                       ~uVar9 & (~(uVar11 | uVar4) & (uVar14 << 1 | (uint)bVar21) |
                                (uVar11 | uVar4) & uVar14);
              puVar20[4] = (short)uVar14;
              *puVar20 = (short)(uVar14 >> 0x10);
              unaff_D6 = unaff_D6 << 4 | unaff_D6 >> 0x1c;
              sVar13 = sVar13 + -1;
              puVar16 = puVar17 + 1;
              puVar19 = puVar20 + 1;
              bVar21 = bVar22;
            } while (sVar13 != -1);
            puVar16 = puVar17 + 0x4d;
            puVar18 = (undefined2 *)(DAT_0001a534 + (int)puVar18);
            puVar19 = puVar20 + 5;
            sVar15 = sVar15 + -1;
          } while (sVar15 != -1);
        }
      }
    }
    FUN_00013594(in_D0,in_D1w,unaff_D2w,unaff_D3,in_A0,in_A1);
    uVar23 = FUN_000123a0();
    in_A1 = extraout_A1;
    if ((uVar23 & 3) == 0) {
      in_A1 = extraout_A1 + 1;
    }
    unaff_D2w = unaff_D2w + 1;
    sVar15 = (short)(uVar23 >> 0x20);
    uVar10 = sVar15 - 1;
    in_A0 = extraout_A0;
    if (sVar15 == 0) {
      uVar10 = 0xf;
      in_A0 = extraout_A0 + -4;
    }
    in_D0 = (uint)uVar10;
    in_D1w = (short)uVar23 - 1;
  } while (in_D1w != 0xffff);
  return;
}


// ---------------------------------------------------------------
// FUN_000117de @ 000117de

void FUN_000117de(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint in_D0;
  undefined4 uVar10;
  short in_D1w;
  short extraout_D1w;
  short sVar11;
  short unaff_D2w;
  ushort uVar12;
  ushort uVar13;
  short unaff_D3w;
  uint uVar14;
  uint uVar15;
  ushort uVar16;
  uint uVar17;
  short sVar18;
  uint uVar19;
  short sVar20;
  undefined2 *in_A0;
  undefined2 *puVar21;
  undefined2 *puVar22;
  undefined2 *extraout_A0;
  undefined2 *puVar23;
  undefined2 *puVar24;
  undefined2 *extraout_A1;
  undefined2 *puVar25;
  undefined2 *puVar26;
  undefined2 *puVar27;
  bool bVar28;
  bool bVar29;
  
  DAT_0001a53e = 1;
  sVar11 = in_D1w * 4 + -1;
  uVar12 = unaff_D2w << 2;
  puVar25 = in_A0 + -0x4000;
  uVar14 = (uint)(ushort)(unaff_D3w - 1);
  do {
    uVar19 = -0x80000000 << 0x20 - (in_D0 & 0x3f) | 0x80000000U >> (in_D0 & 0x3f);
    uVar15 = 0xffffffff >> (in_D0 & 0x3f);
    uVar8 = ~(uVar15 >> 1);
    uVar16 = 1;
    bVar29 = true;
    uVar5 = 0x10 - (short)in_D0;
    uVar13 = uVar12 - uVar5;
    if (uVar5 <= uVar12 && uVar13 != 0) {
      do {
        uVar16 = uVar16 + 1;
        bVar29 = (bool)(bVar29 ^ 1);
        bVar28 = 0xf < uVar13;
        uVar13 = uVar13 - 0x10;
      } while (bVar28 && uVar13 != 0);
    }
    uVar17 = ~(-1 << (-uVar13 & 0x3f));
    uVar16 = uVar16 >> 1;
    if (bVar29) {
      uVar16 = uVar16 + 1;
      uVar17 = uVar17 << 0x10 | uVar17 >> 0x10 | 0xffff;
    }
    sVar20 = (short)uVar14;
    if (uVar16 == 2) {
      puVar26 = (undefined2 *)&DAT_0000d8f0;
      puVar21 = in_A0;
      puVar23 = puVar25;
      do {
        sVar18 = 3;
        do {
          puVar27 = puVar26;
          puVar24 = puVar23;
          puVar22 = puVar21;
          uVar16 = puVar22[4];
          uVar6 = CONCAT22(*puVar22,uVar16);
          uVar1 = puVar22[8];
          uVar2 = puVar22[0xc];
          uVar6 = ~uVar19 & ((uVar6 & uVar15) >> 1 | uVar8 & uVar6) |
                  uVar19 & CONCAT22(*puVar24,puVar24[4]);
          puVar27[4] = (short)uVar6;
          *puVar27 = (short)(uVar6 >> 0x10);
          uVar6 = ~uVar17 & ((uint)((uVar16 & 1) != 0) << 0x1f | CONCAT22(uVar1,uVar2) >> 1) |
                  uVar17 & CONCAT22(uVar1,uVar2);
          puVar27[0xc] = (short)uVar6;
          puVar27[8] = (short)(uVar6 >> 0x10);
          sVar18 = sVar18 + -1;
          puVar21 = puVar22 + 1;
          puVar23 = puVar24 + 1;
          puVar26 = puVar27 + 1;
        } while (sVar18 != -1);
        puVar21 = puVar22 + 0x4d;
        puVar23 = puVar24 + 0x4d;
        puVar26 = puVar27 + 0xd;
        sVar20 = sVar20 + -1;
      } while (sVar20 != -1);
    }
    else if (uVar16 == 3) {
      puVar26 = (undefined2 *)&DAT_0000d8f0;
      puVar21 = in_A0;
      puVar23 = puVar25;
      do {
        sVar18 = 3;
        do {
          puVar27 = puVar26;
          puVar24 = puVar23;
          puVar22 = puVar21;
          uVar1 = *puVar24;
          uVar2 = puVar24[4];
          uVar16 = puVar22[4];
          uVar7 = CONCAT22(*puVar22,uVar16);
          uVar5 = puVar22[0xc];
          uVar3 = puVar22[0x10];
          uVar4 = puVar22[0x14];
          uVar6 = CONCAT22(puVar22[8],uVar5) >> 1;
          puVar27[0xc] = (short)uVar6;
          puVar27[8] = (short)(((uint)((uVar16 & 1) != 0) << 0x1f | uVar6) >> 0x10);
          uVar6 = ~uVar19 & ((uVar15 & uVar7) >> 1 | uVar8 & uVar7) | uVar19 & CONCAT22(uVar1,uVar2)
          ;
          puVar27[4] = (short)uVar6;
          *puVar27 = (short)(uVar6 >> 0x10);
          uVar6 = ~uVar17 & ((uint)((uVar5 & 1) != 0) << 0x1f | CONCAT22(uVar3,uVar4) >> 1) |
                  uVar17 & CONCAT22(uVar3,uVar4);
          puVar27[0x14] = (short)uVar6;
          puVar27[0x10] = (short)(uVar6 >> 0x10);
          sVar18 = sVar18 + -1;
          puVar21 = puVar22 + 1;
          puVar23 = puVar24 + 1;
          puVar26 = puVar27 + 1;
        } while (sVar18 != -1);
        puVar21 = puVar22 + 0x4d;
        puVar23 = puVar24 + 0x4d;
        puVar26 = puVar27 + 0x15;
        sVar20 = sVar20 + -1;
      } while (sVar20 != -1);
    }
    else {
      bVar29 = uVar16 < 4;
      if (uVar16 == 4) {
        puVar26 = (undefined2 *)&DAT_0000d8f0;
        puVar21 = in_A0;
        puVar23 = puVar25;
        do {
          sVar18 = 3;
          do {
            puVar27 = puVar26;
            puVar24 = puVar23;
            puVar22 = puVar21;
            uVar1 = *puVar24;
            uVar2 = puVar24[4];
            uVar16 = puVar22[4];
            uVar9 = CONCAT22(*puVar22,uVar16);
            uVar5 = puVar22[0xc];
            uVar13 = puVar22[0x14];
            uVar3 = puVar22[0x18];
            uVar4 = puVar22[0x1c];
            uVar6 = CONCAT22(puVar22[8],uVar5) >> 1;
            uVar7 = CONCAT22(puVar22[0x10],uVar13) >> 1;
            puVar27[0xc] = (short)uVar6;
            puVar27[8] = (short)(((uint)((uVar16 & 1) != 0) << 0x1f | uVar6) >> 0x10);
            puVar27[0x14] = (short)uVar7;
            puVar27[0x10] = (short)(((uint)((uVar5 & 1) != 0) << 0x1f | uVar7) >> 0x10);
            uVar6 = ~uVar19 & ((uVar15 & uVar9) >> 1 | uVar8 & uVar9) |
                    uVar19 & CONCAT22(uVar1,uVar2);
            puVar27[4] = (short)uVar6;
            *puVar27 = (short)(uVar6 >> 0x10);
            uVar6 = ~uVar17 & ((uint)((uVar13 & 1) != 0) << 0x1f | CONCAT22(uVar3,uVar4) >> 1) |
                    uVar17 & CONCAT22(uVar3,uVar4);
            puVar27[0x1c] = (short)uVar6;
            puVar27[0x18] = (short)(uVar6 >> 0x10);
            sVar18 = sVar18 + -1;
            puVar21 = puVar22 + 1;
            puVar23 = puVar24 + 1;
            puVar26 = puVar27 + 1;
          } while (sVar18 != -1);
          puVar21 = puVar22 + 0x4d;
          puVar23 = puVar24 + 0x4d;
          puVar26 = puVar27 + 0x1d;
          sVar20 = sVar20 + -1;
        } while (sVar20 != -1);
      }
      else {
        puVar26 = (undefined2 *)&DAT_0000d8f0;
        puVar21 = in_A0;
        puVar23 = puVar25;
        do {
          sVar18 = 3;
          bVar28 = bVar29;
          do {
            puVar27 = puVar26;
            puVar24 = puVar23;
            puVar22 = puVar21;
            uVar15 = CONCAT22(*puVar22,puVar22[4]);
            bVar29 = (puVar22[4] & 1) != 0;
            uVar15 = ~uVar19 & (~(uVar17 | uVar8) & ((uint)bVar28 << 0x1f | uVar15 >> 1) |
                               (uVar17 | uVar8) & uVar15) | uVar19 & CONCAT22(*puVar24,puVar24[4]);
            puVar27[4] = (short)uVar15;
            *puVar27 = (short)(uVar15 >> 0x10);
            sVar18 = sVar18 + -1;
            puVar21 = puVar22 + 1;
            puVar23 = puVar24 + 1;
            puVar26 = puVar27 + 1;
            bVar28 = bVar29;
          } while (sVar18 != -1);
          puVar21 = puVar22 + 0x4d;
          puVar23 = puVar24 + 0x4d;
          puVar26 = puVar27 + 5;
          sVar20 = sVar20 + -1;
        } while (sVar20 != -1);
      }
    }
    FUN_00013594(in_D0,sVar11,uVar12,uVar14,in_A0,puVar25);
    uVar10 = FUN_000123a0();
    uVar12 = uVar12 - DAT_0001a53e;
    uVar16 = (short)uVar10 + 1;
    in_D0 = CONCAT22((short)((uint)uVar10 >> 0x10),uVar16) & 0xffff000f;
    in_A0 = extraout_A0;
    puVar25 = extraout_A1;
    if ((uVar16 & 0xf) == 0) {
      puVar25 = extraout_A1 + 4;
      in_A0 = extraout_A0 + 4;
    }
    sVar11 = extraout_D1w + -1;
  } while (sVar11 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000117fe @ 000117fe

void FUN_000117fe(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint in_D0;
  short in_D1w;
  ushort unaff_D2w;
  ushort uVar10;
  undefined4 unaff_D3;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  short sVar14;
  uint uVar15;
  short sVar16;
  undefined2 *in_A0;
  undefined2 *puVar17;
  undefined2 *puVar18;
  undefined2 *extraout_A0;
  undefined2 *in_A1;
  undefined2 *puVar19;
  undefined2 *puVar20;
  undefined2 *extraout_A1;
  undefined2 *puVar21;
  undefined2 *puVar22;
  bool bVar23;
  bool bVar24;
  undefined8 uVar25;
  
  do {
    uVar15 = -0x80000000 << 0x20 - (in_D0 & 0x3f) | 0x80000000U >> (in_D0 & 0x3f);
    uVar11 = 0xffffffff >> (in_D0 & 0x3f);
    uVar8 = ~(uVar11 >> 1);
    uVar12 = 1;
    bVar24 = true;
    uVar5 = 0x10 - (short)in_D0;
    uVar10 = unaff_D2w - uVar5;
    if (uVar5 <= unaff_D2w && uVar10 != 0) {
      do {
        uVar12 = uVar12 + 1;
        bVar24 = (bool)(bVar24 ^ 1);
        bVar23 = 0xf < uVar10;
        uVar10 = uVar10 - 0x10;
      } while (bVar23 && uVar10 != 0);
    }
    uVar13 = ~(-1 << (-uVar10 & 0x3f));
    uVar12 = uVar12 >> 1;
    if (bVar24) {
      uVar12 = uVar12 + 1;
      uVar13 = uVar13 << 0x10 | uVar13 >> 0x10 | 0xffff;
    }
    sVar16 = (short)unaff_D3;
    if (uVar12 == 2) {
      puVar21 = (undefined2 *)&DAT_0000d8f0;
      puVar17 = in_A0;
      puVar19 = in_A1;
      do {
        sVar14 = 3;
        do {
          puVar22 = puVar21;
          puVar20 = puVar19;
          puVar18 = puVar17;
          uVar12 = puVar18[4];
          uVar6 = CONCAT22(*puVar18,uVar12);
          uVar1 = puVar18[8];
          uVar2 = puVar18[0xc];
          uVar6 = ~uVar15 & ((uVar6 & uVar11) >> 1 | uVar8 & uVar6) |
                  uVar15 & CONCAT22(*puVar20,puVar20[4]);
          puVar22[4] = (short)uVar6;
          *puVar22 = (short)(uVar6 >> 0x10);
          uVar6 = ~uVar13 & ((uint)((uVar12 & 1) != 0) << 0x1f | CONCAT22(uVar1,uVar2) >> 1) |
                  uVar13 & CONCAT22(uVar1,uVar2);
          puVar22[0xc] = (short)uVar6;
          puVar22[8] = (short)(uVar6 >> 0x10);
          sVar14 = sVar14 + -1;
          puVar17 = puVar18 + 1;
          puVar19 = puVar20 + 1;
          puVar21 = puVar22 + 1;
        } while (sVar14 != -1);
        puVar17 = puVar18 + 0x4d;
        puVar19 = puVar20 + 0x4d;
        puVar21 = puVar22 + 0xd;
        sVar16 = sVar16 + -1;
      } while (sVar16 != -1);
    }
    else if (uVar12 == 3) {
      puVar21 = (undefined2 *)&DAT_0000d8f0;
      puVar17 = in_A0;
      puVar19 = in_A1;
      do {
        sVar14 = 3;
        do {
          puVar22 = puVar21;
          puVar20 = puVar19;
          puVar18 = puVar17;
          uVar1 = *puVar20;
          uVar2 = puVar20[4];
          uVar12 = puVar18[4];
          uVar7 = CONCAT22(*puVar18,uVar12);
          uVar5 = puVar18[0xc];
          uVar3 = puVar18[0x10];
          uVar4 = puVar18[0x14];
          uVar6 = CONCAT22(puVar18[8],uVar5) >> 1;
          puVar22[0xc] = (short)uVar6;
          puVar22[8] = (short)(((uint)((uVar12 & 1) != 0) << 0x1f | uVar6) >> 0x10);
          uVar6 = ~uVar15 & ((uVar11 & uVar7) >> 1 | uVar8 & uVar7) | uVar15 & CONCAT22(uVar1,uVar2)
          ;
          puVar22[4] = (short)uVar6;
          *puVar22 = (short)(uVar6 >> 0x10);
          uVar6 = ~uVar13 & ((uint)((uVar5 & 1) != 0) << 0x1f | CONCAT22(uVar3,uVar4) >> 1) |
                  uVar13 & CONCAT22(uVar3,uVar4);
          puVar22[0x14] = (short)uVar6;
          puVar22[0x10] = (short)(uVar6 >> 0x10);
          sVar14 = sVar14 + -1;
          puVar17 = puVar18 + 1;
          puVar19 = puVar20 + 1;
          puVar21 = puVar22 + 1;
        } while (sVar14 != -1);
        puVar17 = puVar18 + 0x4d;
        puVar19 = puVar20 + 0x4d;
        puVar21 = puVar22 + 0x15;
        sVar16 = sVar16 + -1;
      } while (sVar16 != -1);
    }
    else {
      bVar24 = uVar12 < 4;
      if (uVar12 == 4) {
        puVar21 = (undefined2 *)&DAT_0000d8f0;
        puVar17 = in_A0;
        puVar19 = in_A1;
        do {
          sVar14 = 3;
          do {
            puVar22 = puVar21;
            puVar20 = puVar19;
            puVar18 = puVar17;
            uVar1 = *puVar20;
            uVar2 = puVar20[4];
            uVar12 = puVar18[4];
            uVar9 = CONCAT22(*puVar18,uVar12);
            uVar5 = puVar18[0xc];
            uVar10 = puVar18[0x14];
            uVar3 = puVar18[0x18];
            uVar4 = puVar18[0x1c];
            uVar6 = CONCAT22(puVar18[8],uVar5) >> 1;
            uVar7 = CONCAT22(puVar18[0x10],uVar10) >> 1;
            puVar22[0xc] = (short)uVar6;
            puVar22[8] = (short)(((uint)((uVar12 & 1) != 0) << 0x1f | uVar6) >> 0x10);
            puVar22[0x14] = (short)uVar7;
            puVar22[0x10] = (short)(((uint)((uVar5 & 1) != 0) << 0x1f | uVar7) >> 0x10);
            uVar6 = ~uVar15 & ((uVar11 & uVar9) >> 1 | uVar8 & uVar9) |
                    uVar15 & CONCAT22(uVar1,uVar2);
            puVar22[4] = (short)uVar6;
            *puVar22 = (short)(uVar6 >> 0x10);
            uVar6 = ~uVar13 & ((uint)((uVar10 & 1) != 0) << 0x1f | CONCAT22(uVar3,uVar4) >> 1) |
                    uVar13 & CONCAT22(uVar3,uVar4);
            puVar22[0x1c] = (short)uVar6;
            puVar22[0x18] = (short)(uVar6 >> 0x10);
            sVar14 = sVar14 + -1;
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            puVar21 = puVar22 + 1;
          } while (sVar14 != -1);
          puVar17 = puVar18 + 0x4d;
          puVar19 = puVar20 + 0x4d;
          puVar21 = puVar22 + 0x1d;
          sVar16 = sVar16 + -1;
        } while (sVar16 != -1);
      }
      else {
        puVar21 = (undefined2 *)&DAT_0000d8f0;
        puVar17 = in_A0;
        puVar19 = in_A1;
        do {
          sVar14 = 3;
          bVar23 = bVar24;
          do {
            puVar22 = puVar21;
            puVar20 = puVar19;
            puVar18 = puVar17;
            uVar11 = CONCAT22(*puVar18,puVar18[4]);
            bVar24 = (puVar18[4] & 1) != 0;
            uVar11 = ~uVar15 & (~(uVar13 | uVar8) & ((uint)bVar23 << 0x1f | uVar11 >> 1) |
                               (uVar13 | uVar8) & uVar11) | uVar15 & CONCAT22(*puVar20,puVar20[4]);
            puVar22[4] = (short)uVar11;
            *puVar22 = (short)(uVar11 >> 0x10);
            sVar14 = sVar14 + -1;
            puVar17 = puVar18 + 1;
            puVar19 = puVar20 + 1;
            puVar21 = puVar22 + 1;
            bVar23 = bVar24;
          } while (sVar14 != -1);
          puVar17 = puVar18 + 0x4d;
          puVar19 = puVar20 + 0x4d;
          puVar21 = puVar22 + 5;
          sVar16 = sVar16 + -1;
        } while (sVar16 != -1);
      }
    }
    FUN_00013594(in_D0,in_D1w,unaff_D2w,unaff_D3,in_A0,in_A1);
    uVar25 = FUN_000123a0();
    unaff_D2w = unaff_D2w - DAT_0001a53e;
    uVar12 = (short)((ulonglong)uVar25 >> 0x20) + 1;
    in_D0 = CONCAT22((short)((ulonglong)uVar25 >> 0x30),uVar12) & 0xffff000f;
    in_A0 = extraout_A0;
    in_A1 = extraout_A1;
    if ((uVar12 & 0xf) == 0) {
      in_A1 = extraout_A1 + 4;
      in_A0 = extraout_A0 + 4;
    }
    in_D1w = (short)uVar25 + -1;
  } while (in_D1w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011ada @ 00011ada

void FUN_00011ada(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint in_D0;
  short in_D1w;
  short extraout_D1w;
  short sVar9;
  short unaff_D2w;
  ushort uVar10;
  ushort uVar11;
  short unaff_D3w;
  uint uVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  short sVar16;
  uint uVar17;
  short sVar18;
  ushort *in_A0;
  ushort *puVar19;
  ushort *puVar20;
  ushort *extraout_A0;
  ushort *puVar21;
  ushort *puVar22;
  ushort *extraout_A1;
  ushort *puVar23;
  undefined2 *puVar24;
  undefined2 *puVar25;
  bool bVar26;
  bool bVar27;
  
  DAT_0001a53e = 1;
  sVar9 = in_D1w * 4 + -1;
  uVar10 = unaff_D2w << 2;
  puVar23 = in_A0 + -0x4000;
  uVar12 = (uint)(ushort)(unaff_D3w - 1);
  do {
    uVar13 = 0xffffffff >> (in_D0 & 0x3f);
    uVar7 = ~uVar13;
    uVar14 = 1;
    bVar27 = true;
    uVar4 = 0x10 - (short)in_D0;
    uVar11 = uVar10 - uVar4;
    if (uVar4 <= uVar10 && uVar11 != 0) {
      do {
        uVar14 = uVar14 + 1;
        bVar27 = (bool)(bVar27 ^ 1);
        bVar26 = 0xf < uVar11;
        uVar11 = uVar11 - 0x10;
      } while (bVar26 && uVar11 != 0);
    }
    uVar15 = ~(-1 << (-uVar11 & 0x3f));
    uVar4 = uVar11 + 0x1f;
    uVar14 = uVar14 >> 1;
    if (bVar27) {
      uVar14 = uVar14 + 1;
      uVar4 = uVar11 + 0xf;
      uVar15 = uVar15 << 0x10 | uVar15 >> 0x10 | 0xffff;
    }
    uVar17 = -0x80000000 << 0x20 - (uVar4 & 0x3f) | 0x80000000U >> (uVar4 & 0x3f);
    sVar18 = (short)uVar12;
    if (uVar14 == 2) {
      puVar24 = (undefined2 *)&DAT_0000d8f0;
      bVar27 = false;
      puVar19 = in_A0;
      puVar21 = puVar23;
      do {
        sVar16 = 3;
        do {
          puVar25 = puVar24;
          puVar22 = puVar21;
          puVar20 = puVar19;
          uVar14 = puVar22[8];
          uVar4 = puVar22[0xc];
          uVar5 = CONCAT22(*puVar20,puVar20[4]);
          uVar8 = CONCAT22(puVar20[8],puVar20[0xc]);
          uVar6 = (uint)bVar27;
          bVar27 = (*puVar20 & 0x8000) != 0;
          uVar5 = uVar13 & (uVar5 << 1 | (uint)((puVar20[8] & 0x8000) != 0)) | uVar7 & uVar5;
          puVar25[4] = (short)uVar5;
          *puVar25 = (short)(uVar5 >> 0x10);
          uVar5 = ~uVar17 & (~uVar15 & (uVar8 << 1 | uVar6) | uVar15 & uVar8) |
                  uVar17 & CONCAT22(uVar14,uVar4);
          puVar25[0xc] = (short)uVar5;
          puVar25[8] = (short)(uVar5 >> 0x10);
          sVar16 = sVar16 + -1;
          puVar19 = puVar20 + 1;
          puVar21 = puVar22 + 1;
          puVar24 = puVar25 + 1;
        } while (sVar16 != -1);
        puVar19 = puVar20 + 0x4d;
        puVar21 = puVar22 + 0x4d;
        puVar24 = puVar25 + 0xd;
        sVar18 = sVar18 + -1;
      } while (sVar18 != -1);
    }
    else if (uVar14 == 3) {
      puVar24 = (undefined2 *)&DAT_0000d8f0;
      puVar19 = in_A0;
      puVar21 = puVar23;
      do {
        sVar16 = 3;
        do {
          puVar25 = puVar24;
          puVar22 = puVar21;
          puVar20 = puVar19;
          uVar4 = puVar22[0x10];
          uVar11 = puVar22[0x14];
          uVar14 = *puVar20;
          uVar1 = puVar20[4];
          uVar2 = puVar20[8];
          uVar6 = CONCAT22(puVar20[0x10],puVar20[0x14]);
          uVar5 = CONCAT22(uVar2,puVar20[0xc]) << 1;
          puVar25[0xc] = (short)(uVar5 | (short)puVar20[0x10] < 0);
          puVar25[8] = (short)(uVar5 >> 0x10);
          uVar5 = uVar13 & (CONCAT22(uVar14,uVar1) << 1 | (uint)((uVar2 & 0x8000) != 0)) |
                  uVar7 & CONCAT22(uVar14,uVar1);
          puVar25[4] = (short)uVar5;
          *puVar25 = (short)(uVar5 >> 0x10);
          uVar5 = ~uVar17 & (~uVar15 & uVar6 << 1 | uVar15 & uVar6) |
                  uVar17 & CONCAT22(uVar4,uVar11);
          puVar25[0x14] = (short)uVar5;
          puVar25[0x10] = (short)(uVar5 >> 0x10);
          sVar16 = sVar16 + -1;
          puVar19 = puVar20 + 1;
          puVar21 = puVar22 + 1;
          puVar24 = puVar25 + 1;
        } while (sVar16 != -1);
        puVar19 = puVar20 + 0x4d;
        puVar21 = puVar22 + 0x4d;
        puVar24 = puVar25 + 0x15;
        sVar18 = sVar18 + -1;
      } while (sVar18 != -1);
    }
    else {
      bVar27 = uVar14 < 4;
      if (uVar14 == 4) {
        puVar24 = (undefined2 *)&DAT_0000d8f0;
        puVar19 = in_A0;
        puVar21 = puVar23;
        do {
          sVar16 = 3;
          do {
            puVar25 = puVar24;
            puVar22 = puVar21;
            puVar20 = puVar19;
            uVar4 = puVar22[0x18];
            uVar11 = puVar22[0x1c];
            uVar14 = *puVar20;
            uVar1 = puVar20[4];
            uVar2 = puVar20[8];
            uVar3 = puVar20[0x18];
            uVar8 = CONCAT22(uVar3,puVar20[0x1c]);
            uVar5 = CONCAT22(puVar20[0x10],puVar20[0x14]) << 1;
            uVar6 = CONCAT22(uVar2,puVar20[0xc]) << 1;
            puVar25[0xc] = (short)(uVar6 | (puVar20[0x10] & 0x8000) != 0);
            puVar25[8] = (short)(uVar6 >> 0x10);
            puVar25[0x14] = (short)(uVar5 | (short)uVar3 < 0);
            puVar25[0x10] = (short)(uVar5 >> 0x10);
            uVar5 = uVar13 & (CONCAT22(uVar14,uVar1) << 1 | (uint)((uVar2 & 0x8000) != 0)) |
                    uVar7 & CONCAT22(uVar14,uVar1);
            puVar25[4] = (short)uVar5;
            *puVar25 = (short)(uVar5 >> 0x10);
            uVar5 = ~uVar17 & (~uVar15 & uVar8 << 1 | uVar15 & uVar8) |
                    uVar17 & CONCAT22(uVar4,uVar11);
            puVar25[0x1c] = (short)uVar5;
            puVar25[0x18] = (short)(uVar5 >> 0x10);
            sVar16 = sVar16 + -1;
            puVar19 = puVar20 + 1;
            puVar21 = puVar22 + 1;
            puVar24 = puVar25 + 1;
          } while (sVar16 != -1);
          puVar19 = puVar20 + 0x4d;
          puVar21 = puVar22 + 0x4d;
          puVar24 = puVar25 + 0x1d;
          sVar18 = sVar18 + -1;
        } while (sVar18 != -1);
      }
      else {
        puVar24 = (undefined2 *)&DAT_0000d8f0;
        puVar19 = in_A0;
        puVar21 = puVar23;
        do {
          sVar16 = 3;
          bVar26 = bVar27;
          do {
            puVar25 = puVar24;
            puVar22 = puVar21;
            puVar20 = puVar19;
            uVar13 = CONCAT22(*puVar20,puVar20[4]);
            bVar27 = (*puVar20 & 0x8000) != 0;
            uVar13 = ~uVar17 & (~(uVar15 | uVar7) & (uVar13 << 1 | (uint)bVar26) |
                               (uVar15 | uVar7) & uVar13) | uVar17 & CONCAT22(*puVar22,puVar22[4]);
            puVar25[4] = (short)uVar13;
            *puVar25 = (short)(uVar13 >> 0x10);
            sVar16 = sVar16 + -1;
            puVar19 = puVar20 + 1;
            puVar21 = puVar22 + 1;
            puVar24 = puVar25 + 1;
            bVar26 = bVar27;
          } while (sVar16 != -1);
          puVar19 = puVar20 + 0x4d;
          puVar21 = puVar22 + 0x4d;
          puVar24 = puVar25 + 5;
          sVar18 = sVar18 + -1;
        } while (sVar18 != -1);
      }
    }
    FUN_00013594(in_D0,sVar9,uVar10,uVar12,in_A0,puVar23);
    in_D0 = FUN_000123a0();
    uVar10 = uVar10 - DAT_0001a53e;
    in_A0 = extraout_A0;
    puVar23 = extraout_A1;
    if (DAT_0001a53e == 0) {
      sVar9 = (short)in_D0;
      in_D0 = (uint)(ushort)(sVar9 - 1);
      if (sVar9 == 0) {
        puVar23 = extraout_A1 + -4;
        in_A0 = extraout_A0 + -4;
        in_D0 = 0xf;
      }
    }
    sVar9 = extraout_D1w + -1;
  } while (sVar9 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011afa @ 00011afa

void FUN_00011afa(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint in_D0;
  short in_D1w;
  ushort unaff_D2w;
  ushort uVar9;
  undefined4 unaff_D3;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  short sVar13;
  uint uVar14;
  short sVar15;
  ushort *in_A0;
  ushort *puVar16;
  ushort *puVar17;
  ushort *extraout_A0;
  undefined2 *in_A1;
  undefined2 *puVar18;
  undefined2 *puVar19;
  undefined2 *extraout_A1;
  undefined2 *puVar20;
  undefined2 *puVar21;
  bool bVar22;
  bool bVar23;
  undefined8 uVar24;
  
  do {
    uVar10 = 0xffffffff >> (in_D0 & 0x3f);
    uVar7 = ~uVar10;
    uVar11 = 1;
    bVar23 = true;
    uVar4 = 0x10 - (short)in_D0;
    uVar9 = unaff_D2w - uVar4;
    if (uVar4 <= unaff_D2w && uVar9 != 0) {
      do {
        uVar11 = uVar11 + 1;
        bVar23 = (bool)(bVar23 ^ 1);
        bVar22 = 0xf < uVar9;
        uVar9 = uVar9 - 0x10;
      } while (bVar22 && uVar9 != 0);
    }
    uVar12 = ~(-1 << (-uVar9 & 0x3f));
    uVar4 = uVar9 + 0x1f;
    uVar11 = uVar11 >> 1;
    if (bVar23) {
      uVar11 = uVar11 + 1;
      uVar4 = uVar9 + 0xf;
      uVar12 = uVar12 << 0x10 | uVar12 >> 0x10 | 0xffff;
    }
    uVar14 = -0x80000000 << 0x20 - (uVar4 & 0x3f) | 0x80000000U >> (uVar4 & 0x3f);
    sVar15 = (short)unaff_D3;
    if (uVar11 == 2) {
      puVar20 = (undefined2 *)&DAT_0000d8f0;
      bVar23 = false;
      puVar16 = in_A0;
      puVar18 = in_A1;
      do {
        sVar13 = 3;
        do {
          puVar21 = puVar20;
          puVar19 = puVar18;
          puVar17 = puVar16;
          uVar1 = puVar19[8];
          uVar2 = puVar19[0xc];
          uVar5 = CONCAT22(*puVar17,puVar17[4]);
          uVar8 = CONCAT22(puVar17[8],puVar17[0xc]);
          uVar6 = (uint)bVar23;
          bVar23 = (*puVar17 & 0x8000) != 0;
          uVar5 = uVar10 & (uVar5 << 1 | (uint)((puVar17[8] & 0x8000) != 0)) | uVar7 & uVar5;
          puVar21[4] = (short)uVar5;
          *puVar21 = (short)(uVar5 >> 0x10);
          uVar5 = ~uVar14 & (~uVar12 & (uVar8 << 1 | uVar6) | uVar12 & uVar8) |
                  uVar14 & CONCAT22(uVar1,uVar2);
          puVar21[0xc] = (short)uVar5;
          puVar21[8] = (short)(uVar5 >> 0x10);
          sVar13 = sVar13 + -1;
          puVar16 = puVar17 + 1;
          puVar18 = puVar19 + 1;
          puVar20 = puVar21 + 1;
        } while (sVar13 != -1);
        puVar16 = puVar17 + 0x4d;
        puVar18 = puVar19 + 0x4d;
        puVar20 = puVar21 + 0xd;
        sVar15 = sVar15 + -1;
      } while (sVar15 != -1);
    }
    else if (uVar11 == 3) {
      puVar20 = (undefined2 *)&DAT_0000d8f0;
      puVar16 = in_A0;
      puVar18 = in_A1;
      do {
        sVar13 = 3;
        do {
          puVar21 = puVar20;
          puVar19 = puVar18;
          puVar17 = puVar16;
          uVar1 = puVar19[0x10];
          uVar2 = puVar19[0x14];
          uVar11 = *puVar17;
          uVar4 = puVar17[4];
          uVar9 = puVar17[8];
          uVar6 = CONCAT22(puVar17[0x10],puVar17[0x14]);
          uVar5 = CONCAT22(uVar9,puVar17[0xc]) << 1;
          puVar21[0xc] = (short)(uVar5 | (short)puVar17[0x10] < 0);
          puVar21[8] = (short)(uVar5 >> 0x10);
          uVar5 = uVar10 & (CONCAT22(uVar11,uVar4) << 1 | (uint)((uVar9 & 0x8000) != 0)) |
                  uVar7 & CONCAT22(uVar11,uVar4);
          puVar21[4] = (short)uVar5;
          *puVar21 = (short)(uVar5 >> 0x10);
          uVar5 = ~uVar14 & (~uVar12 & uVar6 << 1 | uVar12 & uVar6) | uVar14 & CONCAT22(uVar1,uVar2)
          ;
          puVar21[0x14] = (short)uVar5;
          puVar21[0x10] = (short)(uVar5 >> 0x10);
          sVar13 = sVar13 + -1;
          puVar16 = puVar17 + 1;
          puVar18 = puVar19 + 1;
          puVar20 = puVar21 + 1;
        } while (sVar13 != -1);
        puVar16 = puVar17 + 0x4d;
        puVar18 = puVar19 + 0x4d;
        puVar20 = puVar21 + 0x15;
        sVar15 = sVar15 + -1;
      } while (sVar15 != -1);
    }
    else {
      bVar23 = uVar11 < 4;
      if (uVar11 == 4) {
        puVar20 = (undefined2 *)&DAT_0000d8f0;
        puVar16 = in_A0;
        puVar18 = in_A1;
        do {
          sVar13 = 3;
          do {
            puVar21 = puVar20;
            puVar19 = puVar18;
            puVar17 = puVar16;
            uVar1 = puVar19[0x18];
            uVar2 = puVar19[0x1c];
            uVar11 = *puVar17;
            uVar4 = puVar17[4];
            uVar9 = puVar17[8];
            uVar3 = puVar17[0x18];
            uVar8 = CONCAT22(uVar3,puVar17[0x1c]);
            uVar5 = CONCAT22(puVar17[0x10],puVar17[0x14]) << 1;
            uVar6 = CONCAT22(uVar9,puVar17[0xc]) << 1;
            puVar21[0xc] = (short)(uVar6 | (puVar17[0x10] & 0x8000) != 0);
            puVar21[8] = (short)(uVar6 >> 0x10);
            puVar21[0x14] = (short)(uVar5 | (short)uVar3 < 0);
            puVar21[0x10] = (short)(uVar5 >> 0x10);
            uVar5 = uVar10 & (CONCAT22(uVar11,uVar4) << 1 | (uint)((uVar9 & 0x8000) != 0)) |
                    uVar7 & CONCAT22(uVar11,uVar4);
            puVar21[4] = (short)uVar5;
            *puVar21 = (short)(uVar5 >> 0x10);
            uVar5 = ~uVar14 & (~uVar12 & uVar8 << 1 | uVar12 & uVar8) |
                    uVar14 & CONCAT22(uVar1,uVar2);
            puVar21[0x1c] = (short)uVar5;
            puVar21[0x18] = (short)(uVar5 >> 0x10);
            sVar13 = sVar13 + -1;
            puVar16 = puVar17 + 1;
            puVar18 = puVar19 + 1;
            puVar20 = puVar21 + 1;
          } while (sVar13 != -1);
          puVar16 = puVar17 + 0x4d;
          puVar18 = puVar19 + 0x4d;
          puVar20 = puVar21 + 0x1d;
          sVar15 = sVar15 + -1;
        } while (sVar15 != -1);
      }
      else {
        puVar20 = (undefined2 *)&DAT_0000d8f0;
        puVar16 = in_A0;
        puVar18 = in_A1;
        do {
          sVar13 = 3;
          bVar22 = bVar23;
          do {
            puVar21 = puVar20;
            puVar19 = puVar18;
            puVar17 = puVar16;
            uVar10 = CONCAT22(*puVar17,puVar17[4]);
            bVar23 = (*puVar17 & 0x8000) != 0;
            uVar10 = ~uVar14 & (~(uVar12 | uVar7) & (uVar10 << 1 | (uint)bVar22) |
                               (uVar12 | uVar7) & uVar10) | uVar14 & CONCAT22(*puVar19,puVar19[4]);
            puVar21[4] = (short)uVar10;
            *puVar21 = (short)(uVar10 >> 0x10);
            sVar13 = sVar13 + -1;
            puVar16 = puVar17 + 1;
            puVar18 = puVar19 + 1;
            puVar20 = puVar21 + 1;
            bVar22 = bVar23;
          } while (sVar13 != -1);
          puVar16 = puVar17 + 0x4d;
          puVar18 = puVar19 + 0x4d;
          puVar20 = puVar21 + 5;
          sVar15 = sVar15 + -1;
        } while (sVar15 != -1);
      }
    }
    FUN_00013594(in_D0,in_D1w,unaff_D2w,unaff_D3,in_A0,in_A1);
    uVar24 = FUN_000123a0();
    in_D0 = (uint)((ulonglong)uVar24 >> 0x20);
    unaff_D2w = unaff_D2w - DAT_0001a53e;
    in_A0 = extraout_A0;
    in_A1 = extraout_A1;
    if (DAT_0001a53e == 0) {
      sVar15 = (short)((ulonglong)uVar24 >> 0x20);
      in_D0 = (uint)(ushort)(sVar15 - 1);
      if (sVar15 == 0) {
        in_A1 = extraout_A1 + -4;
        in_A0 = extraout_A0 + -4;
        in_D0 = 0xf;
      }
    }
    in_D1w = (short)uVar24 + -1;
  } while (in_D1w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011dee @ 00011dee

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011dee(void)

{
  short in_D1w;
  short unaff_D3w;
  short sVar1;
  int iVar2;
  
  _DAT_0001a53e = 1;
  FUN_00012698();
  iVar2 = (int)unaff_D3w;
  do {
    sVar1 = (short)iVar2 + -1;
    do {
      FUN_000123c0();
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    FUN_000123c0();
    FUN_00013594();
    iVar2 = iVar2 - _DAT_0001a53e;
    in_D1w = in_D1w + -1;
  } while (in_D1w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011e5e @ 00011e5e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011e5e(void)

{
  short in_D1w;
  short unaff_D3w;
  short sVar1;
  int iVar2;
  
  _DAT_0001a53e = 1;
  FUN_00012698();
  iVar2 = (int)unaff_D3w;
  do {
    sVar1 = (short)iVar2 + -1;
    do {
      FUN_000123c0();
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    FUN_000123c0();
    FUN_00013594();
    iVar2 = iVar2 - _DAT_0001a53e;
    in_D1w = in_D1w + -1;
  } while (in_D1w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011e7a @ 00011e7a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011e7a(void)

{
  short unaff_D7w;
  short sVar1;
  int unaff_A3;
  
  do {
    sVar1 = (short)unaff_A3 + -1;
    do {
      FUN_000123c0();
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    FUN_000123c0();
    FUN_00013594();
    unaff_A3 = unaff_A3 - _DAT_0001a53e;
    unaff_D7w = unaff_D7w + -1;
  } while (unaff_D7w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011ec4 @ 00011ec4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_00011ec4(void)

{
  byte bVar1;
  byte in_D0b;
  short sVar2;
  short unaff_D7w;
  int unaff_A3;
  
  bVar1 = in_D0b | 0xa0;
  while (unaff_D7w = unaff_D7w + -1, unaff_D7w != -1) {
    sVar2 = (short)unaff_A3 + -1;
    do {
      FUN_000123c0();
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    FUN_000123c0();
    bVar1 = FUN_00013594();
    unaff_A3 = unaff_A3 - _DAT_0001a53e;
  }
  return bVar1;
}


// ---------------------------------------------------------------
// FUN_00011ece @ 00011ece

void FUN_00011ece(void)

{
  short in_D1w;
  
  do {
    FUN_00012466();
    in_D1w = in_D1w + -1;
  } while (in_D1w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011ee8 @ 00011ee8

void FUN_00011ee8(void)

{
  short in_D1w;
  
  do {
    FUN_00012466();
    in_D1w = in_D1w + -1;
  } while (in_D1w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00011f02 @ 00011f02

void FUN_00011f02(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000128a4();
    FUN_000126e0();
    FUN_00011ece();
    return;
  }
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_00011f2e @ 00011f2e

void FUN_00011f2e(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000128a4();
    FUN_000126e0();
    FUN_00010fec();
    FUN_00011ee8();
    return;
  }
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_00011f64 @ 00011f64

void FUN_00011f64(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000128a4();
    FUN_000124da();
    FUN_000111ac();
    return;
  }
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_00011f98 @ 00011f98

void FUN_00011f98(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000128a4();
    FUN_00010fec();
    FUN_000124da();
    FUN_000114b0();
    return;
  }
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_00011fd8 @ 00011fd8

void FUN_00011fd8(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000120e4();
    FUN_00011e5e();
    FUN_000123c0();
    return;
  }
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_0001200a @ 0001200a

void FUN_0001200a(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000120e4();
    FUN_00010fec();
    FUN_00011dee();
    FUN_000123c0();
    return;
  }
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_00012044 @ 00012044

void FUN_00012044(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000120e4();
    FUN_000117de();
    FUN_0001215e();
    return;
  }
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_00012076 @ 00012076

void FUN_00012076(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000120e4();
    FUN_00011ada();
    FUN_0001215e();
    return;
  }
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_000120a8 @ 000120a8

void FUN_000120a8(void)

{
  short in_D0w;
  short in_D1w;
  short unaff_D2w;
  short unaff_D3w;
  short unaff_D4w;
  short sVar1;
  short unaff_D7w;
  undefined4 in_A0;
  short *psVar2;
  
  psVar2 = &DAT_0001a850;
  sVar1 = 9;
  do {
    if (*psVar2 == 0) break;
    psVar2 = psVar2 + 8;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  *psVar2 = unaff_D4w;
  *(undefined4 *)(psVar2 + 1) = in_A0;
  psVar2[3] = unaff_D7w;
  psVar2[4] = in_D0w;
  psVar2[5] = in_D1w;
  psVar2[6] = unaff_D2w;
  psVar2[7] = unaff_D3w;
  DAT_0001ad0a = (undefined1)DAT_0001a850;
  return;
}


// ---------------------------------------------------------------
// FUN_000120dc @ 000120dc

undefined4 FUN_000120dc(void)

{
  uint uVar1;
  short in_D0w;
  
  uVar1 = (uint)(ushort)((in_D0w + -1) * 0x10);
  *(undefined2 *)((int)&DAT_0001a850 + uVar1) = 2;
  DAT_0001ad0a = (undefined1)DAT_0001a850;
  return CONCAT22((short)((uint)screen_ptr_a >> 0x10),*(undefined2 *)((int)&DAT_0001a858 + uVar1));
}


// ---------------------------------------------------------------
// FUN_000120e4 @ 000120e4

undefined4 FUN_000120e4(void)

{
  uint uVar1;
  short in_D0w;
  
  uVar1 = (uint)(ushort)((in_D0w + -1) * 0x10);
  *(undefined2 *)((int)&DAT_0001a850 + uVar1) = 0;
  DAT_0001ad0a = (undefined1)DAT_0001a850;
  return CONCAT22((short)((uint)screen_ptr_a >> 0x10),*(undefined2 *)((int)&DAT_0001a858 + uVar1));
}


// ---------------------------------------------------------------
// FUN_0001213a @ 0001213a

undefined4 FUN_0001213a(void)

{
  undefined4 in_D0;
  short sVar1;
  short *psVar2;
  
  psVar2 = &DAT_0001a850;
  sVar1 = 9;
  do {
    if ((short)in_D0 == *psVar2) {
      *psVar2 = 0;
      DAT_0001ad0a = (undefined1)DAT_0001a850;
      return CONCAT22((short)((uint)screen_ptr_a >> 0x10),psVar2[4]);
    }
    psVar2 = psVar2 + 8;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return in_D0;
}


// ---------------------------------------------------------------
// FUN_0001215e @ 0001215e

void FUN_0001215e(void)

{
  short unaff_D3w;
  short sVar1;
  
  FUN_00012698();
  if (DAT_0000d8ea != 'A') {
    TEMPL_data = 0;
  }
  sVar1 = unaff_D3w + -1;
  do {
    FUN_000123c0();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00012190 @ 00012190

void FUN_00012190(void)

{
  short unaff_D3w;
  short sVar1;
  
  FUN_00012698();
  sVar1 = unaff_D3w + -1;
  do {
    FUN_000123c0();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000121b6 @ 000121b6

void FUN_000121b6(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = 7999;
  puVar2 = screen_ptr_a;
  puVar3 = screen_ptr_b;
  do {
    *puVar3 = *puVar2;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000121c4 @ 000121c4

void FUN_000121c4(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = 7999;
  puVar2 = screen_ptr_b;
  puVar3 = screen_ptr_a;
  do {
    *puVar3 = *puVar2;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// copy_screen @ 000121c6

void copy_screen(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  sVar1 = 7999;
  puVar2 = screen_ptr_b;
  puVar3 = screen_ptr_a;
  do {
    *puVar3 = *puVar2;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// swap_screens @ 000121de

void swap_screens(void)

{
  undefined4 uVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  sVar2 = 7999;
  puVar3 = screen_ptr_a;
  puVar4 = screen_ptr_b;
  do {
    uVar1 = *puVar3;
    *puVar3 = *puVar4;
    *puVar4 = uVar1;
    sVar2 = sVar2 + -1;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (sVar2 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000121fa @ 000121fa

void FUN_000121fa(void)

{
  undefined2 uVar1;
  undefined2 extraout_D1w;
  
  uVar1 = FUN_000120e4();
  FUN_0001215e(CONCAT22(uVar1,extraout_D1w));
  FUN_00010fec();
  FUN_0001215e();
  DAT_0001a484 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_0001222e @ 0001222e

void FUN_0001222e(void)

{
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_00012240 @ 00012240

void FUN_00012240(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  int unaff_A6;
  
  uVar1 = DAT_0001a84e + (ushort)*(byte *)(unaff_A6 + 1);
  if (((uVar1 & 0x8000) == 0) && (sVar2 = uVar1 - 1, uVar1 != 0)) {
    do {
      sVar3 = 0x32;
      do {
        wait_frame();
        if ((input_buttons & 4) != 0) {
          return;
        }
        sVar3 = sVar3 + -1;
      } while (sVar3 != -1);
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0001224e @ 0001224e

void FUN_0001224e(void)

{
  short sVar1;
  short sVar2;
  
  if (((DAT_0001a84e + 4U & 0x8000) == 0) &&
     (sVar1 = DAT_0001a84e + 3, (ushort)(DAT_0001a84e + 4U) != 0)) {
    do {
      sVar2 = 0x32;
      do {
        wait_frame();
        if ((input_buttons & 4) != 0) {
          return;
        }
        sVar2 = sVar2 + -1;
      } while (sVar2 != -1);
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0001228a @ 0001228a

void FUN_0001228a(void)

{
  prompt_wait();
  return;
}


// ---------------------------------------------------------------
// prompt_wait @ 00012292

undefined8 prompt_wait(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  if (DAT_0001acc6 != -0x79) {
    DAT_0001a74e = '\0';
    do {
      wait_frame();
    } while ((input_buttons & 4) != 0);
    do {
      if ((DAT_0001acd4 & 0xf) == 0) {
        FUN_000122ee();
      }
      wait_frame();
    } while ((input_buttons & 4) == 0);
    if (DAT_0001a74e != '\0') {
      FUN_000122ee();
    }
    return CONCAT44(in_D0,in_D1);
  }
  __m68k_trap(1);
  return CONCAT44(in_D0,in_D1);
}


// ---------------------------------------------------------------
// FUN_000122ee @ 000122ee

void FUN_000122ee(void)

{
  if (DAT_0001acc6 != -0x79) {
    FUN_00013594();
    FUN_00011020();
    DAT_0001a74e = ~DAT_0001a74e;
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00012324 @ 00012324

void FUN_00012324(void)

{
  __m68k_trap(1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001232e @ 0001232e

void FUN_0001232e(void)

{
  undefined2 uVar1;
  undefined2 extraout_D1w;
  bool bVar2;
  
  DAT_0001a484 = 0;
  while( true ) {
    bVar2 = false;
    uVar1 = FUN_0001213a();
    if (!bVar2) break;
    FUN_0001215e(CONCAT22(uVar1,extraout_D1w));
    FUN_00010fec();
    FUN_0001215e();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00012368 @ 00012368

void FUN_00012368(void)

{
  bool bVar1;
  
  while( true ) {
    bVar1 = false;
    FUN_0001213a();
    if (!bVar1) break;
    FUN_0001215e();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00012384 @ 00012384

void FUN_00012384(void)

{
  bool bVar1;
  
  while( true ) {
    bVar1 = false;
    FUN_0001213a();
    if (!bVar1) break;
    FUN_0001215e();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000123a0 @ 000123a0

void FUN_000123a0(void)

{
  short unaff_D4w;
  short unaff_D5w;
  short sVar1;
  undefined4 *in_A0;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  sVar1 = unaff_D4w;
  puVar3 = (undefined4 *)&DAT_0000d8f0;
  puVar2 = in_A0;
  do {
    do {
      puVar4 = puVar3 + 1;
      *in_A0 = *puVar3;
      sVar1 = sVar1 + -1;
      puVar3 = puVar4;
      in_A0 = in_A0 + 1;
    } while (sVar1 != -1);
    in_A0 = puVar2 + 0x28;
    unaff_D5w = unaff_D5w + -1;
    sVar1 = unaff_D4w;
    puVar2 = in_A0;
  } while (unaff_D5w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000123c0 @ 000123c0

void FUN_000123c0(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  ushort *in_A0;
  ushort *puVar8;
  ushort *in_A1;
  ushort *puVar9;
  bool bVar10;
  
  sVar7 = DAT_0001a53c + -1;
  uVar6 = DAT_0001a538;
  if (sVar7 == 0) {
    uVar6 = DAT_0001a53a | DAT_0001a538;
  }
  uVar5 = ~uVar6;
  uVar1 = *in_A1;
  uVar2 = in_A1[1];
  uVar3 = in_A1[2];
  uVar4 = in_A1[3];
  *in_A0 = uVar6 & *in_A0;
  puVar8 = in_A0 + 1;
  *in_A0 = uVar5 & uVar1 | *in_A0;
  *puVar8 = uVar6 & *puVar8;
  puVar9 = in_A0 + 2;
  *puVar8 = uVar5 & uVar2 | *puVar8;
  *puVar9 = uVar6 & *puVar9;
  puVar8 = in_A0 + 3;
  *puVar9 = uVar5 & uVar3 | *puVar9;
  *puVar8 = uVar6 & *puVar8;
  *puVar8 = uVar5 & uVar4 | *puVar8;
  while( true ) {
    uVar6 = DAT_0001a53a;
    puVar9 = in_A1 + 4;
    puVar8 = in_A0 + 4;
    bVar10 = sVar7 == 0;
    sVar7 = sVar7 + -1;
    if (bVar10) {
      return;
    }
    if (sVar7 == 0) break;
    *(undefined4 *)puVar8 = *(undefined4 *)puVar9;
    *(undefined4 *)(in_A0 + 6) = *(undefined4 *)(in_A1 + 6);
    in_A0 = puVar8;
    in_A1 = puVar9;
  }
  uVar5 = ~DAT_0001a53a;
  uVar1 = *puVar9;
  uVar2 = in_A1[5];
  uVar3 = in_A1[6];
  uVar4 = in_A1[7];
  *puVar8 = DAT_0001a53a & *puVar8;
  puVar9 = in_A0 + 5;
  *puVar8 = uVar5 & uVar1 | *puVar8;
  *puVar9 = uVar6 & *puVar9;
  puVar8 = in_A0 + 6;
  *puVar9 = uVar5 & uVar2 | *puVar9;
  *puVar8 = uVar6 & *puVar8;
  puVar9 = in_A0 + 7;
  *puVar8 = uVar5 & uVar3 | *puVar8;
  *puVar9 = uVar6 & *puVar9;
  *puVar9 = uVar5 & uVar4 | *puVar9;
  return;
}


// ---------------------------------------------------------------
// FUN_00012436 @ 00012436

void FUN_00012436(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short sVar7;
  ushort *puVar8;
  short sVar9;
  short sVar10;
  ushort *puVar11;
  ushort *puVar12;
  ushort *puVar13;
  ushort *puVar14;
  ushort *puVar15;
  ushort *puVar16;
  
  puVar8 = DAT_0001a4b2;
  sVar7 = DAT_0001a4a4;
  uVar6 = DAT_0001a4a0;
  uVar5 = DAT_0001a49e;
  DAT_0001a538 = DAT_0001a49e;
  DAT_0001a53a = DAT_0001a4a0;
  DAT_0001a53c = DAT_0001a4a2;
  puVar14 = (ushort *)&DAT_0000d8f0;
  sVar10 = DAT_0001a4a4 + -1;
  puVar11 = DAT_0001a4b2;
  do {
    sVar9 = DAT_0001a53c + -1;
    uVar1 = *puVar14;
    uVar2 = puVar14[1];
    uVar3 = puVar14[2];
    uVar4 = puVar14[3];
    *puVar11 = uVar5 & *puVar11;
    puVar13 = puVar11 + 1;
    *puVar11 = uVar1 | *puVar11;
    *puVar13 = uVar5 & *puVar13;
    puVar16 = puVar11 + 2;
    *puVar13 = uVar2 | *puVar13;
    *puVar16 = uVar5 & *puVar16;
    puVar13 = puVar11 + 3;
    *puVar16 = uVar3 | *puVar16;
    *puVar13 = uVar5 & *puVar13;
    *puVar13 = uVar4 | *puVar13;
    puVar13 = puVar11;
    puVar16 = puVar14;
    while( true ) {
      puVar15 = puVar16 + 4;
      puVar12 = puVar13 + 4;
      sVar9 = sVar9 + -1;
      if (sVar9 == 0) break;
      *(undefined4 *)puVar12 = *(undefined4 *)puVar15;
      *(undefined4 *)(puVar13 + 6) = *(undefined4 *)(puVar16 + 6);
      puVar13 = puVar12;
      puVar16 = puVar15;
    }
    uVar1 = *puVar15;
    uVar2 = puVar16[5];
    uVar3 = puVar16[6];
    uVar4 = puVar16[7];
    *puVar12 = uVar6 & *puVar12;
    puVar16 = puVar13 + 5;
    *puVar12 = uVar1 | *puVar12;
    *puVar16 = uVar6 & *puVar16;
    puVar12 = puVar13 + 6;
    *puVar16 = uVar2 | *puVar16;
    *puVar12 = uVar6 & *puVar12;
    puVar13 = puVar13 + 7;
    *puVar12 = uVar3 | *puVar12;
    *puVar13 = uVar6 & *puVar13;
    *puVar13 = uVar4 | *puVar13;
    puVar11 = puVar11 + 0x50;
    puVar14 = puVar14 + 0x20;
    sVar10 = sVar10 + -1;
  } while (sVar10 != -1);
  FUN_00013594(sVar7,puVar8,&DAT_0000d8f0);
  return;
}


// ---------------------------------------------------------------
// FUN_00012466 @ 00012466

void FUN_00012466(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  short unaff_D3w;
  short sVar7;
  short sVar8;
  ushort *in_A0;
  ushort *puVar9;
  ushort *puVar10;
  ushort *in_A1;
  ushort *puVar11;
  ushort *puVar12;
  
  uVar6 = DAT_0001a53a;
  uVar5 = DAT_0001a538;
  sVar8 = unaff_D3w + -1;
  do {
    sVar7 = DAT_0001a53c + -1;
    uVar1 = *in_A1;
    uVar2 = in_A1[1];
    uVar3 = in_A1[2];
    uVar4 = in_A1[3];
    *in_A0 = uVar5 & *in_A0;
    puVar10 = in_A0 + 1;
    *in_A0 = uVar1 | *in_A0;
    *puVar10 = uVar5 & *puVar10;
    puVar12 = in_A0 + 2;
    *puVar10 = uVar2 | *puVar10;
    *puVar12 = uVar5 & *puVar12;
    puVar10 = in_A0 + 3;
    *puVar12 = uVar3 | *puVar12;
    *puVar10 = uVar5 & *puVar10;
    *puVar10 = uVar4 | *puVar10;
    puVar10 = in_A0;
    puVar12 = in_A1;
    while( true ) {
      puVar11 = puVar12 + 4;
      puVar9 = puVar10 + 4;
      sVar7 = sVar7 + -1;
      if (sVar7 == 0) break;
      *(undefined4 *)puVar9 = *(undefined4 *)puVar11;
      *(undefined4 *)(puVar10 + 6) = *(undefined4 *)(puVar12 + 6);
      puVar10 = puVar9;
      puVar12 = puVar11;
    }
    uVar1 = *puVar11;
    uVar2 = puVar12[5];
    uVar3 = puVar12[6];
    uVar4 = puVar12[7];
    *puVar9 = uVar6 & *puVar9;
    puVar12 = puVar10 + 5;
    *puVar9 = uVar1 | *puVar9;
    *puVar12 = uVar6 & *puVar12;
    puVar9 = puVar10 + 6;
    *puVar12 = uVar2 | *puVar12;
    *puVar9 = uVar6 & *puVar9;
    puVar10 = puVar10 + 7;
    *puVar9 = uVar3 | *puVar9;
    *puVar10 = uVar6 & *puVar10;
    *puVar10 = uVar4 | *puVar10;
    in_A0 = in_A0 + 0x50;
    in_A1 = in_A1 + 0x20;
    sVar8 = sVar8 + -1;
  } while (sVar8 != -1);
  FUN_00013594();
  return;
}


// ---------------------------------------------------------------
// FUN_000124da @ 000124da

void FUN_000124da(void)

{
  FUN_00012510();
  FUN_00013594();
  return;
}


// ---------------------------------------------------------------
// FUN_000124f2 @ 000124f2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000124f2(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  short sVar8;
  ushort uVar9;
  int iVar10;
  ushort uVar11;
  byte *pbVar12;
  short *psVar13;
  byte *pbVar14;
  short *psVar15;
  
  iVar5 = _DAT_0000d8f8;
  uVar9 = (ushort)DAT_0000d8f1;
  psVar13 = (short *)&DAT_0000d8fc;
  sVar8 = DAT_0000d8f0 - 1;
  pbVar12 = _DAT_0000d8f2;
  uVar11 = _DAT_0000d8f6;
  do {
    uVar6 = 0xf0f0f0f0;
    iVar10 = 0;
    pbVar14 = pbVar12;
    if ((uVar11 & 8) != 0) {
      pbVar14 = pbVar12 + 1;
    }
    if ((uVar11 & 4) != 0) {
      uVar6 = 0xf0f0f0f;
      iVar10 = 4;
    }
    psVar15 = psVar13;
    sVar7 = uVar9 - 1;
    do {
      sVar1 = *psVar15;
      bVar4 = (byte)((ushort)sVar1 >> 8);
      _DAT_00055b02 = CONCAT13(bVar4,CONCAT12((char)((ushort)(sVar1 << 4) >> 8),sVar1 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar1 << 4) | bVar4 >> 4);
      uVar3 = uVar6 & (_DAT_00055b02 << 0x20 - iVar10 | _DAT_00055b02 >> iVar10) |
              ~uVar6 & ((uint)*pbVar14 << 0x18 | (uint)pbVar14[2] << 0x10 | (uint)pbVar14[4] << 8 |
                       (uint)pbVar14[6]);
      *pbVar14 = (byte)(uVar3 >> 0x18);
      pbVar14[2] = (byte)(uVar3 >> 0x10);
      pbVar14[4] = (byte)(uVar3 >> 8);
      pbVar14[6] = (byte)uVar3;
      pbVar14 = pbVar14 + 0xa0;
      psVar15 = (short *)(iVar5 + (int)psVar15);
      sVar7 = sVar7 + -1;
    } while (sVar7 != -1);
    psVar13 = psVar13 + 1;
    uVar2 = uVar11 + 4;
    uVar11 = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      pbVar12 = pbVar12 + 8;
    }
    sVar8 = sVar8 + -1;
  } while (sVar8 != -1);
  return;
}


// ---------------------------------------------------------------
// blit_sprite @ 000124f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void blit_sprite(void)

{
  int iVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  ushort uVar11;
  byte *pbVar12;
  byte *in_A1;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  
  if (in_A1 != (byte *)0x0) {
    bVar3 = in_A1[1];
    pbVar12 = *(byte **)(in_A1 + 2);
    uVar11 = *(ushort *)(in_A1 + 6);
    pbVar13 = in_A1 + 0xc;
    iVar1 = *(int *)(in_A1 + 8);
    sVar9 = *in_A1 - 1;
    do {
      uVar7 = 0xf0f0f0f0;
      iVar10 = 0;
      pbVar14 = pbVar12;
      if ((uVar11 & 8) != 0) {
        pbVar14 = pbVar12 + 1;
      }
      if ((uVar11 & 4) != 0) {
        uVar7 = 0xf0f0f0f;
        iVar10 = 4;
      }
      pbVar15 = pbVar13;
      sVar8 = bVar3 - 1;
      do {
        sVar2 = *(short *)pbVar15;
        bVar6 = (byte)((ushort)sVar2 >> 8);
        _DAT_00055b02 = CONCAT13(bVar6,CONCAT12((char)((ushort)(sVar2 << 4) >> 8),sVar2 << 8));
        _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar2 << 4) | bVar6 >> 4);
        uVar5 = uVar7 & (_DAT_00055b02 << 0x20 - iVar10 | _DAT_00055b02 >> iVar10) |
                ~uVar7 & ((uint)*pbVar14 << 0x18 | (uint)pbVar14[2] << 0x10 | (uint)pbVar14[4] << 8
                         | (uint)pbVar14[6]);
        *pbVar14 = (byte)(uVar5 >> 0x18);
        pbVar14[2] = (byte)(uVar5 >> 0x10);
        pbVar14[4] = (byte)(uVar5 >> 8);
        pbVar14[6] = (byte)uVar5;
        pbVar14 = pbVar14 + 0xa0;
        pbVar15 = pbVar15 + iVar1;
        sVar8 = sVar8 + -1;
      } while (sVar8 != -1);
      pbVar13 = pbVar13 + 2;
      uVar4 = uVar11 + 4;
      uVar11 = uVar4 & 0xf;
      if ((uVar4 & 0xf) == 0) {
        pbVar12 = pbVar12 + 8;
      }
      sVar9 = sVar9 + -1;
    } while (sVar9 != -1);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00012510 @ 00012510

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012510(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  short unaff_D2w;
  short sVar6;
  short sVar7;
  short unaff_D3w;
  int iVar8;
  ushort unaff_D7w;
  byte *in_A0;
  short *in_A1;
  byte *pbVar9;
  int unaff_A3;
  short *psVar10;
  
  sVar7 = unaff_D2w + -1;
  do {
    uVar5 = 0xf0f0f0f0;
    iVar8 = 0;
    pbVar9 = in_A0;
    if ((unaff_D7w & 8) != 0) {
      pbVar9 = in_A0 + 1;
    }
    if ((unaff_D7w & 4) != 0) {
      uVar5 = 0xf0f0f0f;
      iVar8 = 4;
    }
    psVar10 = in_A1;
    sVar6 = unaff_D3w + -1;
    do {
      sVar1 = *psVar10;
      bVar4 = (byte)((ushort)sVar1 >> 8);
      _DAT_00055b02 = CONCAT13(bVar4,CONCAT12((char)((ushort)(sVar1 << 4) >> 8),sVar1 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar1 << 4) | bVar4 >> 4);
      uVar3 = uVar5 & (_DAT_00055b02 << 0x20 - iVar8 | _DAT_00055b02 >> iVar8) |
              ~uVar5 & ((uint)*pbVar9 << 0x18 | (uint)pbVar9[2] << 0x10 | (uint)pbVar9[4] << 8 |
                       (uint)pbVar9[6]);
      *pbVar9 = (byte)(uVar3 >> 0x18);
      pbVar9[2] = (byte)(uVar3 >> 0x10);
      pbVar9[4] = (byte)(uVar3 >> 8);
      pbVar9[6] = (byte)uVar3;
      pbVar9 = pbVar9 + 0xa0;
      psVar10 = (short *)(unaff_A3 + (int)psVar10);
      sVar6 = sVar6 + -1;
    } while (sVar6 != -1);
    in_A1 = in_A1 + 1;
    uVar2 = unaff_D7w + 4;
    unaff_D7w = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      in_A0 = in_A0 + 8;
    }
    sVar7 = sVar7 + -1;
  } while (sVar7 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001258a @ 0001258a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001258a(void)

{
  uint uVar1;
  ushort uVar2;
  ushort unaff_D2w;
  short sVar3;
  short sVar4;
  short unaff_D3w;
  ushort uVar5;
  int iVar6;
  ushort unaff_D7w;
  byte *in_A0;
  ushort *puVar7;
  byte *pbVar8;
  ushort *puVar9;
  
  DAT_0000d8f0 = (undefined1)unaff_D2w;
  DAT_0000d8f1 = (undefined1)unaff_D3w;
  _DAT_0000d8f8 = (uint)unaff_D2w * 2;
  puVar7 = (ushort *)&DAT_0000d8fc;
  sVar4 = unaff_D2w - 1;
  _DAT_0000d8f2 = in_A0;
  _DAT_0000d8f6 = unaff_D7w;
  do {
    iVar6 = 0;
    pbVar8 = in_A0;
    if ((unaff_D7w & 8) != 0) {
      pbVar8 = in_A0 + 1;
    }
    puVar9 = puVar7;
    sVar3 = unaff_D3w + -1;
    if ((unaff_D7w & 4) != 0) {
      iVar6 = 4;
    }
    do {
      uVar1 = (uint)*pbVar8 << 0x18 | (uint)pbVar8[2] << 0x10 | (uint)pbVar8[4] << 8 |
              (uint)pbVar8[6];
      uVar1 = (uVar1 << iVar6 | uVar1 >> 0x20 - iVar6) & 0xf0f0f0f0;
      DAT_00055b03 = (undefined1)(uVar1 >> 0x10);
      DAT_00055b05 = (undefined1)uVar1;
      uVar2 = CONCAT11(DAT_00055b03,DAT_00055b05);
      DAT_00055b02 = (undefined1)(uVar1 >> 0x18);
      DAT_00055b04 = (undefined1)(uVar1 >> 8);
      uVar5 = CONCAT11(DAT_00055b02,DAT_00055b04);
      _DAT_00055b02 = uVar1;
      *puVar9 = uVar5 | uVar2 >> 4;
      pbVar8 = pbVar8 + 0xa0;
      puVar9 = puVar9 + unaff_D2w;
      sVar3 = sVar3 + -1;
    } while (sVar3 != -1);
    puVar7 = puVar7 + 1;
    uVar2 = unaff_D7w + 4;
    unaff_D7w = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      in_A0 = in_A0 + 8;
    }
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00012590 @ 00012590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012590(void)

{
  uint uVar1;
  ushort uVar2;
  ushort unaff_D2w;
  short sVar3;
  short sVar4;
  short unaff_D3w;
  ushort uVar5;
  int iVar6;
  ushort unaff_D7w;
  byte *in_A0;
  undefined1 *in_A1;
  ushort *puVar7;
  byte *pbVar8;
  ushort *puVar9;
  
  *in_A1 = (char)unaff_D2w;
  in_A1[1] = (char)unaff_D3w;
  *(byte **)(in_A1 + 2) = in_A0;
  *(ushort *)(in_A1 + 6) = unaff_D7w;
  puVar7 = (ushort *)(in_A1 + 0xc);
  *(uint *)(in_A1 + 8) = (uint)unaff_D2w * 2;
  sVar4 = unaff_D2w - 1;
  do {
    iVar6 = 0;
    pbVar8 = in_A0;
    if ((unaff_D7w & 8) != 0) {
      pbVar8 = in_A0 + 1;
    }
    puVar9 = puVar7;
    sVar3 = unaff_D3w + -1;
    if ((unaff_D7w & 4) != 0) {
      iVar6 = 4;
    }
    do {
      uVar1 = (uint)*pbVar8 << 0x18 | (uint)pbVar8[2] << 0x10 | (uint)pbVar8[4] << 8 |
              (uint)pbVar8[6];
      uVar1 = (uVar1 << iVar6 | uVar1 >> 0x20 - iVar6) & 0xf0f0f0f0;
      DAT_00055b03 = (undefined1)(uVar1 >> 0x10);
      DAT_00055b05 = (undefined1)uVar1;
      uVar2 = CONCAT11(DAT_00055b03,DAT_00055b05);
      DAT_00055b02 = (undefined1)(uVar1 >> 0x18);
      DAT_00055b04 = (undefined1)(uVar1 >> 8);
      uVar5 = CONCAT11(DAT_00055b02,DAT_00055b04);
      _DAT_00055b02 = uVar1;
      *puVar9 = uVar5 | uVar2 >> 4;
      pbVar8 = pbVar8 + 0xa0;
      puVar9 = puVar9 + unaff_D2w;
      sVar3 = sVar3 + -1;
    } while (sVar3 != -1);
    puVar7 = puVar7 + 1;
    uVar2 = unaff_D7w + 4;
    unaff_D7w = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      in_A0 = in_A0 + 8;
    }
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00012698 @ 00012698

void FUN_00012698(void)

{
  ushort uVar1;
  ushort unaff_D2w;
  short sVar2;
  ushort uVar3;
  ushort unaff_D7w;
  bool bVar4;
  
  uVar1 = 4 - (unaff_D7w >> 2);
  DAT_0001a53c = 1;
  uVar3 = unaff_D2w - uVar1;
  sVar2 = 1;
  if (uVar1 <= unaff_D2w && uVar3 != 0) {
    do {
      DAT_0001a53c = sVar2 + 1;
      bVar4 = 3 < uVar3;
      uVar3 = uVar3 - 4;
      sVar2 = DAT_0001a53c;
    } while (bVar4 && uVar3 != 0);
  }
  DAT_0001a538 = ~(0xffffU >> (unaff_D7w & 0x3f));
  DAT_0001a53a = ~(-1 << (uVar3 * -4 & 0x3f));
  return;
}


// ---------------------------------------------------------------
// FUN_000126e0 @ 000126e0

void FUN_000126e0(void)

{
  int iVar1;
  short unaff_D2w;
  ushort uVar2;
  ushort uVar3;
  short unaff_D3w;
  ushort uVar4;
  short sVar5;
  short sVar6;
  uint unaff_D7;
  undefined4 *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *extraout_A1;
  ushort *puVar10;
  ushort *puVar11;
  
  iVar1 = DAT_0001a534;
  sVar6 = 0x626;
  puVar7 = (undefined4 *)&DAT_0000d8f0;
  do {
    *puVar7 = 0;
    sVar6 = sVar6 + -1;
    puVar7 = puVar7 + 1;
  } while (sVar6 != -1);
  FUN_00012698();
  puVar8 = (ushort *)&DAT_0000d8f0;
  sVar6 = unaff_D2w + -1;
  puVar10 = extraout_A1;
  do {
    uVar4 = -0x1000 << 0x10 - (unaff_D7 & 0x3f) | 0xf000U >> (unaff_D7 & 0x3f);
    puVar9 = puVar8;
    puVar11 = puVar10;
    sVar5 = unaff_D3w + -1;
    do {
      uVar2 = *puVar11 << 0x10 - (unaff_D7 & 0x3f) | *puVar11 >> (unaff_D7 & 0x3f);
      *puVar9 = uVar4 & uVar2 | *puVar9;
      uVar3 = uVar2 << 4 | uVar2 >> 0xc;
      puVar9[1] = uVar4 & uVar3 | puVar9[1];
      uVar3 = uVar3 << 4 | (uVar2 & 0xfff) >> 8;
      puVar9[2] = uVar4 & uVar3 | puVar9[2];
      puVar9[3] = uVar4 & (uVar3 << 4 | (uVar2 << 4 & 0xfff) >> 8) | puVar9[3];
      puVar9 = puVar9 + 0x20;
      puVar11 = (ushort *)(iVar1 + (int)puVar11);
      sVar5 = sVar5 + -1;
    } while (sVar5 != -1);
    puVar10 = puVar10 + 1;
    uVar4 = (short)unaff_D7 + 4U & 0xf;
    unaff_D7 = (uint)uVar4;
    if (uVar4 == 0) {
      puVar8 = puVar8 + 4;
    }
    sVar6 = sVar6 + -1;
  } while (sVar6 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001276c @ 0001276c

void FUN_0001276c(void)

{
  ushort uVar1;
  ushort uVar2;
  short unaff_D2w;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  short unaff_D3w;
  short sVar6;
  ushort unaff_D6w;
  uint unaff_D7;
  ushort *in_A0;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  
  sVar5 = unaff_D2w + -1;
  do {
    uVar2 = 0xfff << 0x10 - (unaff_D7 & 0x3f) | 0xfffU >> (unaff_D7 & 0x3f);
    uVar1 = ~uVar2;
    sVar6 = unaff_D3w + -1;
    puVar7 = in_A0;
    do {
      uVar3 = unaff_D6w << 0x10 - (unaff_D7 & 0x3f) | unaff_D6w >> (unaff_D7 & 0x3f);
      *puVar7 = uVar2 & *puVar7;
      puVar8 = puVar7 + 1;
      *puVar7 = uVar1 & uVar3 | *puVar7;
      uVar4 = uVar3 << 4 | uVar3 >> 0xc;
      *puVar8 = uVar2 & *puVar8;
      puVar9 = puVar7 + 2;
      *puVar8 = uVar1 & uVar4 | *puVar8;
      uVar4 = uVar4 << 4 | (uVar3 & 0xfff) >> 8;
      *puVar9 = uVar2 & *puVar9;
      puVar8 = puVar7 + 3;
      *puVar9 = uVar1 & uVar4 | *puVar9;
      *puVar8 = uVar2 & *puVar8;
      *puVar8 = uVar1 & (uVar4 << 4 | (uVar3 << 4 & 0xfff) >> 8) | *puVar8;
      puVar7 = puVar7 + 0x50;
      sVar6 = sVar6 + -1;
    } while (sVar6 != -1);
    uVar1 = (short)unaff_D7 + 4U & 0xf;
    unaff_D7 = (uint)uVar1;
    if (uVar1 == 0) {
      in_A0 = in_A0 + 4;
    }
    sVar5 = sVar5 + -1;
  } while (sVar5 != -1);
  FUN_00013594();
  return;
}


// ---------------------------------------------------------------
// FUN_000127e0 @ 000127e0

void FUN_000127e0(void)

{
  FUN_000127fa();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_000127f0 @ 000127f0

void FUN_000127f0(void)

{
  FUN_000127fa();
  FUN_0001104a();
  return;
}


// ---------------------------------------------------------------
// FUN_000127fa @ 000127fa

void FUN_000127fa(void)

{
  undefined2 extraout_D1w;
  short unaff_D3w;
  undefined2 unaff_D4w;
  undefined2 unaff_D5w;
  short sVar1;
  undefined4 in_A0;
  undefined4 *puVar2;
  
  sVar1 = 0x626;
  puVar2 = (undefined4 *)&DAT_0000d8f0;
  DAT_0001a4a4 = unaff_D3w;
  DAT_0001a4b2 = in_A0;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  FUN_00012698();
  sVar1 = unaff_D3w + -1;
  DAT_0001a49e = extraout_D1w;
  DAT_0001a4a0 = unaff_D5w;
  DAT_0001a4a2 = unaff_D4w;
  do {
    FUN_000123c0();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001285a @ 0001285a

byte FUN_0001285a(void)

{
  byte in_D0b;
  byte *pbVar1;
  
  pbVar1 = &DAT_00019e19;
  do {
    if ((PTR_DAT_0001a772[3] & 0xf8) == *pbVar1) {
      DAT_0001ab4c = pbVar1[4];
      DAT_0001ab4d = pbVar1[5];
      return pbVar1[2];
    }
    pbVar1 = pbVar1 + 6;
  } while (pbVar1 != &UNK_00019ea9);
  return in_D0b;
}


// ---------------------------------------------------------------
// FUN_000128a4 @ 000128a4

void FUN_000128a4(void)

{
  uint uVar1;
  uint in_D0;
  undefined4 in_D1;
  ushort uVar2;
  int extraout_A1;
  int unaff_A6;
  undefined1 uVar3;
  uint6 uVar4;
  
  uVar1 = CONCAT31((int3)((uint)in_D1 >> 8),*(char *)(unaff_A6 + 1));
  if (*(char *)(unaff_A6 + 1) == -1) {
    uVar3 = DAT_0001ad0a == '\0';
    if ((bool)uVar3) {
      FUN_00018d28(in_D0 & 0xffff0000,uVar1 & 0xffff00ff);
      uVar2 = 0;
      uVar4 = FUN_0001285a();
      if (!(bool)uVar3) goto LAB_000128e2;
    }
    return;
  }
  uVar4 = (uint6)CONCAT14(*(undefined1 *)(unaff_A6 + 2),uVar1) & 0xffffffff00ff;
  uVar2 = (ushort)*(byte *)(unaff_A6 + 3);
LAB_000128e2:
  DAT_0001a532 = (undefined2)(uVar4 >> 0x20);
  DAT_0001ab4e = (undefined1)uVar4;
  DAT_0001a530 = uVar2;
  FUN_000129c8();
  DAT_0001a52c = (ushort)*(byte *)(extraout_A1 + 2);
  DAT_0001a528 = extraout_A1 + 4;
  DAT_0001a52e = (ushort)*(byte *)(extraout_A1 + 3);
  FUN_00010fec();
  FUN_000120a8();
  return;
}


// ---------------------------------------------------------------
// FUN_00012950 @ 00012950

void FUN_00012950(void)

{
  short in_D1w;
  short sVar1;
  
  if (in_D1w != 0) {
    sVar1 = in_D1w + -1;
    do {
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0001296c @ 0001296c

void FUN_0001296c(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  ushort uVar4;
  short sVar5;
  ushort uVar6;
  int iVar7;
  short sVar8;
  short sVar9;
  undefined4 *puVar10;
  undefined2 *puVar11;
  undefined4 *puVar12;
  byte *unaff_A5;
  
  iVar7 = (uint)*unaff_A5 * 10;
  PTR_DAT_0003b1ac._3_1_ = (&DAT_0001a252)[iVar7];
  uVar4 = (ushort)(byte)PTR_DAT_0003b1ac;
  PTR_DAT_0003b1ac._2_1_ = (&DAT_0001a253)[iVar7];
  uVar6 = (ushort)PTR_DAT_0003b1ac._2_1_;
  DAT_0001a534 = (uint)(byte)PTR_DAT_0003b1ac << 1;
  uVar1 = *(undefined2 *)(&DAT_0001a254 + iVar7);
  sVar5 = uVar4 - 1;
  sVar8 = sVar5;
  puVar10 = &DAT_0003b1b0;
  do {
    puVar12 = (undefined4 *)((int)puVar10 + 2);
    *(undefined2 *)puVar10 = uVar1;
    sVar8 = sVar8 + -1;
    puVar10 = puVar12;
  } while (sVar8 != -1);
  uVar2 = *(undefined2 *)(&DAT_0001a256 + iVar7);
  sVar8 = uVar6 - 3;
  do {
    *(undefined2 *)puVar12 = *(undefined2 *)(&DAT_0001a258 + iVar7);
    sVar9 = uVar4 - 3;
    puVar3 = (undefined2 *)((int)puVar12 + 2);
    do {
      puVar11 = puVar3;
      *puVar11 = uVar2;
      sVar9 = sVar9 + -1;
      puVar3 = puVar11 + 1;
    } while (sVar9 != -1);
    puVar12 = (undefined4 *)(puVar11 + 2);
    puVar11[1] = *(undefined2 *)(&DAT_0001a25a + iVar7);
    sVar8 = sVar8 + -1;
  } while (sVar8 != -1);
  do {
    *(undefined2 *)puVar12 = uVar1;
    sVar5 = sVar5 + -1;
    puVar12 = (undefined4 *)((int)puVar12 + 2);
  } while (sVar5 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000129c8 @ 000129c8

void FUN_000129c8(void)

{
  undefined *unaff_A5;
  
  FUN_00012950();
  FUN_0001296c();
  do {
    FUN_00010f8e();
    if ((unaff_A5[2] & 0x40) == 0) {
      FUN_00012ad6();
    }
    else {
      FUN_00012b04();
    }
    unaff_A5 = unaff_A5 + 3;
  } while (unaff_A5 != &UNK_0002751e);
  return;
}


// ---------------------------------------------------------------
// FUN_000129d6 @ 000129d6

void FUN_000129d6(void)

{
  int unaff_A4;
  int unaff_A5;
  
  do {
    FUN_00010f8e();
    if ((*(byte *)(unaff_A5 + 2) & 0x40) == 0) {
      FUN_00012ad6();
    }
    else {
      FUN_00012b04();
    }
    unaff_A5 = unaff_A5 + 3;
  } while (unaff_A5 != unaff_A4);
  return;
}


// ---------------------------------------------------------------
// FUN_00012a4a @ 00012a4a

void FUN_00012a4a(void)

{
  byte *unaff_A5;
  
  FUN_00012950();
  do {
    FUN_00010f8e();
    if ((*unaff_A5 & 0x80) == 0) {
      FUN_00012ad6();
    }
    else {
      FUN_00012b04();
    }
    unaff_A5 = unaff_A5 + 3;
  } while (unaff_A5 != &UNK_00023e9c);
  DAT_0001a534 = 0x28;
  DAT_0001a530 = 0x20;
  DAT_0001a52e = 0x14;
  DAT_0001a52c = 0x3b;
  return;
}


// ---------------------------------------------------------------
// FUN_00012ad6 @ 00012ad6

void FUN_00012ad6(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short unaff_D2w;
  short unaff_D3w;
  short sVar4;
  short sVar5;
  byte *in_A0;
  byte *pbVar6;
  byte *in_A1;
  byte *pbVar7;
  int unaff_A3;
  
  sVar4 = unaff_D3w + -1;
  sVar5 = unaff_D2w + -1;
  pbVar6 = in_A0;
  do {
    do {
      pbVar7 = in_A1 + 1;
      bVar1 = *in_A1;
      in_A1 = in_A1 + 2;
      bVar2 = *pbVar7;
      bVar3 = bVar2 | bVar1;
      bVar3 = ~(bVar3 << 4 | bVar3 >> 4 | bVar3);
      *in_A0 = bVar3 & *in_A0;
      pbVar7 = in_A0 + 1;
      *in_A0 = bVar1 | *in_A0;
      *pbVar7 = bVar3 & *pbVar7;
      in_A0 = in_A0 + 2;
      *pbVar7 = bVar2 | *pbVar7;
      sVar5 = sVar5 + -1;
    } while (sVar5 != -1);
    in_A0 = pbVar6 + unaff_A3;
    sVar4 = sVar4 + -1;
    sVar5 = unaff_D2w + -1;
    pbVar6 = in_A0;
  } while (sVar4 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00012b04 @ 00012b04

void FUN_00012b04(void)

{
  short sVar1;
  byte bVar2;
  int unaff_D2;
  short unaff_D3w;
  short sVar3;
  short sVar4;
  byte unaff_D6b;
  int in_A0;
  byte *pbVar5;
  int extraout_A0;
  byte *pbVar6;
  int unaff_A3;
  
  pbVar5 = (byte *)(unaff_D2 * 2 + in_A0);
  sVar1 = (short)unaff_D2 + -1;
  sVar3 = unaff_D3w + -1;
  sVar4 = sVar1;
  do {
    do {
      FUN_00012b40();
      FUN_00012b40();
      bVar2 = ~(unaff_D6b << 4 | unaff_D6b >> 4 | unaff_D6b);
      pbVar6 = pbVar5 + -1;
      *pbVar6 = bVar2 & *pbVar6;
      *pbVar6 = unaff_D6b | *pbVar6;
      pbVar5 = pbVar5 + -2;
      *pbVar5 = bVar2 & *pbVar5;
      *pbVar5 = unaff_D6b | *pbVar5;
      sVar4 = sVar4 + -1;
    } while (sVar4 != -1);
    pbVar5 = (byte *)(unaff_A3 + extraout_A0);
    sVar3 = sVar3 + -1;
    sVar4 = sVar1;
  } while (sVar3 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00012b40 @ 00012b40

void FUN_00012b40(void)

{
  return;
}


// ---------------------------------------------------------------
// FUN_00012ce4 @ 00012ce4

void FUN_00012ce4(void)

{
  undefined2 extraout_D1u;
  undefined2 extraout_D1u_00;
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 unaff_D2;
  undefined4 extraout_A0;
  undefined4 extraout_A0_00;
  undefined4 extraout_A0_01;
  undefined4 extraout_A0_02;
  undefined4 extraout_A1;
  undefined4 extraout_A1_00;
  undefined4 extraout_A1_01;
  undefined4 extraout_A1_02;
  int unaff_A6;
  int iVar3;
  
  FUN_00018f8e();
  iVar3 = unaff_A6 + 1;
  DAT_0001acca = DAT_0001acca + 1 & 3;
  if (DAT_0001acca == 0) {
    uVar1 = 0x18;
    if (DAT_0001acc6 != '\t') {
      uVar1 = 0x1e;
    }
    DAT_0001acc6 = uVar1;
    FUN_00014496(iVar3);
    FUN_000117fe(DAT_0001a83e,CONCAT22(extraout_D1u,0x2b),DAT_0001a842,0x3b,DAT_0001a846);
    FUN_0001215e();
    FUN_00011afa(DAT_0001a82e,CONCAT22(extraout_D1u_00,0x2b),DAT_0001a832,0x3b,DAT_0001a836);
    FUN_0001215e();
    xbios_supexec();
    return;
  }
  uVar2 = (undefined2)((uint)unaff_D2 >> 0x10);
  if (DAT_0001acca != 1) {
    if (DAT_0001acca != 2) {
      uVar1 = 9;
      if (DAT_0001acc6 != '_') {
        uVar1 = 0x66;
      }
      DAT_0001acc6 = uVar1;
      FUN_00014496(iVar3);
      DAT_0001a534 = 0x28;
      FUN_00010fec();
      DAT_0001a83e = FUN_000117de();
      DAT_0001a842 = CONCAT22(uVar2,0x14);
      DAT_0001a846 = extraout_A0_01;
      DAT_0001a84a = extraout_A1_01;
      FUN_00010fec();
      DAT_0001a82e = FUN_00011ada();
      DAT_0001a832 = CONCAT22(uVar2,0x14);
      DAT_0001a836 = extraout_A0_02;
      DAT_0001a83a = extraout_A1_02;
      xbios_supexec();
      return;
    }
    uVar1 = 0x5f;
    if (DAT_0001acc6 != '\t') {
      uVar1 = 0x67;
    }
    DAT_0001acc6 = uVar1;
    FUN_00014496(iVar3);
    FUN_00012a4a();
    FUN_000111b6();
    FUN_00012a4a();
    FUN_000114ba();
    FUN_00018f8e();
    return;
  }
  uVar1 = 9;
  if (DAT_0001acc6 != '\x18') {
    uVar1 = 0x66;
  }
  DAT_0001acc6 = uVar1;
  FUN_00014496(iVar3);
  FUN_00012a4a();
  DAT_0001a532 = 0x10;
  FUN_00010fec();
  FUN_000124da();
  DAT_0001a82e = FUN_000111ac();
  DAT_0001a832 = CONCAT22(uVar2,1);
  DAT_0001a836 = extraout_A0;
  DAT_0001a83a = extraout_A1;
  FUN_00012a4a();
  DAT_0001a532 = 0x37;
  FUN_00010fec();
  FUN_000124da();
  DAT_0001a83e = FUN_000114b0();
  DAT_0001a842 = CONCAT22(uVar2,1);
  DAT_0001a846 = extraout_A0_00;
  DAT_0001a84a = extraout_A1_00;
  xbios_supexec();
  return;
}


// ---------------------------------------------------------------
// FUN_00012d96 @ 00012d96

void FUN_00012d96(void)

{
  FUN_00012a4a();
  FUN_00010fec();
  FUN_00012510();
  FUN_00012a4a();
  FUN_00010fec();
  FUN_00012510();
  return;
}


// ---------------------------------------------------------------
// FUN_00012dd8 @ 00012dd8

void FUN_00012dd8(void)

{
  FUN_00012a4a();
  FUN_00010fec();
  FUN_000124da();
  FUN_00012a4a();
  FUN_00010fec();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_00012e08 @ 00012e08

void FUN_00012e08(void)

{
  short sVar1;
  undefined2 extraout_D1w;
  short unaff_D2w;
  short unaff_D3w;
  ushort uVar2;
  
  if (DAT_0001a570 == '\0') {
    sVar1 = FUN_000120e4();
    DAT_0001a577 = 0x11;
    DAT_0001a56a = 100;
    DAT_0001a532 = sVar1 << 2;
    DAT_0001a52e = unaff_D2w * 4;
    DAT_0001a49c = unaff_D3w * DAT_0001a52e;
    uVar2 = 0;
    DAT_0001a530 = extraout_D1w;
    while( true ) {
      FUN_00010fee();
      FUN_00012ef6();
      sVar1 = DAT_0001a56a;
      do {
        sVar1 = sVar1 + -1;
      } while (sVar1 != -1);
      uVar2 = uVar2 + 0x11;
      if (DAT_0001a49c == uVar2) break;
      if (DAT_0001a49c < uVar2) {
        uVar2 = uVar2 - DAT_0001a49c;
      }
    }
    return;
  }
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_00012e2e @ 00012e2e

void FUN_00012e2e(void)

{
  byte bVar1;
  short in_D0w;
  undefined2 in_D1w;
  short sVar2;
  short unaff_D2w;
  short unaff_D3w;
  ushort uVar3;
  
  bVar1 = DAT_0001a577;
  DAT_0001a532 = in_D0w << 2;
  DAT_0001a52e = unaff_D2w * 4;
  DAT_0001a49c = unaff_D3w * DAT_0001a52e;
  uVar3 = 0;
  DAT_0001a530 = in_D1w;
  while( true ) {
    FUN_00010fee();
    FUN_00012ef6();
    sVar2 = DAT_0001a56a;
    do {
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    uVar3 = bVar1 + uVar3;
    if (DAT_0001a49c == uVar3) break;
    if (DAT_0001a49c < uVar3) {
      uVar3 = uVar3 - DAT_0001a49c;
    }
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00012ea2 @ 00012ea2

void FUN_00012ea2(void)

{
  DAT_0001a56a = 1;
  DAT_0001a577 = 0x11;
  FUN_00012e2e();
  return;
}


// ---------------------------------------------------------------
// FUN_00012ef6 @ 00012ef6

void FUN_00012ef6(void)

{
  ushort uVar1;
  ushort unaff_D4w;
  ushort uVar2;
  uint unaff_D7;
  ushort *in_A0;
  ushort *puVar3;
  ushort *puVar4;
  
  uVar2 = unaff_D4w << 0x10 - (unaff_D7 & 0x3f) | unaff_D4w >> (unaff_D7 & 0x3f);
  uVar1 = ~uVar2;
  *in_A0 = uVar1 & *in_A0;
  puVar3 = in_A0 + 1;
  *in_A0 = uVar2 & in_A0[-0x4000] | *in_A0;
  *puVar3 = uVar1 & *puVar3;
  puVar4 = in_A0 + 2;
  *puVar3 = uVar2 & in_A0[-0x3fff] | *puVar3;
  *puVar4 = uVar1 & *puVar4;
  puVar3 = in_A0 + 3;
  *puVar4 = uVar2 & in_A0[-0x3ffe] | *puVar4;
  *puVar3 = uVar1 & *puVar3;
  *puVar3 = uVar2 & in_A0[-0x3ffd] | *puVar3;
  return;
}


// ---------------------------------------------------------------
// FUN_00012f28 @ 00012f28

void FUN_00012f28(void)

{
  short sVar1;
  short unaff_D2w;
  short unaff_D3w;
  ushort uVar2;
  
  if (DAT_0001a570 == '\0') {
    sVar1 = FUN_000128a4();
    DAT_0001a532 = sVar1 << 2;
    DAT_0001a52e = unaff_D2w * 4;
    DAT_0001a49e = unaff_D3w * DAT_0001a52e;
    uVar2 = 0;
    while( true ) {
      FUN_00010fee();
      FUN_00012fb6();
      sVar1 = 100;
      do {
        sVar1 = sVar1 + -1;
      } while (sVar1 != -1);
      uVar2 = uVar2 + 0x11;
      if (DAT_0001a49e == uVar2) break;
      if (DAT_0001a49e < uVar2) {
        uVar2 = uVar2 - DAT_0001a49e;
      }
    }
    return;
  }
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_00012fb6 @ 00012fb6

void FUN_00012fb6(void)

{
  ushort uVar1;
  ushort in_D0w;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint unaff_D7;
  ushort *in_A0;
  ushort *puVar5;
  ushort *puVar6;
  
  uVar4 = -0x8000 << 0x10 - (unaff_D7 & 0x3f) | 0x8000U >> (unaff_D7 & 0x3f);
  uVar1 = ~uVar4;
  uVar2 = in_D0w << 0x10 - (unaff_D7 & 0x3f) | in_D0w >> (unaff_D7 & 0x3f);
  *in_A0 = uVar1 & *in_A0;
  puVar5 = in_A0 + 1;
  *in_A0 = uVar4 & uVar2 | *in_A0;
  uVar3 = uVar2 << 4 | uVar2 >> 0xc;
  *puVar5 = uVar1 & *puVar5;
  puVar6 = in_A0 + 2;
  *puVar5 = uVar4 & uVar3 | *puVar5;
  uVar3 = uVar3 << 4 | (uVar2 & 0xfff) >> 8;
  *puVar6 = uVar1 & *puVar6;
  puVar5 = in_A0 + 3;
  *puVar6 = uVar4 & uVar3 | *puVar6;
  *puVar5 = uVar1 & *puVar5;
  *puVar5 = uVar4 & (uVar3 << 4 | (uVar2 << 4 & 0xfff) >> 8) | *puVar5;
  return;
}


// ---------------------------------------------------------------
// FUN_00012fea @ 00012fea

void FUN_00012fea(void)

{
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_00012fee @ 00012fee

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00012fee(void)

{
  undefined2 extraout_D0u;
  undefined2 in_D0w;
  uint uVar1;
  undefined2 extraout_D1u;
  undefined2 uVar2;
  undefined2 in_D1w;
  uint uVar3;
  uint unaff_D2;
  short unaff_D3w;
  short sVar4;
  undefined4 unaff_D7;
  short sVar5;
  int extraout_A0;
  undefined2 *puVar6;
  
  _DAT_0001a46a = 0x8000;
  FUN_00010fee();
  puVar6 = (undefined2 *)(extraout_A0 - _DAT_0001a46a);
  sVar5 = (short)((uint)unaff_D7 >> 0x10);
  uVar1 = CONCAT22(extraout_D0u,sVar5);
  sVar4 = unaff_D3w + -1;
  uVar3 = CONCAT22(extraout_D1u,0xf - sVar5);
  do {
    while( true ) {
      uVar1 = CONCAT22((short)(uVar1 >> 0x10),*puVar6);
      if ((unaff_D2 & 1) == 0) {
        uVar1 = uVar1 & ~(1 << (uVar3 & 0x1f));
      }
      else {
        uVar1 = uVar1 | 1 << (uVar3 & 0x1f);
      }
      *puVar6 = (short)uVar1;
      uVar1 = CONCAT22((short)(uVar1 >> 0x10),puVar6[1]);
      if ((unaff_D2 & 2) == 0) {
        uVar1 = uVar1 & ~(1 << (uVar3 & 0x1f));
      }
      else {
        uVar1 = uVar1 | 1 << (uVar3 & 0x1f);
      }
      puVar6[1] = (short)uVar1;
      uVar1 = CONCAT22((short)(uVar1 >> 0x10),puVar6[2]);
      if ((unaff_D2 & 4) == 0) {
        uVar1 = uVar1 & ~(1 << (uVar3 & 0x1f));
      }
      else {
        uVar1 = uVar1 | 1 << (uVar3 & 0x1f);
      }
      puVar6[2] = (short)uVar1;
      uVar1 = CONCAT22((short)(uVar1 >> 0x10),puVar6[3]);
      if ((unaff_D2 & 8) == 0) {
        uVar1 = uVar1 & ~(1 << (uVar3 & 0x1f));
      }
      else {
        uVar1 = uVar1 | 1 << (uVar3 & 0x1f);
      }
      puVar6[3] = (short)uVar1;
      uVar2 = (undefined2)(uVar3 >> 0x10);
      if ((short)uVar3 != 0) break;
      puVar6 = puVar6 + 4;
      uVar3 = CONCAT22(uVar2,0xf);
      sVar4 = sVar4 + -1;
      if (sVar4 == -1) goto LAB_0001309a;
    }
    uVar3 = CONCAT22(uVar2,(short)uVar3 + -1);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
LAB_0001309a:
  return CONCAT44(CONCAT22((short)(uVar1 >> 0x10),in_D0w),CONCAT22((short)(uVar3 >> 0x10),in_D1w));
}


// ---------------------------------------------------------------
// FUN_00012ffa @ 00012ffa

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00012ffa(void)

{
  undefined2 extraout_D0u;
  undefined2 in_D0w;
  uint uVar1;
  undefined2 extraout_D1u;
  undefined2 uVar2;
  undefined2 in_D1w;
  uint uVar3;
  uint unaff_D2;
  short unaff_D3w;
  short sVar4;
  undefined4 unaff_D7;
  short sVar5;
  int extraout_A0;
  undefined2 *puVar6;
  
  _DAT_0001a46a = 0;
  FUN_00010fee();
  puVar6 = (undefined2 *)(extraout_A0 - _DAT_0001a46a);
  sVar5 = (short)((uint)unaff_D7 >> 0x10);
  uVar1 = CONCAT22(extraout_D0u,sVar5);
  sVar4 = unaff_D3w + -1;
  uVar3 = CONCAT22(extraout_D1u,0xf - sVar5);
  do {
    while( true ) {
      uVar1 = CONCAT22((short)(uVar1 >> 0x10),*puVar6);
      if ((unaff_D2 & 1) == 0) {
        uVar1 = uVar1 & ~(1 << (uVar3 & 0x1f));
      }
      else {
        uVar1 = uVar1 | 1 << (uVar3 & 0x1f);
      }
      *puVar6 = (short)uVar1;
      uVar1 = CONCAT22((short)(uVar1 >> 0x10),puVar6[1]);
      if ((unaff_D2 & 2) == 0) {
        uVar1 = uVar1 & ~(1 << (uVar3 & 0x1f));
      }
      else {
        uVar1 = uVar1 | 1 << (uVar3 & 0x1f);
      }
      puVar6[1] = (short)uVar1;
      uVar1 = CONCAT22((short)(uVar1 >> 0x10),puVar6[2]);
      if ((unaff_D2 & 4) == 0) {
        uVar1 = uVar1 & ~(1 << (uVar3 & 0x1f));
      }
      else {
        uVar1 = uVar1 | 1 << (uVar3 & 0x1f);
      }
      puVar6[2] = (short)uVar1;
      uVar1 = CONCAT22((short)(uVar1 >> 0x10),puVar6[3]);
      if ((unaff_D2 & 8) == 0) {
        uVar1 = uVar1 & ~(1 << (uVar3 & 0x1f));
      }
      else {
        uVar1 = uVar1 | 1 << (uVar3 & 0x1f);
      }
      puVar6[3] = (short)uVar1;
      uVar2 = (undefined2)(uVar3 >> 0x10);
      if ((short)uVar3 != 0) break;
      puVar6 = puVar6 + 4;
      uVar3 = CONCAT22(uVar2,0xf);
      sVar4 = sVar4 + -1;
      if (sVar4 == -1) goto LAB_0001309a;
    }
    uVar3 = CONCAT22(uVar2,(short)uVar3 + -1);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
LAB_0001309a:
  return CONCAT44(CONCAT22((short)(uVar1 >> 0x10),in_D0w),CONCAT22((short)(uVar3 >> 0x10),in_D1w));
}


// ---------------------------------------------------------------
// FUN_000130a4 @ 000130a4

undefined8 FUN_000130a4(void)

{
  short in_D0w;
  ushort uVar1;
  short in_D1w;
  uint uVar2;
  undefined2 uVar3;
  uint unaff_D2;
  short unaff_D3w;
  short sVar4;
  undefined4 unaff_D7;
  int extraout_A0;
  ushort *puVar5;
  undefined2 *puVar6;
  
  FUN_00010ff4();
  puVar5 = (ushort *)(screen_ptr_a + extraout_A0);
  puVar6 = (undefined2 *)(screen_ptr_b + extraout_A0);
  sVar4 = unaff_D3w + -1;
  uVar2 = (uint)(ushort)(0xf - (short)((uint)unaff_D7 >> 0x10));
  do {
    while( true ) {
      uVar3 = (undefined2)(unaff_D2 >> 0x10);
      if ((CONCAT22(uVar3,*puVar6) & 1 << (uVar2 & 0x1f)) == 0) {
        uVar1 = *puVar5 & ~(ushort)(1 << (uVar2 & 0x1f));
      }
      else {
        uVar1 = *puVar5 | (ushort)(1 << (uVar2 & 0x1f));
      }
      *puVar5 = uVar1;
      if ((CONCAT22(uVar3,puVar6[1]) & 1 << (uVar2 & 0x1f)) == 0) {
        uVar1 = puVar5[1] & ~(ushort)(1 << (uVar2 & 0x1f));
      }
      else {
        uVar1 = puVar5[1] | (ushort)(1 << (uVar2 & 0x1f));
      }
      puVar5[1] = uVar1;
      if ((CONCAT22(uVar3,puVar6[2]) & 1 << (uVar2 & 0x1f)) == 0) {
        uVar1 = puVar5[2] & ~(ushort)(1 << (uVar2 & 0x1f));
      }
      else {
        uVar1 = puVar5[2] | (ushort)(1 << (uVar2 & 0x1f));
      }
      puVar5[2] = uVar1;
      unaff_D2 = CONCAT22(uVar3,puVar6[3]);
      if ((unaff_D2 & 1 << (uVar2 & 0x1f)) == 0) {
        uVar1 = puVar5[3] & ~(ushort)(1 << (uVar2 & 0x1f));
      }
      else {
        uVar1 = puVar5[3] | (ushort)(1 << (uVar2 & 0x1f));
      }
      puVar5[3] = uVar1;
      if ((short)uVar2 != 0) break;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      uVar2 = 0xf;
      sVar4 = sVar4 + -1;
      if (sVar4 == -1) goto LAB_00013158;
    }
    uVar2 = (uint)(ushort)((short)uVar2 - 1);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
LAB_00013158:
  return CONCAT44((int)in_D0w,(int)in_D1w);
}


// ---------------------------------------------------------------
// FUN_00013162 @ 00013162

undefined8 FUN_00013162(void)

{
  short in_D0w;
  ushort uVar1;
  short in_D1w;
  uint uVar2;
  undefined2 uVar3;
  uint unaff_D2;
  short unaff_D3w;
  short sVar4;
  undefined4 unaff_D7;
  int extraout_A0;
  ushort *puVar5;
  undefined2 *puVar6;
  
  FUN_00010ff4();
  puVar5 = (ushort *)(screen_ptr_a + extraout_A0);
  puVar6 = (undefined2 *)(screen_ptr_b + extraout_A0);
  sVar4 = unaff_D3w + -1;
  uVar2 = (uint)(ushort)(0xf - (short)((uint)unaff_D7 >> 0x10));
  do {
    uVar3 = (undefined2)(unaff_D2 >> 0x10);
    if ((CONCAT22(uVar3,*puVar6) & 1 << (uVar2 & 0x1f)) == 0) {
      uVar1 = *puVar5 & ~(ushort)(1 << (uVar2 & 0x1f));
    }
    else {
      uVar1 = *puVar5 | (ushort)(1 << (uVar2 & 0x1f));
    }
    *puVar5 = uVar1;
    if ((CONCAT22(uVar3,puVar6[1]) & 1 << (uVar2 & 0x1f)) == 0) {
      uVar1 = puVar5[1] & ~(ushort)(1 << (uVar2 & 0x1f));
    }
    else {
      uVar1 = puVar5[1] | (ushort)(1 << (uVar2 & 0x1f));
    }
    puVar5[1] = uVar1;
    if ((CONCAT22(uVar3,puVar6[2]) & 1 << (uVar2 & 0x1f)) == 0) {
      uVar1 = puVar5[2] & ~(ushort)(1 << (uVar2 & 0x1f));
    }
    else {
      uVar1 = puVar5[2] | (ushort)(1 << (uVar2 & 0x1f));
    }
    puVar5[2] = uVar1;
    unaff_D2 = CONCAT22(uVar3,puVar6[3]);
    if ((unaff_D2 & 1 << (uVar2 & 0x1f)) == 0) {
      uVar1 = puVar5[3] & ~(ushort)(1 << (uVar2 & 0x1f));
    }
    else {
      uVar1 = puVar5[3] | (ushort)(1 << (uVar2 & 0x1f));
    }
    puVar5[3] = uVar1;
    puVar5 = puVar5 + 0x50;
    puVar6 = puVar6 + 0x50;
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  return CONCAT44((int)in_D0w,(int)in_D1w);
}


// ---------------------------------------------------------------
// FUN_0001320a @ 0001320a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001320a(void)

{
  ushort uVar1;
  undefined2 extraout_D0u;
  undefined2 in_D0w;
  uint uVar2;
  undefined2 extraout_D1u;
  undefined2 in_D1w;
  uint unaff_D2;
  short unaff_D3w;
  short sVar3;
  undefined4 unaff_D7;
  short sVar4;
  int extraout_A0;
  undefined2 *puVar5;
  
  _DAT_0001a46a = 0x8000;
  FUN_00010fee();
  puVar5 = (undefined2 *)(extraout_A0 - _DAT_0001a46a);
  sVar4 = (short)((uint)unaff_D7 >> 0x10);
  uVar2 = CONCAT22(extraout_D0u,sVar4);
  sVar3 = unaff_D3w + -1;
  uVar1 = 0xf - sVar4;
  do {
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),*puVar5);
    if ((unaff_D2 & 1) == 0) {
      uVar2 = uVar2 & ~(1 << (uVar1 & 0x1f));
    }
    else {
      uVar2 = uVar2 | 1 << (uVar1 & 0x1f);
    }
    *puVar5 = (short)uVar2;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),puVar5[1]);
    if ((unaff_D2 & 2) == 0) {
      uVar2 = uVar2 & ~(1 << (uVar1 & 0x1f));
    }
    else {
      uVar2 = uVar2 | 1 << (uVar1 & 0x1f);
    }
    puVar5[1] = (short)uVar2;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),puVar5[2]);
    if ((unaff_D2 & 4) == 0) {
      uVar2 = uVar2 & ~(1 << (uVar1 & 0x1f));
    }
    else {
      uVar2 = uVar2 | 1 << (uVar1 & 0x1f);
    }
    puVar5[2] = (short)uVar2;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),puVar5[3]);
    if ((unaff_D2 & 8) == 0) {
      uVar2 = uVar2 & ~(1 << (uVar1 & 0x1f));
    }
    else {
      uVar2 = uVar2 | 1 << (uVar1 & 0x1f);
    }
    puVar5[3] = (short)uVar2;
    puVar5 = puVar5 + 0x50;
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  return CONCAT44(CONCAT22((short)(uVar2 >> 0x10),in_D0w),CONCAT22(extraout_D1u,in_D1w));
}


// ---------------------------------------------------------------
// FUN_00013216 @ 00013216

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00013216(void)

{
  ushort uVar1;
  undefined2 extraout_D0u;
  undefined2 in_D0w;
  uint uVar2;
  undefined2 extraout_D1u;
  undefined2 in_D1w;
  uint unaff_D2;
  short unaff_D3w;
  short sVar3;
  undefined4 unaff_D7;
  short sVar4;
  int extraout_A0;
  undefined2 *puVar5;
  
  _DAT_0001a46a = 0;
  FUN_00010fee();
  puVar5 = (undefined2 *)(extraout_A0 - _DAT_0001a46a);
  sVar4 = (short)((uint)unaff_D7 >> 0x10);
  uVar2 = CONCAT22(extraout_D0u,sVar4);
  sVar3 = unaff_D3w + -1;
  uVar1 = 0xf - sVar4;
  do {
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),*puVar5);
    if ((unaff_D2 & 1) == 0) {
      uVar2 = uVar2 & ~(1 << (uVar1 & 0x1f));
    }
    else {
      uVar2 = uVar2 | 1 << (uVar1 & 0x1f);
    }
    *puVar5 = (short)uVar2;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),puVar5[1]);
    if ((unaff_D2 & 2) == 0) {
      uVar2 = uVar2 & ~(1 << (uVar1 & 0x1f));
    }
    else {
      uVar2 = uVar2 | 1 << (uVar1 & 0x1f);
    }
    puVar5[1] = (short)uVar2;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),puVar5[2]);
    if ((unaff_D2 & 4) == 0) {
      uVar2 = uVar2 & ~(1 << (uVar1 & 0x1f));
    }
    else {
      uVar2 = uVar2 | 1 << (uVar1 & 0x1f);
    }
    puVar5[2] = (short)uVar2;
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),puVar5[3]);
    if ((unaff_D2 & 8) == 0) {
      uVar2 = uVar2 & ~(1 << (uVar1 & 0x1f));
    }
    else {
      uVar2 = uVar2 | 1 << (uVar1 & 0x1f);
    }
    puVar5[3] = (short)uVar2;
    puVar5 = puVar5 + 0x50;
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  return CONCAT44(CONCAT22((short)(uVar2 >> 0x10),in_D0w),CONCAT22(extraout_D1u,in_D1w));
}


// ---------------------------------------------------------------
// FUN_000132aa @ 000132aa

void FUN_000132aa(void)

{
  undefined4 extraout_A0;
  
  if (DAT_0001a570 == '\0') {
    FUN_000128a4();
    FUN_000127e0();
    FUN_00013370(DAT_0001a52c,extraout_A0);
    FUN_00012466();
    return;
  }
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_000132ec @ 000132ec

void FUN_000132ec(void)

{
  undefined4 extraout_A0;
  
  if (DAT_0001a570 == '\0') {
    FUN_000128a4();
    FUN_000127e0();
    FUN_00013e14(DAT_0001a52c,extraout_A0);
    FUN_00012466();
    return;
  }
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_0001332e @ 0001332e

void FUN_0001332e(void)

{
  undefined4 extraout_A0;
  
  if (DAT_0001a570 == '\0') {
    FUN_000128a4();
    FUN_000127e0();
    FUN_00013eae(DAT_0001a52c,extraout_A0);
    FUN_00012466();
    return;
  }
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_00013370 @ 00013370

void FUN_00013370(void)

{
  short in_D0w;
  short sVar1;
  short in_D1w;
  short extraout_D1w;
  short extraout_D1w_00;
  short extraout_D1w_01;
  short extraout_D1w_02;
  short unaff_D2w;
  short sVar2;
  ushort unaff_D3w;
  short sVar3;
  
  DAT_0001a516 = in_D0w * 4;
  DAT_0001a518 = unaff_D2w * 4 + DAT_0001a516 + -1;
  DAT_0001a522 = unaff_D3w + in_D1w + -1;
  sVar3 = (unaff_D3w >> 1) + 1;
  sVar2 = 0;
  DAT_0001a51a = DAT_0001a518;
  DAT_0001a51c = DAT_0001a516;
  DAT_0001a51e = in_D1w;
  DAT_0001a520 = in_D1w;
  DAT_0001a524 = DAT_0001a522;
  do {
    FUN_00013162();
    sVar1 = FUN_000130a4();
    DAT_0001a516 = sVar2 + sVar1 + 1;
    DAT_0001a51e = extraout_D1w + 1;
    FUN_000130a4();
    sVar1 = FUN_00013162();
    DAT_0001a520 = sVar2 + extraout_D1w_00 + 1;
    DAT_0001a518 = sVar1 + -1;
    FUN_00013162();
    sVar1 = FUN_000130a4();
    DAT_0001a51a = sVar1 + -1;
    DAT_0001a522 = extraout_D1w_01 + -1;
    FUN_00013162();
    sVar1 = FUN_000130a4();
    DAT_0001a524 = extraout_D1w_02 + -1;
    DAT_0001a51c = sVar2 + sVar1 + 1;
    sVar2 = sVar2 + 1;
    sVar1 = 1000;
    do {
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00013474 @ 00013474

void FUN_00013474(void)

{
  if (DAT_0001a570 == '\0') {
    FUN_000120e4();
    FUN_00013370();
    return;
  }
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_00013490 @ 00013490

void FUN_00013490(void)

{
  undefined2 unaff_D3w;
  
  if (DAT_0001a570 == '\0') {
    FUN_000120e4();
    DAT_0001a52c = unaff_D3w;
    FUN_00013e14();
    return;
  }
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_000134b2 @ 000134b2

void FUN_000134b2(void)

{
  undefined2 unaff_D2w;
  undefined2 unaff_D3w;
  
  if (DAT_0001a570 == '\0') {
    FUN_000120e4();
    DAT_0001a52c = unaff_D3w;
    DAT_0001a52e = unaff_D2w;
    FUN_00013eae();
    return;
  }
  FUN_000120e4();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_000134da @ 000134da

void FUN_000134da(void)

{
  FUN_000128a4();
  FUN_000124da();
  return;
}


// ---------------------------------------------------------------
// FUN_0001350c @ 0001350c

undefined2 FUN_0001350c(void)

{
  int unaff_A6;
  
  return CONCAT11(*(undefined1 *)(unaff_A6 + 2),*(undefined1 *)(unaff_A6 + 1));
}


// ---------------------------------------------------------------
// FUN_00013522 @ 00013522

undefined2 FUN_00013522(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int unaff_A6;
  
  uVar1 = *(undefined1 *)(unaff_A6 + 2);
  uVar2 = *(undefined1 *)(unaff_A6 + 1);
  *(int *)(PTR_DAT_0001a7d6 + -4) = unaff_A6 + 3;
  *(undefined4 *)(PTR_DAT_0001a7d6 + -8) = templ_ptr;
  PTR_DAT_0001a7d6 = PTR_DAT_0001a7d6 + -8;
  return CONCAT11(uVar1,uVar2);
}


// ---------------------------------------------------------------
// FUN_00013552 @ 00013552

void FUN_00013552(void)

{
  templ_ptr = *(undefined4 *)PTR_DAT_0001a7d6;
  PTR_DAT_0001a7d6 = PTR_DAT_0001a7d6 + 8;
  return;
}


// ---------------------------------------------------------------
// load_fond @ 00013568

void load_fond(void)

{
  cur_filename = &UNK_0001a41e;
  load_buffer = screen_ptr_b + -0x22;
  load_length = 0x7d22;
  load_resource();
  return;
}


// ---------------------------------------------------------------
// load_named_screen @ 00013572

void load_named_screen(void)

{
  load_buffer = screen_ptr_b + -0x22;
  load_length = 0x7d22;
  load_resource();
  return;
}


// ---------------------------------------------------------------
// FUN_00013594 @ 00013594

/* WARNING: Removing unreachable block (ram,0x000135a4) */

void FUN_00013594(void)

{
                    /* WARNING: Do nothing block with infinite loop */
  do {
  } while( true );
}


// ---------------------------------------------------------------
// FUN_000135ba @ 000135ba

/* WARNING: Control flow encountered bad instruction data */

void FUN_000135ba(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ---------------------------------------------------------------
// set_palette @ 000135da

void set_palette(void)

{
  xbios_setpalette();
  return;
}


// ---------------------------------------------------------------
// FUN_000135e0 @ 000135e0

void FUN_000135e0(void)

{
  return;
}


// ---------------------------------------------------------------
// crt0_init @ 000135e2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void crt0_init(void)

{
  int in_D0;
  
  __m68k_trap(0xe);
  _DAT_0001a558 = (undefined2)in_D0;
  __m68k_trap(0xe);
  screen_ptr_b = in_D0 + -0x8000;
  DAT_0001a466 = in_D0 + -0x8020;
  __m68k_trap(1);
  _DAT_0001a4d4 = *_DAT_00000456;
  screen_ptr_a = in_D0;
  *_DAT_00000456 = &DAT_000160c2;
  _DAT_00000502 = 0x1019a;
  DAT_0001a579 = DAT_000004bd;
  __m68k_trap(1);
  __m68k_trap(0xe);
  unique0x00016c00 = (undefined4 *)(in_D0 + -0x8010);
  _DAT_0001a44a = *unique0x00016c00;
  *unique0x00016c00 = FUN_00013686;
  __m68k_trap(0xe);
  return;
}


// ---------------------------------------------------------------
// FUN_00013686 @ 00013686

void FUN_00013686(void)

{
  short sVar1;
  undefined1 *in_A0;
  undefined1 *puVar2;
  
  sVar1 = 4;
  puVar2 = &DAT_0001a44f;
  do {
    *puVar2 = *in_A0;
    sVar1 = sVar1 + -1;
    in_A0 = in_A0 + 1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// wait_frame @ 00013698

/* WARNING: Removing unreachable block (ram,0x000136bc) */
/* WARNING: Removing unreachable block (ram,0x000136d4) */
/* WARNING: Removing unreachable block (ram,0x000136e0) */
/* WARNING: Removing unreachable block (ram,0x000136f8) */
/* WARNING: Removing unreachable block (ram,0x00013700) */

void wait_frame(void)

{
  __m68k_trap(0xe);
  do {
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00013702 @ 00013702

void FUN_00013702(void)

{
  byte bVar1;
  short unaff_D2w;
  short unaff_D3w;
  undefined2 unaff_D7w;
  ushort *unaff_A2;
  byte *unaff_A6;
  
  FUN_000128a4();
  DAT_0001a544 = unaff_D3w + -1;
  DAT_0001a542 = unaff_D2w * 4 + -1;
  bVar1 = *unaff_A6;
  DAT_0001a486 = unaff_D7w;
  *unaff_A2 = (ushort)unaff_A6[1];
  unaff_A2[-1] = (ushort)bVar1;
  FUN_00013a18();
  return;
}


// ---------------------------------------------------------------
// FUN_00013740 @ 00013740

void FUN_00013740(void)

{
  short sVar1;
  uint uVar2;
  ushort uVar3;
  short unaff_D2w;
  short unaff_D3w;
  ushort uVar4;
  short sVar5;
  short unaff_D7w;
  int extraout_A0;
  int iVar6;
  undefined8 uVar7;
  
  if (DAT_0001a570 != '\0') {
    FUN_000128a4();
    FUN_000124da();
    return;
  }
  uVar7 = FUN_000128a4();
  DAT_0001a544 = unaff_D3w + -1;
  DAT_0001a542 = unaff_D2w * 4 + -1;
  FUN_00010fee(uVar7);
  uVar3 = DAT_0001a52e << 2;
  uVar4 = uVar3;
  if (uVar3 < DAT_0001a52c) {
    uVar4 = DAT_0001a52c;
  }
  uVar2 = (uint)uVar4;
  DAT_0001a54a = (short)(((uint)DAT_0001a52c << 1) / uVar2);
  DAT_0001a54c = (ushort)((((uint)DAT_0001a52c << 1) % uVar2 << 0x10) / uVar2);
  DAT_0001a552 = (short)(((uint)uVar3 << 1) / uVar2);
  DAT_0001a554 = (ushort)((((uint)uVar3 << 1) % uVar2 << 0x10) / uVar2);
  DAT_0001a546 = 2;
  DAT_0001a54e = 2;
  sVar5 = (uVar4 >> 1) - 3;
  iVar6 = extraout_A0;
  DAT_0001a486 = unaff_D7w;
  do {
    FUN_00013a18(sVar5,iVar6);
    uVar4 = DAT_0001a54a + (short)DAT_0001a546;
    uVar3 = (ushort)(DAT_0001a546 >> 0x10);
    sVar1 = DAT_0001a54c + uVar3;
    if (CARRY2(DAT_0001a54c,uVar3)) {
      DAT_0001a546 = CONCAT22(uVar4,sVar1) << 0x10 | (uint)uVar4;
LAB_0001383c:
      iVar6 = iVar6 + -0xa0;
    }
    else {
      DAT_0001a546 = CONCAT22(uVar4,sVar1) << 0x10 | (uint)uVar4;
      if ((uVar4 & 1) == 0) goto LAB_0001383c;
    }
    uVar4 = DAT_0001a552 + (short)DAT_0001a54e;
    uVar3 = (ushort)(DAT_0001a54e >> 0x10);
    sVar1 = DAT_0001a554 + uVar3;
    if (CARRY2(DAT_0001a554,uVar3)) {
      DAT_0001a54e = CONCAT22(sVar1,uVar4 + 1);
LAB_0001387c:
      if (DAT_0001a486 == 0) {
        iVar6 = iVar6 + -8;
        DAT_0001a486 = 0x10;
      }
      DAT_0001a486 = DAT_0001a486 + -1;
    }
    else {
      DAT_0001a54e = CONCAT22(uVar4,sVar1) << 0x10 | (uint)uVar4;
      if ((uVar4 & 1) == 0) goto LAB_0001387c;
    }
    sVar5 = sVar5 + -1;
    if (sVar5 == -1) {
      FUN_000124da();
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------
// FUN_000138a6 @ 000138a6

void FUN_000138a6(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  short sVar5;
  ushort uVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint *puVar11;
  uint *puVar12;
  
  if (DAT_0001a570 != '\0') {
    FUN_000120e4();
    FUN_0001215e();
    return;
  }
  FUN_000120e4();
  FUN_0001398e();
  uVar6 = 1;
  do {
    puVar11 = (uint *)&DAT_0000d8f0;
    bVar4 = false;
    do {
      if ((ushort)((ushort)*puVar11 >> 2) < uVar6) {
        pbVar7 = (byte *)((uint)*(ushort *)puVar11 + screen_ptr_a);
        pbVar9 = (byte *)((uint)*(ushort *)puVar11 + screen_ptr_b);
        sVar5 = 7;
        pbVar10 = pbVar7;
        puVar12 = puVar11;
        do {
          puVar12 = puVar12 + 1;
          if (((uint)*pbVar10 << 0x18 | (uint)pbVar10[2] << 0x10 | (uint)pbVar10[4] << 8 |
              (uint)pbVar10[6]) == *puVar12) {
            bVar1 = pbVar9[2];
            bVar2 = pbVar9[4];
            bVar3 = pbVar9[6];
            *pbVar10 = *pbVar9;
            pbVar10[2] = bVar1;
            pbVar10[4] = bVar2;
            pbVar10[6] = bVar3;
          }
          pbVar10 = pbVar10 + 0xa0;
          pbVar9 = pbVar9 + 0xa0;
          sVar5 = sVar5 + -1;
        } while (sVar5 != -1);
        if ((ushort)*puVar11 != 0) {
          pbVar7 = pbVar7 + (uint)(ushort)(((ushort)*puVar11 & 7) + 1) * 0xa0;
          uVar8 = (int)pbVar7 - screen_ptr_a;
          *(ushort *)puVar11 = (ushort)uVar8;
          if (uVar8 < 0x7800) {
            sVar5 = 7;
            puVar12 = puVar11;
            do {
              puVar12 = puVar12 + 1;
              uVar8 = *puVar12;
              *pbVar7 = (byte)(uVar8 >> 0x18);
              pbVar7[2] = (byte)(uVar8 >> 0x10);
              pbVar7[4] = (byte)(uVar8 >> 8);
              pbVar7[6] = (byte)uVar8;
              pbVar7 = pbVar7 + 0xa0;
              sVar5 = sVar5 + -1;
            } while (sVar5 != -1);
            goto LAB_00013968;
          }
          *(ushort *)((int)puVar11 + 2) = 0;
        }
      }
      else {
LAB_00013968:
        bVar4 = true;
      }
      puVar11 = puVar11 + 9;
    } while (*(ushort *)puVar11 != 0);
    FUN_00013594();
    uVar6 = uVar6 + 1;
    if (!bVar4) {
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------
// FUN_0001398e @ 0001398e

void FUN_0001398e(void)

{
  ushort uVar1;
  ushort unaff_D2w;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  uint unaff_D7;
  byte *in_A0;
  byte *pbVar5;
  byte *pbVar6;
  uint *puVar7;
  uint *puVar8;
  byte *pbVar9;
  
  puVar7 = (uint *)&DAT_0000d8f0;
  if ((unaff_D7 & 8) != 0) {
    in_A0 = in_A0 + 1;
  }
  if ((unaff_D7 & 4) != 0) {
    unaff_D2w = unaff_D2w + 1;
  }
  uVar2 = unaff_D2w >> 1;
  pbVar6 = &DAT_0001a1f2;
  pbVar5 = in_A0;
  uVar3 = uVar2;
  if ((unaff_D2w & 1) == 0) {
    uVar2 = uVar2 - 1;
    uVar3 = uVar2;
  }
  do {
    do {
      sVar4 = 7;
      *(short *)puVar7 = (short)in_A0 - (short)screen_ptr_a;
      pbVar9 = pbVar6 + 1;
      uVar1 = (ushort)*pbVar6;
      if (*pbVar6 == 0) {
        uVar1 = 1;
      }
      *(ushort *)((int)puVar7 + 2) = uVar1;
      pbVar6 = in_A0;
      puVar8 = puVar7 + 1;
      do {
        puVar7 = puVar8 + 1;
        *puVar8 = (uint)*pbVar6 << 0x18 | (uint)pbVar6[2] << 0x10 | (uint)pbVar6[4] << 8 |
                  (uint)pbVar6[6];
        pbVar6 = pbVar6 + 0xa0;
        sVar4 = sVar4 + -1;
        puVar8 = puVar7;
      } while (sVar4 != -1);
      pbVar6 = in_A0 + 1;
      if (((uint)pbVar6 & 1) == 0) {
        pbVar6 = in_A0 + 7;
      }
      uVar2 = uVar2 - 1;
      in_A0 = pbVar6;
      pbVar6 = pbVar9;
    } while (uVar2 != 0xffff);
    in_A0 = pbVar5 + 0x500;
    uVar2 = uVar3 - 1;
    pbVar5 = in_A0;
    uVar3 = uVar2;
  } while (uVar2 != 0xffff);
  *puVar7 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00013a18 @ 00013a18

void FUN_00013a18(void)

{
  uint *puVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar5;
  uint uVar4;
  short unaff_D2w;
  short sVar6;
  short unaff_D3w;
  ushort uVar7;
  ushort uVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint *unaff_A2;
  uint *puVar12;
  
  puVar10 = (uint *)&DAT_0000d8f0;
  DAT_0001a480 = unaff_D3w + 1;
  DAT_0001a490 = DAT_0001a542 / DAT_0001a480;
  DAT_0001a492 = (ushort)(((uint)DAT_0001a542 % (uint)DAT_0001a480 << 0x10) / (uint)DAT_0001a480);
  uVar7 = unaff_D2w + 1;
  DAT_0001a498 = DAT_0001a544 / uVar7;
  DAT_0001a49a = (ushort)(((uint)DAT_0001a544 % (uint)uVar7 << 0x10) / (uint)uVar7);
  DAT_0001a494 = 0;
  uVar4 = 0;
  while( true ) {
    uVar8 = DAT_0001a480;
    iVar9 = (uVar4 & 0xffff) * (uint)DAT_0001a52e * 2 + DAT_0001a528;
    uVar3 = 0x10 - DAT_0001a486;
    uVar4 = unaff_A2[1];
    *puVar10 = *unaff_A2 >> (uVar3 & 0x3f);
    puVar10[1] = uVar4 >> (uVar3 & 0x3f);
    DAT_0001a48c = 0;
    DAT_0001a556 = 0;
    uVar4 = 0;
    puVar12 = unaff_A2;
    while( true ) {
      uVar5 = *(short *)(iVar9 + (uint)(((byte)uVar4 & 0xfc) >> 1)) << ((byte)uVar4 & 3);
      *(ushort *)puVar10 = *(short *)puVar10 << 1 | (ushort)((short)uVar5 < 0);
      *(ushort *)((int)puVar10 + 2) =
           *(ushort *)((int)puVar10 + 2) << 1 | (ushort)(((uVar5 & 0x7fff) >> 0xb & 1) != 0);
      *(ushort *)(puVar10 + 1) =
           *(short *)(puVar10 + 1) << 1 | (ushort)(((uVar5 & 0x7ff) >> 7 & 1) != 0);
      *(ushort *)((int)puVar10 + 6) =
           *(ushort *)((int)puVar10 + 6) << 1 | (ushort)(((uVar5 & 0x7f) >> 3 & 1) != 0);
      uVar3 = uVar3 - 1;
      if (uVar3 == 0) {
        puVar10 = puVar10 + 2;
        puVar12 = puVar12 + 2;
        DAT_0001a556 = DAT_0001a556 + 2;
        uVar3 = 0x10;
      }
      uVar5 = (ushort)(DAT_0001a48c >> 0x10);
      uVar4 = CONCAT22(DAT_0001a490 + (short)DAT_0001a48c,DAT_0001a492 + uVar5);
      if (CARRY2(DAT_0001a492,uVar5)) {
        uVar4 = uVar4 + 0x10000;
      }
      DAT_0001a48c = uVar4 << 0x10 | uVar4 >> 0x10;
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      uVar4 = DAT_0001a48c;
      if (uVar8 == 0) {
        uVar4 = (uint)DAT_0001a542;
      }
    }
    puVar1 = puVar10 + 1;
    sVar6 = -1 << (uVar3 & 0x3f);
    uVar2 = CONCAT22(sVar6,sVar6);
    uVar4 = puVar12[1];
    puVar11 = puVar10 + 1;
    *puVar10 = ~uVar2 & *puVar12 | uVar2 & *puVar10 << (uVar3 & 0x3f);
    puVar10 = puVar10 + 2;
    *puVar11 = ~uVar2 & uVar4 | uVar2 & *puVar1 << (uVar3 & 0x3f);
    DAT_0001a556 = DAT_0001a556 + 2;
    unaff_A2 = unaff_A2 + 0x28;
    uVar3 = (ushort)(DAT_0001a494 >> 0x10);
    uVar4 = CONCAT22(DAT_0001a498 + (short)DAT_0001a494,DAT_0001a49a + uVar3);
    if (CARRY2(DAT_0001a49a,uVar3)) {
      uVar4 = uVar4 + 0x10000;
    }
    DAT_0001a494 = uVar4 << 0x10 | uVar4 >> 0x10;
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    uVar4 = DAT_0001a494;
    if (uVar7 == 0) {
      uVar4 = (uint)DAT_0001a544;
    }
  }
  FUN_000123a0();
  return;
}


// ---------------------------------------------------------------
// FUN_00013bc2 @ 00013bc2

void FUN_00013bc2(void)

{
  ushort uVar1;
  ushort uVar3;
  uint uVar2;
  short unaff_D2w;
  short unaff_D3w;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  ushort *in_A1;
  ushort *puVar7;
  
  DAT_0001a480 = unaff_D3w + 1;
  DAT_0001a490 = DAT_0001a542 / DAT_0001a480;
  DAT_0001a492 = (ushort)(((uint)DAT_0001a542 % (uint)DAT_0001a480 << 0x10) / (uint)DAT_0001a480);
  uVar4 = unaff_D2w + 1;
  DAT_0001a498 = DAT_0001a544 / uVar4;
  DAT_0001a49a = (ushort)(((uint)DAT_0001a544 % (uint)uVar4 << 0x10) / (uint)uVar4);
  DAT_0001a494 = 0;
  uVar2 = 0;
  while( true ) {
    uVar5 = DAT_0001a480;
    iVar6 = (uVar2 & 0xffff) * (uint)DAT_0001a52e * 2 + DAT_0001a528;
    uVar1 = 0x10 - DAT_0001a486;
    in_A1[0] = 0;
    in_A1[1] = 0;
    in_A1[2] = 0;
    in_A1[3] = 0;
    DAT_0001a48c = 0;
    uVar2 = 0;
    puVar7 = in_A1;
    while( true ) {
      uVar3 = *(short *)(iVar6 + (uint)(((byte)uVar2 & 0xfc) >> 1)) << ((byte)uVar2 & 3);
      *puVar7 = *puVar7 << 1 | (ushort)((short)uVar3 < 0);
      puVar7[1] = puVar7[1] << 1 | (ushort)(((uVar3 & 0x7fff) >> 0xb & 1) != 0);
      puVar7[2] = puVar7[2] << 1 | (ushort)(((uVar3 & 0x7ff) >> 7 & 1) != 0);
      puVar7[3] = puVar7[3] << 1 | (ushort)(((uVar3 & 0x7f) >> 3 & 1) != 0);
      uVar1 = uVar1 - 1;
      if (uVar1 == 0) {
        puVar7 = puVar7 + 4;
        uVar1 = 0x10;
      }
      uVar3 = (ushort)(DAT_0001a48c >> 0x10);
      uVar2 = CONCAT22(DAT_0001a490 + (short)DAT_0001a48c,DAT_0001a492 + uVar3);
      if (CARRY2(DAT_0001a492,uVar3)) {
        uVar2 = uVar2 + 0x10000;
      }
      DAT_0001a48c = uVar2 << 0x10 | uVar2 >> 0x10;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      uVar2 = DAT_0001a48c;
      if (uVar5 == 0) {
        uVar2 = (uint)DAT_0001a542;
      }
    }
    *(int *)puVar7 = *(int *)puVar7 << (uVar1 & 0x3f);
    *(int *)(puVar7 + 2) = *(int *)(puVar7 + 2) << (uVar1 & 0x3f);
    in_A1 = in_A1 + 0x50;
    uVar1 = (ushort)(DAT_0001a494 >> 0x10);
    uVar2 = CONCAT22(DAT_0001a498 + (short)DAT_0001a494,DAT_0001a49a + uVar1);
    if (CARRY2(DAT_0001a49a,uVar1)) {
      uVar2 = uVar2 + 0x10000;
    }
    DAT_0001a494 = uVar2 << 0x10 | uVar2 >> 0x10;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    uVar2 = DAT_0001a494;
    if (uVar4 == 0) {
      uVar2 = (uint)DAT_0001a544;
    }
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00013d0e @ 00013d0e

void FUN_00013d0e(void)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  uint uVar6;
  short sVar7;
  ushort unaff_D7w;
  short sVar8;
  byte *extraout_A0;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  
  DAT_00055b02 = DAT_0001a518 < DAT_0001a516;
  uVar3 = DAT_0001a518 - DAT_0001a516;
  if ((bool)DAT_00055b02) {
    uVar3 = ~uVar3;
  }
  DAT_00055b03 = DAT_0001a51c < DAT_0001a51a;
  uVar4 = DAT_0001a51c - DAT_0001a51a;
  if ((bool)DAT_00055b03) {
    uVar4 = ~uVar4;
  }
  sVar7 = uVar4 + uVar3 + 1;
  sVar5 = uVar4 * 2;
  FUN_00010fee();
  pbVar9 = extraout_A0;
  if ((unaff_D7w & 8) != 0) {
    pbVar9 = extraout_A0 + 1;
  }
  pbVar11 = pbVar9 + -0x8000;
  uVar6 = -0x7f7f7f80 << 0x20 - (uint)(unaff_D7w & 7) | 0x80808080U >> (uint)(unaff_D7w & 7);
  sVar8 = ~(uVar3 << 1) + sVar5;
  do {
    uVar1 = ~uVar6 & ((uint)*pbVar9 << 0x18 | (uint)pbVar9[2] << 0x10 | (uint)pbVar9[4] << 8 |
                     (uint)pbVar9[6]) |
            uVar6 & ((uint)*pbVar11 << 0x18 | (uint)pbVar11[2] << 0x10 | (uint)pbVar11[4] << 8 |
                    (uint)pbVar11[6]);
    *pbVar9 = (byte)(uVar1 >> 0x18);
    pbVar9[2] = (byte)(uVar1 >> 0x10);
    pbVar9[4] = (byte)(uVar1 >> 8);
    pbVar9[6] = (byte)uVar1;
    pbVar10 = pbVar9;
    pbVar12 = pbVar11;
    do {
      sVar7 = sVar7 + -1;
      if (sVar7 == 0) {
        return;
      }
      if (0 < sVar8) {
        if (DAT_00055b03 == '\x01') {
          pbVar9 = pbVar10 + -0xa0;
          pbVar11 = pbVar12 + -0xa0;
        }
        else {
          pbVar9 = pbVar10 + 0xa0;
          pbVar11 = pbVar12 + 0xa0;
        }
        sVar8 = ~(uVar3 << 1) + sVar8;
        break;
      }
      pbVar9 = pbVar10;
      pbVar11 = pbVar12;
      if (DAT_00055b02 == '\x01') {
        iVar2 = (int)uVar6 >> 0x1f;
        uVar6 = uVar6 << 1 | -iVar2;
        if (-iVar2 != 0) {
          pbVar9 = pbVar10 + -1;
          pbVar11 = pbVar12 + -1;
          if (((uint)pbVar9 & 1) != 0) {
            pbVar9 = pbVar10 + -7;
            pbVar11 = pbVar12 + -7;
          }
        }
      }
      else {
        uVar1 = uVar6 << 0x1f;
        uVar6 = uVar1 | uVar6 >> 1;
        if (uVar1 != 0) {
          pbVar9 = pbVar10 + 1;
          pbVar11 = pbVar12 + 1;
          if (((uint)(pbVar10 + 1) & 1) == 0) {
            pbVar9 = pbVar10 + 7;
            pbVar11 = pbVar12 + 7;
          }
        }
      }
      bVar13 = SCARRY2(sVar5,sVar8);
      sVar8 = sVar5 + sVar8;
      pbVar10 = pbVar9;
      pbVar12 = pbVar11;
    } while (sVar8 != 0 && bVar13 == sVar8 < 0);
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00013e14 @ 00013e14

void FUN_00013e14(void)

{
  short sVar1;
  short in_D0w;
  short in_D1w;
  short unaff_D2w;
  short sVar2;
  short sVar3;
  short unaff_D3w;
  
  DAT_0001a518 = unaff_D2w * 4 + in_D0w * 4;
  DAT_0001a51c = in_D1w + unaff_D3w + -1;
  sVar2 = unaff_D2w * 4 + -1;
  sVar3 = in_D0w * 4;
  DAT_0001a51a = in_D1w;
  do {
    DAT_0001a516 = sVar3;
    DAT_0001a518 = DAT_0001a518 + -1;
    FUN_00013d0e();
    FUN_00013594();
    sVar1 = DAT_0001a51a;
    sVar2 = sVar2 + -1;
    sVar3 = DAT_0001a516 + 1;
  } while (sVar2 != -1);
  sVar2 = DAT_0001a516;
  DAT_0001a516 = DAT_0001a518;
  DAT_0001a51a = DAT_0001a51c;
  DAT_0001a51c = sVar1;
  sVar3 = DAT_0001a52c + -1;
  DAT_0001a518 = sVar2;
  do {
    FUN_00013d0e();
    FUN_00013594();
    DAT_0001a51a = DAT_0001a51a + -1;
    DAT_0001a51c = DAT_0001a51c + 1;
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00013eae @ 00013eae

void FUN_00013eae(void)

{
  short in_D0w;
  short in_D1w;
  short unaff_D2w;
  short sVar1;
  short sVar2;
  short unaff_D3w;
  
  DAT_0001a516 = in_D0w * 4;
  DAT_0001a518 = unaff_D2w * 2 + DAT_0001a516 + -1;
  DAT_0001a51a = in_D1w + unaff_D3w + -1;
  sVar1 = unaff_D3w + -1;
  DAT_0001a51c = DAT_0001a51a;
  do {
    FUN_00013d0e();
    FUN_00013594();
    DAT_0001a51a = DAT_0001a51a + -1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  sVar1 = DAT_0001a52e * 4 + -1;
  do {
    FUN_00013d0e();
    FUN_00013594();
    DAT_0001a516 = DAT_0001a516 + 1;
    sVar1 = sVar1 + -1;
    sVar2 = DAT_0001a52c;
  } while (sVar1 != -1);
  do {
    FUN_00013d0e();
    FUN_00013594();
    DAT_0001a51a = DAT_0001a51a + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00013f2a @ 00013f2a

void FUN_00013f2a(void)

{
  FUN_00013f56();
  FUN_00018f7a();
  copy_screen();
  return;
}


// ---------------------------------------------------------------
// FUN_00013f4c @ 00013f4c

void FUN_00013f4c(void)

{
  undefined *unaff_A5;
  int unaff_A6;
  
  DAT_0001a49e = 0;
  FUN_00012950(unaff_A6 + 2);
  DAT_0001a4b2 = &UNK_00024982;
  do {
    FUN_00014138();
    unaff_A5 = unaff_A5 + 3;
  } while (unaff_A5 != DAT_0001a4b2);
  return;
}


// ---------------------------------------------------------------
// FUN_00013f56 @ 00013f56

void FUN_00013f56(void)

{
  undefined2 in_D0w;
  undefined *unaff_A5;
  
  DAT_0001a49e = in_D0w;
  FUN_00012950();
  DAT_0001a4b2 = &UNK_00024982;
  do {
    FUN_00014138();
    unaff_A5 = unaff_A5 + 3;
  } while (unaff_A5 != DAT_0001a4b2);
  return;
}


// ---------------------------------------------------------------
// FUN_00013f86 @ 00013f86

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013f86(void)

{
  byte bVar1;
  undefined4 extraout_D1;
  char unaff_D2b;
  char unaff_D3b;
  byte unaff_D5b;
  byte unaff_D6b;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte *unaff_A5;
  
  FUN_00015944();
  DAT_0001a49e = (undefined2)CONCAT31((int3)((uint)extraout_D1 >> 8),DAT_0001acf1);
  FUN_00012950();
  DAT_0001a4b2 = &UNK_00024982;
  _DAT_0001ab40 = 0xff00ff00;
  DAT_0001a751 = '\0';
  puVar2 = &DAT_0001a7b6;
LAB_00013fca:
  do {
    bVar1 = *unaff_A5;
    puVar3 = puVar2;
    if ((0x31 < bVar1) && (bVar1 < 0x3d)) {
      puVar3 = puVar2 + 1;
      *puVar2 = unaff_A5 + -3;
      DAT_0001a751 = DAT_0001a751 + '\x01';
      if ((DAT_0001a751 == DAT_0001acc9) ||
         (((DAT_0001acc7 == ' ' && (bVar1 == 0x3b)) && ((DAT_0001aced & 8) != 0)))) {
        unaff_A5 = unaff_A5 + 3;
        puVar2 = puVar3;
        goto LAB_00013fca;
      }
    }
    FUN_00014138();
    if (unaff_D6b < DAT_0001ab40) {
      _DAT_0001ab40 = CONCAT13(unaff_D6b,_DAT_0001ab41);
    }
    if (DAT_0001ab41 <= (byte)(unaff_D2b + unaff_D6b)) {
      _DAT_0001ab41 = CONCAT12(unaff_D2b + unaff_D6b,_DAT_0001ab42);
    }
    if (unaff_D5b < DAT_0001ab42) {
      _DAT_0001ab42 = CONCAT11(unaff_D5b,DAT_0001ab43);
    }
    if (DAT_0001ab43 <= (byte)(unaff_D3b + unaff_D5b)) {
      _DAT_0001ab40 = CONCAT31(_DAT_0001ab40,unaff_D3b + unaff_D5b);
    }
    unaff_A5 = unaff_A5 + 3;
    puVar2 = puVar3;
    if (unaff_A5 == DAT_0001a4b2) {
      DAT_0001a50a = (ushort)DAT_0001ab40;
      DAT_0001ab49 = (DAT_0001ab41 - DAT_0001ab40) + -2;
      DAT_0001aa6a = DAT_0001a50a + 1;
      DAT_0001a50c = (ushort)(byte)(DAT_0001ab43 + 2);
      _DAT_0001a46a = 0x8000;
      PTR_DAT_0001a4d8 = &UNK_0001d3c2;
      DAT_0001aa6c = DAT_0001a50c;
      print_char();
      FUN_000109fe();
      print_char();
      FUN_00012fee();
      FUN_00012fee();
      FUN_00012fee();
      FUN_0001320a();
      FUN_0001320a();
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00014138 @ 00014138

void FUN_00014138(void)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  ushort uVar6;
  undefined1 *extraout_A1;
  char *unaff_A6;
  
  FUN_00010f8e();
  bVar3 = unaff_A6[1];
  uVar1 = *extraout_A1;
  bVar2 = extraout_A1[1];
  if ((bVar3 & 0x80) != 0) {
    bVar3 = bVar3 & 0x7f;
  }
  DAT_0001a534 = (uint)bVar2 << 1;
  if ((unaff_A6[2] & 0x80U) != 0) {
    DAT_0001a534 = ~DAT_0001a534 + 1;
  }
  uVar6 = (ushort)(byte)(unaff_A6[2] << 1);
  if ((*unaff_A6 == 'S') && (uVar4 = DAT_0001a49e & 1, DAT_0001a49e = DAT_0001a49e >> 1, uVar4 != 0)
     ) {
    uVar6 = uVar6 - 8;
  }
  uVar5 = DAT_0001a534 >> 0x10;
  FUN_00010fec();
  if ((unaff_A6[1] & 0x80U) == 0) {
    FUN_00011050();
  }
  else {
    FUN_00011102(bVar2,uVar1,CONCAT22((short)uVar5,uVar6),bVar3);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000141dc @ 000141dc

void FUN_000141dc(void)

{
  FUN_00014138();
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_000141ea @ 000141ea

void FUN_000141ea(void)

{
  FUN_00014138();
  return;
}


// ---------------------------------------------------------------
// FUN_000141f4 @ 000141f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000141f4(void)

{
  short sVar1;
  int unaff_A6;
  
  FUN_000142cc(unaff_A6 + 2);
  FUN_00018f8e();
  sVar1 = (_DAT_0000d902 >> 1) - 1;
  do {
    FUN_000143e2();
    _DAT_0000d902 = _DAT_0000d902 - 2;
    _DAT_0000d904 = (uint)_DAT_0000d900 * 4 + _DAT_0000d904;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  FUN_00018f7a();
  return;
}


// ---------------------------------------------------------------
// FUN_000141fa @ 000141fa

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000141fa(void)

{
  short sVar1;
  
  FUN_000142cc();
  FUN_00018f8e();
  sVar1 = (_DAT_0000d902 >> 1) - 1;
  do {
    FUN_000143e2();
    _DAT_0000d902 = _DAT_0000d902 - 2;
    _DAT_0000d904 = (uint)_DAT_0000d900 * 4 + _DAT_0000d904;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  FUN_00018f7a();
  return;
}


// ---------------------------------------------------------------
// FUN_00014246 @ 00014246

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014246(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int unaff_A6;
  
  FUN_000142cc(unaff_A6 + 2);
  FUN_00018f8e();
  iVar2 = _DAT_0000d904;
  uVar1 = _DAT_0000d902;
  iVar3 = (uint)_DAT_0000d900 * 2;
  _DAT_0000d904 =
       (_DAT_0000d900 & 0x7fff) * 2 * (uint)_DAT_0000d902 + _DAT_0000d904 + (uint)_DAT_0000d900 * -2
  ;
  sVar4 = (_DAT_0000d902 >> 1) - 1;
  _DAT_0000d902 = 1;
  do {
    FUN_000143e2();
    _DAT_0000d902 = _DAT_0000d902 + 2;
    _DAT_0000d904 = _DAT_0000d904 - CONCAT22((short)((uint)iVar3 >> 0x10),(short)iVar3 << 1);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  _DAT_0000d902 = uVar1;
  _DAT_0000d904 = iVar2;
  FUN_000143e2();
  FUN_00018f8e();
  return;
}


// ---------------------------------------------------------------
// FUN_0001424c @ 0001424c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001424c(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  
  FUN_000142cc();
  FUN_00018f8e();
  iVar2 = _DAT_0000d904;
  uVar1 = _DAT_0000d902;
  iVar3 = (uint)_DAT_0000d900 * 2;
  _DAT_0000d904 =
       (_DAT_0000d900 & 0x7fff) * 2 * (uint)_DAT_0000d902 + _DAT_0000d904 + (uint)_DAT_0000d900 * -2
  ;
  sVar4 = (_DAT_0000d902 >> 1) - 1;
  _DAT_0000d902 = 1;
  do {
    FUN_000143e2();
    _DAT_0000d902 = _DAT_0000d902 + 2;
    _DAT_0000d904 = _DAT_0000d904 - CONCAT22((short)((uint)iVar3 >> 0x10),(short)iVar3 << 1);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  _DAT_0000d902 = uVar1;
  _DAT_0000d904 = iVar2;
  FUN_000143e2();
  FUN_00018f8e();
  return;
}


// ---------------------------------------------------------------
// FUN_000142cc @ 000142cc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000142cc(void)

{
  byte bVar1;
  byte bVar2;
  ushort *puVar3;
  char in_D0b;
  ushort uVar4;
  byte bVar6;
  ushort uVar5;
  ushort uVar7;
  ushort uVar8;
  short sVar9;
  byte bVar10;
  ushort unaff_D7w;
  int extraout_A0;
  undefined4 extraout_A0_00;
  byte *extraout_A1;
  undefined4 extraout_A1_00;
  ushort *puVar11;
  int iVar12;
  
  _DAT_0001a56c = 0xff00ff00;
  iVar12 = (&DAT_0001a7b6)[(byte)(in_D0b - 1) & 0xf];
  sVar9 = 2;
  _DAT_0000d8f0 = 0;
  if ((*(byte *)(iVar12 + 1) & 0x80) != 0) {
    _DAT_0000d8f0 = 0xffff;
  }
  puVar3 = (ushort *)&DAT_0000d8f2;
  do {
    puVar11 = puVar3;
    FUN_00010f8e();
    bVar10 = *(byte *)(iVar12 + 1);
    bVar1 = *extraout_A1;
    bVar2 = extraout_A1[1];
    if ((bVar10 & 0x80) != 0) {
      bVar10 = bVar10 & 0x7f;
    }
    DAT_0001a534 = (uint)bVar2 << 1;
    bVar6 = *(char *)(iVar12 + 2) * '\x02';
    if (bVar10 < DAT_0001a56c) {
      _DAT_0001a56c = CONCAT13(bVar10,_DAT_0001a56d);
    }
    if (DAT_0001a56d <= (byte)(bVar2 + bVar10)) {
      _DAT_0001a56d = CONCAT12(bVar2 + bVar10,_DAT_0001a56e);
    }
    if (bVar6 < DAT_0001a56e) {
      _DAT_0001a56e = CONCAT11(bVar6,DAT_0001a56f);
    }
    bVar6 = bVar1 + bVar6;
    if (DAT_0001a56f <= bVar6) {
      _DAT_0001a56c = CONCAT31(_DAT_0001a56c,bVar6);
    }
    FUN_00010fec();
    *puVar11 = (ushort)bVar2;
    puVar11[1] = (ushort)bVar1;
    *(undefined4 *)(puVar11 + 2) = extraout_A1_00;
    *(int *)(puVar11 + 4) = extraout_A0 + -0x8000;
    puVar11[6] = unaff_D7w;
    iVar12 = iVar12 + 3;
    sVar9 = sVar9 + -1;
    puVar3 = puVar11 + 7;
  } while (sVar9 != -1);
  uVar4 = (ushort)DAT_0001a56c;
  uVar7 = (ushort)DAT_0001a56d;
  uVar5 = (ushort)DAT_0001a56e;
  uVar8 = (ushort)DAT_0001a56f;
  FUN_00010fec();
  puVar11[7] = uVar7 - uVar4;
  puVar11[8] = uVar8 - uVar5;
  *(undefined4 *)(puVar11 + 9) = extraout_A0_00;
  puVar11[0xb] = unaff_D7w;
  return;
}


// ---------------------------------------------------------------
// FUN_000143e2 @ 000143e2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000143e2(void)

{
  short sVar1;
  
  sVar1 = 2;
  do {
    if (_DAT_0000d8f0 == 0) {
      FUN_00011050();
    }
    else {
      FUN_00011102();
    }
    FUN_00013594();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  FUN_0001215e();
  return;
}


// ---------------------------------------------------------------
// FUN_0001442c @ 0001442c

void FUN_0001442c(void)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0001acc7;
  FUN_0001443e();
  DAT_0001acc7 = uVar1;
  return;
}


// ---------------------------------------------------------------
// FUN_0001443e @ 0001443e

void FUN_0001443e(void)

{
  char cVar1;
  short sVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  int unaff_A6;
  
  cVar1 = *(char *)(unaff_A6 + 1);
  DAT_0001accb = DAT_0001acc6;
  uVar3 = 0xe5;
  DAT_0001acc6 = cVar1;
  if (((DAT_0001ad32 != '\0') || (uVar3 = 0xdd, cVar1 == -0x7f)) || (uVar3 = 0xde, cVar1 == -0x7e))
  {
    sVar2 = 7;
    puVar4 = &DAT_0001a695;
    do {
      *puVar4 = uVar3;
      sVar2 = sVar2 + -1;
      puVar4 = puVar4 + 1;
    } while (sVar2 != -1);
  }
  FUN_00014496();
  FUN_00014588();
  return;
}


// ---------------------------------------------------------------
// FUN_00014496 @ 00014496

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014496(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  undefined1 *unaff_A5;
  ushort *puVar6;
  ushort *puVar7;
  
  do {
    FUN_00012950();
  } while (DAT_0000d8eb != 'R');
  DAT_0001acd2 = *unaff_A5;
  DAT_0001acc7 = unaff_A5[1];
  DAT_0001ab48 = unaff_A5[2];
  DAT_0001ab45 = unaff_A5[2];
  DAT_0001acf4 = unaff_A5[3];
  object_list_begin = (ushort *)(unaff_A5 + 5);
  DAT_0001ab4b = unaff_A5[4];
  if (DAT_0001ab4b != 0) {
    sVar2 = DAT_0001ab4b - 1;
    sVar3 = 0x4a;
    puVar4 = &DAT_0001ab62;
    do {
      *puVar4 = 0;
      sVar3 = sVar3 + -1;
      puVar4 = puVar4 + 1;
    } while (sVar3 != -1);
    puVar5 = &DAT_0001ab62;
    do {
      uVar1 = *object_list_begin;
      puVar6 = object_list_begin + 1;
      if ((uVar1 & 0x10) != 0) {
        puVar6 = object_list_begin + 2;
        *puVar5 = object_list_begin[1];
      }
      puVar7 = puVar6;
      if ((uVar1 & 8) != 0) {
        puVar7 = puVar6 + 1;
        puVar5[1] = *puVar6;
      }
      puVar6 = puVar7;
      if ((uVar1 & 4) != 0) {
        puVar6 = puVar7 + 1;
        puVar5[2] = *puVar7;
      }
      puVar7 = puVar6;
      if ((uVar1 & 2) != 0) {
        puVar7 = puVar6 + 1;
        puVar5[3] = *puVar6;
      }
      object_list_begin = puVar7;
      if ((uVar1 & 1) != 0) {
        object_list_begin = puVar7 + 1;
        puVar5[4] = *puVar7;
      }
      puVar5 = puVar5 + 5;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
  }
  _DAT_0001a762 = object_list_begin;
  object_list_end = &UNK_0001ad38;
  DAT_0001a7d2 = object_list_begin;
  DAT_0001ab4a = 0;
  DAT_0001acd3 = 0;
  DAT_0001aceb = 0;
  DAT_0001abf8 = 0;
  DAT_0001acae = 0;
  DAT_0001acaa = 0;
  DAT_0001ace7 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00014588 @ 00014588

void FUN_00014588(void)

{
  DAT_0001abfa = 0;
  DAT_0001ab5c = 0xa01c;
  DAT_0001ab5e = 0;
  DAT_0001ab56 = 0xf7;
  DAT_0001ab50 = 0x9048;
  DAT_0001ab52 = 0xa01d;
  DAT_0001ab54 = 0;
  DAT_0001ab58 = 0x9048;
  DAT_0001ab5a = 0x9048;
  DAT_0001ad09 = 0;
  DAT_0001ad11 = 0;
  DAT_0001ad0b = 0;
  DAT_0001ad27 = 0;
  DAT_0001acd1 = 0;
  DAT_0001acf9 = 0;
  DAT_0001acfa = 0;
  DAT_0001acce = 0;
  DAT_0001acff = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00014602 @ 00014602

void FUN_00014602(void)

{
  FUN_0001460a();
  FUN_00012368();
  FUN_0001232e();
  FUN_00012384();
  if ((DAT_0001a572 == '\0') && (DAT_0001a570 == '\0')) {
    FUN_00015934();
  }
  copy_screen();
  DAT_0001ab4f = 0;
  xbios_supexec();
  if (DAT_0001acd2 == '\x16') {
    FUN_00018f8e();
    DAT_0001ab4f = 1;
  }
  FUN_00014748();
  FUN_000162da();
  FUN_0001857c();
  FUN_00018944();
  if (DAT_0001acc9 != '\0') {
    FUN_0001424c();
  }
  draw_hint_icons();
  return;
}


// ---------------------------------------------------------------
// FUN_0001460a @ 0001460a

void FUN_0001460a(void)

{
  byte bVar1;
  int unaff_A4;
  int unaff_A5;
  
  DAT_0001a572 = 0;
  bVar1 = 0;
  if (DAT_0001a570 == '\0') {
    if ((DAT_0001ad0f & 0x38) != 0) {
      if ((DAT_0001ad0f & 0x38) != 8) goto LAB_0001464e;
      DAT_0001a572 = 1;
      FUN_000141fa();
    }
    bVar1 = DAT_0001ad0f & 7;
  }
LAB_0001464e:
  DAT_0001acc8 = bVar1;
  FUN_000188ce();
  FUN_0001443e();
  DAT_0001acfe = DAT_0001acd2;
  if (DAT_0001acc8 != 0) {
    DAT_0001acc9 = 1;
    do {
      if ((DAT_0001acc8 | 0x88) == *(byte *)(unaff_A5 + 4)) goto LAB_0001468c;
      DAT_0001acc9 = DAT_0001acc9 + 1;
      unaff_A5 = unaff_A5 + 8;
    } while (unaff_A4 != unaff_A5);
  }
  DAT_0001acc9 = 0;
LAB_0001468c:
  DAT_0001a572 = DAT_0001acc9 | DAT_0001a572;
  FUN_00013f86();
  if (DAT_0001ad25 != '\0') {
    FUN_00013f56();
    DAT_0001ad25 = '\0';
  }
  FUN_00016460();
  FUN_00017094();
  FUN_000172ca();
  FUN_00017480();
  update_icon_list();
  DAT_0001ad0f = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_000146d0 @ 000146d0

void FUN_000146d0(void)

{
  int unaff_A6;
  
  FUN_00012368(unaff_A6 + 1);
  FUN_0001232e();
  FUN_00012384();
  if ((DAT_0001a572 == '\0') && (DAT_0001a570 == '\0')) {
    FUN_00015934();
  }
  copy_screen();
  DAT_0001ab4f = 0;
  xbios_supexec();
  if (DAT_0001acd2 == '\x16') {
    FUN_00018f8e();
    DAT_0001ab4f = 1;
  }
  FUN_00014748();
  FUN_000162da();
  FUN_0001857c();
  FUN_00018944();
  if (DAT_0001acc9 != '\0') {
    FUN_0001424c();
  }
  draw_hint_icons();
  return;
}


// ---------------------------------------------------------------
// FUN_00014748 @ 00014748

void FUN_00014748(void)

{
  if (DAT_0001acc6 == '\t') {
    FUN_00012d96();
  }
  if (DAT_0001acc6 == 'f') {
    FUN_00012d96();
  }
  if (DAT_0001acc6 == '_') {
    FUN_00012dd8();
  }
  if (DAT_0001acc6 == 'g') {
    FUN_00012dd8();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0001478a @ 0001478a

void FUN_0001478a(void)

{
  byte bVar1;
  byte *unaff_A4;
  
  bVar1 = (byte)(cursor_x >> 2);
  if ((((*unaff_A4 <= bVar1) && (bVar1 < unaff_A4[1])) && (unaff_A4[2] <= (byte)cursor_y)) &&
     ((byte)cursor_y < unaff_A4[3])) {
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00014798 @ 00014798

void FUN_00014798(void)

{
  byte in_D0b;
  byte in_D1b;
  byte *unaff_A4;
  
  if ((((*unaff_A4 <= in_D0b) && (in_D0b < unaff_A4[1])) && (unaff_A4[2] <= in_D1b)) &&
     (in_D1b < unaff_A4[3])) {
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000147c2 @ 000147c2

void FUN_000147c2(void)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  
  uVar1 = 10;
  bVar3 = false;
  FUN_0001478a();
  if (!bVar3) {
    sVar2 = 6;
    do {
      bVar3 = 0xfffe < uVar1;
      uVar1 = uVar1 + 1;
      FUN_00014798();
      if (bVar3) break;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    if (!bVar3) {
      DAT_0001ab46 = 100;
      DAT_0001a48a = 1;
      the_command = 0;
      return;
    }
  }
  the_command = uVar1 | 0xa000;
  DAT_0001ab46 = (char)uVar1 + '\x02';
  if (DAT_0001ab46 == '\x03') {
    DAT_0001ab46 = 'e';
  }
  DAT_0001a48a = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_000147ce @ 000147ce

void FUN_000147ce(void)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  
  uVar1 = 1;
  bVar3 = false;
  FUN_0001478a();
  if (!bVar3) {
    sVar2 = 6;
    do {
      bVar3 = 0xfffe < uVar1;
      uVar1 = uVar1 + 1;
      FUN_00014798();
      if (bVar3) break;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    if (!bVar3) {
      DAT_0001ab46 = 100;
      DAT_0001a48a = 1;
      the_command = 0;
      return;
    }
  }
  the_command = uVar1 | 0xa000;
  DAT_0001ab46 = (char)uVar1 + '\x02';
  if (DAT_0001ab46 == '\x03') {
    DAT_0001ab46 = 'e';
  }
  DAT_0001a48a = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00014832 @ 00014832

void FUN_00014832(void)

{
  hit_test_objects();
  PTR_DAT_000199ca = &UNK_000194dc;
  if (DAT_0001a48a == '\0') {
    PTR_DAT_000199ca = &UNK_0001961c;
    if (((DAT_0001ad0f & 0x38) != 0x10) &&
       (PTR_DAT_000199ca = &UNK_0001965c, (DAT_0001ad0f & 0x20) != 0)) {
      PTR_DAT_000199ca = &UNK_0001969c;
    }
  }
  return;
}


// ---------------------------------------------------------------
// hit_test_objects @ 00014886

void hit_test_objects(void)

{
  short sVar1;
  byte unaff_D2b;
  byte unaff_D3b;
  byte bVar2;
  undefined1 *puVar3;
  uint uVar4;
  bool bVar5;
  
  bVar2 = 1;
  bVar5 = false;
  uVar4 = object_list_begin;
  while (((FUN_00014798(), !bVar5 || ((*(byte *)(uVar4 + 4) & 0x80) == 0)) ||
         ((unaff_D2b & *(byte *)(uVar4 + 4)) != unaff_D3b))) {
    uVar4 = uVar4 + 8;
    bVar2 = bVar2 + 1;
    bVar5 = uVar4 < object_list_end;
    if (uVar4 == object_list_end) {
      DAT_0001a48a = 1;
      DAT_0001ab45 = DAT_0001ab48;
      DAT_0001acc9 = 0;
      return;
    }
  }
  DAT_0001acc9 = bVar2;
  selected_icon_ptr = &command_hints_list + (byte)(bVar2 - 1);
  selected_object = uVar4;
  DAT_0001ad0f = *(undefined1 *)(uVar4 + 4);
  DAT_0001ab45 = *(undefined1 *)(uVar4 + 5);
  DAT_0001a48a = 0;
  the_command = *(undefined2 *)(uVar4 + 6);
  sVar1 = 0x28;
  puVar3 = &DAT_0001aa72;
  DAT_0001ace6 = '\x01';
  do {
    if ((puVar3[1] & 0xf) == bVar2) {
      PTR_DAT_0001a772 = puVar3;
      return;
    }
    puVar3 = puVar3 + 5;
    DAT_0001ace6 = DAT_0001ace6 + '\x01';
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  DAT_0001ace6 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00014926 @ 00014926

void FUN_00014926(void)

{
  short sVar1;
  undefined1 *puVar2;
  
  sVar1 = 0x28;
  puVar2 = &DAT_0001aa72;
  DAT_0001ace6 = '\x01';
  do {
    if ((puVar2[1] & 0xf) == DAT_0001acc9) {
      PTR_DAT_0001a772 = puVar2;
      return;
    }
    puVar2 = puVar2 + 5;
    DAT_0001ace6 = DAT_0001ace6 + '\x01';
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  DAT_0001ace6 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00014966 @ 00014966

void FUN_00014966(void)

{
  bool bVar1;
  ushort unaff_D3w;
  short sVar2;
  undefined *puVar3;
  undefined1 in_CF;
  bool bVar4;
  
  puVar3 = &DAT_0001a6ae;
  FUN_0001478a();
  if (!(bool)in_CF) {
    sVar2 = unaff_D3w - 2;
    bVar1 = unaff_D3w < 2;
    if (unaff_D3w >= 2) {
      do {
        bVar4 = bVar1;
        puVar3 = puVar3 + 10;
        FUN_00014798();
        if (bVar4) break;
        sVar2 = sVar2 + -1;
        bVar1 = false;
      } while (sVar2 != -1);
      if (bVar4) goto LAB_000149a4;
    }
    DAT_0001ab46 = 100;
    DAT_0001a48a = 1;
    the_command = 0;
    return;
  }
LAB_000149a4:
  the_command = *(undefined2 *)(puVar3 + 6);
  DAT_0001ab46 = puVar3[4];
  DAT_0001a48a = 0;
  DAT_0001ace9 = puVar3[8];
  PTR_DAT_0001a75e = &DAT_0001a8f0 + (uint)(byte)(puVar3[8] - 1) * 6;
  return;
}


// ---------------------------------------------------------------
// FUN_000149da @ 000149da

void FUN_000149da(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined1 uVar3;
  
  uVar1 = templ_ptr;
  if (DAT_0001acec < 0x3f) {
    DAT_0001a488 = 0xf0ff;
    FUN_00014db2();
    uVar3 = 1;
    if ((((DAT_0001a510 != 0) && (uVar3 = 2, the_command != 0)) && (uVar3 = 3, 5 < DAT_0001ace9)) &&
       (DAT_0001ace9 < 0x1b)) {
      the_command = -0x3dfc;
      run_command_keep_sp();
      *PTR_DAT_0001a75e = 0;
      FUN_00014db2();
      puVar2 = PTR_DAT_0001a75e;
      uVar3 = 4;
      if ((the_command != 0) && (uVar3 = 5, DAT_0001acd7 < 0x80)) {
        uVar3 = 6;
        PTR_DAT_0001a75e[-6] = 0x10;
        *puVar2 = 0;
      }
    }
    DAT_0001ad0e = uVar3;
    templ_ptr = uVar1;
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00014a98 @ 00014a98

void FUN_00014a98(void)

{
  int in_D0;
  
  DAT_00019700 = *(undefined2 *)(&DAT_000196dc + in_D0 * 4);
  DAT_00019702 = *(undefined2 *)(&DAT_000196de + in_D0 * 4);
  PTR_DAT_000199ca = &DAT_0001949c + in_D0 * 0x40;
  return;
}


// ---------------------------------------------------------------
// FUN_00014ac6 @ 00014ac6

void FUN_00014ac6(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = templ_ptr;
  do {
    DAT_0001a488 = 0xf0ff;
    FUN_00014db2();
    iVar4 = DAT_0001a812;
    puVar3 = PTR_DAT_0001a75e;
    if (DAT_0001a510 == 0) {
      the_command = 0xc1bc;
LAB_00014d58:
      run_command_keep_sp();
LAB_00014d5c:
      FUN_00014bdc();
      templ_ptr = uVar2;
      return;
    }
    if (the_command == 0) {
LAB_00014b7e:
      the_command = 0xc1c0;
      goto LAB_00014d58;
    }
    the_command = 0x9140;
    if (*(char *)(DAT_0001a812 + 4) == '\0') goto LAB_00014d5c;
    iVar5 = (uint)(byte)(*(char *)(DAT_0001a812 + 4) - 1) * 6;
    if ((*PTR_DAT_0001a75e == -0x7f) ||
       (cVar1 = PTR_DAT_0001a75e[3], cVar1 == (&DAT_0001a8f3)[iVar5])) goto LAB_00014b7e;
    if ((((cVar1 == 'm') || (cVar1 == -0x7c)) || (cVar1 == 'l')) || (DAT_0001acd7 < 0x9a)) {
      *PTR_DAT_0001a75e = 0x20;
      (&DAT_0001a8f0)[iVar5] = 0x80;
      *(undefined1 *)(iVar4 + 4) = DAT_0001ace9;
      the_command = 0xc04b;
      if (puVar3[3] == -0x7c) {
        DAT_0001acf7 = DAT_0001acf7 + -1;
      }
      else {
        the_command = 0xc1ba;
        if (((&DAT_0001a8f3)[iVar5] != 'h') && (the_command = 0xc1bb, (&DAT_0001a8f3)[iVar5] != 'k')
           ) {
          the_command = 0xc1b9;
        }
      }
      goto LAB_00014d58;
    }
    *PTR_DAT_0001a75e = 0x81;
    the_command = -0x3e43;
    run_command_keep_sp();
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00014bdc @ 00014bdc

void FUN_00014bdc(void)

{
  short sVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_0001a8f0;
  sVar1 = 0x3e;
  do {
    if (*pcVar2 == -0x7f) {
      *pcVar2 = -0x80;
    }
    pcVar2 = pcVar2 + 6;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00014bfa @ 00014bfa

void FUN_00014bfa(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = templ_ptr;
  the_command = -0x6f67;
  run_command_keep_sp();
  do {
    DAT_0001a488 = 0xf0ff;
    FUN_00014db2();
    iVar4 = DAT_0001a812;
    puVar3 = PTR_DAT_0001a75e;
    if (DAT_0001a510 == 0) {
      the_command = -0x3e3b;
LAB_00014d58:
      run_command_keep_sp();
LAB_00014d5c:
      FUN_00014bdc();
      templ_ptr = uVar2;
      return;
    }
    if (the_command == 0) goto LAB_00014d5c;
    the_command = -0x6ec0;
    if (*(char *)(DAT_0001a812 + 4) == '\0') goto LAB_00014d58;
    iVar5 = (uint)(byte)(*(char *)(DAT_0001a812 + 4) - 1) * 6;
    if (*PTR_DAT_0001a75e == -0x7f) {
      the_command = -0x3e40;
      goto LAB_00014d58;
    }
    if (((((&DAT_0001a8f3)[iVar5] != 'h') && ((&DAT_0001a8f3)[iVar5] != 'z')) &&
        ((&DAT_0001a8f3)[iVar5] != 'k')) && ((&DAT_0001a8f3)[iVar5] != 'i')) goto LAB_00014d58;
    cVar1 = PTR_DAT_0001a75e[3];
    if ((cVar1 != (&DAT_0001a8f3)[iVar5]) &&
       (((cVar1 == 'm' || (cVar1 == 'l')) || ((cVar1 == -0x7c || (DAT_0001acd7 < 0x9a)))))) {
      DAT_0001ad04 = '\0';
      the_command = -0x3e3a;
      run_command_keep_sp();
      if (DAT_0001ad04 == '\0') goto LAB_00014d5c;
      *puVar3 = 0x20;
      (&DAT_0001a8f0)[iVar5] = 0x80;
      *(undefined1 *)(iVar4 + 4) = DAT_0001ace9;
      the_command = -0x3fb5;
      if (puVar3[3] == -0x7c) {
        DAT_0001acf7 = DAT_0001acf7 + -1;
      }
      else {
        the_command = -0x3e46;
        if (((&DAT_0001a8f3)[iVar5] != 'h') &&
           (the_command = -0x3e45, (&DAT_0001a8f3)[iVar5] != 'k')) {
          the_command = -0x3e47;
        }
      }
      goto LAB_00014d58;
    }
    *PTR_DAT_0001a75e = 0x81;
    the_command = -0x3e43;
    run_command_keep_sp();
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00014d76 @ 00014d76

void FUN_00014d76(void)

{
  FUN_0001060a();
  DAT_0001a488 = 0xff;
  FUN_00014db2();
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00014d90 @ 00014d90

void FUN_00014d90(void)

{
  FUN_0001060a();
  DAT_0001a488 = 0xf;
  FUN_00014db2();
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00014db2 @ 00014db2

void FUN_00014db2(void)

{
  the_command = 0;
  FUN_00010fec();
  FUN_0001258a();
  FUN_00015492();
  if (DAT_0001a510 != 0) {
    FUN_00010522();
    do {
      wait_frame();
      FUN_00014a98();
      FUN_00014966();
      if (DAT_0001ab46 != DAT_0001ab47) {
        FUN_00010a88();
      }
      handle_frame_input();
    } while ((input_buttons & 4) == 0);
    FUN_0001060a();
  }
  FUN_000124f2();
  FUN_00018f98();
  DAT_0001ad29 = 1;
  if (((PTR_DAT_0001a75e[3] != 'l') && (PTR_DAT_0001a75e[3] != 's')) && (PTR_DAT_0001a75e[3] != 'u')
     ) {
    DAT_0001ad29 = 0;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00014e66 @ 00014e66

void FUN_00014e66(void)

{
  the_command = 0;
  FUN_00010fec();
  FUN_0001258a();
  FUN_00011020();
  FUN_00010522();
  do {
    wait_frame();
    FUN_00014a98();
    FUN_000147c2();
    if (DAT_0001ab46 != 'd') {
      DAT_0001ab46 = DAT_0001ab46 + 'm';
    }
    if (DAT_0001ab46 != DAT_0001ab47) {
      FUN_00010a88();
    }
    handle_frame_input();
  } while ((input_buttons & 4) == 0);
  FUN_0001060a();
  FUN_000124f2();
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00014ee8 @ 00014ee8

void FUN_00014ee8(void)

{
  ushort uVar1;
  short unaff_D5w;
  short unaff_D6w;
  int unaff_A6;
  
  the_command = (&DAT_0001ab62)[(uint)(byte)(DAT_0001acc9 - 1) * 5 + (uint)*(byte *)(unaff_A6 + 1)];
  if (the_command == 0) {
    the_command = (&DAT_0001ab50)[*(byte *)(unaff_A6 + 1)];
    run_command_keep_sp();
    return;
  }
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  if (uVar1 == 0) {
    FUN_00010630();
    return;
  }
  if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
    if (uVar1 != 0x9000) {
      if (uVar1 == 0xf000) {
        register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
      }
      *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
      FUN_00012950();
      templ_ptr = &TEMPL_data;
      FUN_00010630();
      return;
    }
    FUN_00010fc4();
    FUN_00010998();
    DAT_0001a512 = unaff_D6w + 2;
    if (4 < (byte)unaff_D5w) {
      DAT_0001a512 = 0x14;
    }
    FUN_000109bc();
    DAT_0001a514 = unaff_D5w * 6 + 7;
    DAT_0001a532 = cursor_x >> 2;
    if (DAT_0001a532 < 9) {
      DAT_0001a532 = 9;
    }
    if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
      DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
    }
    DAT_0001a530 = cursor_y;
    if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
      DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
    }
    FUN_00010fec();
    FUN_0001258a();
    FUN_00010e66();
    prompt_wait();
    FUN_000124f2();
    return;
  }
  (**(code **)(&cmd_jump_table +
              (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),(char)(the_command & 0x3ff) + -1)
                      << 2)))();
  return;
}


// ---------------------------------------------------------------
// FUN_00014f24 @ 00014f24

void FUN_00014f24(void)

{
  byte bVar1;
  byte in_D0b;
  
  if (DAT_0001ad20 < in_D0b) {
    register0x0000003c = (BADSPACEBASE *)&stack0x00000004;
  }
  else {
    bVar1 = DAT_0001ad20 & 0xf0;
    DAT_0001ad20 = DAT_0001ad20 - in_D0b;
    if (bVar1 == (DAT_0001ad20 & 0xf0)) {
      return;
    }
  }
  *(undefined4 *)((int)register0x0000003c + -4) = 0x14f5c;
  FUN_000159e2();
  return;
}


// ---------------------------------------------------------------
// FUN_00014f5e @ 00014f5e

void FUN_00014f5e(void)

{
  FUN_00014f24();
  FUN_00016310();
  DAT_0001ad0f = 0xff;
  return;
}


// ---------------------------------------------------------------
// FUN_00014f74 @ 00014f74

void FUN_00014f74(void)

{
  ushort uVar1;
  short unaff_D5w;
  short unaff_D6w;
  
  FUN_00014f24();
  if (DAT_0001ad09 != '\0') {
    the_command = DAT_0001abfc;
    run_command_keep_sp();
    return;
  }
  FUN_000164d4();
  FUN_00016abe();
  if (*(short *)(DAT_0001a466 + 2) != 0) {
    FUN_000162e2();
  }
  FUN_00014a98();
  FUN_000167be();
  FUN_00018f8e();
  copy_screen();
  if (*(short *)(DAT_0001a466 + 2) != 0) {
    FUN_000162da();
  }
  FUN_000164f6();
  if ((DAT_0001acc9 == '\0') ||
     (the_command = (&DAT_0001ab62)[(uint)(byte)(DAT_0001acc9 - 1) * 5], the_command == 0)) {
    the_command = DAT_0001ab50;
  }
  if (((0x3e < DAT_0001acec) && (DAT_0001acd2 < 0x16)) && (DAT_0001acd2 != 1)) {
    the_command = 0x9005;
    run_command_keep_sp();
    return;
  }
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  if (uVar1 != 0) {
    if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
      if (uVar1 != 0x9000) {
        if (uVar1 == 0xf000) {
          register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
        }
        *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
        FUN_00012950();
        templ_ptr = &TEMPL_data;
        FUN_00010630();
        return;
      }
      FUN_00010fc4();
      FUN_00010998();
      DAT_0001a512 = unaff_D6w + 2;
      if (4 < (byte)unaff_D5w) {
        DAT_0001a512 = 0x14;
      }
      FUN_000109bc();
      DAT_0001a514 = unaff_D5w * 6 + 7;
      DAT_0001a532 = cursor_x >> 2;
      if (DAT_0001a532 < 9) {
        DAT_0001a532 = 9;
      }
      if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
        DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
      }
      DAT_0001a530 = cursor_y;
      if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
        DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
      }
      FUN_00010fec();
      FUN_0001258a();
      FUN_00010e66();
      prompt_wait();
      FUN_000124f2();
      return;
    }
    (**(code **)(&cmd_jump_table +
                (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),
                                  (char)(the_command & 0x3ff) + -1) << 2)))();
    return;
  }
  FUN_00010630();
  return;
}


// ---------------------------------------------------------------
// FUN_00015052 @ 00015052

void FUN_00015052(void)

{
  ushort uVar1;
  short unaff_D5w;
  short unaff_D6w;
  
  FUN_00014f24();
  if (DAT_0001ad09 != '\0') {
    the_command = DAT_0001abfe;
    run_command_keep_sp();
    return;
  }
  FUN_0001680c();
  if ((DAT_0001acc9 == '\0') ||
     (the_command = (&DAT_0001ab66)[(uint)(byte)(DAT_0001acc9 - 1) * 5], the_command == 0)) {
    the_command = DAT_0001ab52;
    run_command_keep_sp();
    return;
  }
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  if (uVar1 != 0) {
    if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
      if (uVar1 != 0x9000) {
        if (uVar1 == 0xf000) {
          register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
        }
        *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
        FUN_00012950();
        templ_ptr = &TEMPL_data;
        FUN_00010630();
        return;
      }
      FUN_00010fc4();
      FUN_00010998();
      DAT_0001a512 = unaff_D6w + 2;
      if (4 < (byte)unaff_D5w) {
        DAT_0001a512 = 0x14;
      }
      FUN_000109bc();
      DAT_0001a514 = unaff_D5w * 6 + 7;
      DAT_0001a532 = cursor_x >> 2;
      if (DAT_0001a532 < 9) {
        DAT_0001a532 = 9;
      }
      if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
        DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
      }
      DAT_0001a530 = cursor_y;
      if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
        DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
      }
      FUN_00010fec();
      FUN_0001258a();
      FUN_00010e66();
      prompt_wait();
      FUN_000124f2();
      return;
    }
    (**(code **)(&cmd_jump_table +
                (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),
                                  (char)(the_command & 0x3ff) + -1) << 2)))();
    return;
  }
  FUN_00010630();
  return;
}


// ---------------------------------------------------------------
// FUN_000150ae @ 000150ae

void FUN_000150ae(void)

{
  FUN_00014f24();
  if (DAT_0001ad09 == '\0') {
    FUN_000164d4();
    FUN_0001680c();
    if (DAT_0001acc9 == '\0') {
      the_command = DAT_0001ab5c;
      DAT_0001acd3 = 0;
      run_command_keep_sp();
      return;
    }
    FUN_00018f7a();
    the_command = (&DAT_0001ab64)[(uint)(byte)(DAT_0001acc9 - 1) * 5];
    if (the_command != 0) goto LAB_0001513a;
  }
  if (DAT_0001ad09 == '\x12') {
    DAT_0001acd3 = 1;
    DAT_0001ace8 = 2;
    return;
  }
  PTR_DAT_0001a772[1] = PTR_DAT_0001a772[1] | 0x80;
  DAT_0001acd3 = DAT_0001acc9;
  DAT_0001ace8 = 2;
  the_command = 0;
  if (DAT_0001ad09 != '\0') {
    the_command = 0x90aa;
    run_command_keep_sp();
    return;
  }
LAB_0001513a:
  FUN_000159e2();
  FUN_000164f6();
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00015192 @ 00015192

void FUN_00015192(void)

{
  short sVar1;
  undefined1 *puVar2;
  
  puVar2 = &DAT_0001aa72;
  sVar1 = 0x28;
  do {
    puVar2[1] = puVar2[1] & 0x7f;
    puVar2 = puVar2 + 5;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  DAT_0001acd3 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_000151b0 @ 000151b0

void FUN_000151b0(void)

{
  undefined4 uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  char cVar5;
  short unaff_D5w;
  short sVar6;
  short unaff_D6w;
  undefined4 *extraout_A0;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  FUN_00014f24();
  the_command = DAT_0001ac08;
  if (DAT_0001ad09 != '\0') {
    if (DAT_0001ac08 == 0) {
      return;
    }
    uVar2 = DAT_0001ac08 & 0xf000;
    if (uVar2 != 0) {
      if ((uVar2 != 0xa000) && (uVar2 != 0xb000)) {
        if (uVar2 != 0x9000) {
          if (uVar2 == 0xf000) {
            register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
          }
          *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
          FUN_00012950();
          templ_ptr = &TEMPL_data;
          FUN_00010630();
          return;
        }
        FUN_00010fc4();
        FUN_00010998();
        DAT_0001a512 = unaff_D6w + 2;
        if (4 < (byte)unaff_D5w) {
          DAT_0001a512 = 0x14;
        }
        FUN_000109bc();
        DAT_0001a514 = unaff_D5w * 6 + 7;
        DAT_0001a532 = cursor_x >> 2;
        if (DAT_0001a532 < 9) {
          DAT_0001a532 = 9;
        }
        if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
          DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
        }
        DAT_0001a530 = cursor_y;
        if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
          DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
        }
        FUN_00010fec();
        FUN_0001258a();
        FUN_00010e66();
        prompt_wait();
        FUN_000124f2();
        return;
      }
      (**(code **)(&cmd_jump_table +
                  (ushort)(CONCAT11((char)((DAT_0001ac08 & 0x3ff) >> 8),
                                    (char)(DAT_0001ac08 & 0x3ff) + -1) << 2)))();
      return;
    }
    FUN_00010630();
    return;
  }
  FUN_000164d4();
  if (*(short *)(DAT_0001a466 + 2) != 0) {
    FUN_000162e2();
  }
  FUN_00018f8e();
  cVar5 = DAT_0001ab42;
  FUN_00010fec();
  sVar3 = ((byte)(DAT_0001ab41 - DAT_0001ab40) >> 2) - 1;
  sVar4 = (byte)(DAT_0001ab43 - DAT_0001ab42) - 1;
  sVar6 = sVar3;
  puVar9 = extraout_A0;
  puVar8 = extraout_A0;
  do {
    do {
      uVar1 = *puVar9;
      *puVar9 = puVar9[1];
      puVar9[1] = uVar1;
      puVar9 = puVar9 + 2;
      sVar6 = sVar6 + -1;
    } while (sVar6 != -1);
    FUN_00013594();
    sVar6 = sVar3;
    puVar9 = puVar8;
    do {
      uVar1 = *puVar9;
      *puVar9 = puVar9[1];
      puVar9[1] = uVar1;
      puVar9 = puVar9 + 2;
      sVar6 = sVar6 + -1;
      iVar7 = object_list_begin;
    } while (sVar6 != -1);
    do {
      if (((*(byte *)(iVar7 + 4) & 0xb8) == 0x28) && (cVar5 == *(char *)(iVar7 + 2))) {
        *(byte *)(iVar7 + 4) = *(byte *)(iVar7 + 4) | 0x80;
        FUN_00018f8e();
        FUN_000159e2();
        FUN_00018f8e();
        break;
      }
      iVar7 = iVar7 + 8;
    } while (object_list_end != iVar7);
    puVar9 = puVar8 + 0x28;
    cVar5 = cVar5 + '\x01';
    sVar4 = sVar4 + -1;
    sVar6 = sVar3;
    puVar8 = puVar9;
    if (sVar4 == -1) {
      FUN_000164f6();
      xbios_supexec();
      if (*(short *)(DAT_0001a466 + 2) != 0) {
        FUN_000162da();
      }
      the_command = DAT_0001ab54;
      run_command_keep_sp();
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------
// FUN_000152ee @ 000152ee

void FUN_000152ee(void)

{
  ushort uVar1;
  short unaff_D5w;
  short unaff_D6w;
  
  FUN_00014f24();
  if (DAT_0001ad09 != '\0') {
    the_command = DAT_0001ac00;
    run_command_keep_sp();
    return;
  }
  FUN_00014a98();
  FUN_000167be();
  FUN_000164d4();
  FUN_00018f8e();
  FUN_000159e2();
  FUN_000164f6();
  if ((DAT_0001acc9 == '\0') ||
     (the_command = (&DAT_0001ab68)[(uint)(byte)(DAT_0001acc9 - 1) * 5], the_command == 0)) {
    the_command = DAT_0001ab5a;
    run_command_keep_sp();
    return;
  }
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  if (uVar1 != 0) {
    if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
      if (uVar1 != 0x9000) {
        if (uVar1 == 0xf000) {
          register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
        }
        *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
        FUN_00012950();
        templ_ptr = &TEMPL_data;
        FUN_00010630();
        return;
      }
      FUN_00010fc4();
      FUN_00010998();
      DAT_0001a512 = unaff_D6w + 2;
      if (4 < (byte)unaff_D5w) {
        DAT_0001a512 = 0x14;
      }
      FUN_000109bc();
      DAT_0001a514 = unaff_D5w * 6 + 7;
      DAT_0001a532 = cursor_x >> 2;
      if (DAT_0001a532 < 9) {
        DAT_0001a532 = 9;
      }
      if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
        DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
      }
      DAT_0001a530 = cursor_y;
      if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
        DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
      }
      FUN_00010fec();
      FUN_0001258a();
      FUN_00010e66();
      prompt_wait();
      FUN_000124f2();
      return;
    }
    (**(code **)(&cmd_jump_table +
                (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),
                                  (char)(the_command & 0x3ff) + -1) << 2)))();
    return;
  }
  FUN_00010630();
  return;
}


// ---------------------------------------------------------------
// FUN_00015382 @ 00015382

void FUN_00015382(void)

{
  ushort uVar1;
  short unaff_D5w;
  short unaff_D6w;
  
  FUN_00014f24();
  DAT_0001ad03 = 1;
  if (*(short *)(DAT_0001a466 + 2) != 0) {
    FUN_000162e2();
  }
  if (DAT_0001ad09 != '\0') {
    the_command = DAT_0001ac02;
    run_command_keep_sp();
    return;
  }
  FUN_0001680c();
  if (DAT_0001acc9 != '\0') {
    the_command = (&DAT_0001ab6a)[(uint)(byte)(DAT_0001acc9 - 1) * 5];
    if ((the_command & 0xf000) == 0x9000) goto LAB_000153fe;
    if (the_command != 0) {
      if (the_command == 0) {
        return;
      }
      uVar1 = the_command & 0xf000;
      if (uVar1 != 0) {
        if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
          if (uVar1 != 0x9000) {
            if (uVar1 == 0xf000) {
              register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
            }
            *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
            FUN_00012950();
            templ_ptr = &TEMPL_data;
            FUN_00010630();
            return;
          }
          FUN_00010fc4();
          FUN_00010998();
          DAT_0001a512 = unaff_D6w + 2;
          if (4 < (byte)unaff_D5w) {
            DAT_0001a512 = 0x14;
          }
          FUN_000109bc();
          DAT_0001a514 = unaff_D5w * 6 + 7;
          DAT_0001a532 = cursor_x >> 2;
          if (DAT_0001a532 < 9) {
            DAT_0001a532 = 9;
          }
          if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
            DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
          }
          DAT_0001a530 = cursor_y;
          if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
            DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
          }
          FUN_00010fec();
          FUN_0001258a();
          FUN_00010e66();
          prompt_wait();
          FUN_000124f2();
          return;
        }
        (**(code **)(&cmd_jump_table +
                    (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),
                                      (char)(the_command & 0x3ff) + -1) << 2)))();
        return;
      }
      FUN_00010630();
      return;
    }
  }
  the_command = DAT_0001ab58;
LAB_000153fe:
  if (*(short *)(DAT_0001a466 + 2) != 0) {
    FUN_000162da();
  }
  DAT_0001ad03 = 0;
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00015428 @ 00015428

void FUN_00015428(void)

{
  ushort uVar1;
  
  FUN_00014f24();
  uVar1 = DAT_0001ac04;
  if (((DAT_0001ad09 == '\0') && (uVar1 = DAT_0001ab56, 0x3e < DAT_0001acec)) &&
     (DAT_0001acd2 < 0x16)) {
    uVar1 = 0x113;
  }
  if ((uVar1 & 0x8000) == 0) {
    FUN_00010fb4();
    FUN_00010b6c();
    FUN_0001228a();
    FUN_0001232e();
    return;
  }
  the_command = uVar1;
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00015492 @ 00015492

void FUN_00015492(void)

{
  ushort unaff_D2w;
  ushort unaff_D3w;
  short sVar1;
  ushort *puVar2;
  ushort *extraout_A1;
  
  sVar1 = 0x3e;
  puVar2 = (ushort *)&DAT_0001a8f0;
  do {
    if ((unaff_D2w & *puVar2) == unaff_D3w) {
      FUN_00010fec();
      FUN_0001276c();
      FUN_00018f8e();
      DAT_0001a6b2 = *(undefined1 *)((int)puVar2 + 3);
      DAT_0001a6b4 = puVar2[2];
      DAT_0001a6b6 = '?' - (char)sVar1;
      FUN_00015510();
      puVar2 = extraout_A1;
    }
    puVar2 = puVar2 + 3;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  DAT_0001a510 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00015510 @ 00015510

void FUN_00015510(void)

{
  FUN_00011020();
  return;
}


// ---------------------------------------------------------------
// FUN_00015530 @ 00015530

void FUN_00015530(void)

{
  ushort uVar1;
  short unaff_D5w;
  short unaff_D6w;
  
  DAT_0001aceb = DAT_0001aceb + '\x01';
  DAT_0001ab60 = DAT_0001ab60 + 300;
  the_command = DAT_0001acaa;
  run_command_keep_sp();
  the_command = DAT_0001acae;
  run_command_keep_sp();
  DAT_0001ace7 = DAT_0001acf2;
  the_command = DAT_0001ab5e;
  if (DAT_0001ab5e == 0) {
    if (DAT_0001abf8 == 0) {
      the_command = 0x9005;
      run_command_keep_sp();
      return;
    }
  }
  else {
    if (((0x3e < DAT_0001acec) && (DAT_0001acd2 < 0x16)) && (DAT_0001acd2 != 1)) {
      the_command = 0x9005;
      run_command_keep_sp();
      return;
    }
    if (DAT_0001ab5e != 0) {
      uVar1 = DAT_0001ab5e & 0xf000;
      if (uVar1 == 0) {
        FUN_00010630();
        return;
      }
      if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
        if (uVar1 != 0x9000) {
          if (uVar1 == 0xf000) {
            register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
          }
          *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
          FUN_00012950();
          templ_ptr = &TEMPL_data;
          FUN_00010630();
          return;
        }
        FUN_00010fc4();
        FUN_00010998();
        DAT_0001a512 = unaff_D6w + 2;
        if (4 < (byte)unaff_D5w) {
          DAT_0001a512 = 0x14;
        }
        FUN_000109bc();
        DAT_0001a514 = unaff_D5w * 6 + 7;
        DAT_0001a532 = cursor_x >> 2;
        if (DAT_0001a532 < 9) {
          DAT_0001a532 = 9;
        }
        if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
          DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
        }
        DAT_0001a530 = cursor_y;
        if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
          DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
        }
        FUN_00010fec();
        FUN_0001258a();
        FUN_00010e66();
        prompt_wait();
        FUN_000124f2();
        return;
      }
      (**(code **)(&cmd_jump_table +
                  (ushort)(CONCAT11((char)((DAT_0001ab5e & 0x3ff) >> 8),
                                    (char)(DAT_0001ab5e & 0x3ff) + -1) << 2)))();
      return;
    }
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00015588 @ 00015588

void FUN_00015588(void)

{
  the_command = 0xc35c;
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00015594 @ 00015594

void FUN_00015594(void)

{
  undefined1 in_CF;
  
  xbios_supexec();
  FUN_00016ed8();
  if ((bool)in_CF) {
    the_command = 0x918f;
    run_command_keep_sp();
    return;
  }
  the_command = 0x90aa;
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_000155b8 @ 000155b8

void FUN_000155b8(void)

{
  the_command = 0xc35d;
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_000155c4 @ 000155c4

void FUN_000155c4(void)

{
  undefined1 in_CF;
  
  xbios_supexec();
  FUN_00016fb4();
  if ((bool)in_CF) {
    the_command = 0x9190;
    run_command_keep_sp();
    return;
  }
  the_command = 0x90aa;
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_000155dc @ 000155dc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000155dc(void)

{
  FUN_000134da();
  do {
    DAT_0001a50a = 0x41;
    DAT_0001a50c = 0x78;
    _DAT_0001a46a = 0;
    FUN_00013594();
    print_char();
    print_char();
    print_char();
    print_char();
    wait_frame();
  } while ((input_buttons & 4) == 0);
  FUN_00012368();
  return;
}


// ---------------------------------------------------------------
// FUN_0001566a @ 0001566a

void FUN_0001566a(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  ushort extraout_D0u;
  ushort uVar6;
  undefined4 uVar5;
  ushort extraout_D1u;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  short sVar11;
  char *pcVar12;
  byte *pbVar13;
  char *pcVar14;
  undefined1 *puVar15;
  undefined *puVar16;
  byte *pbVar17;
  int unaff_A6;
  byte *pbVar18;
  bool bVar19;
  
  DAT_0001ab44 = DAT_0001ab45;
  pbVar18 = (byte *)(unaff_A6 + 1);
  if (DAT_0001a575 == 0xff) {
    uVar6 = cursor_x >> 2;
    if (0x49 < (ushort)(uVar6 + 0xc)) {
      uVar6 = 0x3e;
    }
    DAT_0001a575 = (byte)uVar6;
    if (DAT_0001a575 < 8) {
      DAT_0001a575 = 8;
    }
    sVar11 = cursor_y;
    if (0xb3 < (ushort)(cursor_y + 0x2dU)) {
      sVar11 = 0x87;
    }
    DAT_0001a576 = (char)sVar11;
  }
  DAT_0001a534 = (uint)DAT_00028ad5 << 1;
  FUN_00010fec();
  FUN_000127f0();
  FUN_00018f8e();
  cVar4 = DAT_0001a576;
  bVar3 = DAT_0001a575;
  pcVar14 = &DAT_00019ad6;
  pcVar12 = "\x02";
  pbVar17 = pbVar18 + 1;
  bVar10 = *pbVar18;
  uVar8 = 0xffff;
  sVar11 = 7;
  do {
    bVar2 = bVar10 & 1;
    bVar10 = bVar10 >> 1;
    if (bVar2 != 0) {
      cVar1 = *pcVar12;
      *pcVar14 = bVar3 + cVar1;
      pcVar14[1] = bVar3 + cVar1 + '\x02';
      cVar1 = pcVar12[1];
      pcVar14[2] = cVar4 + cVar1;
      pcVar14[3] = cVar4 + cVar1 + '\b';
      uVar8 = (uint)(ushort)((short)uVar8 + 1);
      pcVar14 = pcVar14 + 4;
    }
    pcVar12 = pcVar12 + 2;
    sVar11 = sVar11 + -1;
  } while (sVar11 != -1);
  puVar15 = &DAT_00019ad6;
  uVar9 = uVar8;
  do {
    sVar11 = (short)uVar8;
    FUN_00011020(uVar8,puVar15);
    puVar15 = puVar15 + 4;
    uVar8 = (uint)(ushort)(sVar11 - 1U);
  } while ((ushort)(sVar11 - 1U) != 0xffff);
  FUN_00014a98();
  FUN_00010522();
  do {
    wait_frame();
    puVar16 = &UNK_00019ad2;
    sVar11 = (short)uVar9;
    pbVar18 = pbVar17 + -3;
    do {
      pbVar13 = pbVar18;
      bVar19 = false;
      puVar16 = puVar16 + 4;
      pbVar18 = pbVar13 + 3;
      FUN_0001478a();
      if (bVar19) break;
      sVar11 = sVar11 + -1;
    } while (sVar11 != -1);
    DAT_0001ab46 = 100;
    the_command = -1;
    if (sVar11 != -1) {
      DAT_0001ab46 = *pbVar18;
      the_command = *(short *)(pbVar13 + 4);
    }
    DAT_0001a48a = sVar11 == -1;
    if (DAT_0001ab46 != DAT_0001ab47) {
      FUN_00010a88();
    }
    handle_frame_input();
    if ((input_buttons & 4) != 0) {
      FUN_0001060a(uVar9);
      if (the_command != -1) {
        FUN_00013594();
        FUN_00018f8e();
        uVar5 = CONCAT31((int3)(((uint)extraout_D0u << 0x10) >> 8),*puVar16);
        uVar7 = CONCAT31((int3)(((uint)extraout_D1u << 0x10) >> 8),puVar16[2]);
        FUN_00011020(uVar5,uVar7);
        sVar11 = -1;
        do {
          sVar11 = sVar11 + -1;
        } while (sVar11 != -1);
        FUN_00011020(uVar5,uVar7);
        sVar11 = -1;
        do {
          sVar11 = sVar11 + -1;
        } while (sVar11 != -1);
        FUN_00011020();
        sVar11 = -1;
        do {
          sVar11 = sVar11 + -1;
        } while (sVar11 != -1);
      }
      FUN_00012436();
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00015888 @ 00015888

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015888(void)

{
  undefined4 unaff_A6;
  
  DAT_0001a4be = templ_ptr;
  DAT_0001a575 = 0xff;
  DAT_0001a4c2 = unaff_A6;
  while( true ) {
    do {
      FUN_0001566a();
      if (the_command == 0xffff) {
        templ_ptr = DAT_0001a4be;
        return;
      }
      if (((the_command & 0xf000) == 0xc000) || ((the_command & 0xf000) == 0xa000))
      goto LAB_0001592e;
      run_command_keep_sp();
      DAT_0001ace7 = DAT_0001ace7 + 1;
    } while (_FUN_00019316 != 0x2f3c);
    if (((DAT_0001ad09 == '\0') && (DAT_0001acf2 < DAT_0001ace7)) &&
       (the_command = DAT_0001abf8, DAT_0001abf8 != 0)) break;
    DAT_0001ace8 = DAT_0001ace8 + -1;
    if (DAT_0001ace8 == '\0') {
      FUN_00015192();
    }
  }
LAB_0001592e:
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00015934 @ 00015934

void FUN_00015934(void)

{
  short sVar1;
  
  DAT_0001a573 = '\x01';
  sVar1 = 0x34;
  do {
    FUN_000159bc();
    if (DAT_0001a573 != '\0') {
      FUN_00013594();
    }
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  sVar1 = 8;
  do {
    FUN_000159bc();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00015944 @ 00015944

void FUN_00015944(void)

{
  short sVar1;
  
  DAT_0001a573 = '\0';
  sVar1 = 0x34;
  do {
    FUN_000159bc();
    if (DAT_0001a573 != '\0') {
      FUN_00013594();
    }
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  sVar1 = 8;
  do {
    FUN_000159bc();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000159bc @ 000159bc

void FUN_000159bc(void)

{
  short unaff_D3w;
  undefined4 *in_A1;
  undefined4 *puVar1;
  undefined4 *unaff_A2;
  
  do {
    *unaff_A2 = *in_A1;
    unaff_A2[1] = in_A1[1];
    puVar1 = in_A1 + 3;
    unaff_A2[2] = in_A1[2];
    in_A1 = in_A1 + 4;
    unaff_A2[3] = *puVar1;
    unaff_A2 = unaff_A2 + 0x28;
    unaff_D3w = unaff_D3w + -1;
  } while (unaff_D3w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000159d2 @ 000159d2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000159d2(void)

{
  byte bVar1;
  byte *unaff_A5;
  int unaff_A6;
  
  DAT_0001a474 = (ushort)*(byte *)(unaff_A6 + 3);
  DAT_0001a476 = 0;
  DAT_0001a478 = 0;
  DAT_0001a472 = (ushort)*(byte *)(unaff_A6 + 2);
  FUN_00012950(unaff_A6 + 4);
  DAT_0001a4b6 = &UNK_00023ee8;
  while( true ) {
    bVar1 = *unaff_A5;
    if (unaff_A5 == DAT_0001a4b6) break;
    if (bVar1 == 0xfe) {
      _DAT_0001a47a = (short)(char)unaff_A5[1];
      _DAT_0001a47c = (short)(char)unaff_A5[2];
      unaff_A5 = unaff_A5 + 3;
    }
    else if (bVar1 == 0xfd) {
      if (unaff_A5[2] == 0) {
        FUN_00018f8e();
      }
      else {
        FUN_00018f98();
      }
      unaff_A5 = unaff_A5 + 3;
    }
    else if (bVar1 == 0xfc) {
      xbios_supexec();
      unaff_A5 = unaff_A5 + 1;
    }
    else {
      (**(code **)(&DAT_00019eaa + (bVar1 & 0x3fffc007) * 4))();
    }
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000159e2 @ 000159e2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000159e2(void)

{
  byte bVar1;
  undefined2 in_D0w;
  undefined2 unaff_D2w;
  byte *unaff_A5;
  
  DAT_0001a476 = 0;
  DAT_0001a478 = 0;
  DAT_0001a472 = in_D0w;
  DAT_0001a474 = unaff_D2w;
  FUN_00012950();
  DAT_0001a4b6 = &UNK_00023ee8;
  while( true ) {
    bVar1 = *unaff_A5;
    if (unaff_A5 == DAT_0001a4b6) break;
    if (bVar1 == 0xfe) {
      _DAT_0001a47a = (short)(char)unaff_A5[1];
      _DAT_0001a47c = (short)(char)unaff_A5[2];
      unaff_A5 = unaff_A5 + 3;
    }
    else if (bVar1 == 0xfd) {
      if (unaff_A5[2] == 0) {
        FUN_00018f8e();
      }
      else {
        FUN_00018f98();
      }
      unaff_A5 = unaff_A5 + 3;
    }
    else if (bVar1 == 0xfc) {
      xbios_supexec();
      unaff_A5 = unaff_A5 + 1;
    }
    else {
      (**(code **)(&DAT_00019eaa + (bVar1 & 0x3fffc007) * 4))();
    }
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00015ac8 @ 00015ac8

void FUN_00015ac8(void)

{
  byte bVar1;
  short in_D0w;
  short sVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  sVar2 = 399;
  pbVar4 = DAT_0001a4c6;
  do {
    pbVar4[0] = 0;
    pbVar4[1] = 0;
    pbVar4[2] = 0;
    pbVar4[3] = 0;
    sVar2 = sVar2 + -1;
    pbVar4 = pbVar4 + 4;
  } while (sVar2 != -1);
  pbVar4 = &DAT_00027fe2;
  if (in_D0w != 0) {
    sVar2 = in_D0w + -1;
    do {
      pbVar4 = pbVar4 + *pbVar4;
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
  }
  bVar1 = *pbVar4;
  pbVar3 = DAT_0001a4c6 + 1;
  *DAT_0001a4c6 = pbVar4[1];
  pbVar5 = pbVar4 + 3;
  *pbVar3 = pbVar4[2];
  do {
    FUN_00010f8e();
    if ((pbVar5[2] & 0x80) == 0) {
      FUN_00012ad6();
    }
    else {
      FUN_00012b04();
    }
    pbVar5 = pbVar5 + 3;
  } while (pbVar5 != pbVar4 + bVar1);
  return;
}


// ---------------------------------------------------------------
// FUN_00015da6 @ 00015da6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015da6(void)

{
  byte bVar1;
  ushort in_D0w;
  ushort uVar2;
  uint in_D1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  uint unaff_D2;
  short sVar7;
  short unaff_D3w;
  short sVar8;
  undefined4 unaff_D5;
  short sVar10;
  int iVar9;
  uint uVar11;
  ushort unaff_D7w;
  int extraout_A0;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  undefined4 extraout_A0_00;
  short *extraout_A1;
  short *psVar15;
  undefined **ppuVar16;
  undefined **ppuVar17;
  short *psVar18;
  
  uVar5 = in_D1;
  FUN_00010fec();
  pbVar12 = (byte *)(extraout_A0 + -0x8000);
  sVar6 = unaff_D3w + -1;
  sVar7 = ((ushort)(unaff_D2 >> 2) & 0x3fff) + 2;
  ppuVar16 = &PTR_DAT_0003b1ac;
  pbVar14 = pbVar12;
  sVar10 = sVar7;
  DAT_0001a49e = sVar7;
  DAT_0001a4a0 = sVar6;
  DAT_0001a4b2 = pbVar12;
  pbVar13 = pbVar12;
  sVar8 = sVar6;
  do {
    do {
      ppuVar17 = ppuVar16 + 1;
      *ppuVar16 = *(undefined **)pbVar14;
      ppuVar16 = ppuVar16 + 2;
      *ppuVar17 = *(undefined **)(pbVar14 + 4);
      sVar10 = sVar10 + -1;
      pbVar14 = pbVar14 + 8;
    } while (sVar10 != -1);
    pbVar14 = pbVar13 + 0xa0;
    sVar8 = sVar8 + -1;
    sVar10 = sVar7;
    pbVar13 = pbVar14;
  } while (sVar8 != -1);
  sVar7 = (short)unaff_D2 + -1;
  psVar15 = extraout_A1;
  do {
    iVar9 = 0;
    pbVar14 = pbVar12;
    if ((unaff_D7w & 8) != 0) {
      pbVar14 = pbVar12 + 1;
    }
    psVar18 = psVar15;
    sVar10 = sVar6;
    if ((unaff_D7w & 4) != 0) {
      iVar9 = 4;
    }
    do {
      sVar8 = *psVar18;
      bVar1 = (byte)((ushort)sVar8 >> 8);
      _DAT_00055b02 = CONCAT13(bVar1,CONCAT12((char)((ushort)(sVar8 << 4) >> 8),sVar8 << 8));
      _DAT_00055b02 = CONCAT31(_DAT_00055b02,(byte)(sVar8 << 4) | bVar1 >> 4);
      uVar11 = _DAT_00055b02 << 0x20 - iVar9 | _DAT_00055b02 >> iVar9;
      uVar3 = uVar11 << 0x10 | uVar11 >> 0x10;
      uVar4 = uVar3 << 8 | (uVar11 & 0xffff) >> 8;
      uVar3 = (uVar4 << 0x10 | (uVar11 << 0x10 & 0xffffff | uVar11 >> 0x10) >> 8 |
              uVar4 | uVar3 | uVar11) & 0xf0f0f0f0;
      uVar3 = uVar3 << 0x20 - iVar9 | uVar3 >> iVar9;
      uVar3 = uVar3 & uVar11 |
              ~uVar3 & ((uint)*pbVar14 << 0x18 | (uint)pbVar14[2] << 0x10 | (uint)pbVar14[4] << 8 |
                       (uint)pbVar14[6]);
      *pbVar14 = (byte)(uVar3 >> 0x18);
      pbVar14[2] = (byte)(uVar3 >> 0x10);
      pbVar14[4] = (byte)(uVar3 >> 8);
      pbVar14[6] = (byte)uVar3;
      pbVar14 = pbVar14 + 0xa0;
      psVar18 = (short *)(CONCAT22((short)((uint)unaff_D5 >> 0x10),(short)unaff_D5 << 1) +
                         (int)psVar18);
      sVar10 = sVar10 + -1;
    } while (sVar10 != -1);
    psVar15 = psVar15 + 1;
    uVar2 = unaff_D7w + 4;
    unaff_D7w = uVar2 & 0xf;
    if ((uVar2 & 0xf) == 0) {
      pbVar12 = pbVar12 + 8;
    }
    sVar7 = sVar7 + -1;
  } while (sVar7 != -1);
  uVar2 = in_D0w;
  if (DAT_0001a478 != 0) {
    if (DAT_0001a472 <= in_D0w) {
      uVar2 = DAT_0001a472;
    }
    if (DAT_0001a474 <= (ushort)uVar5) {
      uVar5 = (uint)DAT_0001a474;
    }
  }
  FUN_00010fec(uVar2,uVar5);
  sVar7 = DAT_0001a470;
  if (DAT_0001a470 != 0) {
    do {
      sVar6 = 3000;
      do {
        sVar6 = sVar6 + -1;
      } while (sVar6 != -1);
      sVar7 = sVar7 + -1;
    } while (sVar7 != -1);
  }
  FUN_00013594(extraout_A0_00);
  if (DAT_0001a578 == '\0') {
    FUN_0001215e();
  }
  else {
    FUN_00012e2e();
  }
  sVar7 = DAT_0001a49e;
  ppuVar16 = &PTR_DAT_0003b1ac;
  pbVar14 = DAT_0001a4b2;
  sVar6 = sVar7;
  pbVar13 = DAT_0001a4b2;
  sVar10 = DAT_0001a4a0;
  do {
    do {
      ppuVar17 = ppuVar16 + 1;
      *(undefined **)pbVar14 = *ppuVar16;
      ppuVar16 = ppuVar16 + 2;
      *(undefined **)(pbVar14 + 4) = *ppuVar17;
      sVar6 = sVar6 + -1;
      pbVar14 = pbVar14 + 8;
    } while (sVar6 != -1);
    pbVar14 = pbVar13 + 0xa0;
    sVar10 = sVar10 + -1;
    sVar6 = sVar7;
    pbVar13 = pbVar14;
  } while (sVar10 != -1);
  DAT_0001a472 = in_D0w;
  DAT_0001a474 = (short)in_D1;
  DAT_0001a476 = (short)unaff_D2;
  DAT_0001a478 = unaff_D3w;
  _DAT_0001a47c = 0;
  _DAT_0001a47a = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00015f6c @ 00015f6c

byte FUN_00015f6c(void)

{
  byte bVar1;
  byte bVar2;
  undefined *extraout_A1;
  undefined *puVar3;
  byte *unaff_A6;
  byte *pbVar4;
  
  pbVar4 = unaff_A6 + 1;
  bVar2 = *unaff_A6;
  if ((bVar2 & 0x80) == 0) {
    bVar1 = *pbVar4;
    if ((bVar2 & 0x20) != 0) {
      bVar1 = unaff_A6[2];
    }
    return bVar1;
  }
  puVar3 = (&PTR_DAT_0001a752)[bVar2 & 0x1f];
  if ((bVar2 & 0x40) != 0) {
    pbVar4 = unaff_A6 + 2;
    bVar2 = FUN_00010f8e();
    puVar3 = extraout_A1;
  }
  bVar1 = puVar3[*pbVar4];
  if ((bVar2 & 0x20) != 0) {
    bVar1 = (puVar3 + *pbVar4)[1];
  }
  return bVar1;
}


// ---------------------------------------------------------------
// FUN_00015fd4 @ 00015fd4

void FUN_00015fd4(void)

{
  ushort in_D0w;
  ushort unaff_D6w;
  uint unaff_D7;
  
  if ((unaff_D7 & 0x40) == 0) {
    return;
  }
  if (((((unaff_D7 & 0x20) == 0) || (unaff_D6w != in_D0w)) &&
      (((unaff_D7 & 0x10) == 0 || (in_D0w <= unaff_D6w)))) &&
     (((((unaff_D7 & 8) == 0 || (unaff_D6w <= in_D0w)) &&
       (((unaff_D7 & 4) == 0 || (unaff_D6w == in_D0w)))) &&
      ((((unaff_D7 & 2) == 0 || ((short)in_D0w < (short)unaff_D6w)) &&
       (((unaff_D7 & 1) == 0 || ((short)unaff_D6w < (short)in_D0w)))))))) {
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0001606e @ 0001606e

void FUN_0001606e(void)

{
  byte *unaff_A6;
  
  FUN_00015f6c();
  while( true ) {
    if ((*unaff_A6 & 0x80) != 0) break;
    FUN_00015f6c();
    FUN_00015fd4();
    unaff_A6 = unaff_A6 + 1;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00016088 @ 00016088

void FUN_00016088(void)

{
  uint uVar1;
  undefined2 unaff_D6w;
  undefined2 *extraout_A0;
  
  uVar1 = FUN_00015f6c();
  FUN_0001606e();
  if ((uVar1 & 0x80000000) == 0) {
    *(char *)extraout_A0 = (char)unaff_D6w;
    return;
  }
  *extraout_A0 = unaff_D6w;
  return;
}


// ---------------------------------------------------------------
// FUN_000160aa @ 000160aa

void FUN_000160aa(void)

{
  short unaff_D6w;
  
  FUN_0001606e();
  if (unaff_D6w == 0) {
    FUN_0001350c();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000160c0 @ 000160c0

void FUN_000160c0(void)

{
  return;
}


// ---------------------------------------------------------------
// FUN_00016210 @ 00016210

void FUN_00016210(void)

{
  DAT_0001a579 = DAT_0001a579 + 1;
  DAT_0001acd7 = (&DAT_0002741e)[DAT_0001a579];
  return;
}


// ---------------------------------------------------------------
// FUN_00016230 @ 00016230

undefined2 FUN_00016230(void)

{
  DAT_0001a579 = DAT_0001a579 + 1;
  return *(undefined2 *)(&DAT_0002741e + DAT_0001a579);
}


// ---------------------------------------------------------------
// FUN_00016250 @ 00016250

void FUN_00016250(void)

{
  FUN_00018a10();
  __m68k_trap(0xe);
  FUN_00013594();
  __m68k_trap(0xe);
  return;
}


// ---------------------------------------------------------------
// FUN_0001627a @ 0001627a

void FUN_0001627a(void)

{
  byte bVar1;
  short sVar2;
  byte *pbVar3;
  
  bVar1 = DAT_0001acd2;
  if ((byte)((char)DAT_0001ab60 - (char)DAT_0001a526) < 0xb4) {
    return;
  }
  DAT_0001a526 = DAT_0001ab60;
  pbVar3 = &DAT_0001a8f0;
  sVar2 = 0x3e;
  do {
    if ((((*pbVar3 & 0x40) != 0) && (bVar1 != pbVar3[1])) && (pbVar3[1] < 0x34)) {
      *pbVar3 = *pbVar3 & 0xbf;
    }
    pbVar3 = pbVar3 + 6;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000162ce @ 000162ce

void FUN_000162ce(void)

{
  FUN_000162e2();
  return;
}


// ---------------------------------------------------------------
// FUN_000162d8 @ 000162d8

void FUN_000162d8(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  sVar1 = 4;
  puVar2 = (undefined2 *)(&DAT_0001a10a + (uint)DAT_0001acf4 * 10);
  puVar3 = DAT_0001a466;
  do {
    puVar3 = puVar3 + 1;
    *puVar3 = *puVar2;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  __m68k_trap(0xe);
  return;
}


// ---------------------------------------------------------------
// FUN_000162da @ 000162da

void FUN_000162da(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  sVar1 = 4;
  puVar2 = (undefined2 *)(&DAT_0001a10a + (uint)DAT_0001acf4 * 10);
  puVar3 = DAT_0001a466;
  do {
    puVar3 = puVar3 + 1;
    *puVar3 = *puVar2;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  __m68k_trap(0xe);
  return;
}


// ---------------------------------------------------------------
// FUN_000162e2 @ 000162e2

void FUN_000162e2(void)

{
  uint in_D0;
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  sVar1 = 4;
  puVar2 = (undefined2 *)(&DAT_0001a10a + (in_D0 & 0xffff) * 10);
  puVar3 = DAT_0001a466;
  do {
    puVar3 = puVar3 + 1;
    *puVar3 = *puVar2;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  __m68k_trap(0xe);
  return;
}


// ---------------------------------------------------------------
// xbios_setpalette @ 00016300

void xbios_setpalette(void)

{
  __m68k_trap(0xe);
  return;
}


// ---------------------------------------------------------------
// FUN_00016310 @ 00016310

void FUN_00016310(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  ushort *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  ushort *puVar9;
  
  FUN_00018f98();
  sVar1 = 0xf;
  puVar6 = DAT_0001a466;
  puVar9 = (ushort *)&DAT_0000d8f0;
  do {
    *puVar9 = *puVar6;
    sVar1 = sVar1 + -1;
    puVar6 = puVar6 + 1;
    puVar9 = puVar9 + 1;
  } while (sVar1 != -1);
  while( true ) {
    sVar5 = 0;
    sVar1 = 4;
    puVar6 = DAT_0001a466;
    do {
      puVar6 = puVar6 + 1;
      uVar4 = *puVar6;
      if (uVar4 != 0x777) {
        sVar5 = -1;
        uVar2 = uVar4 & 0xf;
        if (uVar2 != 7) {
          uVar2 = uVar2 + 1;
        }
        uVar3 = uVar4 & 0xf0;
        if (uVar3 != 0x70) {
          uVar3 = uVar3 + 0x10;
        }
        uVar4 = uVar4 & 0xf00;
        if (uVar4 != 0x700) {
          uVar4 = uVar4 + 0x100;
        }
        uVar4 = uVar4 | uVar3 | uVar2;
      }
      *puVar6 = uVar4;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    if (sVar5 == 0) break;
    FUN_00013594();
    sVar1 = -1;
    do {
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    xbios_setpalette();
  }
  FUN_00018f8e();
  the_command = DAT_0001abfa;
  run_command_keep_sp();
  sVar1 = 4;
  puVar7 = (undefined2 *)(&DAT_0001a10a + (uint)DAT_0001acf4 * 10);
  puVar8 = (undefined2 *)&DAT_0000d8f2;
  do {
    *puVar8 = *puVar7;
    sVar1 = sVar1 + -1;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  } while (sVar1 != -1);
  while( true ) {
    puVar9 = (ushort *)&DAT_0000d8f2;
    sVar5 = 0;
    sVar1 = 4;
    puVar6 = DAT_0001a466;
    do {
      puVar6 = puVar6 + 1;
      uVar4 = *puVar6;
      if (uVar4 != *puVar9) {
        sVar5 = -1;
        uVar2 = uVar4 & 0xf;
        if (uVar2 != (*puVar9 & 0xf)) {
          uVar2 = uVar2 - 1;
        }
        uVar3 = uVar4 & 0xf0;
        if (uVar3 != (*puVar9 & 0xf0)) {
          uVar3 = uVar3 - 0x10;
        }
        uVar4 = uVar4 & 0xf00;
        if (uVar4 != (*puVar9 & 0xf00)) {
          uVar4 = uVar4 - 0x100;
        }
        uVar4 = uVar4 | uVar3 | uVar2;
      }
      *puVar6 = uVar4;
      puVar9 = puVar9 + 1;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    if (sVar5 == 0) break;
    FUN_00013594();
    sVar1 = -1;
    do {
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    xbios_setpalette();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00016460 @ 00016460

void FUN_00016460(void)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = object_list_begin;
  sVar1 = 0xf;
  puVar2 = &command_hints_list;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  do {
    if ((*(byte *)(iVar3 + 4) & 0x40) != 0) {
      FUN_000164a4();
    }
    iVar3 = iVar3 + 8;
  } while (iVar3 != object_list_end);
  return;
}


// ---------------------------------------------------------------
// FUN_000164a4 @ 000164a4

void FUN_000164a4(void)

{
  undefined4 in_A1;
  undefined4 *unaff_A2;
  
  *unaff_A2 = in_A1;
  FUN_00010fec();
  FUN_00012590();
  return;
}


// ---------------------------------------------------------------
// FUN_000164d4 @ 000164d4

void FUN_000164d4(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_0001acc7 == 0x29) {
    sVar1 = 7999;
    puVar2 = screen_ptr_a;
    puVar3 = screen_ptr_b;
    do {
      *puVar3 = *puVar2;
      sVar1 = sVar1 + -1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (sVar1 != -1);
    return;
  }
  if ((0x15 < DAT_0001acc7) && (DAT_0001acc7 < 0x19)) {
    FUN_000121b6();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000164f6 @ 000164f6

void FUN_000164f6(void)

{
  if ((0x15 < DAT_0001acc7) && (DAT_0001acc7 < 0x19)) {
    FUN_00013f56();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00016512 @ 00016512

void FUN_00016512(void)

{
  short sVar1;
  
  sVar1 = 0xf;
  do {
    FUN_0001652e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016514 @ 00016514

void FUN_00016514(void)

{
  short sVar1;
  
  sVar1 = 0xf;
  do {
    FUN_0001652e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001652e @ 0001652e

void FUN_0001652e(void)

{
  int *unaff_A2;
  
  if (*unaff_A2 != 0) {
    FUN_00012190();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00016554 @ 00016554

void FUN_00016554(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = 0xf;
  puVar2 = &command_hints_list;
  do {
    blit_sprite(puVar2);
    puVar2 = puVar2 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// draw_hint_icons @ 00016556

void draw_hint_icons(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = 0xf;
  puVar2 = &command_hints_list;
  do {
    blit_sprite(puVar2);
    puVar2 = puVar2 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016576 @ 00016576

void FUN_00016576(void)

{
  update_icon_list();
  return;
}


// ---------------------------------------------------------------
// update_icon_list @ 00016582

void update_icon_list(void)

{
  byte bVar1;
  short sVar2;
  char *pcVar3;
  char *extraout_A1;
  int iVar4;
  
  iVar4 = object_list_begin;
  do {
    if ((*(byte *)(iVar4 + 4) & 0x38) == 0x10) {
      *(byte *)(iVar4 + 4) = *(byte *)(iVar4 + 4) & 0x7f;
    }
    iVar4 = iVar4 + 8;
  } while (iVar4 != object_list_end);
  sVar2 = 0x28;
  pcVar3 = &DAT_0001aa72;
  do {
    pcVar3[1] = pcVar3[1] & 0xf0;
    if ((DAT_0001acd2 == *pcVar3) && ((pcVar3[1] & 0x40U) == 0)) {
      bVar1 = 1;
      iVar4 = object_list_begin;
      do {
        if ((pcVar3[3] & 7U | 0x10) == (*(byte *)(iVar4 + 4) & 0xbf)) {
          *(byte *)(iVar4 + 4) = *(byte *)(iVar4 + 4) | 0x80;
          *(char *)(iVar4 + 5) = pcVar3[2];
          pcVar3[1] = bVar1 | pcVar3[1];
          if ((*(byte *)(iVar4 + 4) & 0x40) != 0) {
            FUN_00016636();
            pcVar3 = extraout_A1;
          }
          break;
        }
        iVar4 = iVar4 + 8;
        bVar1 = bVar1 + 1;
      } while (iVar4 != object_list_end);
    }
    pcVar3 = pcVar3 + 5;
    sVar2 = sVar2 + -1;
    if (sVar2 == -1) {
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00016636 @ 00016636

undefined4 FUN_00016636(void)

{
  short sVar1;
  undefined4 unaff_D3;
  undefined1 *puVar2;
  byte *pbVar3;
  
  puVar2 = &DAT_0001aa72;
  sVar1 = 0x28;
  do {
    if ((byte)unaff_D3 == (puVar2[1] & 0xf)) {
      pbVar3 = &UNK_0001a57d + (uint)((byte)puVar2[3] >> 3) + ((byte)puVar2[3] & 0xf8);
      *pbVar3 = *pbVar3 + 1;
      *pbVar3 = *pbVar3 & 7;
      DAT_0001a4c6 = &DAT_0000d8f0;
      FUN_00015ac8();
      FUN_00010fec();
      FUN_0001103e(DAT_0000d8f0,CONCAT31((int3)((uint)unaff_D3 >> 8),DAT_0000d8f1) & 0xffff00ff);
      return 0xff;
    }
    puVar2 = puVar2 + 5;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return 0;
}


// ---------------------------------------------------------------
// FUN_000166da @ 000166da

void FUN_000166da(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  if ((DAT_0001acd4 & 0x1f) != 0x1e) {
    return;
  }
  iVar4 = DAT_0001a7d2;
  if (DAT_0001a7d2 == object_list_end) {
    DAT_0001ab4a = '\0';
    iVar4 = object_list_begin;
  }
  do {
    cVar1 = DAT_0001ab4a + '\x01';
    DAT_0001ab4a = cVar1;
    if (((*(byte *)(iVar4 + 4) & 0x40) != 0) && ((*(byte *)(iVar4 + 4) & 0xf8) == 0xd0)) {
      DAT_0001a7d2 = iVar4 + 8;
      uVar3 = iVar4 - object_list_begin;
      cVar2 = (char)(uVar3 >> 3) + '\x01';
      bVar5 = cVar2 == '\0';
      FUN_00016636();
      if (!bVar5) {
        FUN_00013594(cVar1,CONCAT31((uint3)(uVar3 >> 0xb),cVar2));
        FUN_0001060a();
        FUN_0001215e();
        FUN_00010526();
        blit_sprite();
        return;
      }
    }
    iVar4 = iVar4 + 8;
  } while (iVar4 != object_list_end);
  DAT_0001a7d2 = iVar4;
  return;
}


// ---------------------------------------------------------------
// FUN_000166ec @ 000166ec

void FUN_000166ec(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = DAT_0001a7d2;
  if (DAT_0001a7d2 == object_list_end) {
    DAT_0001ab4a = '\0';
    iVar4 = object_list_begin;
  }
  do {
    cVar1 = DAT_0001ab4a + '\x01';
    DAT_0001ab4a = cVar1;
    if (((*(byte *)(iVar4 + 4) & 0x40) != 0) && ((*(byte *)(iVar4 + 4) & 0xf8) == 0xd0)) {
      DAT_0001a7d2 = iVar4 + 8;
      uVar3 = iVar4 - object_list_begin;
      cVar2 = (char)(uVar3 >> 3) + '\x01';
      bVar5 = cVar2 == '\0';
      FUN_00016636();
      if (!bVar5) {
        FUN_00013594(cVar1,CONCAT31((uint3)(uVar3 >> 0xb),cVar2));
        FUN_0001060a();
        FUN_0001215e();
        FUN_00010526();
        blit_sprite();
        return;
      }
    }
    iVar4 = iVar4 + 8;
  } while (iVar4 != object_list_end);
  DAT_0001a7d2 = iVar4;
  return;
}


// ---------------------------------------------------------------
// FUN_000167aa @ 000167aa

void FUN_000167aa(void)

{
  int unaff_A6;
  
  FUN_00014a98();
  DAT_0001a74e = *(undefined1 *)(unaff_A6 + 2);
  DAT_0001a74f = *(undefined1 *)(unaff_A6 + 3);
  FUN_00010522();
  do {
    wait_frame();
    hit_test_objects();
    if (DAT_0001ab45 != DAT_0001ab44) {
      FUN_000109fe();
    }
    handle_frame_input();
  } while ((input_buttons & 4) == 0);
  FUN_0001060a();
  return;
}


// ---------------------------------------------------------------
// FUN_000167be @ 000167be

void FUN_000167be(void)

{
  undefined1 unaff_D2b;
  undefined1 unaff_D3b;
  
  DAT_0001a74e = unaff_D2b;
  DAT_0001a74f = unaff_D3b;
  FUN_00010522();
  do {
    wait_frame();
    hit_test_objects();
    if (DAT_0001ab45 != DAT_0001ab44) {
      FUN_000109fe();
    }
    handle_frame_input();
  } while ((input_buttons & 4) == 0);
  FUN_0001060a();
  return;
}


// ---------------------------------------------------------------
// FUN_0001680c @ 0001680c

void FUN_0001680c(void)

{
  FUN_00014a98();
  FUN_000167be();
  return;
}


// ---------------------------------------------------------------
// reset_clear @ 0001682a

/* WARNING: This function may have set the stack pointer */

undefined8 reset_clear(void)

{
  undefined4 unaff_D2;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 extraout_A0;
  undefined4 extraout_A1;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  undefined4 unaff_A4;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  bool bVar1;
  undefined8 uVar2;
  
  while( true ) {
    load_buffer = &PTR_DAT_0001a752;
    load_length = 0x291c;
    cur_filename = "A:CLEAR.BIN";
    bVar1 = false;
    load_resource();
    if (!bVar1) break;
    the_command = 0x918e;
    run_command_keep_sp();
  }
  DAT_0001ad0f = 0xff;
  DAT_0001d1fa = 0x16862;
  FUN_00016210();
  DAT_0001acd8 = 2;
  do {
    DAT_0001d1fa = 0x1015c;
    wait_frame();
  } while ((input_buttons & 4) != 0);
  DAT_0001acc6 = 7;
  DAT_0001ad0d = 0;
  the_command = 0xc001;
  DAT_0001d1fa = 0x10182;
  run_command_keep_sp();
  DAT_0001d1fa = 0x10186;
  draw_hint_icons();
  DAT_0001d1fa = 0x1018a;
  FUN_00010522();
  DAT_0001d1fa = 0x1018e;
  game_loop();
  DAT_0001d1fa = 0x10192;
  uVar2 = FUN_000135e0();
  DAT_0001d1be = (undefined4)((ulonglong)uVar2 >> 0x20);
  DAT_0001d1c2 = (undefined4)uVar2;
  DAT_0001d1fa = 0;
  __m68k_trap(1);
  DAT_0001d1ba = 0x101a2;
  DAT_0001d1c6 = unaff_D2;
  DAT_0001d1ca = unaff_D3;
  DAT_0001d1ce = unaff_D4;
  DAT_0001d1d2 = unaff_D5;
  DAT_0001d1d6 = unaff_D6;
  DAT_0001d1da = unaff_D7;
  DAT_0001d1de = extraout_A0;
  DAT_0001d1e2 = extraout_A1;
  DAT_0001d1e6 = unaff_A2;
  DAT_0001d1ea = unaff_A3;
  DAT_0001d1ee = unaff_A4;
  DAT_0001d1f2 = unaff_A5;
  DAT_0001d1f6 = unaff_A6;
  FUN_00012324();
  return CONCAT44(DAT_0001d1be,DAT_0001d1c2);
}


// ---------------------------------------------------------------
// FUN_0001687e @ 0001687e

void FUN_0001687e(void)

{
  int unaff_A6;
  
  FUN_00010fb4();
  FUN_00010b6c(unaff_A6 + 1);
  return;
}


// ---------------------------------------------------------------
// FUN_000168a0 @ 000168a0

void FUN_000168a0(void)

{
  int unaff_A6;
  
  FUN_00018f7a();
  FUN_00010fb4();
  FUN_0001695a(unaff_A6 + 1);
  FUN_00010b6c();
  FUN_0001228a();
  FUN_0001232e();
  return;
}


// ---------------------------------------------------------------
// FUN_000168d4 @ 000168d4

void FUN_000168d4(void)

{
  int unaff_A6;
  
  FUN_00010fb4();
  FUN_0001695a(unaff_A6 + 1);
  *(byte *)(unaff_A6 + 4) = *(byte *)(unaff_A6 + 4) & 0xbf;
  FUN_00010b6c();
  FUN_0001228a();
  FUN_0001232e();
  return;
}


// ---------------------------------------------------------------
// FUN_00016902 @ 00016902

void FUN_00016902(void)

{
  int unaff_A6;
  
  FUN_00010fb4();
  DAT_0001a484 = DAT_0001a482;
  FUN_0001695a();
  *(byte *)(unaff_A6 + 3) = *(byte *)(unaff_A6 + 3) & 0xbf;
  FUN_00010b6c();
  FUN_00018e12();
  FUN_0001228a();
  FUN_0001232e();
  return;
}


// ---------------------------------------------------------------
// FUN_0001695a @ 0001695a

void FUN_0001695a(void)

{
  if (*selected_object < 0x23) {
    DAT_00019971 = selected_object[1];
    DAT_00019973 = 0xf4;
  }
  else {
    DAT_00019971 = *selected_object - 0x14;
    DAT_00019973 = 0xd4;
  }
  DAT_00019972 = selected_object[2] - 0x28;
  return;
}


// ---------------------------------------------------------------
// FUN_0001699c @ 0001699c

/* WARNING: Removing unreachable block (ram,0x00016a14) */

void FUN_0001699c(void)

{
  ushort uVar1;
  char cVar2;
  short unaff_D5w;
  short unaff_D6w;
  int extraout_A0;
  
  FUN_0001680c();
  the_command = 0x9183;
  if ((DAT_0001acc9 != '\0') && (DAT_0001ace6 != '\0')) {
    cVar2 = *(char *)(extraout_A0 + 2);
    if (cVar2 == ']') {
      cVar2 = '=';
    }
    if (cVar2 == -0x7b) {
      cVar2 = '<';
    }
    the_command = *(ushort *)(&UNK_0001ac82 + (uint)(byte)(cVar2 - 0x2a) * 2);
  }
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  if (uVar1 == 0) {
    FUN_00010630();
    return;
  }
  if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
    if (uVar1 == 0x9000) {
      FUN_00010fc4();
      FUN_00010998();
      DAT_0001a512 = unaff_D6w + 2;
      if (4 < (byte)unaff_D5w) {
        DAT_0001a512 = 0x14;
      }
      FUN_000109bc();
      DAT_0001a514 = unaff_D5w * 6 + 7;
      DAT_0001a532 = cursor_x >> 2;
      if (DAT_0001a532 < 9) {
        DAT_0001a532 = 9;
      }
      if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
        DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
      }
      DAT_0001a530 = cursor_y;
      if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
        DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
      }
      FUN_00010fec();
      FUN_0001258a();
      FUN_00010e66();
      prompt_wait();
      FUN_000124f2();
      return;
    }
    if (uVar1 == 0xf000) {
      register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
    }
    *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
    FUN_00012950();
    templ_ptr = &TEMPL_data;
    FUN_00010630();
    return;
  }
  (**(code **)(&cmd_jump_table +
              (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),(char)(the_command & 0x3ff) + -1)
                      << 2)))();
  return;
}


// ---------------------------------------------------------------
// FUN_000169a4 @ 000169a4

/* WARNING: Removing unreachable block (ram,0x00016a14) */

void FUN_000169a4(void)

{
  ushort uVar1;
  char cVar2;
  short unaff_D5w;
  short unaff_D6w;
  int extraout_A0;
  
  FUN_0001680c();
  the_command = 0x9183;
  if ((DAT_0001acc9 != '\0') && (DAT_0001ace6 != '\0')) {
    cVar2 = *(char *)(extraout_A0 + 2);
    if (cVar2 == ']') {
      cVar2 = '=';
    }
    if (cVar2 == -0x7b) {
      cVar2 = '<';
    }
    the_command = *(ushort *)(&UNK_0001ac5a + (uint)(byte)(cVar2 - 0x2a) * 2);
  }
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  if (uVar1 == 0) {
    FUN_00010630();
    return;
  }
  if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
    if (uVar1 == 0x9000) {
      FUN_00010fc4();
      FUN_00010998();
      DAT_0001a512 = unaff_D6w + 2;
      if (4 < (byte)unaff_D5w) {
        DAT_0001a512 = 0x14;
      }
      FUN_000109bc();
      DAT_0001a514 = unaff_D5w * 6 + 7;
      DAT_0001a532 = cursor_x >> 2;
      if (DAT_0001a532 < 9) {
        DAT_0001a532 = 9;
      }
      if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
        DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
      }
      DAT_0001a530 = cursor_y;
      if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
        DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
      }
      FUN_00010fec();
      FUN_0001258a();
      FUN_00010e66();
      prompt_wait();
      FUN_000124f2();
      return;
    }
    if (uVar1 == 0xf000) {
      register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
    }
    *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
    FUN_00012950();
    templ_ptr = &TEMPL_data;
    FUN_00010630();
    return;
  }
  (**(code **)(&cmd_jump_table +
              (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),(char)(the_command & 0x3ff) + -1)
                      << 2)))();
  return;
}


// ---------------------------------------------------------------
// FUN_000169ac @ 000169ac

/* WARNING: Removing unreachable block (ram,0x000103e8) */
/* WARNING: Removing unreachable block (ram,0x000103e0) */
/* WARNING: Removing unreachable block (ram,0x000103ee) */
/* WARNING: Removing unreachable block (ram,0x00010420) */
/* WARNING: Removing unreachable block (ram,0x0001040a) */
/* WARNING: Removing unreachable block (ram,0x00010768) */

void FUN_000169ac(void)

{
  char cVar1;
  short unaff_D5w;
  short unaff_D6w;
  int extraout_A0;
  
  FUN_0001680c();
  the_command = 0x9183;
  if ((DAT_0001acc9 != '\0') && (DAT_0001ace6 != '\0')) {
    cVar1 = *(char *)(extraout_A0 + 2);
    if (cVar1 == ']') {
      cVar1 = '=';
    }
    if (cVar1 == -0x7b) {
      cVar1 = '<';
    }
    the_command = *(undefined2 *)(&UNK_0001ac32 + (uint)(byte)(cVar1 - 0x2a) * 2);
    FUN_00018f8e();
    run_command_keep_sp();
    return;
  }
  FUN_00010fc4();
  FUN_00010998();
  DAT_0001a512 = unaff_D6w + 2;
  if (4 < (byte)unaff_D5w) {
    DAT_0001a512 = 0x14;
  }
  FUN_000109bc();
  DAT_0001a514 = unaff_D5w * 6 + 7;
  DAT_0001a532 = cursor_x >> 2;
  if (DAT_0001a532 < 9) {
    DAT_0001a532 = 9;
  }
  if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
    DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
  }
  DAT_0001a530 = cursor_y;
  if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
    DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
  }
  FUN_00010fec();
  FUN_0001258a();
  FUN_00010e66();
  prompt_wait();
  FUN_000124f2();
  return;
}


// ---------------------------------------------------------------
// FUN_000169b4 @ 000169b4

/* WARNING: Removing unreachable block (ram,0x00016a14) */

void FUN_000169b4(void)

{
  ushort uVar1;
  char cVar2;
  short unaff_D5w;
  short unaff_D6w;
  int extraout_A0;
  
  FUN_0001680c();
  the_command = 0x9183;
  if ((DAT_0001acc9 != '\0') && (DAT_0001ace6 != '\0')) {
    cVar2 = *(char *)(extraout_A0 + 2);
    if (cVar2 == ']') {
      cVar2 = '=';
    }
    if (cVar2 == -0x7b) {
      cVar2 = '<';
    }
    the_command = *(ushort *)(&DAT_0001ac0a + (uint)(byte)(cVar2 - 0x2a) * 2);
  }
  if (the_command == 0) {
    return;
  }
  uVar1 = the_command & 0xf000;
  if (uVar1 == 0) {
    FUN_00010630();
    return;
  }
  if ((uVar1 != 0xa000) && (uVar1 != 0xb000)) {
    if (uVar1 == 0x9000) {
      FUN_00010fc4();
      FUN_00010998();
      DAT_0001a512 = unaff_D6w + 2;
      if (4 < (byte)unaff_D5w) {
        DAT_0001a512 = 0x14;
      }
      FUN_000109bc();
      DAT_0001a514 = unaff_D5w * 6 + 7;
      DAT_0001a532 = cursor_x >> 2;
      if (DAT_0001a532 < 9) {
        DAT_0001a532 = 9;
      }
      if (0x48 < (ushort)(DAT_0001a512 + DAT_0001a532 + 2)) {
        DAT_0001a532 = DAT_0001a532 - (DAT_0001a512 + DAT_0001a532 + -0x47);
      }
      DAT_0001a530 = cursor_y;
      if (199 < (ushort)(DAT_0001a514 + cursor_y)) {
        DAT_0001a530 = cursor_y - ((DAT_0001a514 + cursor_y) - 200U);
      }
      FUN_00010fec();
      FUN_0001258a();
      FUN_00010e66();
      prompt_wait();
      FUN_000124f2();
      return;
    }
    if (uVar1 == 0xf000) {
      register0x0000003c = (BADSPACEBASE *)DAT_0001a826;
    }
    *(undefined4 *)((int)register0x0000003c + -4) = 0x103fe;
    FUN_00012950();
    templ_ptr = &TEMPL_data;
    FUN_00010630();
    return;
  }
  (**(code **)(&cmd_jump_table +
              (ushort)(CONCAT11((char)((the_command & 0x3ff) >> 8),(char)(the_command & 0x3ff) + -1)
                      << 2)))();
  return;
}


// ---------------------------------------------------------------
// FUN_00016a20 @ 00016a20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00016a20(void)

{
  short sVar1;
  short sVar2;
  
  DAT_0001ad30 = 1;
  FUN_0001066e();
  DAT_0000d8f0 = s_G_G_G_G_0001998a[0];
  DAT_0000d8f1 = s_G_G_G_G_0001998a[1];
  _DAT_000192e4 = 0;
  DAT_000192be = 0x64c8e;
  FUN_00016ab6();
  sVar2 = 10;
  do {
    FUN_00014138();
    FUN_00013594();
    copy_screen();
    sVar1 = -1;
    do {
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    FUN_00014138();
    FUN_00013594();
    copy_screen();
    sVar1 = -1;
    do {
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  FUN_00014138();
  FUN_00014138();
  copy_screen();
  xbios_supexec();
  return;
}


// ---------------------------------------------------------------
// FUN_00016ab6 @ 00016ab6

void FUN_00016ab6(void)

{
  FUN_00018f0c();
  return;
}


// ---------------------------------------------------------------
// FUN_00016abe @ 00016abe

void FUN_00016abe(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  FUN_00016dbc();
  sVar1 = ((byte)(DAT_0001ab41 - DAT_0001ab40) >> 2) - 1;
  sVar3 = (byte)(DAT_0001ab43 - DAT_0001ab42) / 0x1e - 1;
  sVar2 = sVar1;
  do {
    do {
      FUN_00016b2e();
      sVar2 = sVar2 + -1;
    } while (sVar2 != -1);
    sVar3 = sVar3 + -1;
    sVar2 = sVar1;
  } while (sVar3 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016b2e @ 00016b2e

void FUN_00016b2e(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar6;
  short unaff_D2w;
  short unaff_D3w;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *unaff_A3;
  int unaff_A5;
  
  puVar9 = (ushort *)(&DAT_0000d8f0 + unaff_A5);
  sVar6 = unaff_D2w;
  puVar11 = unaff_A3;
  puVar10 = puVar9;
  do {
    do {
      uVar1 = *puVar9;
      uVar2 = puVar9[1];
      uVar3 = puVar9[2];
      uVar4 = puVar9[3];
      puVar9 = puVar9 + 4;
      uVar5 = ~(uVar4 | uVar3 | uVar2 | uVar1);
      *unaff_A3 = uVar5 & *unaff_A3;
      puVar7 = unaff_A3 + 1;
      *unaff_A3 = uVar1 | *unaff_A3;
      *puVar7 = uVar5 & *puVar7;
      puVar8 = unaff_A3 + 2;
      *puVar7 = uVar2 | *puVar7;
      *puVar8 = uVar5 & *puVar8;
      puVar7 = unaff_A3 + 3;
      *puVar8 = uVar3 | *puVar8;
      *puVar7 = uVar5 & *puVar7;
      unaff_A3 = unaff_A3 + 4;
      *puVar7 = uVar4 | *puVar7;
      sVar6 = sVar6 + -1;
    } while (sVar6 != -1);
    unaff_A3 = puVar11 + 0x50;
    puVar9 = puVar10 + 0x20;
    unaff_D3w = unaff_D3w + -1;
    sVar6 = unaff_D2w;
    puVar11 = unaff_A3;
    puVar10 = puVar9;
  } while (unaff_D3w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016b76 @ 00016b76

void FUN_00016b76(void)

{
  short sVar1;
  short unaff_D2w;
  short unaff_D3w;
  undefined4 *puVar2;
  undefined4 *puVar4;
  undefined4 *unaff_A3;
  undefined4 *puVar3;
  undefined4 *puVar5;
  
  do {
    puVar4 = unaff_A3 + -0x2000;
    sVar1 = unaff_D2w;
    puVar2 = unaff_A3;
    do {
      puVar5 = puVar4 + 1;
      puVar3 = puVar2 + 1;
      *puVar2 = *puVar4;
      puVar4 = puVar4 + 2;
      puVar2 = puVar2 + 2;
      *puVar3 = *puVar5;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    unaff_A3 = unaff_A3 + 0x28;
    unaff_D3w = unaff_D3w + -1;
  } while (unaff_D3w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016b9c @ 00016b9c

void FUN_00016b9c(void)

{
  short sVar1;
  
  FUN_00016dbc();
  FUN_00016b2e();
  FUN_00016dbc();
  sVar1 = 0x47;
  FUN_00016b2e();
  prompt_wait();
  do {
    FUN_00016d1e();
    FUN_00016b76();
    FUN_00016b2e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  FUN_00016b76();
  return;
}


// ---------------------------------------------------------------
// FUN_00016c00 @ 00016c00

void FUN_00016c00(void)

{
  FUN_00016dbc();
  FUN_00016b2e();
  DAT_0001a56a = 1;
  DAT_0001a577 = 0x11;
  FUN_00012e2e();
  return;
}


// ---------------------------------------------------------------
// FUN_00016c48 @ 00016c48

void FUN_00016c48(void)

{
  short sVar1;
  char *unaff_A6;
  
  FUN_00016dbc();
  sVar1 = 3;
  if (*unaff_A6 != '\0') {
    sVar1 = 2;
  }
  do {
    FUN_00016d1e();
    FUN_00016b76();
    FUN_00016b2e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  if (*unaff_A6 != '\0') {
    FUN_00016b76();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00016c6c @ 00016c6c

void FUN_00016c6c(void)

{
  short sVar1;
  char *unaff_A6;
  
  sVar1 = 3;
  if (*unaff_A6 != '\0') {
    sVar1 = 2;
  }
  do {
    FUN_00016d1e();
    FUN_00016b76();
    FUN_00016b2e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  if (*unaff_A6 != '\0') {
    FUN_00016b76();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00016ca6 @ 00016ca6

void FUN_00016ca6(void)

{
  short sVar1;
  
  FUN_00016dbc();
  sVar1 = 0x21;
  do {
    FUN_00016d1e();
    FUN_00016b76();
    FUN_00016b2e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016ce2 @ 00016ce2

void FUN_00016ce2(void)

{
  short sVar1;
  
  FUN_00016dbc();
  sVar1 = 0x43;
  do {
    FUN_00016d1e();
    FUN_00016b76();
    FUN_00016b2e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016d1e @ 00016d1e

/* WARNING: Removing unreachable block (ram,0x00016d2e) */
/* WARNING: Removing unreachable block (ram,0x00016d3a) */

void FUN_00016d1e(void)

{
                    /* WARNING: Do nothing block with infinite loop */
  do {
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00016d3c @ 00016d3c

void FUN_00016d3c(void)

{
  short sVar1;
  
  FUN_00016dbc();
  sVar1 = 0xf;
  do {
    FUN_00016d1e();
    FUN_00016b76();
    FUN_00016b2e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016d78 @ 00016d78

void FUN_00016d78(void)

{
  short sVar1;
  
  FUN_00016dbc();
  sVar1 = 0xe;
  do {
    FUN_00016d1e();
    FUN_00016b76();
    FUN_00016b2e();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00016dba @ 00016dba

void FUN_00016dba(void)

{
  return;
}


// ---------------------------------------------------------------
// FUN_00016dbc @ 00016dbc

void FUN_00016dbc(void)

{
  int extraout_A1;
  
  FUN_00010fec();
  FUN_00010f8e();
  DAT_0001a534 = (uint)*(byte *)(extraout_A1 + 1) << 1;
  FUN_000126e0();
  return;
}


// ---------------------------------------------------------------
// FUN_00016dec @ 00016dec

void FUN_00016dec(void)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_D3;
  undefined4 unaff_D4;
  uint uVar5;
  undefined4 unaff_D5;
  undefined4 unaff_D6;
  undefined4 unaff_D7;
  undefined4 extraout_A0;
  int extraout_A1;
  int extraout_A1_00;
  undefined4 extraout_A1_01;
  undefined4 unaff_A2;
  undefined4 unaff_A3;
  char *unaff_A5;
  int unaff_A6;
  
  FUN_0001285a();
  bVar1 = *(byte *)(unaff_A6 + 1);
  uVar4 = (uint)bVar1;
  uVar5 = CONCAT31((int3)((uint)unaff_D4 >> 8),*(undefined1 *)(unaff_A6 + 3)) & 0xffff00ff;
  FUN_00018e12();
  DAT_0001aa6e = (ushort)uVar5;
  DAT_0001a2ae = bVar1;
  FUN_00012950();
  do {
    DAT_0001a2ad = *unaff_A5;
    FUN_000129c8();
    iVar3 = extraout_A1;
    pcVar2 = unaff_A5 + 1;
    if (unaff_A5[1] == -1) {
      FUN_000129d6();
      iVar3 = extraout_A1_00;
      pcVar2 = unaff_A5 + 2;
    }
    unaff_A5 = pcVar2;
    FUN_000120dc(iVar3 + 4);
    FUN_000124da();
    if (DAT_0001aa6e != 0) {
      if (unaff_A5[-1] == '%') {
        if (DAT_0001ad03 == '\0') {
          FUN_00018a30((uint)DAT_0001aa6e,uVar4,unaff_D3,uVar5,unaff_D5,unaff_D6,unaff_D7,
                       extraout_A0,extraout_A1_01,unaff_A2,unaff_A3);
        }
        else {
          FUN_00016250();
        }
      }
      else {
        iVar3 = (uint)DAT_0001aa6e << 0xc;
        do {
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
  } while (unaff_A5 != &DAT_000246e6);
  return;
}


// ---------------------------------------------------------------
// FUN_00016ed8 @ 00016ed8

void FUN_00016ed8(void)

{
  int iVar1;
  bool bVar2;
  undefined1 uVar3;
  
  DAT_0001ad0d = 1;
  cur_filename = "SCENA.BIN";
  bVar2 = false;
  gemdos_fopen();
  if (!bVar2) {
    load_length = 0x291c;
    load_buffer = &PTR_DAT_0001a752;
    bVar2 = false;
    iVar1 = gemdos_fread();
    if ((!bVar2) && (iVar1 == load_length)) {
      load_buffer = screen_ptr_b;
      load_length = 32000;
      bVar2 = false;
      iVar1 = gemdos_fread();
      if ((!bVar2) && (uVar3 = iVar1 - load_length < 0, iVar1 == load_length)) {
        copy_screen();
        FUN_000162da();
        iVar1 = gemdos_fread();
        if ((!(bool)uVar3) && (bVar2 = iVar1 - load_length < 0, iVar1 == load_length)) {
          gemdos_fclose();
          if (!bVar2) {
            FUN_00016f90();
            FUN_00016460();
            DAT_0001ad0d = 0;
            DAT_0001a750 = 0;
            return;
          }
        }
      }
    }
  }
  DAT_0001ad0d = 0;
  DAT_0001a750 = 0xff;
  return;
}


// ---------------------------------------------------------------
// FUN_00016f90 @ 00016f90

void FUN_00016f90(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_DAT_0001a752;
  do {
    if (*ppuVar1 != (undefined *)0x0) {
      *ppuVar1 = &UNK_000101a8 + (int)*ppuVar1;
    }
    ppuVar1 = ppuVar1 + 1;
  } while (ppuVar1 != (undefined **)&DAT_0001a82e);
  return;
}


// ---------------------------------------------------------------
// FUN_00016fb4 @ 00016fb4

void FUN_00016fb4(void)

{
  int iVar1;
  undefined **ppuVar2;
  bool bVar3;
  
  DAT_0001ad0d = 1;
  draw_hint_icons();
  ppuVar2 = &PTR_DAT_0001a752;
  do {
    if (*ppuVar2 != (undefined *)0x0) {
      *ppuVar2 = *ppuVar2 + -0x101a8;
    }
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 != (undefined **)&DAT_0001a82e);
  cur_filename = "SCENA.BIN";
  bVar3 = false;
  gemdos_fcreate();
  if (!bVar3) {
    load_length = 0x291c;
    load_buffer = &PTR_DAT_0001a752;
    bVar3 = false;
    iVar1 = gemdos_fwrite();
    if ((!bVar3) && (iVar1 == load_length)) {
      load_buffer = screen_ptr_a;
      load_length = 32000;
      bVar3 = false;
      iVar1 = gemdos_fwrite();
      if ((!bVar3) && (iVar1 == load_length)) {
        load_buffer = screen_ptr_b;
        bVar3 = (int)screen_ptr_b < 0;
        iVar1 = gemdos_fwrite();
        if ((!bVar3) && (bVar3 = iVar1 - load_length < 0, iVar1 == load_length)) {
          gemdos_fclose();
          if (!bVar3) {
            FUN_00016f90();
            DAT_0001ad0d = 0;
            DAT_0001a750 = 0;
            return;
          }
        }
      }
    }
  }
  FUN_00016f90();
  DAT_0001ad0d = 0;
  DAT_0001a750 = 0xff;
  return;
}


// ---------------------------------------------------------------
// FUN_00017094 @ 00017094

void FUN_00017094(void)

{
  undefined1 *in_A1;
  int iVar1;
  char *pcVar2;
  
  if ((DAT_0001acd2 != '\b') || ((DAT_0001acfc & 0x80) == 0)) {
    in_A1 = &DAT_0001aa72;
    DAT_0001aa73 = DAT_0001aa73 & 0xbf;
    DAT_0001ab1d = DAT_0001ab1d & 0xbf;
    DAT_0001ab22 = DAT_0001ab22 & 0xbf;
    iVar1 = object_list_begin;
    do {
      if ((*(byte *)(iVar1 + 4) & 0x7f) == 0x50) {
        pcVar2 = &DAT_00019b46;
        do {
          if (DAT_0001acc7 == *pcVar2) {
            DAT_0001a80a = pcVar2;
            if (((DAT_0001acd2 != DAT_0001aa72) && (DAT_0001acd2 != DAT_0001ab1c)) &&
               (DAT_0001acd2 != DAT_0001ab21)) {
              DAT_0001ab1c = '\0';
              DAT_0001aa72 = 0;
              DAT_0001ab21 = '\0';
              DAT_0001acfc = DAT_0001acfc & 0x80;
              if (0x26 < DAT_0001acd7) {
                if (0x4d < DAT_0001acd7) {
                  return;
                }
                DAT_0001acaa = 0xa014;
                DAT_0001acac = DAT_0001ab60 + 5;
                DAT_0001acfc = DAT_0001acfc | 1;
                return;
              }
              DAT_0001aa72 = DAT_0001acd2;
            }
            DAT_0001acaa = 0xa015;
            DAT_0001acac = DAT_0001ab60 + 5;
            DAT_0001acfc = DAT_0001acfc | 1;
            return;
          }
          pcVar2 = pcVar2 + 0xd;
        } while (pcVar2 != &DAT_00019c8b);
        break;
      }
      iVar1 = iVar1 + 8;
    } while (iVar1 != object_list_end);
  }
  in_A1[0xaa] = 0;
  *in_A1 = 0;
  in_A1[0xaf] = 0;
  DAT_0001acfc = DAT_0001acfc & 0x80;
  return;
}


// ---------------------------------------------------------------
// FUN_000171b4 @ 000171b4

void FUN_000171b4(void)

{
  DAT_0001aa72 = DAT_0001acd2;
  FUN_000177bc();
  FUN_00017856();
  xbios_supexec();
  DAT_0001acaa = 0xa015;
  DAT_0001acac = DAT_0001ab60 + 5;
  draw_hint_icons();
  update_icon_list();
  copy_screen();
  return;
}


// ---------------------------------------------------------------
// FUN_000171fa @ 000171fa

void FUN_000171fa(void)

{
  byte *pbVar1;
  char *pcVar2;
  
  DAT_0001a806 = &DAT_0001aa72;
  if (DAT_0001aa72 == '\0') {
    DAT_0001a806 = &DAT_0001ab1c;
    if (DAT_0001ab1c == '\0') {
      DAT_0001ab21 = 0;
      DAT_0001acfc = DAT_0001acfc | 0x80;
      DAT_0001a806 = &DAT_0001aa72;
      DAT_0001aa73 = DAT_0001ab22;
    }
  }
  pcVar2 = &DAT_00019cd1;
  do {
    if (DAT_0001acc6 == *pcVar2) {
      DAT_0001acaa = 0xa016;
      DAT_0001acac = DAT_0001ab60 + 5;
      *DAT_0001a806 = pcVar2[1];
      goto LAB_00017280;
    }
    pcVar2 = pcVar2 + 2;
  } while (pcVar2 != &UNK_00019cf7);
  *DAT_0001a806 = '\0';
  DAT_0001acaa = 0;
LAB_00017280:
  pbVar1 = (byte *)(((DAT_0001a806[1] & 0xf) - 1) * 8 + object_list_begin + 4);
  *pbVar1 = *pbVar1 & 0x7f;
  FUN_000177bc();
  FUN_00017856();
  xbios_supexec();
  DAT_0001acfc = DAT_0001acfc & 0x80;
  return;
}


// ---------------------------------------------------------------
// FUN_000172ba @ 000172ba

void FUN_000172ba(void)

{
  *DAT_0001a806 = 0;
  DAT_0001acaa = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_000172ca @ 000172ca

void FUN_000172ca(void)

{
  int iVar1;
  char *pcVar2;
  
  if ((DAT_0001acd2 == ';') && (DAT_0001ad14 == '\0')) {
    DAT_0001aa8b = 0x3b;
    return;
  }
  DAT_0001aa8c = DAT_0001aa8c & 0xbf;
  iVar1 = object_list_begin;
  while ((*(byte *)(iVar1 + 4) & 0x7f) != 0x51) {
    iVar1 = iVar1 + 8;
    if (iVar1 == object_list_end) {
      DAT_0001aa8b = 0;
      return;
    }
  }
  pcVar2 = &DAT_00019c8b;
  do {
    if (DAT_0001acc7 == *pcVar2) {
      DAT_0001a80e = pcVar2;
      if (DAT_0001acd2 != DAT_0001aa8b) {
        DAT_0001aa8b = 0;
        if (DAT_0001acd7 < 0xd9) {
          if (0xb1 < DAT_0001acd7) {
            DAT_0001acae = 0xa01e;
            DAT_0001acb0 = DAT_0001ab60 + 5;
            return;
          }
          return;
        }
        DAT_0001aa8b = DAT_0001acd2;
      }
      DAT_0001acae = 0xa01f;
      DAT_0001acb0 = DAT_0001ab60 + 5;
      return;
    }
    pcVar2 = pcVar2 + 7;
  } while (pcVar2 != &DAT_00019cd1);
  DAT_0001aa8b = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_000173ae @ 000173ae

void FUN_000173ae(void)

{
  DAT_0001aa8b = DAT_0001acd2;
  FUN_000177bc();
  FUN_00017856();
  DAT_0001acae = 0xa01f;
  DAT_0001acb0 = DAT_0001ab60 + 5;
  draw_hint_icons();
  update_icon_list();
  copy_screen();
  return;
}


// ---------------------------------------------------------------
// FUN_000173f2 @ 000173f2

void FUN_000173f2(void)

{
  byte *pbVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_00019cd1;
  do {
    if (DAT_0001acc6 == *pcVar2) {
      DAT_0001acae = 0xa020;
      DAT_0001acb0 = DAT_0001ab60 + 5;
      DAT_0001aa8b = pcVar2[1];
      goto LAB_00017448;
    }
    pcVar2 = pcVar2 + 2;
  } while (pcVar2 != &UNK_00019cf7);
  DAT_0001aa8b = '\0';
  DAT_0001acae = 0;
LAB_00017448:
  pbVar1 = (byte *)(((DAT_0001aa8c & 0xf) - 1) * 8 + object_list_begin + 4);
  *pbVar1 = *pbVar1 & 0x7f;
  FUN_000177bc();
  FUN_00017856();
  return;
}


// ---------------------------------------------------------------
// FUN_00017472 @ 00017472

void FUN_00017472(void)

{
  DAT_0001aa8b = 0;
  DAT_0001acae = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00017480 @ 00017480

void FUN_00017480(void)

{
  byte bVar1;
  byte extraout_D1b;
  undefined4 extraout_A0;
  int extraout_A1;
  byte *extraout_A1_00;
  bool bVar2;
  
  if (DAT_0001acd2 == 0x37) {
    DAT_0001aa77 = 0x37;
    DAT_0001aa7c = 0x37;
    DAT_0001aa81 = 0x37;
    DAT_0001aa79 = 0x32;
    DAT_0001aa7e = 0x32;
    DAT_0001aa83 = 0x32;
    return;
  }
  DAT_0001aa77 = 0;
  DAT_0001aa7c = 0;
  DAT_0001aa81 = 0;
  DAT_0001aa86 = 0;
  if ((0x3e < DAT_0001acec) || (0x2b < DAT_0001acd2)) {
    return;
  }
  bVar2 = false;
  FUN_0001778e();
  if (!bVar2) {
    return;
  }
  DAT_0001ad00 = DAT_0001ad00 + 5;
  if (0x18 < DAT_0001ad00) {
    DAT_0001ad00 = 5;
  }
  DAT_0001a812 = (uint)DAT_0001ad00 + extraout_A1;
  if ((*(byte *)(DAT_0001a812 + 1) & 0x40) != 0) {
    DAT_0001a816 = extraout_A0;
    return;
  }
  DAT_0001a816 = extraout_A0;
  bVar1 = FUN_00016210();
  DAT_0001acff = 0;
  if (DAT_0001acd2 < 6) {
    if ((((extraout_D1b < 0x5a) && (extraout_A1_00[4] != 0)) && (5 < extraout_A1_00[4])) &&
       ((extraout_A1_00[4] < 0x1b && ((extraout_A1_00[4] < 0x13 || (0x16 < extraout_A1_00[4])))))) {
      DAT_0001acff = 1;
    }
    if (bVar1 < 0x17) {
LAB_000175c4:
      *extraout_A1_00 = DAT_0001acd2;
      PTR_DAT_0001a772 = extraout_A1_00;
      DAT_0001abf8 = 0xa018;
      DAT_0001acf2 = 3;
      return;
    }
    if (0x33 < bVar1) {
      DAT_0001acff = 0;
      return;
    }
  }
  else {
    if ((extraout_D1b < 0x27) && (extraout_A1_00[4] != 0)) {
      DAT_0001acff = 1;
    }
    if (0xa5 < extraout_D1b) {
      DAT_0001acff = 2;
    }
    if (bVar1 < 0x1a) goto LAB_000175c4;
    if (0x33 < bVar1) {
      DAT_0001acff = 0;
      return;
    }
  }
  DAT_0001abf8 = 0xa019;
  DAT_0001acf2 = 3;
  DAT_0001acff = DAT_0001acff | 4;
  PTR_DAT_0001a772 = extraout_A1_00;
  return;
}


// ---------------------------------------------------------------
// FUN_000175f6 @ 000175f6

void FUN_000175f6(void)

{
  FUN_00012368();
  *DAT_0001a812 = DAT_0001acd2;
  DAT_0001abf8 = 0xa018;
  DAT_0001acf2 = 3;
  DAT_0001ace7 = 0;
  FUN_000177bc();
  FUN_00017856();
  draw_hint_icons();
  update_icon_list();
  copy_screen();
  if (DAT_0001acff == '\x05') {
    the_command = 0xc029;
    DAT_0001acff = 0;
    run_command_keep_sp();
    return;
  }
  if (DAT_0001acff == '\x06') {
    the_command = 0xc165;
    DAT_0001acff = 0;
    run_command_keep_sp();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00017678 @ 00017678

void FUN_00017678(void)

{
  undefined1 *puVar1;
  
  FUN_00012368();
  FUN_00012384();
  puVar1 = DAT_0001a812;
  *DAT_0001a812 = 0;
  DAT_0001abf8 = 0;
  if ((puVar1[1] & 0x40) == 0) {
    *(byte *)(DAT_0001a816 + 4) = *(byte *)(DAT_0001a816 + 4) & 0x7f;
    DAT_0001acff = 0;
    FUN_000177bc();
    FUN_00017856();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000176c0 @ 000176c0

void FUN_000176c0(void)

{
  if (DAT_0001a57b == '\0') {
    if (DAT_0001acc7 == '=') {
      FUN_0001066e();
    }
  }
  else {
    FUN_0001066e();
  }
  DAT_0001ad2d = 0;
  if (DAT_0001ad09 != '\x12') {
    FUN_000162da();
    if (*selected_icon_ptr != 0) {
      blit_sprite(*selected_icon_ptr);
      FUN_0001215e();
      if ((((DAT_0001ad03 == '\0') && (DAT_0001ad26 == '\0')) && (DAT_0001acf7 != '\0')) &&
         (DAT_0001a57b == '\0')) {
        DAT_0001ad2d = 1;
        FUN_00018f8e();
        FUN_000159e2();
      }
    }
  }
  DAT_0001a57a = DAT_0001ad03;
  DAT_0001ad03 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_0001778e @ 0001778e

void FUN_0001778e(void)

{
  byte in_D0b;
  int iVar1;
  
  iVar1 = object_list_begin;
  do {
    if ((*(byte *)(iVar1 + 4) & 0x3f) == in_D0b) {
      return;
    }
    iVar1 = iVar1 + 8;
  } while (iVar1 != object_list_end);
  return;
}


// ---------------------------------------------------------------
// FUN_00017792 @ 00017792

void FUN_00017792(void)

{
  byte in_D0b;
  byte unaff_D3b;
  int iVar1;
  
  iVar1 = object_list_begin;
  do {
    if ((unaff_D3b & *(byte *)(iVar1 + 4)) == in_D0b) {
      return;
    }
    iVar1 = iVar1 + 8;
  } while (iVar1 != object_list_end);
  return;
}


// ---------------------------------------------------------------
// FUN_000177bc @ 000177bc

uint FUN_000177bc(void)

{
  uint in_D0;
  uint uVar1;
  char unaff_D2b;
  undefined4 extraout_A0;
  bool bVar2;
  
  PTR_DAT_0001a772 = &DAT_0001aa72 + (in_D0 & 0xff);
  bVar2 = ((&DAT_0001aa75)[in_D0 & 0xff] & 7 | 0x10) == 0;
  uVar1 = FUN_0001778e();
  if (bVar2) {
    selected_object = extraout_A0;
    DAT_0001acc9 = unaff_D2b;
    selected_icon_ptr = &command_hints_list + (byte)(unaff_D2b - 1);
    return uVar1 & 0xffffff00;
  }
  return uVar1;
}


// ---------------------------------------------------------------
// FUN_000177e4 @ 000177e4

undefined1 FUN_000177e4(void)

{
  char unaff_D2b;
  undefined4 in_A0;
  
  selected_object = in_A0;
  DAT_0001acc9 = unaff_D2b;
  selected_icon_ptr = &command_hints_list + (byte)(unaff_D2b - 1);
  return 0;
}


// ---------------------------------------------------------------
// FUN_0001780c @ 0001780c

undefined4 FUN_0001780c(void)

{
  undefined4 uVar1;
  int unaff_A6;
  bool bVar2;
  undefined8 uVar3;
  
  bVar2 = *(char *)(unaff_A6 + 1) == '\0';
  if ((!bVar2) && (FUN_00017792(), !bVar2)) {
    uVar3 = FUN_000135e0();
    uVar1 = (undefined4)((ulonglong)uVar3 >> 0x20);
    __m68k_trap(1);
    FUN_00012324(uVar3);
    return uVar1;
  }
  FUN_000177e4();
  uVar1 = FUN_00014926();
  if (DAT_0001ace6 == '\0') {
    PTR_DAT_0001a772 = &DAT_0001aad6;
  }
  return uVar1;
}


// ---------------------------------------------------------------
// FUN_00017856 @ 00017856

void FUN_00017856(void)

{
  byte *pbVar1;
  byte *in_A1;
  undefined4 uVar2;
  
  uVar2 = *selected_icon_ptr;
  blit_sprite(uVar2);
  if ((*in_A1 & 0x80) != 0) {
    cursor_x = (ushort)*selected_object << 2;
    cursor_y = (ushort)selected_object[2];
    pbVar1 = selected_object;
    if ((in_A1[1] != 0) || (in_A1[2] != 0)) {
      draw_text_box(selected_object,uVar2);
    }
    DAT_00055b02 = *in_A1 & 0x7f;
    DAT_00055b03 = *pbVar1;
    DAT_00055b04 = pbVar1[2];
  }
  FUN_000159d2();
  return;
}


// ---------------------------------------------------------------
// FUN_000178cc @ 000178cc

void FUN_000178cc(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int unaff_A6;
  
  iVar2 = DAT_0001a812;
  bVar1 = *(byte *)(DAT_0001a812 + 4);
  if (bVar1 != 0) {
    *(undefined1 *)(DAT_0001a812 + 4) = 0;
    iVar3 = (uint)(ushort)(bVar1 - 1) * 6;
    PTR_DAT_0001a75e = &DAT_0001a8f0 + iVar3;
    DAT_0001ad01 = DAT_0001ad01 + '\x01';
    (&DAT_0001ad33)[*(byte *)(iVar2 + 3) >> 6] = (&DAT_0001a8f3)[iVar3];
    FUN_000184cc(unaff_A6 + 1);
    the_command = 0x90aa;
    run_command_keep_sp();
    return;
  }
  the_command = 0x9140;
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00017930 @ 00017930

void FUN_00017930(void)

{
  undefined4 in_D1;
  undefined1 *puVar1;
  int unaff_A6;
  
  puVar1 = PTR_DAT_0001a75e;
  if (*(char *)(unaff_A6 + 1) == '\0') {
    puVar1 = &DAT_0001a8f0 + (uint)(byte)(*(char *)(DAT_0001a812 + 4) - 1) * 6;
  }
  DAT_0001997c = (char)DAT_0001a85a + 'F';
  DAT_0001997b = (undefined1)DAT_0001a858;
  DAT_0001997a = puVar1[3] + '\x12';
  FUN_00010dfa(DAT_0001a858,
               CONCAT31((int3)(CONCAT22((short)((uint)in_D1 >> 0x10),DAT_0001a85a) >> 8),
                        DAT_0001997c),puVar1,unaff_A6 + 2);
  FUN_00011020();
  return;
}


// ---------------------------------------------------------------
// FUN_000179a2 @ 000179a2

void FUN_000179a2(void)

{
  the_command = 0x9148;
  if ((PTR_DAT_0001a772[3] & 0xf8) == 0x30) {
    PTR_DAT_0001a772[3] = PTR_DAT_0001a772[3] & 0xe7;
    PTR_DAT_0001a75e = &DAT_0001a9d4 + (uint)(byte)(DAT_0001ace6 - 10) * 6;
    DAT_0001ad01 = DAT_0001ad01 + '\x01';
    FUN_000184cc();
    the_command = 0x9147;
    run_command_keep_sp();
    DAT_0001ad2e = 1;
    the_command = 0x9032;
  }
  run_command_keep_sp();
  return;
}


// ---------------------------------------------------------------
// FUN_00017a1a @ 00017a1a

void FUN_00017a1a(void)

{
  undefined4 uVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  undefined *extraout_A0;
  undefined *extraout_A0_00;
  undefined *puVar5;
  
  uVar1 = templ_ptr;
  cVar3 = '#';
  uVar4 = 0x14;
  DAT_0001a57b = 1;
  if (PTR_DAT_0001a772[2] != ',') {
    puVar5 = PTR_DAT_0001a772;
    if (DAT_0001acaa == -0x5feb) {
      the_command = DAT_0001acaa;
      run_command_keep_sp(PTR_DAT_0001a772 + -0x1aa72);
      FUN_000177bc();
      puVar5 = extraout_A0;
    }
    if (DAT_0001abf8 == -0x3ca9) {
      the_command = DAT_0001abf8;
      run_command_keep_sp();
      puVar5 = extraout_A0_00;
    }
    if ((puVar5[2] != '8') && (puVar5[2] != '3')) {
      cVar3 = (char)DAT_0001a858 + '\x10';
      uVar4 = (undefined1)DAT_0001a85a;
      DAT_0001a57b = 0;
    }
  }
  DAT_0001996a = cVar3;
  DAT_0001996b = uVar4;
  FUN_00011f98();
  FUN_00018a30();
  if (((PTR_DAT_0001a772[2] != ',') && (PTR_DAT_0001a772[2] != '8')) && (PTR_DAT_0001a772[2] != '3')
     ) {
    FUN_000120e4();
    FUN_0001215e();
  }
  cVar3 = '\0';
  DAT_0001ad02 = 0;
  if (DAT_0001ad03 == '\0') {
    cVar3 = (&UNK_0001a69d)[(byte)(PTR_DAT_0001a772[2] - 0x2a)];
    if ((cVar3 != '\x01') && ((PTR_DAT_0001a772[1] & 0x80) != 0)) {
      cVar3 = cVar3 + -1;
    }
    if ((DAT_0001acf7 != '\0') || (DAT_0001ad2c != '\0')) {
      cVar3 = cVar3 + -1;
    }
  }
  if ((cVar3 != '\x05') &&
     ((((bVar2 = PTR_DAT_0001a772[4], 0x12 < bVar2 && (bVar2 < 0x17)) ||
       ((0x26 < bVar2 && (bVar2 < 0x34)))) ||
      (((bVar2 == 0x38 || (bVar2 == 0x39)) || ((PTR_DAT_0001a772[3] & 0xf8) == 0x30)))))) {
    cVar3 = cVar3 + '\x01';
  }
  uVar4 = 1;
  if ((cVar3 != '\0') && (cVar3 != '\x01')) {
    if (cVar3 == '\x02') {
      if (DAT_0001acd7 < 0xcd) goto LAB_00017c28;
    }
    else if ((cVar3 != '\x04') || (99 < DAT_0001acd7)) {
      uVar4 = 2;
      if (cVar3 == '\x03') {
        if (DAT_0001acd7 < 0x80) {
          uVar4 = 0x91;
          bVar2 = FUN_00016210();
          if (0x32 < bVar2) {
            uVar4 = 0x92;
          }
        }
        else {
          uVar4 = 0x31;
          bVar2 = FUN_00016210();
          if (0xcc < bVar2) {
            uVar4 = 0x32;
          }
        }
      }
      goto LAB_00017c28;
    }
    uVar4 = 0x51;
    bVar2 = FUN_00016210();
    if (0x7f < bVar2) {
      uVar4 = 0x52;
    }
  }
LAB_00017c28:
  DAT_0001ad02 = uVar4;
  FUN_000160c0();
  templ_ptr = uVar1;
  return;
}


// ---------------------------------------------------------------
// FUN_00017c42 @ 00017c42

void FUN_00017c42(void)

{
  undefined *puVar1;
  
  draw_hint_icons();
  FUN_000177bc();
  DAT_0001ad26 = 1;
  FUN_000176c0();
  DAT_0001ad26 = 0;
  DAT_0001ab30 = 0;
  FUN_000177bc();
  *(undefined1 *)(object_list_begin + 0x2c) = 0x53;
  *(byte *)(selected_object + 4) = *(byte *)(selected_object + 4) | 0x80;
  puVar1 = PTR_DAT_0001a772;
  PTR_DAT_0001a772[1] = PTR_DAT_0001a772[1] & 0xbf;
  *puVar1 = DAT_0001acd2;
  update_icon_list();
  copy_screen();
  return;
}


// ---------------------------------------------------------------
// FUN_00017ca4 @ 00017ca4

void FUN_00017ca4(void)

{
  undefined *puVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  int unaff_A6;
  char *pcVar5;
  
  iVar2 = selected_object;
  puVar1 = PTR_DAT_0001a772;
  if (DAT_0001ad09 == '\x12') {
    return;
  }
  DAT_0001aa70 = (short)PTR_DAT_0001a772 + 0x558e;
  PTR_DAT_0001a772[1] = PTR_DAT_0001a772[1] | 0x40;
  *puVar1 = 0;
  *(byte *)(iVar2 + 4) = *(byte *)(iVar2 + 4) & 0x7f;
  if (puVar1[3] == '\x10') {
    DAT_0001ab1c = DAT_0001acd2;
    DAT_0001ab1d = puVar1[1];
LAB_00017e02:
    if (DAT_0001acf7 == '\0') {
      FUN_00017856(unaff_A6 + 1);
    }
    the_command = DAT_0001acaa;
    run_command_keep_sp();
    return;
  }
  if (puVar1[3] == '\b') {
    DAT_0001ab21 = DAT_0001acd2;
    DAT_0001ab22 = puVar1[1];
    goto LAB_00017e02;
  }
  if ((((DAT_0001a57a == '\0') && (DAT_0001ad26 == '\0')) && (DAT_0001acf7 != '\0')) &&
     (DAT_0001a57b == '\0')) {
    DAT_0001ad02 = DAT_0001ad02 & 0xfe;
    return;
  }
  DAT_0001a57a = 0;
  cVar3 = '/';
  if (puVar1[2] != '8') {
    cVar3 = 'B';
    if (puVar1[2] != '3') {
      cVar3 = '\0';
      pcVar4 = &DAT_00019dbd;
      pcVar5 = &DAT_00019d55;
      goto LAB_00017d6e;
    }
    DAT_0001acae = 0;
  }
  pcVar5 = &DAT_00019d2d;
  pcVar4 = &DAT_00019d55;
LAB_00017d6e:
  while (DAT_0001acc7 != *pcVar5) {
    pcVar5 = pcVar5 + 4;
    if (pcVar5 == pcVar4) {
      DAT_0001a57a = 0;
      return;
    }
  }
  if (cVar3 != '\0') {
    pcVar5[1] = cVar3;
  }
  if ((pcVar5[1] == '\x18') || (pcVar5[1] == '\x1c')) {
    DAT_000192d0 = '\x01';
    FUN_00018f8e();
  }
  else if (pcVar5[1] == '7') {
    FUN_00018f8e();
  }
  else if (pcVar5[1] == 'C') {
    FUN_00018f8e();
  }
  FUN_000159d2();
  if (DAT_000192d0 != '\0') {
    return;
  }
  xbios_supexec();
  return;
}


// ---------------------------------------------------------------
// script_step @ 00017e3c

void script_step(void)

{
  char *pcVar1;
  bool bVar2;
  
  if (DAT_0001ad0b != '\0') {
    return;
  }
  if (0x3e < DAT_0001acec) {
    return;
  }
  DAT_0001ac06 = 0;
  if ((DAT_0001aab4 & 0x40) != 0) {
    DAT_0001aab3 = '8';
    DAT_0001aab4 = DAT_0001aab4 & 0xf;
    DAT_0001aab6 = 0x34;
  }
  if ((DAT_0001aae1 & 0x20) != 0) {
    DAT_0001acf6 = DAT_0001acf6 | 4;
  }
  if (DAT_0001ab60 <= DAT_0001acb2) {
    DAT_0001ac06 = 0;
    return;
  }
  DAT_0001acb2 = DAT_0001ab60 + 0x1e;
  pcVar1 = PTR_DAT_0001a822 + 1;
  DAT_0001ad05 = *PTR_DAT_0001a822;
  if (pcVar1 == &UNK_00019d0f) {
    pcVar1 = &DAT_00019d03;
  }
  DAT_0001ad06 = *pcVar1;
  if (DAT_0001ad05 == '8') {
    DAT_0001acf6 = DAT_0001acf6 & 0xfb;
    DAT_0001aae1 = DAT_0001aae1 & 0x1f;
    DAT_0001aae3 = 0x37;
    if (DAT_0001aab3 == '8') {
      DAT_0001aab4 = DAT_0001aab4 & 0x1f;
      DAT_0001ad07 = '\x01';
    }
  }
  PTR_DAT_0001a822 = pcVar1;
  if (((DAT_0001ad05 == '\f') && (DAT_0001ad06 == '\n')) &&
     (DAT_0001ad07 = '\0', DAT_0001aab3 == '8')) {
    DAT_0001ad06 = ',';
    PTR_DAT_0001a822 = &UNK_00019d07;
  }
  DAT_0001aae0 = DAT_0001ad06;
  if (DAT_0001ad07 == '\0') {
    if ((DAT_0001aae1 & 0x40) != 0) {
      DAT_0001ac06 = 0;
      return;
    }
    if (DAT_0001acd2 == DAT_0001ad05) {
      FUN_0001060a();
      FUN_00016514();
      FUN_000177bc();
      *(byte *)(selected_object + 4) = *(byte *)(selected_object + 4) & 0x7f;
      FUN_00017856();
      draw_hint_icons();
      FUN_00010526();
      return;
    }
    if (DAT_0001acd2 != DAT_0001ad06) {
      DAT_0001ac06 = 0;
      return;
    }
    FUN_0001060a();
    FUN_00016514();
    FUN_000177bc();
  }
  else {
    DAT_0001aab3 = DAT_0001ad06;
    DAT_0001aad6 = DAT_0001ad06;
    DAT_0001aadb = DAT_0001ad06;
    if (DAT_0001acd2 == DAT_0001ad05) {
      FUN_0001060a();
      FUN_00016514();
      FUN_000177bc();
      *(byte *)(selected_object + 4) = *(byte *)(selected_object + 4) & 0x7f;
      FUN_000177bc();
      *(byte *)(selected_object + 4) = *(byte *)(selected_object + 4) & 0x7f;
      FUN_000177bc();
      *(byte *)(selected_object + 4) = *(byte *)(selected_object + 4) & 0x7f;
      FUN_000177bc();
      *(byte *)(selected_object + 4) = *(byte *)(selected_object + 4) & 0x7f;
      FUN_00017856();
      draw_hint_icons();
      FUN_00010526();
      return;
    }
    if (DAT_0001acd2 != DAT_0001ad06) {
      DAT_0001ac06 = 0;
      return;
    }
    FUN_0001060a();
    FUN_00016514();
    FUN_000177bc();
    FUN_00017856();
    bVar2 = false;
    FUN_000177bc();
    if (!bVar2) goto LAB_00017fec;
    FUN_00017856();
    FUN_000177bc();
    FUN_00017856();
    FUN_000177bc();
  }
  FUN_00017856();
LAB_00017fec:
  update_icon_list();
  copy_screen();
  draw_hint_icons();
  FUN_00010526();
  if (DAT_0001acf7 != '\0') {
    DAT_0001ac06 = 0xc1fd;
    return;
  }
  if ((DAT_0001aae1 & 0x20) == 0) {
    if (DAT_0001acd2 != ',') {
      return;
    }
    DAT_0001ac06 = 0xc060;
    return;
  }
  DAT_0001ac06 = 0xc1e5;
  return;
}


// ---------------------------------------------------------------
// FUN_00018128 @ 00018128

void FUN_00018128(void)

{
  if ((PTR_DAT_0001a772[3] & 0x38) == 0x30) {
    PTR_DAT_0001a772[3] = PTR_DAT_0001a772[3] & 0xe7;
    PTR_DAT_0001a75e = &DAT_0001a9d4 + (uint)(byte)(DAT_0001ace6 - 10) * 6;
    FUN_000184d6();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0001816e @ 0001816e

void FUN_0001816e(void)

{
  FUN_00018192();
  return;
}


// ---------------------------------------------------------------
// FUN_0001817a @ 0001817a

void FUN_0001817a(void)

{
  char *pcVar1;
  bool bVar2;
  
  DAT_0001ad0b = 0;
  *(undefined1 *)(object_list_begin + 0x2c) = 0x53;
  DAT_0001abf8 = 0;
  if (DAT_0001acc7 == '\b') {
    FUN_0001066e();
  }
  bVar2 = false;
  FUN_000177bc();
  if (bVar2) {
    *(byte *)(selected_object + 4) = *(byte *)(selected_object + 4) & 0x7f;
    blit_sprite();
  }
  pcVar1 = &DAT_00019dbd;
  do {
    if (DAT_0001acc7 == *pcVar1) {
      FUN_000159d2();
      return;
    }
    pcVar1 = pcVar1 + 4;
  } while (pcVar1 != &DAT_00019e19);
  return;
}


// ---------------------------------------------------------------
// FUN_00018192 @ 00018192

void FUN_00018192(void)

{
  char *pcVar1;
  bool bVar2;
  
  if (DAT_0001acc7 == '\b') {
    FUN_0001066e();
  }
  bVar2 = false;
  FUN_000177bc();
  if (bVar2) {
    *(byte *)(selected_object + 4) = *(byte *)(selected_object + 4) & 0x7f;
    blit_sprite();
  }
  pcVar1 = &DAT_00019dbd;
  do {
    if (DAT_0001acc7 == *pcVar1) {
      FUN_000159d2();
      return;
    }
    pcVar1 = pcVar1 + 4;
  } while (pcVar1 != &DAT_00019e19);
  return;
}


// ---------------------------------------------------------------
// FUN_000181f0 @ 000181f0

void FUN_000181f0(void)

{
  short sVar2;
  undefined *puVar1;
  ushort uVar3;
  uint uVar4;
  undefined **ppuVar5;
  short *psVar6;
  short *extraout_A1;
  undefined **ppuVar7;
  uint6 uVar8;
  
  sVar2 = 0xf;
  ppuVar7 = &PTR_DAT_0003b1ac;
  do {
    ppuVar5 = ppuVar7 + 1;
    *ppuVar7 = (undefined *)0x14000c8;
    sVar2 = sVar2 + -1;
    ppuVar7 = ppuVar5;
  } while (sVar2 != -1);
  *ppuVar5 = (undefined *)0x0;
  DAT_0001a49e = 0;
  DAT_0001a4a0 = 0;
  DAT_0001a4a2 = 0;
  while( true ) {
    uVar8 = CONCAT24(DAT_0001a4a2,0xf);
    ppuVar7 = &PTR_DAT_0003b1ac;
    psVar6 = &DAT_000198c0;
    uVar4 = (uint)DAT_0001a49e;
    DAT_0001a4a0 = DAT_0001a4a0 + 1;
    if ((DAT_0001a4a0 & 7) == 0) {
      uVar8 = FUN_00016230();
      DAT_0001a4a2 = (undefined2)(uVar8 >> 0x20);
      psVar6 = extraout_A1;
    }
    do {
      if ((uVar8 & 0x100000000) != 0) {
        uVar3 = *psVar6 + *(ushort *)ppuVar7;
        if (599 < uVar3) {
          uVar4 = uVar4 | 1 << ((uint)uVar8 & 0x1f);
          uVar3 = *(ushort *)ppuVar7;
        }
        *(ushort *)ppuVar7 = uVar3;
        uVar3 = psVar6[1] + *(ushort *)((int)ppuVar7 + 2);
        if (399 < uVar3) {
          uVar4 = uVar4 | 1 << ((uint)uVar8 & 0x1f);
          uVar3 = *(ushort *)((int)ppuVar7 + 2);
        }
        *(ushort *)((int)ppuVar7 + 2) = uVar3;
      }
      psVar6 = psVar6 + 2;
      ppuVar7 = ppuVar7 + 1;
      uVar3 = (short)uVar8 - 1;
      uVar8 = CONCAT24((ushort)(uVar8 >> 0x21),(uint)uVar3);
    } while (uVar3 != 0xffff);
    if ((short)uVar4 != 0) break;
    sVar2 = 0xf;
    DAT_0001a49e = 0;
    ppuVar7 = &PTR_DAT_0003b1ac;
    do {
      DAT_0001a51a = (ushort)*ppuVar7 >> 1;
      DAT_0001a516 = (ushort)((uint)*ppuVar7 >> 0x11);
      puVar1 = ppuVar7[1];
      if (puVar1 == (undefined *)0x0) {
        puVar1 = PTR_DAT_0003b1ac;
      }
      DAT_0001a51c = (ushort)puVar1 >> 1;
      DAT_0001a518 = (ushort)((uint)puVar1 >> 0x11);
      FUN_00013d0e();
      sVar2 = sVar2 + -1;
      ppuVar7 = ppuVar7 + 1;
    } while (sVar2 != -1);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000182f0 @ 000182f0

void FUN_000182f0(void)

{
  short extraout_D1w;
  undefined4 *puVar1;
  int extraout_A1;
  
  puVar1 = (undefined4 *)&DAT_0000d8f0;
  do {
    *puVar1 = 0;
    FUN_00018316();
    puVar1 = (undefined4 *)(extraout_A1 + 10);
  } while (extraout_D1w != 0);
  return;
}


// ---------------------------------------------------------------
// FUN_00018316 @ 00018316

void FUN_00018316(void)

{
  undefined2 uVar1;
  ushort uVar2;
  int extraout_A1;
  int extraout_A1_00;
  int extraout_A1_01;
  
  uVar1 = FUN_00016230();
  *(undefined2 *)(extraout_A1 + 4) = uVar1;
  uVar1 = FUN_00016230();
  *(undefined2 *)(extraout_A1_00 + 6) = uVar1;
  uVar2 = FUN_00016230();
  *(ushort *)(extraout_A1_01 + 8) = uVar2 & 0xfff;
  return;
}


// ---------------------------------------------------------------
// FUN_00018334 @ 00018334

void FUN_00018334(void)

{
  short sVar1;
  
  sVar1 = 100;
  do {
    FUN_0001834a();
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001834a @ 0001834a

void FUN_0001834a(void)

{
  uint *puVar1;
  uint uVar2;
  ushort uVar3;
  short sVar4;
  ushort unaff_D5w;
  short sVar5;
  uint unaff_D7;
  ushort *extraout_A0;
  short *psVar6;
  short *extraout_A1;
  short *extraout_A1_00;
  
  psVar6 = (short *)&DAT_0000d8f0;
  sVar5 = 0xff;
  do {
    puVar1 = (uint *)CONCAT22((short)((uint)screen_ptr_a >> 0x10),*psVar6 + (short)screen_ptr_a);
    uVar2 = 0x7fff7fff << 0x20 - ((ushort)psVar6[1] & 0x3f) |
            0x7fff7fffU >> ((ushort)psVar6[1] & 0x3f);
    *puVar1 = uVar2 & *puVar1;
    puVar1[1] = uVar2 & puVar1[1];
    uVar3 = psVar6[4];
    if (uVar3 < 0x148) {
      if (0x1d < unaff_D5w) {
        FUN_00018316();
        extraout_A1[4] = extraout_A1[4] | 0x1800;
        psVar6 = extraout_A1;
      }
    }
    else {
      psVar6[4] = uVar3 - 0x148;
      sVar4 = (short)(0xcffff / (ushort)(uVar3 - 0x138));
      uVar3 = (short)((uint)((int)sVar4 * (int)psVar6[2]) >> 0x10) + 0xa0;
      if (((((short)uVar3 < 0) || (0x13f < uVar3)) ||
          (uVar3 = (short)((uint)((int)psVar6[3] * (int)sVar4) >> 0x10) + 100, (short)uVar3 < 0)) ||
         (199 < uVar3)) {
        psVar6[4] = 0;
      }
      else {
        FUN_00010fee();
        *extraout_A1_00 = (short)extraout_A0 - (short)screen_ptr_a;
        extraout_A1_00[1] = (short)unaff_D7;
        uVar3 = -0x8000 << 0x10 - (unaff_D7 & 0x3f) | 0x8000U >> (unaff_D7 & 0x3f);
        if ((ushort)extraout_A1_00[4] < 0xc00) {
          if ((ushort)extraout_A1_00[4] < 0x600) {
            *extraout_A0 = uVar3 | *extraout_A0;
            goto LAB_0001840a;
          }
        }
        else {
LAB_0001840a:
          extraout_A0[1] = uVar3 | extraout_A0[1];
          extraout_A0[3] = uVar3 | extraout_A0[3];
        }
        extraout_A0[2] = uVar3 | extraout_A0[2];
        psVar6 = extraout_A1_00;
      }
    }
    psVar6 = psVar6 + 5;
    sVar5 = sVar5 + -1;
    if (sVar5 == -1) {
      FUN_00013594();
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------
// FUN_0001842c @ 0001842c

void FUN_0001842c(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  
  DAT_0001ab4f = 0;
  FUN_00018f8e();
  DAT_0001ad0d = 1;
  sVar1 = 3999;
  puVar3 = screen_ptr_b;
  do {
    puVar2 = puVar3 + 1;
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 2;
    *puVar2 = 0xffff0000;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  FUN_000181f0();
  sVar1 = 3999;
  puVar3 = screen_ptr_b;
  do {
    puVar2 = puVar3 + 1;
    *puVar3 = 0;
    puVar3 = puVar3 + 2;
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  copy_screen();
  FUN_000182f0();
  FUN_00018334();
  FUN_00018f8e();
  FUN_000159e2();
  DAT_0001acc6 = 0x87;
  uVar4 = 1;
  while (load_fond(), (bool)uVar4) {
    the_command = 0x918e;
    uVar4 = 1;
    run_command_keep_sp();
  }
  set_palette();
  FUN_000181f0();
  copy_screen();
  reset_clear();
  return;
}


// ---------------------------------------------------------------
// FUN_000184cc @ 000184cc

void FUN_000184cc(void)

{
  undefined1 *extraout_A0;
  
  FUN_00018538();
  *extraout_A0 = 0x80;
  extraout_A0[1] = DAT_0001acd2;
  FUN_000164d4(0x55);
  FUN_000159e2();
  FUN_0001857c();
  FUN_000164f6();
  return;
}


// ---------------------------------------------------------------
// FUN_000184d6 @ 000184d6

void FUN_000184d6(void)

{
  undefined1 *extraout_A0;
  
  FUN_00018538();
  *extraout_A0 = 0x40;
  extraout_A0[1] = DAT_0001acd2;
  FUN_000164d4(0x2b);
  FUN_000159e2();
  FUN_0001857c();
  FUN_000164f6();
  return;
}


// ---------------------------------------------------------------
// FUN_0001851a @ 0001851a

void FUN_0001851a(void)

{
  int unaff_A6;
  
  PTR_DAT_0001a75e = &DAT_0001a8f0 + (*(byte *)(unaff_A6 + 1) - 1 & 0xffff) * 6;
  FUN_000184cc();
  return;
}


// ---------------------------------------------------------------
// FUN_00018538 @ 00018538

void FUN_00018538(void)

{
  char unaff_D3b;
  char unaff_D4b;
  int unaff_A5;
  
  FUN_00012950();
  *(char *)(unaff_A5 + 2) = unaff_D3b;
  if (((unaff_D3b == '%') || (unaff_D3b == ':')) || (unaff_D3b == '(')) {
    if (unaff_D4b == -0x80) {
      DAT_0001ad2c = DAT_0001ad2c + '\x01';
      return;
    }
    DAT_0001ad2c = DAT_0001ad2c + -1;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0001857a @ 0001857a

void FUN_0001857a(void)

{
  short sVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  pcVar3 = &DAT_0001a8f0;
  sVar1 = 0x3e;
  uVar2 = 0xad;
  do {
    if ((*pcVar3 == '@') && (DAT_0001acd2 == pcVar3[1])) goto LAB_000185a8;
    pcVar3 = pcVar3 + 6;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  uVar2 = 0xac;
LAB_000185a8:
  FUN_00011020(0x4a,0xe,uVar2);
  FUN_00011016();
  pcVar3 = "";
  sVar1 = 0xd;
  DAT_0001acf7 = '\0';
  do {
    if (*pcVar3 == -0x80) {
      DAT_0001acf7 = DAT_0001acf7 + '\x01';
    }
    pcVar3 = pcVar3 + 6;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_0001857c @ 0001857c

void FUN_0001857c(void)

{
  short sVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  pcVar3 = &DAT_0001a8f0;
  sVar1 = 0x3e;
  uVar2 = 0xad;
  do {
    if ((*pcVar3 == '@') && (DAT_0001acd2 == pcVar3[1])) goto LAB_000185a8;
    pcVar3 = pcVar3 + 6;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  uVar2 = 0xac;
LAB_000185a8:
  FUN_00011020(0x4a,0xe,uVar2);
  FUN_00011016();
  pcVar3 = "";
  sVar1 = 0xd;
  DAT_0001acf7 = '\0';
  do {
    if (*pcVar3 == -0x80) {
      DAT_0001acf7 = DAT_0001acf7 + '\x01';
    }
    pcVar3 = pcVar3 + 6;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000185e6 @ 000185e6

void FUN_000185e6(void)

{
  ushort extraout_D0u;
  undefined4 uVar1;
  byte bVar2;
  undefined4 unaff_D2;
  uint uVar3;
  
  FUN_00018f8e();
  uVar1 = CONCAT31((int3)(((uint)extraout_D0u << 0x10) >> 8),*selected_object);
  uVar3 = CONCAT31((int3)((uint)unaff_D2 >> 8),selected_object[2]) & 0xffff00ff;
  FUN_000159e2();
  FUN_00010fb4();
  DAT_0001a484 = DAT_0001a482;
  bVar2 = (byte)uVar1;
  if (bVar2 < 0x23) {
    DAT_00019971 = bVar2 + 8;
    DAT_00019973 = 0xb4;
  }
  else {
    DAT_00019971 = bVar2 - 0x17;
    DAT_00019973 = 0x94;
  }
  DAT_00019972 = (char)uVar3 + -0x28;
  FUN_00010b6c(uVar1,uVar3);
  FUN_00018e12();
  FUN_000159e2(uVar1,uVar3);
  FUN_0001228a();
  FUN_0001232e();
  FUN_00018f8e();
  FUN_000159e2();
  return;
}


// ---------------------------------------------------------------
// FUN_000186b6 @ 000186b6

void FUN_000186b6(void)

{
  char *pcVar1;
  short sVar2;
  int unaff_A6;
  
  sVar2 = *(byte *)(unaff_A6 + 2) - 1;
  pcVar1 = &DAT_0001a8f0 + (*(byte *)(unaff_A6 + 1) - 1 & 0xffff) * 6;
  do {
    PTR_DAT_0001a75e = pcVar1;
    if (*(char *)(unaff_A6 + 3) == *PTR_DAT_0001a75e) {
      return;
    }
    sVar2 = sVar2 + -1;
    pcVar1 = PTR_DAT_0001a75e + 6;
  } while (sVar2 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_000186ee @ 000186ee

void FUN_000186ee(void)

{
  FUN_000162e2();
  the_command = 0x916b;
  run_command_keep_sp();
  FUN_000162da();
  return;
}


// ---------------------------------------------------------------
// FUN_0001870a @ 0001870a

void FUN_0001870a(void)

{
  byte bVar1;
  
  do {
    bVar1 = FUN_00016210();
  } while (0x14e < (ushort)((bVar1 & 7) + 0x149));
  FUN_00010fb4();
  FUN_00010b6c();
  FUN_0001228a();
  FUN_0001232e();
  return;
}


// ---------------------------------------------------------------
// FUN_00018740 @ 00018740

void FUN_00018740(void)

{
  if (0xe0f < DAT_0001ab60) {
    if (DAT_0001acec < 0x3f) {
      DAT_0001acfd = 3;
      DAT_0001acec = 0x3f;
      if (DAT_0001acd2 < 0x2c) {
        DAT_0001acec = 0xff;
      }
      DAT_0001aab3 = 0;
      DAT_0001aab8 = 0;
      DAT_0001aabd = 0;
      DAT_0001aac2 = 0;
      DAT_0001aac7 = 0;
      DAT_0001aacc = 0;
      DAT_0001aad1 = 0x38;
      DAT_0001aad6 = 0x38;
      DAT_0001aadb = 0x38;
      DAT_0001aae0 = 0x38;
      if (DAT_0001acd2 < 0x16) {
        DAT_0001acfd = 3;
        DAT_0001aae0 = 0x38;
        DAT_0001aadb = 0x38;
        DAT_0001aad6 = 0x38;
        DAT_0001aad1 = 0x38;
        DAT_0001aacc = 0;
        DAT_0001aac7 = 0;
        DAT_0001aac2 = 0;
        DAT_0001aabd = 0;
        DAT_0001aab8 = 0;
        DAT_0001aab3 = 0;
        DAT_0001ac06 = 0xc012;
        return;
      }
    }
    else if (0x189b < DAT_0001ab60) {
      if (DAT_0001ab60 < 0x1c20) {
        DAT_0001acfd = 2;
        DAT_0001ad14 = 1;
        if ((DAT_0001acd2 != 0x3d) && (0x3a < DAT_0001acd2)) {
          if (DAT_0001acd2 < 0x4b) {
            DAT_0001ac06 = 0xc012;
            DAT_0001acfd = 2;
            DAT_0001ad14 = 1;
            return;
          }
          return;
        }
      }
      else {
        DAT_0001ac06 = 0xc318;
      }
    }
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0001881e @ 0001881e

void FUN_0001881e(void)

{
  short sVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  FUN_00018f8e();
  FUN_00013f56();
  puVar3 = (undefined4 *)(screen_ptr_a + 0x5500);
  puVar5 = (undefined4 *)(screen_ptr_b + 0x5500);
  sVar2 = 0x3b;
  do {
    sVar1 = 0x27;
    do {
      puVar6 = puVar5;
      puVar4 = puVar3;
      *puVar4 = *puVar6;
      sVar1 = sVar1 + -1;
      puVar3 = puVar4 + 1;
      puVar5 = puVar6 + 1;
    } while (sVar1 != -1);
    FUN_00013594();
    puVar5 = puVar6 + -0x4f;
    puVar3 = puVar4 + -0x4f;
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  FUN_000164a4();
  xbios_supexec();
  return;
}


// ---------------------------------------------------------------
// FUN_00018888 @ 00018888

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018888(void)

{
  DAT_0001a4c6 = &DAT_0000d8f0;
  FUN_00015ac8(0x8000);
  _DAT_0000d8f0 = _DAT_0000d8f0 << 8 | _DAT_0000d8f0 >> 8;
  FUN_00011030();
  return;
}


// ---------------------------------------------------------------
// FUN_00018890 @ 00018890

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018890(void)

{
  DAT_0001a4c6 = &DAT_0000d8f0;
  FUN_00015ac8(0);
  _DAT_0000d8f0 = _DAT_0000d8f0 << 8 | _DAT_0000d8f0 >> 8;
  FUN_00011030();
  return;
}


// ---------------------------------------------------------------
// FUN_000188ce @ 000188ce

void FUN_000188ce(void)

{
  undefined1 uVar1;
  int unaff_A6;
  
  uVar1 = DAT_0001acc9;
  DAT_0001ad1d = 0;
  if (((DAT_0001aaf9 == DAT_0001acd2) && (0x3a < *(byte *)(unaff_A6 + 1))) &&
     (*(byte *)(unaff_A6 + 1) < 0x3f)) {
    DAT_0001ad1d = 0xff;
    FUN_000177bc();
    FUN_00017856();
    if (DAT_0001ab08 != '\0') {
      FUN_000177bc();
      FUN_00017856();
    }
  }
  DAT_0001acc9 = uVar1;
  return;
}


// ---------------------------------------------------------------
// FUN_00018944 @ 00018944

void FUN_00018944(void)

{
  undefined1 uVar1;
  
  uVar1 = DAT_0001acc9;
  if (DAT_0001ad1d != '\0') {
    FUN_000177bc();
    FUN_00017856();
    DAT_0001aaf9 = DAT_0001acd2;
    if (DAT_0001ab08 != '\0') {
      DAT_0001ab08 = DAT_0001acd2;
      FUN_000177bc();
      FUN_00017856();
    }
    DAT_0001acc9 = uVar1;
    update_icon_list();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_000189aa @ 000189aa

void FUN_000189aa(void)

{
  FUN_00012368();
  FUN_0001232e();
  DAT_0001970a = '(';
  if (DAT_0001ad20 != 0) {
    DAT_0001970a = (DAT_0001ad20 >> 4) + 0x29;
  }
  DAT_0001970e = DAT_0001970a + '\x0e';
  FUN_000134da();
  do {
    FUN_00018f8e();
    FUN_00016dec();
    FUN_00018f98();
    FUN_00016dec();
    wait_frame();
  } while ((input_buttons & 4) == 0);
  FUN_00012368();
  return;
}


// ---------------------------------------------------------------
// FUN_00018a10 @ 00018a10

void FUN_00018a10(void)

{
  FUN_00016210();
  FUN_00018f7a();
  return;
}


// ---------------------------------------------------------------
// FUN_00018a30 @ 00018a30

void FUN_00018a30(void)

{
  int iVar1;
  short sVar2;
  short sVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  FUN_00018a10();
  iVar1 = screen_ptr_a;
  sVar3 = 4;
  puVar5 = (undefined4 *)(screen_ptr_a + -0x500);
  sVar2 = 0x13f;
  puVar4 = puVar5;
  do {
    *puVar4 = 0;
    sVar2 = sVar2 + -1;
    puVar4 = puVar4 + 1;
  } while (sVar2 != -1);
  do {
    __m68k_trap(0xe);
    FUN_00013594();
    __m68k_trap(0xe);
    FUN_00013594();
    sVar3 = sVar3 + -1;
  } while (sVar3 != -1);
  sVar2 = 0x7f;
  puVar4 = (undefined4 *)(iVar1 + 0x7b00);
  do {
    *puVar5 = *puVar4;
    sVar2 = sVar2 + -1;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
  } while (sVar2 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00018a98 @ 00018a98

void FUN_00018a98(void)

{
  int iVar1;
  short sVar2;
  short extraout_D1w;
  short unaff_D2w;
  short unaff_D3w;
  short sVar3;
  undefined2 unaff_D7w;
  short sVar4;
  int extraout_A0;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined2 *puVar14;
  short *psVar15;
  
  DAT_0001ad0d = 5;
  sVar2 = 7999;
  puVar5 = screen_ptr_b;
  do {
    *puVar5 = 0;
    sVar2 = sVar2 + -1;
    puVar5 = puVar5 + 1;
  } while (sVar2 != -1);
  copy_screen();
  FUN_000128a4();
  DAT_0001a544 = unaff_D3w + -1;
  DAT_0001a542 = unaff_D2w * 4 + -1;
  DAT_0001a4a8 = 199;
  DAT_0001a84e = 10000;
  puVar14 = &DAT_00019718;
  sVar2 = extraout_D1w;
  while( true ) {
    DAT_0001a4aa = *puVar14;
    DAT_0001a4ac = (ushort)puVar14[1] >> 1;
    DAT_0001a4a6 = sVar2 + DAT_0001a4ac;
    DAT_0001a4a8 = (DAT_0001a4a8 - sVar2) + 1;
    iVar1 = FUN_00010fee();
    DAT_0001a4ba = (undefined4 *)(extraout_A0 - iVar1);
    DAT_0001a486 = unaff_D7w;
    FUN_00013bc2();
    if (DAT_0001a571 == '\0') {
      DAT_0001a571 = '\x01';
      puVar5 = DAT_0001a4ba + -0x2000;
      sVar2 = 0x36;
      puVar6 = DAT_0001a4ba + -0x2028;
      do {
        sVar3 = 0x13;
        puVar7 = puVar5;
        puVar9 = puVar6;
        do {
          puVar10 = puVar7 + 1;
          puVar12 = puVar9 + 1;
          *puVar9 = *puVar7;
          puVar7 = puVar7 + 2;
          puVar9 = puVar9 + 2;
          *puVar12 = *puVar10;
          sVar3 = sVar3 + -1;
        } while (sVar3 != -1);
        puVar5 = puVar5 + 0x28;
        puVar6 = puVar6 + -0x28;
        sVar2 = sVar2 + -1;
      } while (sVar2 != -1);
      sVar2 = 7;
      puVar5 = &DAT_0001a1d2;
      puVar7 = DAT_0001a466;
      do {
        *puVar7 = *puVar5;
        sVar2 = sVar2 + -1;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      } while (sVar2 != -1);
      xbios_setpalette();
      puVar9 = (undefined4 *)(screen_ptr_a + 0x7c60);
      sVar2 = 0x13;
      sVar4 = 0x6b;
      puVar5 = puVar6;
      puVar7 = puVar9;
      sVar3 = sVar2;
      do {
        do {
          puVar10 = puVar7;
          puVar7 = puVar9 + 1;
          *puVar9 = *puVar5;
          puVar9 = puVar9 + 2;
          *puVar7 = puVar5[1];
          sVar2 = sVar2 + -1;
          puVar5 = puVar5 + 2;
          puVar7 = puVar10;
        } while (sVar2 != -1);
        puVar9 = puVar10 + -0x28;
        sVar2 = sVar3 + 0x14;
        FUN_00013594();
        FUN_00013594();
        sVar4 = sVar4 + -1;
        puVar5 = puVar6;
        puVar7 = puVar9;
        sVar3 = sVar2;
      } while (sVar4 != -1);
      sVar2 = 0x897;
      puVar5 = puVar10 + -0x2028;
      do {
        *puVar5 = 0;
        sVar2 = sVar2 + -1;
        puVar5 = puVar5 + 1;
      } while (sVar2 != -1);
      sVar2 = -0x15a0;
      do {
        sVar2 = sVar2 + -1;
      } while (sVar2 != -1);
      FUN_00018f8e();
      unaff_D7w = 0xffff;
    }
    puVar7 = DAT_0001a4ba + -0x2000;
    puVar6 = DAT_0001a4ba;
    puVar5 = DAT_0001a4ba;
    do {
      puVar5 = puVar5 + -0x28;
      sVar2 = 0x13;
      puVar9 = puVar6;
      puVar10 = puVar7;
      puVar12 = puVar5;
      do {
        puVar8 = puVar9 + 1;
        *puVar9 = *puVar10;
        puVar13 = puVar12 + 1;
        *puVar12 = *puVar10;
        puVar11 = puVar10 + 1;
        *puVar10 = 0;
        puVar9 = puVar9 + 2;
        *puVar8 = *puVar11;
        puVar12 = puVar12 + 2;
        *puVar13 = *puVar11;
        puVar10 = puVar10 + 2;
        *puVar11 = 0;
        sVar2 = sVar2 + -1;
      } while (sVar2 != -1);
      puVar6 = puVar6 + 0x28;
      puVar7 = puVar7 + 0x28;
      DAT_0001a4a8 = DAT_0001a4a8 + -1;
    } while (DAT_0001a4a8 != -1);
    DAT_0001a4a8 = DAT_0001a4a6;
    FUN_00013594();
    sVar2 = DAT_0001a84e;
    do {
      sVar2 = sVar2 + -1;
    } while (sVar2 != 0);
    DAT_0001a84e = DAT_0001a84e + 500;
    if (puVar14 == (undefined2 *)&UNK_000198bc) break;
    psVar15 = puVar14 + 3;
    puVar14 = puVar14 + 4;
    sVar2 = *psVar15;
  }
  FUN_000182f0();
  do {
    FUN_0001834a();
  } while( true );
}


// ---------------------------------------------------------------
// FUN_00018c8e @ 00018c8e

void FUN_00018c8e(void)

{
  short sVar1;
  char *pcVar2;
  
  pcVar2 = &DAT_0001a8f0;
  sVar1 = 0x3e;
  do {
    if (*pcVar2 == -0x80) {
      *pcVar2 = '\0';
    }
    pcVar2 = pcVar2 + 6;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  DAT_0001acf7 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_00018cb2 @ 00018cb2

void FUN_00018cb2(void)

{
  short sVar1;
  char *pcVar2;
  
  FUN_00018ce0();
  DAT_0001acf7 = 0;
  FUN_00018ce0();
  pcVar2 = "";
  sVar1 = 1;
  do {
    if (*pcVar2 == -0x80) {
      *pcVar2 = '@';
      pcVar2[1] = DAT_0001acd2;
    }
    pcVar2 = pcVar2 + 6;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00018ce0 @ 00018ce0

void FUN_00018ce0(void)

{
  short in_D0w;
  char *in_A0;
  
  do {
    if (*in_A0 == -0x80) {
      *in_A0 = '@';
      in_A0[1] = DAT_0001acd2;
    }
    in_A0 = in_A0 + 6;
    in_D0w = in_D0w + -1;
  } while (in_D0w != -1);
  return;
}


// ---------------------------------------------------------------
// FUN_00018cfc @ 00018cfc

void FUN_00018cfc(void)

{
  int iVar1;
  
  draw_hint_icons();
  iVar1 = object_list_begin;
  *(char *)(object_list_begin + 0x32) = *(char *)(object_list_begin + 0x32) + -5;
  *(char *)(iVar1 + 0x33) = *(char *)(iVar1 + 0x33) + -5;
  FUN_00016460();
  update_icon_list();
  copy_screen();
  return;
}


// ---------------------------------------------------------------
// FUN_00018d26 @ 00018d26

void FUN_00018d26(void)

{
  byte *pbVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*selected_icon_ptr != 0) {
    DAT_0001a7d2 = selected_object;
    DAT_0001ab4a = DAT_0001acc9 + -1;
    pbVar1 = (byte *)*selected_icon_ptr;
    uVar4 = (uint)(*(int *)(pbVar1 + 2) - screen_ptr_b) / 0xa0;
    uVar3 = uVar4 & 0xffff;
    uVar2 = CONCAT22((short)uVar4,
                     *(ushort *)(pbVar1 + 6) |
                     ((ushort)((uint)(*(int *)(pbVar1 + 2) - screen_ptr_b) % 0xa0) & 0x7ff8) << 1);
    uVar4 = (uint)(ushort)((ushort)*pbVar1 * 4 - 1);
    uVar5 = (uint)(ushort)(pbVar1[1] - 1);
    FUN_00013216(uVar2,uVar3,uVar4,uVar5,selected_icon_ptr);
    FUN_00012ffa(uVar2,uVar3,uVar4,uVar5);
    FUN_00013216(uVar2,uVar3,uVar4,uVar5);
    FUN_00012ffa();
    FUN_0001652e();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018d28 @ 00018d28

void FUN_00018d28(void)

{
  byte *pbVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*selected_icon_ptr != 0) {
    DAT_0001a7d2 = selected_object;
    DAT_0001ab4a = DAT_0001acc9 + -1;
    pbVar1 = (byte *)*selected_icon_ptr;
    uVar4 = (uint)(*(int *)(pbVar1 + 2) - screen_ptr_b) / 0xa0;
    uVar3 = uVar4 & 0xffff;
    uVar2 = CONCAT22((short)uVar4,
                     *(ushort *)(pbVar1 + 6) |
                     ((ushort)((uint)(*(int *)(pbVar1 + 2) - screen_ptr_b) % 0xa0) & 0x7ff8) << 1);
    uVar4 = (uint)(ushort)((ushort)*pbVar1 * 4 - 1);
    uVar5 = (uint)(ushort)(pbVar1[1] - 1);
    FUN_00013216(uVar2,uVar3,uVar4,uVar5,selected_icon_ptr);
    FUN_00012ffa(uVar2,uVar3,uVar4,uVar5);
    FUN_00013216(uVar2,uVar3,uVar4,uVar5);
    FUN_00012ffa();
    FUN_0001652e();
    return;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018dc0 @ 00018dc0

void FUN_00018dc0(void)

{
  if (((DAT_0001acd2 == '\b') || (DAT_0001acd2 == '2')) && (DAT_0001acd7 < 0x32)) {
    FUN_00016210();
    FUN_00018f7a();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018e06 @ 00018e06

void FUN_00018e06(void)

{
  FUN_00018e12();
  return;
}


// ---------------------------------------------------------------
// FUN_00018e12 @ 00018e12

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00018e12(void)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  char in_D1b;
  byte bVar4;
  char cVar5;
  char cVar6;
  short sVar7;
  byte *pbVar8;
  undefined *puVar10;
  int extraout_A0;
  char *pcVar11;
  short extraout_A1w;
  short unaff_A2w;
  undefined1 *puVar12;
  byte *pbVar9;
  
  if ((DAT_0001a484 != 0) && (cVar1 = (&DAT_00019994)[(byte)(in_D1b - 1)], cVar1 != '\0')) {
    bVar4 = 7;
    cVar5 = '\0';
    cVar6 = ')';
    if ((cVar1 != '\x01') && (cVar5 = '\x05', cVar1 != '\x02')) {
      cVar5 = '\n';
      cVar6 = '#';
      bVar4 = 3;
      if (cVar1 != '\x03') {
        cVar5 = '\x0e';
        cVar6 = '\x1d';
        if (cVar1 != '\x04') {
          cVar5 = '\x05';
          bVar4 = 7;
          if (cVar1 != '\x05') {
            bVar4 = 3;
            cVar5 = '\n';
            cVar6 = ')';
            if (cVar1 != '\x06') {
              bVar4 = 7;
              cVar5 = '\0';
              cVar6 = '=';
              if (cVar1 != '\a') {
                bVar4 = 3;
                cVar5 = '\x0e';
                cVar6 = '\x18';
              }
            }
          }
        }
      }
    }
    sVar7 = 9;
    pbVar9 = &TEMPL_data + DAT_0001a484;
    pcVar2 = &DAT_0000d8f0;
    do {
      do {
        pcVar11 = pcVar2;
        pbVar8 = pbVar9 + 1;
        bVar3 = bVar4 & *pbVar9 & 7;
        if ((bVar3 & 4) != 0) {
          bVar3 = bVar3 & 4;
        }
        pbVar9 = pbVar8;
        pcVar2 = pcVar11;
      } while ((byte)(cVar5 + bVar3) == pcVar11[-2]);
      *pcVar11 = cVar5 + bVar3;
      pcVar11[1] = cVar6;
      sVar7 = sVar7 + -1;
      pcVar2 = pcVar11 + 2;
    } while (sVar7 != -1);
    pcVar11[1] = pcVar11[1] + '\x04';
    pcVar11[-1] = pcVar11[-1] + '\x02';
    puVar12 = &DAT_0000d8f2;
    DAT_000192be = 0x55b0a;
    sVar7 = 8;
    DAT_000192cf = 1;
    puVar10 = &DAT_000192d2;
    _DAT_0001930e = &DAT_000192d2;
    do {
      puVar10[1] = puVar12[1];
      FUN_00010f8e();
      *(short *)(extraout_A0 + 2) = (extraout_A1w - (short)DAT_000192be) + 2;
      *(short *)(extraout_A0 + 4) = unaff_A2w - (short)DAT_000192be;
      puVar12 = puVar12 + 2;
      puVar10 = (undefined *)(extraout_A0 + 6);
      sVar7 = sVar7 + -1;
    } while (sVar7 != -1);
    FUN_00018f7a();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018f0c @ 00018f0c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00018f0c(void)

{
  short unaff_D7w;
  undefined *puVar1;
  int extraout_A0;
  short extraout_A1w;
  short unaff_A2w;
  int unaff_A3;
  undefined8 in_stack_00000000;
  
  DAT_000192cf = 1;
  puVar1 = &DAT_000192d2;
  _DAT_0001930e = &DAT_000192d2;
  do {
    puVar1[1] = *(undefined1 *)(unaff_A3 + 1);
    FUN_00010f8e();
    *(short *)(extraout_A0 + 2) = (extraout_A1w - (short)DAT_000192be) + 2;
    *(short *)(extraout_A0 + 4) = unaff_A2w - (short)DAT_000192be;
    unaff_A3 = unaff_A3 + 2;
    puVar1 = (undefined *)(extraout_A0 + 6);
    unaff_D7w = unaff_D7w + -1;
  } while (unaff_D7w != -1);
  FUN_00018f7a();
  return in_stack_00000000;
}


// ---------------------------------------------------------------
// FUN_00018f6e @ 00018f6e

void FUN_00018f6e(void)

{
  if (DAT_0001ab4f == '\0') {
    __m68k_trap(0xe);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018f7a @ 00018f7a

void FUN_00018f7a(void)

{
  if (DAT_0001ab4f == '\0') {
    __m68k_trap(0xe);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018f84 @ 00018f84

void FUN_00018f84(void)

{
  if (DAT_0001ab4f == '\0') {
    __m68k_trap(0xe);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018f8e @ 00018f8e

void FUN_00018f8e(void)

{
  if (DAT_0001ab4f == '\0') {
    __m68k_trap(0xe);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018f98 @ 00018f98

void FUN_00018f98(void)

{
  if (DAT_0001ab4f == '\0') {
    __m68k_trap(0xe);
  }
  return;
}


// ---------------------------------------------------------------
// FUN_00018fa2 @ 00018fa2

void FUN_00018fa2(void)

{
  if (DAT_0001ab4f == '\0') {
    __m68k_trap(0xe);
  }
  return;
}


// ---------------------------------------------------------------
// xbios_supexec @ 00018fa4

void xbios_supexec(void)

{
  if (DAT_0001ab4f == '\0') {
    __m68k_trap(0xe);
  }
  return;
}


// ---------------------------------------------------------------
// sound_timer_start @ 00018fc4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sound_timer_start(void)

{
  char extraout_D1b;
  uint unaff_D4;
  undefined1 *extraout_A1;
  undefined4 unaff_A2;
  
  if (((unaff_D4 & 0x80) != 0) && (DAT_0001a57c != -1)) {
    FUN_0001066e(unaff_D4 & 0xffffff0f);
  }
  FUN_00010f8e();
  DAT_000192ce = *extraout_A1;
  DAT_fffffa13 = 0x20;
  DAT_fffffa07 = 0x20;
  DAT_fffffa19 = 2;
  DAT_000192ca = unaff_A2;
  if (extraout_D1b != '\0') {
    extraout_A1[1] = extraout_D1b;
  }
  DAT_fffffa1f = extraout_A1[1];
  _DAT_000192c6 = extraout_A1 + 2;
  _sound_sample_ptr = extraout_A1 + 2;
  _sound_timer_vector = &UNK_0001910e;
  return;
}


// ---------------------------------------------------------------
// FUN_0001906a @ 0001906a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001906a(void)

{
  sound_timer_start();
  _sound_timer_vector = &UNK_000190f6;
  _DAT_000192c6 = DAT_000192ca;
  return;
}


// ---------------------------------------------------------------
// sound_timer_stop @ 00019084

void sound_timer_stop(void)

{
  DAT_fffffa19 = 0;
  DAT_fffffa13 = 0;
  DAT_fffffa07 = 0;
  DAT_000192d0 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_0001909e @ 0001909e

void FUN_0001909e(void)

{
  DAT_00000484 = 0;
  FUN_00019282();
  ym_write();
  sound_timer_stop();
  return;
}


// ---------------------------------------------------------------
// FUN_00019282 @ 00019282

void FUN_00019282(void)

{
  short sVar1;
  
  do {
    sVar1 = ym_write();
  } while (sVar1 != 0);
  ym_write();
  return;
}


// ---------------------------------------------------------------
// ym_write @ 0001929a

void ym_write(void)

{
  char in_D0b;
  byte in_D1b;
  
  DAT_ffff8800 = in_D0b;
  if (in_D0b == '\a') {
    in_D1b = DAT_ffff8802 ^ (DAT_ffff8802 ^ in_D1b) & 0x3f;
  }
  DAT_ffff8802 = in_D1b;
  return;
}


// ---------------------------------------------------------------
// FUN_00019312 @ 00019312

void FUN_00019312(void)

{
  return;
}


// ---------------------------------------------------------------
// FUN_00019316 @ 00019316

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019316(void)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  char *pcVar5;
  char *pcVar6;
  
  __m68k_trap(0xe);
  pcVar5 = &DAT_0000d900;
  sVar4 = 0x44;
  do {
    pcVar6 = &DAT_00019484;
    sVar3 = 0x17;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      if (cVar2 != cVar1) {
        _DAT_0001947e = 0xffff;
        return;
      }
      sVar3 = sVar3 + -1;
    } while (sVar3 != -1);
    sVar4 = sVar4 + -1;
  } while (sVar4 != -1);
  _DAT_0001947e = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_0001935a @ 0001935a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001935a(void)

{
  short sVar1;
  undefined2 *extraout_A0;
  undefined2 *extraout_A0_00;
  
  DAT_00ff8800 = 0xe;
  DAT_00019314 = 0xe;
  DAT_00ff8802 = 0xd;
  _DAT_ffff8606 = 0x80;
  FUN_00019474();
  *extraout_A0 = 0;
  FUN_00019462();
  FUN_00019438();
  do {
    sVar1 = FUN_000193e4();
  } while ((ushort)(sVar1 + 1U) < 0x46);
  _DAT_ffff8606 = 0x80;
  do {
    FUN_00019474();
  } while ((char)*extraout_A0_00 < '\0');
  DAT_00ff8800 = 0xe;
  DAT_00ff8802 = DAT_00019314;
  return;
}


// ---------------------------------------------------------------
// FUN_000193e4 @ 000193e4

void FUN_000193e4(void)

{
  undefined2 uVar1;
  int in_A0;
  undefined2 *extraout_A0;
  undefined2 *extraout_A0_00;
  int extraout_A0_01;
  undefined2 *extraout_A0_02;
  undefined4 in_A1;
  
  DAT_00ff860d = (undefined1)in_A1;
  DAT_00ff860b = (undefined1)((uint)in_A1 >> 8);
  DAT_00ff8609 = (undefined1)((uint)in_A1 >> 0x10);
  *(undefined2 *)(in_A0 + 2) = 0x84;
  uVar1 = FUN_00019474();
  *extraout_A0 = uVar1;
  FUN_00019474();
  extraout_A0_00[1] = 0x90;
  extraout_A0_00[1] = 400;
  extraout_A0_00[1] = 0x90;
  *extraout_A0_00 = 1;
  FUN_00019474();
  *(undefined2 *)(extraout_A0_01 + 2) = 0x80;
  FUN_00019474();
  *extraout_A0_02 = 0x80;
  FUN_00019462();
  return;
}


// ---------------------------------------------------------------
// FUN_00019438 @ 00019438

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00019438(void)

{
  undefined2 *extraout_A0;
  int extraout_A0_00;
  undefined2 *extraout_A0_01;
  
  _DAT_ffff8606 = 0x86;
  FUN_00019474();
  *extraout_A0 = 0x4f;
  FUN_00019474();
  *(undefined2 *)(extraout_A0_00 + 2) = 0x80;
  FUN_00019474();
  *extraout_A0_01 = 0x14;
  FUN_00019462();
  return;
}


// ---------------------------------------------------------------
// FUN_00019462 @ 00019462

void FUN_00019462(void)

{
  FUN_00019474();
  do {
  } while ((DAT_00fffa01 & 0x20) != 0);
  return;
}


// ---------------------------------------------------------------
// FUN_00019474 @ 00019474

void FUN_00019474(void)

{
  short sVar1;
  
  sVar1 = 0x22;
  do {
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}


// ---------------------------------------------------------------
// init_hardware @ 0003a556

void init_hardware(void)

{
  FUN_0003a5c2();
  FUN_0003a62e();
  FUN_0003a734();
  return;
}


// ---------------------------------------------------------------
// FUN_0003a57c @ 0003a57c

void FUN_0003a57c(void)

{
  short in_D1w;
  short *in_A0;
  
  while( true ) {
    if (*in_A0 == 0) {
      return;
    }
    if (in_D1w == *in_A0) break;
    in_A0 = in_A0 + 3;
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0003a5c2 @ 0003a5c2

undefined8 FUN_0003a5c2(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  __m68k_trap(0xe);
  __m68k_trap(0xd);
  __m68k_trap(0xd);
  return CONCAT44(in_D0,in_D1);
}


// ---------------------------------------------------------------
// mfp_setup @ 0003a604

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mfp_setup(void)

{
  DAT_fffffa13 = 0x20;
  DAT_fffffa07 = 0x20;
  DAT_fffffa19 = 4;
  DAT_fffffa1f = 0xaa;
  _sound_timer_vector = &UNK_0003a872;
  return;
}


// ---------------------------------------------------------------
// FUN_0003a62e @ 0003a62e
// <decompile failed: 
Low-level Error: Cannot properly adjust input varnodes>
// ---------------------------------------------------------------
// xbios_supexec @ 0003a6f4

undefined8 xbios_supexec(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  __m68k_trap(0xe);
  FUN_0003a85e();
  return CONCAT44(in_D0,in_D1);
}


// ---------------------------------------------------------------
// FUN_0003a712 @ 0003a712

void FUN_0003a712(void)

{
  DAT_fffffa19 = 0;
  DAT_fffffa13 = 0;
  DAT_fffffa07 = 0;
  return;
}


// ---------------------------------------------------------------
// FUN_0003a734 @ 0003a734

undefined8 FUN_0003a734(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_D1;
  uint uVar3;
  short sVar4;
  undefined4 *puVar5;
  bool bVar6;
  ulonglong uVar7;
  
  bVar6 = false;
  uVar7 = FUN_0003a57c();
  uVar2 = (uint)(uVar7 >> 0x20);
  if (bVar6) {
    uVar3 = (uint)uVar7 & 0xf;
    if ((uVar7 & 0xf) == 0) {
      uVar3 = 0xf;
    }
    puVar5 = &DAT_0003afbc;
    sVar4 = 0;
    do {
      uVar1 = uVar3 & 1;
      uVar3 = uVar3 >> 1;
      if (uVar1 != 0) {
        if ((uVar7 & 0x8000) != 0) {
          param_1._1_1_ = param_1._1_1_ & 0xf;
          *(byte *)((int)puVar5 + 0x2f) = param_1._1_1_;
        }
        if ((uVar7 & 0x2000) != 0) {
          param_1._1_1_ = param_1._1_1_ & 0xf;
          *(byte *)((int)puVar5 + 0x2b) = param_1._1_1_;
          *(byte *)((int)puVar5 + 0x2f) = param_1._1_1_;
        }
        if ((uVar7 & 0x100) != 0) {
          *(undefined1 *)((int)puVar5 + 0x2b) = 0;
          uVar2 = CONCAT31((int3)(uVar2 >> 8),DAT_0003aea9);
          *(undefined1 *)((int)puVar5 + 0x2f) = DAT_0003aea9;
        }
        if ((uVar7 & 0x200) != 0) {
          *(undefined1 *)((int)puVar5 + 0x2f) = 0;
        }
        if ((uVar7 & 0x40) != 0) {
          DAT_0003b1a2 = (&DAT_0003aec0)[sVar4] | (&DAT_0003aec0)[sVar4] << 3 | DAT_0003b1a2;
          *(ushort *)((int)puVar5 + 0x26) = *(ushort *)((int)puVar5 + 0x26) | 0x40;
        }
        if ((uVar7 & 0x80) != 0) {
          *(undefined2 *)((int)puVar5 + 0x26) = 0;
          *(ushort *)((int)puVar5 + 0x26) = *(ushort *)((int)puVar5 + 0x26) | 0x80;
          *(ushort *)((int)puVar5 + 0x26) = *(ushort *)((int)puVar5 + 0x26) | 1;
          DAT_0003aea6 = 0xff;
          DAT_0003b1a2 = ~(&DAT_0003aec0)[sVar4] & DAT_0003b1a2;
        }
        if ((uVar7 & 0x20) != 0) {
          *(ushort *)((int)puVar5 + 0x26) = *(ushort *)((int)puVar5 + 0x26) | 0x20;
        }
        if ((((uVar7 & 0x10) != 0) && ((*(byte *)((int)puVar5 + 0x27) & 0x40) == 0)) &&
           (*(ushort *)(puVar5 + 9) <= uVar2)) {
          uVar2 = CONCAT22((short)(uVar2 >> 0x10),*(undefined2 *)(puVar5 + 9));
        }
      }
      puVar5 = puVar5 + 0x14;
      sVar4 = sVar4 + 1;
    } while (sVar4 != 3);
  }
  return CONCAT44(uVar2,in_D1);
}


// ---------------------------------------------------------------
// FUN_0003a85e @ 0003a85e

undefined4 FUN_0003a85e(void)

{
  __m68k_trap(3);
  __m68k_trap(3);
  __m68k_trap(3);
  return 0;
}


// ---------------------------------------------------------------
// FUN_0003a992 @ 0003a992

ushort FUN_0003a992(void)

{
  char *pcVar1;
  byte bVar2;
  short in_D0w;
  ushort uVar3;
  char cVar4;
  short *in_A0;
  
  pcVar1 = (char *)(*(int *)(in_A0 + 2) + (int)(short)(ushort)*(byte *)(in_A0 + 5));
  bVar2 = *(byte *)((int)in_A0 + 0xb);
  *(byte *)((int)in_A0 + 0xb) = bVar2 & 0xfe;
  if ((bVar2 & 1) != 0) {
    in_A0[1] = (short)pcVar1[1] + in_A0[1];
  }
  uVar3 = (in_A0[1] + in_D0w) - *in_A0;
  if ((uVar3 & 0x8000) != 0) {
    uVar3 = 0;
  }
  if (((*(byte *)((int)in_A0 + 0xb) & 4) == 0) &&
     (*(char *)(in_A0 + 6) = *(char *)(in_A0 + 6) + '\x01', pcVar1[2] == *(char *)(in_A0 + 6))) {
    *(char *)((int)in_A0 + 0xd) = *(char *)((int)in_A0 + 0xd) + '\x01';
    *(undefined1 *)(in_A0 + 6) = 0;
    if (*pcVar1 == *(char *)((int)in_A0 + 0xd)) {
      *(undefined1 *)((int)in_A0 + 0xd) = 0;
      cVar4 = *(char *)(in_A0 + 5) + '\x03';
      if (cVar4 == '\f') {
        if (*(char *)((int)in_A0 + 0xb) == '\0') {
          *(byte *)((int)in_A0 + 0xb) = *(byte *)((int)in_A0 + 0xb) | 4;
          return uVar3;
        }
        *(undefined1 *)((int)in_A0 + 0xd) = 0;
        *in_A0 = (short)*(char *)(in_A0 + 4) + *in_A0;
        cVar4 = '\x03';
      }
      *(char *)(in_A0 + 5) = cVar4;
    }
    *(byte *)((int)in_A0 + 0xb) = *(byte *)((int)in_A0 + 0xb) | 1;
  }
  return uVar3;
}


// ---------------------------------------------------------------
// FUN_0003aa38 @ 0003aa38

undefined4 FUN_0003aa38(void)

{
  undefined4 in_D0;
  uint unaff_D2;
  char cVar1;
  char unaff_D7b;
  
  cVar1 = (char)unaff_D2;
  if ((unaff_D2 & 0x8000) == 0) {
    if (cVar1 == '\a') {
      DAT_00ff8800 = unaff_D7b + cVar1;
    }
  }
  else {
    FUN_0003aa7c();
    DAT_00ff8800 = cVar1 + unaff_D7b * '\x02' + '\x01';
  }
  FUN_0003aa7c();
  return in_D0;
}


// ---------------------------------------------------------------
// FUN_0003aa7c @ 0003aa7c

void FUN_0003aa7c(void)

{
  char in_D0b;
  char unaff_D6b;
  char *unaff_A5;
  
  do {
    *unaff_A5 = unaff_D6b;
    unaff_A5[2] = in_D0b;
  } while (in_D0b != *unaff_A5);
  return;
}


// ---------------------------------------------------------------
// FUN_0003aa8a @ 0003aa8a

undefined4 FUN_0003aa8a(void)

{
  undefined4 in_D0;
  uint unaff_D2;
  short unaff_D7w;
  
  if ((unaff_D2 & 0x8000) == 0) {
    (&DAT_0003ae7c)[(short)CONCAT31((int3)(unaff_D2 >> 8),(char)unaff_D7w + (char)unaff_D2)] =
         (char)in_D0;
    return in_D0;
  }
  *(short *)(&DAT_0003ae7c +
            CONCAT11((char)((ushort)(unaff_D7w << 1) >> 8),(char)unaff_D2 + (char)(unaff_D7w << 1)))
       = (short)in_D0;
  return in_D0;
}


// ---------------------------------------------------------------
// FUN_0003aab6 @ 0003aab6

void FUN_0003aab6(void)

{
  int iVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  byte bVar4;
  ushort uVar5;
  short unaff_D7w;
  undefined4 *unaff_A3;
  int unaff_A6;
  
  DAT_00000484 = DAT_00000484 & 0xfa;
  if ((*(byte *)((int)unaff_A3 + 0x27) & 0x40) == 0) {
    *(undefined4 *)(unaff_A6 + 0x14) = unaff_A3[6];
    if ((*(char *)((int)unaff_A3 + 0x2f) != *(char *)((int)unaff_A3 + 0x2b)) &&
       (*(char *)(unaff_A3 + 0xb) = *(char *)(unaff_A3 + 0xb) + '\x01',
       *(byte *)(unaff_A6 + 0x1e) < *(byte *)(unaff_A3 + 0xb))) {
      *(undefined1 *)(unaff_A3 + 0xb) = 0;
      if (*(byte *)((int)unaff_A3 + 0x2b) < *(byte *)((int)unaff_A3 + 0x2f)) {
        *(char *)((int)unaff_A3 + 0x2b) = *(char *)((int)unaff_A3 + 0x2b) + '\x01';
      }
      else {
        *(char *)((int)unaff_A3 + 0x2b) = *(char *)((int)unaff_A3 + 0x2b) + -1;
      }
    }
    bVar4 = *(byte *)((int)unaff_A3 + 0x27);
    *(byte *)((int)unaff_A3 + 0x27) = bVar4 & 0xfe;
    if ((bVar4 & 1) != 0) goto LAB_0003abb4;
    if (*(char *)(unaff_A6 + 0x1b) == '\0') {
      *(char *)(unaff_A3 + 10) = *(char *)(unaff_A3 + 10) + -1;
    }
    if (*(char *)(unaff_A3 + 10) == '\0') {
      *(undefined1 *)(unaff_A3 + 10) = *(undefined1 *)((int)unaff_A3 + 0x29);
      while( true ) {
        while( true ) {
          bVar4 = *(byte *)unaff_A3[2];
          if (bVar4 != 0xff) break;
          while( true ) {
            bVar4 = *(byte *)unaff_A3[3];
            if (bVar4 != 0xff) break;
            if ((*(byte *)((int)unaff_A3 + 0x27) & 0x20) == 0) {
              iVar1 = unaff_A3[1];
              if (((*(byte *)(iVar1 + 0x27) & 2) != 0) &&
                 ((*(byte *)((int)unaff_A3 + 0x26) & 2) != 0)) {
                *(ushort *)(iVar1 + 0x26) = *(ushort *)(iVar1 + 0x26) | 0x100;
                *(undefined1 *)(iVar1 + 0x2b) = 0;
              }
              *(byte *)(iVar1 + 0x27) = *(byte *)(iVar1 + 0x27) & 0xfd;
              *(ushort *)((int)unaff_A3 + 0x26) = *(ushort *)((int)unaff_A3 + 0x26) | 0x40;
              FUN_0003aa8a();
              *(byte *)(unaff_A3[6] + 6) =
                   (&DAT_0003aec0)[unaff_D7w] | (&DAT_0003aec0)[unaff_D7w] << 3 |
                   *(byte *)(unaff_A3[6] + 6);
              return;
            }
LAB_0003abb4:
            unaff_A3[3] = *unaff_A3;
            *(undefined2 *)(unaff_A3 + 9) = 0;
          }
          unaff_A3[3] = (byte *)unaff_A3[3] + 1;
          *(short *)(unaff_A3 + 9) = *(short *)(unaff_A3 + 9) + 1;
          unaff_A3[2] = *(int *)(unaff_A6 + 0xc) +
                        (int)*(short *)(*(int *)(unaff_A6 + 0x10) + (int)(short)((ushort)bVar4 << 1)
                                       );
        }
        unaff_A3[2] = (byte *)unaff_A3[2] + 1;
        uVar5 = (ushort)bVar4;
        if ((bVar4 & 0x80) == 0) break;
        if ((bVar4 & 0x40) == 0) {
          if ((bVar4 & 0x20) == 0) {
            *(undefined *)((int)unaff_A3 + 0x29) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
            *(undefined *)(unaff_A3 + 10) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
          }
          else {
            pbVar3 = (byte *)unaff_A3[6];
            if ((bVar4 & 0x1f) == 0) {
              pbVar3[6] = (&DAT_0003aec0)[unaff_D7w] << 3 | pbVar3[6];
            }
            else {
              pbVar3[6] = ~((&DAT_0003aec0)[unaff_D7w] << 3) & pbVar3[6];
            }
            pbVar3[1] = 0;
            *pbVar3 = bVar4 & 0x1f;
          }
        }
        else {
          if ((bVar4 & 0x20) != 0) {
            return;
          }
          pbVar3 = (byte *)(*(int *)(unaff_A6 + 4) + (int)(short)((uVar5 & 0x1f) * 0xd));
          puVar2 = (undefined2 *)unaff_A3[4];
          *(byte *)((int)puVar2 + 0xb) = *pbVar3 & 0x80;
          *(byte *)(puVar2 + 4) = *pbVar3 & 0x7f;
          *(undefined1 *)(puVar2 + 5) = 0;
          puVar2[1] = 0;
          *puVar2 = 0;
          *(undefined1 *)((int)puVar2 + 0xd) = 0;
          *(undefined1 *)(puVar2 + 6) = 0;
          *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
          *(byte **)(puVar2 + 2) = pbVar3 + 1;
        }
      }
      if (bVar4 != 0) {
        uVar5 = (ushort)(byte)(*(char *)((int)unaff_A3 + 0x2a) + bVar4);
      }
      *(undefined2 *)((int)unaff_A3 + 0x22) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar5 << 1));
      *(undefined2 *)(unaff_A3 + 8) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar5 << 1));
      puVar2 = (undefined2 *)unaff_A3[4];
      *(undefined1 *)(puVar2 + 5) = 0;
      puVar2[1] = 0;
      *puVar2 = 0;
      *(undefined1 *)((int)puVar2 + 0xd) = 0;
      *(undefined1 *)(puVar2 + 6) = 0;
      *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
      *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) & 0xfb;
      puVar2 = (undefined2 *)unaff_A3[5];
      *(undefined1 *)(puVar2 + 5) = 0;
      puVar2[1] = 0;
      *puVar2 = 0;
      *(undefined1 *)((int)puVar2 + 0xd) = 0;
      *(undefined1 *)(puVar2 + 6) = 0;
      *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
      *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) & 0xfb;
    }
    FUN_0003a992();
    FUN_0003aa8a();
    FUN_0003a992();
    FUN_0003aa8a();
  }
  return;
}


// ---------------------------------------------------------------
// FUN_0003ad5a @ 0003ad5a

void FUN_0003ad5a(void)

{
  int iVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  byte bVar4;
  ushort uVar5;
  short unaff_D7w;
  undefined4 *unaff_A3;
  int unaff_A6;
  
  *(undefined1 *)((int)unaff_A3 + 0x2a) = *(undefined1 *)unaff_A3[2];
  unaff_A3[2] = (undefined1 *)unaff_A3[2] + 1;
  while( true ) {
    while( true ) {
      bVar4 = *(byte *)unaff_A3[2];
      if (bVar4 != 0xff) break;
      while( true ) {
        bVar4 = *(byte *)unaff_A3[3];
        if (bVar4 != 0xff) break;
        if ((*(byte *)((int)unaff_A3 + 0x27) & 0x20) == 0) {
          iVar1 = unaff_A3[1];
          if (((*(byte *)(iVar1 + 0x27) & 2) != 0) && ((*(byte *)((int)unaff_A3 + 0x26) & 2) != 0))
          {
            *(ushort *)(iVar1 + 0x26) = *(ushort *)(iVar1 + 0x26) | 0x100;
            *(undefined1 *)(iVar1 + 0x2b) = 0;
          }
          *(byte *)(iVar1 + 0x27) = *(byte *)(iVar1 + 0x27) & 0xfd;
          *(ushort *)((int)unaff_A3 + 0x26) = *(ushort *)((int)unaff_A3 + 0x26) | 0x40;
          FUN_0003aa8a();
          *(byte *)(unaff_A3[6] + 6) =
               (&DAT_0003aec0)[unaff_D7w] | (&DAT_0003aec0)[unaff_D7w] << 3 |
               *(byte *)(unaff_A3[6] + 6);
          return;
        }
        unaff_A3[3] = *unaff_A3;
        *(undefined2 *)(unaff_A3 + 9) = 0;
      }
      unaff_A3[3] = (byte *)unaff_A3[3] + 1;
      *(short *)(unaff_A3 + 9) = *(short *)(unaff_A3 + 9) + 1;
      unaff_A3[2] = *(int *)(unaff_A6 + 0xc) +
                    (int)*(short *)(*(int *)(unaff_A6 + 0x10) + (int)(short)((ushort)bVar4 << 1));
    }
    unaff_A3[2] = (byte *)unaff_A3[2] + 1;
    uVar5 = (ushort)bVar4;
    if ((bVar4 & 0x80) == 0) break;
    if ((bVar4 & 0x40) == 0) {
      if ((bVar4 & 0x20) == 0) {
        *(undefined *)((int)unaff_A3 + 0x29) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
        *(undefined *)(unaff_A3 + 10) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
      }
      else {
        pbVar3 = (byte *)unaff_A3[6];
        if ((bVar4 & 0x1f) == 0) {
          pbVar3[6] = (&DAT_0003aec0)[unaff_D7w] << 3 | pbVar3[6];
        }
        else {
          pbVar3[6] = ~((&DAT_0003aec0)[unaff_D7w] << 3) & pbVar3[6];
        }
        pbVar3[1] = 0;
        *pbVar3 = bVar4 & 0x1f;
      }
    }
    else {
      if ((bVar4 & 0x20) != 0) {
        return;
      }
      pbVar3 = (byte *)(*(int *)(unaff_A6 + 4) + (int)(short)((uVar5 & 0x1f) * 0xd));
      puVar2 = (undefined2 *)unaff_A3[4];
      *(byte *)((int)puVar2 + 0xb) = *pbVar3 & 0x80;
      *(byte *)(puVar2 + 4) = *pbVar3 & 0x7f;
      *(undefined1 *)(puVar2 + 5) = 0;
      puVar2[1] = 0;
      *puVar2 = 0;
      *(undefined1 *)((int)puVar2 + 0xd) = 0;
      *(undefined1 *)(puVar2 + 6) = 0;
      *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
      *(byte **)(puVar2 + 2) = pbVar3 + 1;
    }
  }
  if (bVar4 != 0) {
    uVar5 = (ushort)(byte)(*(char *)((int)unaff_A3 + 0x2a) + bVar4);
  }
  *(undefined2 *)((int)unaff_A3 + 0x22) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar5 << 1));
  *(undefined2 *)(unaff_A3 + 8) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar5 << 1));
  puVar2 = (undefined2 *)unaff_A3[4];
  *(undefined1 *)(puVar2 + 5) = 0;
  puVar2[1] = 0;
  *puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 0xd) = 0;
  *(undefined1 *)(puVar2 + 6) = 0;
  *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
  *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) & 0xfb;
  puVar2 = (undefined2 *)unaff_A3[5];
  *(undefined1 *)(puVar2 + 5) = 0;
  puVar2[1] = 0;
  *puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 0xd) = 0;
  *(undefined1 *)(puVar2 + 6) = 0;
  *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
  *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) & 0xfb;
  FUN_0003a992();
  FUN_0003aa8a();
  FUN_0003a992();
  FUN_0003aa8a();
  return;
}


// ---------------------------------------------------------------
// FUN_0003ad6a @ 0003ad6a

void FUN_0003ad6a(void)

{
  byte *pbVar1;
  int iVar2;
  undefined2 *puVar3;
  byte bVar4;
  ushort uVar5;
  short unaff_D7w;
  undefined4 *unaff_A3;
  int unaff_A6;
  
  bVar4 = *(byte *)unaff_A3[2];
  unaff_A3[2] = (byte *)unaff_A3[2] + 1;
  iVar2 = *(int *)(unaff_A6 + 8);
  puVar3 = (undefined2 *)unaff_A3[5];
  *(undefined1 *)((int)puVar3 + 0xb) = 0;
  *(undefined1 *)(puVar3 + 4) = 0;
  *(undefined1 *)(puVar3 + 5) = 0;
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 0xd) = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) | 1;
  *(int *)(puVar3 + 2) = iVar2 + (short)((ushort)bVar4 * 0xd) + 1;
  while( true ) {
    while( true ) {
      bVar4 = *(byte *)unaff_A3[2];
      if (bVar4 != 0xff) break;
      while( true ) {
        bVar4 = *(byte *)unaff_A3[3];
        if (bVar4 != 0xff) break;
        if ((*(byte *)((int)unaff_A3 + 0x27) & 0x20) == 0) {
          iVar2 = unaff_A3[1];
          if (((*(byte *)(iVar2 + 0x27) & 2) != 0) && ((*(byte *)((int)unaff_A3 + 0x26) & 2) != 0))
          {
            *(ushort *)(iVar2 + 0x26) = *(ushort *)(iVar2 + 0x26) | 0x100;
            *(undefined1 *)(iVar2 + 0x2b) = 0;
          }
          *(byte *)(iVar2 + 0x27) = *(byte *)(iVar2 + 0x27) & 0xfd;
          *(ushort *)((int)unaff_A3 + 0x26) = *(ushort *)((int)unaff_A3 + 0x26) | 0x40;
          FUN_0003aa8a();
          *(byte *)(unaff_A3[6] + 6) =
               (&DAT_0003aec0)[unaff_D7w] | (&DAT_0003aec0)[unaff_D7w] << 3 |
               *(byte *)(unaff_A3[6] + 6);
          return;
        }
        unaff_A3[3] = *unaff_A3;
        *(undefined2 *)(unaff_A3 + 9) = 0;
      }
      unaff_A3[3] = (byte *)unaff_A3[3] + 1;
      *(short *)(unaff_A3 + 9) = *(short *)(unaff_A3 + 9) + 1;
      unaff_A3[2] = *(int *)(unaff_A6 + 0xc) +
                    (int)*(short *)(*(int *)(unaff_A6 + 0x10) + (int)(short)((ushort)bVar4 << 1));
    }
    unaff_A3[2] = (byte *)unaff_A3[2] + 1;
    uVar5 = (ushort)bVar4;
    if ((bVar4 & 0x80) == 0) break;
    if ((bVar4 & 0x40) == 0) {
      if ((bVar4 & 0x20) == 0) {
        *(undefined *)((int)unaff_A3 + 0x29) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
        *(undefined *)(unaff_A3 + 10) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
      }
      else {
        pbVar1 = (byte *)unaff_A3[6];
        if ((bVar4 & 0x1f) == 0) {
          pbVar1[6] = (&DAT_0003aec0)[unaff_D7w] << 3 | pbVar1[6];
        }
        else {
          pbVar1[6] = ~((&DAT_0003aec0)[unaff_D7w] << 3) & pbVar1[6];
        }
        pbVar1[1] = 0;
        *pbVar1 = bVar4 & 0x1f;
      }
    }
    else {
      if ((bVar4 & 0x20) != 0) {
        return;
      }
      pbVar1 = (byte *)(*(int *)(unaff_A6 + 4) + (int)(short)((uVar5 & 0x1f) * 0xd));
      puVar3 = (undefined2 *)unaff_A3[4];
      *(byte *)((int)puVar3 + 0xb) = *pbVar1 & 0x80;
      *(byte *)(puVar3 + 4) = *pbVar1 & 0x7f;
      *(undefined1 *)(puVar3 + 5) = 0;
      puVar3[1] = 0;
      *puVar3 = 0;
      *(undefined1 *)((int)puVar3 + 0xd) = 0;
      *(undefined1 *)(puVar3 + 6) = 0;
      *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) | 1;
      *(byte **)(puVar3 + 2) = pbVar1 + 1;
    }
  }
  if (bVar4 != 0) {
    uVar5 = (ushort)(byte)(*(char *)((int)unaff_A3 + 0x2a) + bVar4);
  }
  *(undefined2 *)((int)unaff_A3 + 0x22) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar5 << 1));
  *(undefined2 *)(unaff_A3 + 8) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar5 << 1));
  puVar3 = (undefined2 *)unaff_A3[4];
  *(undefined1 *)(puVar3 + 5) = 0;
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 0xd) = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) | 1;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0xfb;
  puVar3 = (undefined2 *)unaff_A3[5];
  *(undefined1 *)(puVar3 + 5) = 0;
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 0xd) = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) | 1;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0xfb;
  FUN_0003a992();
  FUN_0003aa8a();
  FUN_0003a992();
  FUN_0003aa8a();
  return;
}


// ---------------------------------------------------------------
// FUN_0003adb4 @ 0003adb4

void FUN_0003adb4(void)

{
  byte *pbVar1;
  int iVar2;
  undefined2 *puVar3;
  byte bVar4;
  ushort uVar5;
  short unaff_D7w;
  undefined4 *unaff_A3;
  int unaff_A6;
  
  bVar4 = *(byte *)unaff_A3[2];
  unaff_A3[2] = (byte *)unaff_A3[2] + 1;
  iVar2 = *(int *)(unaff_A6 + 8);
  puVar3 = (undefined2 *)unaff_A3[5];
  *(undefined1 *)((int)puVar3 + 0xb) = 0x80;
  *(undefined1 *)(puVar3 + 4) = 0;
  *(undefined1 *)(puVar3 + 5) = 0;
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 0xd) = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) | 1;
  *(int *)(puVar3 + 2) = iVar2 + (short)((ushort)bVar4 * 0xd) + 1;
  while( true ) {
    while( true ) {
      bVar4 = *(byte *)unaff_A3[2];
      if (bVar4 != 0xff) break;
      while( true ) {
        bVar4 = *(byte *)unaff_A3[3];
        if (bVar4 != 0xff) break;
        if ((*(byte *)((int)unaff_A3 + 0x27) & 0x20) == 0) {
          iVar2 = unaff_A3[1];
          if (((*(byte *)(iVar2 + 0x27) & 2) != 0) && ((*(byte *)((int)unaff_A3 + 0x26) & 2) != 0))
          {
            *(ushort *)(iVar2 + 0x26) = *(ushort *)(iVar2 + 0x26) | 0x100;
            *(undefined1 *)(iVar2 + 0x2b) = 0;
          }
          *(byte *)(iVar2 + 0x27) = *(byte *)(iVar2 + 0x27) & 0xfd;
          *(ushort *)((int)unaff_A3 + 0x26) = *(ushort *)((int)unaff_A3 + 0x26) | 0x40;
          FUN_0003aa8a();
          *(byte *)(unaff_A3[6] + 6) =
               (&DAT_0003aec0)[unaff_D7w] | (&DAT_0003aec0)[unaff_D7w] << 3 |
               *(byte *)(unaff_A3[6] + 6);
          return;
        }
        unaff_A3[3] = *unaff_A3;
        *(undefined2 *)(unaff_A3 + 9) = 0;
      }
      unaff_A3[3] = (byte *)unaff_A3[3] + 1;
      *(short *)(unaff_A3 + 9) = *(short *)(unaff_A3 + 9) + 1;
      unaff_A3[2] = *(int *)(unaff_A6 + 0xc) +
                    (int)*(short *)(*(int *)(unaff_A6 + 0x10) + (int)(short)((ushort)bVar4 << 1));
    }
    unaff_A3[2] = (byte *)unaff_A3[2] + 1;
    uVar5 = (ushort)bVar4;
    if ((bVar4 & 0x80) == 0) break;
    if ((bVar4 & 0x40) == 0) {
      if ((bVar4 & 0x20) == 0) {
        *(undefined *)((int)unaff_A3 + 0x29) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
        *(undefined *)(unaff_A3 + 10) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
      }
      else {
        pbVar1 = (byte *)unaff_A3[6];
        if ((bVar4 & 0x1f) == 0) {
          pbVar1[6] = (&DAT_0003aec0)[unaff_D7w] << 3 | pbVar1[6];
        }
        else {
          pbVar1[6] = ~((&DAT_0003aec0)[unaff_D7w] << 3) & pbVar1[6];
        }
        pbVar1[1] = 0;
        *pbVar1 = bVar4 & 0x1f;
      }
    }
    else {
      if ((bVar4 & 0x20) != 0) {
        return;
      }
      pbVar1 = (byte *)(*(int *)(unaff_A6 + 4) + (int)(short)((uVar5 & 0x1f) * 0xd));
      puVar3 = (undefined2 *)unaff_A3[4];
      *(byte *)((int)puVar3 + 0xb) = *pbVar1 & 0x80;
      *(byte *)(puVar3 + 4) = *pbVar1 & 0x7f;
      *(undefined1 *)(puVar3 + 5) = 0;
      puVar3[1] = 0;
      *puVar3 = 0;
      *(undefined1 *)((int)puVar3 + 0xd) = 0;
      *(undefined1 *)(puVar3 + 6) = 0;
      *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) | 1;
      *(byte **)(puVar3 + 2) = pbVar1 + 1;
    }
  }
  if (bVar4 != 0) {
    uVar5 = (ushort)(byte)(*(char *)((int)unaff_A3 + 0x2a) + bVar4);
  }
  *(undefined2 *)((int)unaff_A3 + 0x22) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar5 << 1));
  *(undefined2 *)(unaff_A3 + 8) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar5 << 1));
  puVar3 = (undefined2 *)unaff_A3[4];
  *(undefined1 *)(puVar3 + 5) = 0;
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 0xd) = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) | 1;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0xfb;
  puVar3 = (undefined2 *)unaff_A3[5];
  *(undefined1 *)(puVar3 + 5) = 0;
  puVar3[1] = 0;
  *puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 0xd) = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) | 1;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0xfb;
  FUN_0003a992();
  FUN_0003aa8a();
  FUN_0003a992();
  FUN_0003aa8a();
  return;
}


// ---------------------------------------------------------------
// FUN_0003ae00 @ 0003ae00

void FUN_0003ae00(void)

{
  int iVar1;
  undefined2 *puVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  byte bVar7;
  short unaff_D7w;
  undefined4 *unaff_A3;
  int unaff_A6;
  
  pbVar3 = (byte *)unaff_A3[2];
  bVar4 = *pbVar3;
  bVar5 = pbVar3[1];
  unaff_A3[2] = pbVar3 + 2;
  pbVar3 = (byte *)unaff_A3[6];
  bVar7 = bVar4 & 0x3f;
  pbVar3[3] = bVar7;
  *pbVar3 = bVar7;
  pbVar3[4] = bVar5 & 0x3f;
  bVar4 = bVar5 >> 6 | bVar4 >> 4 & 0xc;
  pbVar3[1] = bVar4;
  pbVar3[2] = bVar4;
  pbVar3[5] = 0xff;
  if (pbVar3[3] < pbVar3[4]) {
    pbVar3[5] = 1;
  }
  pbVar3[6] = ~((&DAT_0003aec0)[unaff_D7w] << 3) & pbVar3[6];
  while( true ) {
    while( true ) {
      bVar4 = *(byte *)unaff_A3[2];
      if (bVar4 != 0xff) break;
      while( true ) {
        bVar4 = *(byte *)unaff_A3[3];
        if (bVar4 != 0xff) break;
        if ((*(byte *)((int)unaff_A3 + 0x27) & 0x20) == 0) {
          iVar1 = unaff_A3[1];
          if (((*(byte *)(iVar1 + 0x27) & 2) != 0) && ((*(byte *)((int)unaff_A3 + 0x26) & 2) != 0))
          {
            *(ushort *)(iVar1 + 0x26) = *(ushort *)(iVar1 + 0x26) | 0x100;
            *(undefined1 *)(iVar1 + 0x2b) = 0;
          }
          *(byte *)(iVar1 + 0x27) = *(byte *)(iVar1 + 0x27) & 0xfd;
          *(ushort *)((int)unaff_A3 + 0x26) = *(ushort *)((int)unaff_A3 + 0x26) | 0x40;
          FUN_0003aa8a();
          *(byte *)(unaff_A3[6] + 6) =
               (&DAT_0003aec0)[unaff_D7w] | (&DAT_0003aec0)[unaff_D7w] << 3 |
               *(byte *)(unaff_A3[6] + 6);
          return;
        }
        unaff_A3[3] = *unaff_A3;
        *(undefined2 *)(unaff_A3 + 9) = 0;
      }
      unaff_A3[3] = (byte *)unaff_A3[3] + 1;
      *(short *)(unaff_A3 + 9) = *(short *)(unaff_A3 + 9) + 1;
      unaff_A3[2] = *(int *)(unaff_A6 + 0xc) +
                    (int)*(short *)(*(int *)(unaff_A6 + 0x10) + (int)(short)((ushort)bVar4 << 1));
    }
    unaff_A3[2] = (byte *)unaff_A3[2] + 1;
    uVar6 = (ushort)bVar4;
    if ((bVar4 & 0x80) == 0) break;
    if ((bVar4 & 0x40) == 0) {
      if ((bVar4 & 0x20) == 0) {
        *(undefined *)((int)unaff_A3 + 0x29) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
        *(undefined *)(unaff_A3 + 10) = (&DAT_0003af9c)[(short)(bVar4 & 0xff0f)];
      }
      else {
        pbVar3 = (byte *)unaff_A3[6];
        if ((bVar4 & 0x1f) == 0) {
          pbVar3[6] = (&DAT_0003aec0)[unaff_D7w] << 3 | pbVar3[6];
        }
        else {
          pbVar3[6] = ~((&DAT_0003aec0)[unaff_D7w] << 3) & pbVar3[6];
        }
        pbVar3[1] = 0;
        *pbVar3 = bVar4 & 0x1f;
      }
    }
    else {
      if ((bVar4 & 0x20) != 0) {
        return;
      }
      pbVar3 = (byte *)(*(int *)(unaff_A6 + 4) + (int)(short)((uVar6 & 0x1f) * 0xd));
      puVar2 = (undefined2 *)unaff_A3[4];
      *(byte *)((int)puVar2 + 0xb) = *pbVar3 & 0x80;
      *(byte *)(puVar2 + 4) = *pbVar3 & 0x7f;
      *(undefined1 *)(puVar2 + 5) = 0;
      puVar2[1] = 0;
      *puVar2 = 0;
      *(undefined1 *)((int)puVar2 + 0xd) = 0;
      *(undefined1 *)(puVar2 + 6) = 0;
      *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
      *(byte **)(puVar2 + 2) = pbVar3 + 1;
    }
  }
  if (bVar4 != 0) {
    uVar6 = (ushort)(byte)(*(char *)((int)unaff_A3 + 0x2a) + bVar4);
  }
  *(undefined2 *)((int)unaff_A3 + 0x22) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar6 << 1));
  *(undefined2 *)(unaff_A3 + 8) = *(undefined2 *)(&DAT_0003aec4 + (short)(uVar6 << 1));
  puVar2 = (undefined2 *)unaff_A3[4];
  *(undefined1 *)(puVar2 + 5) = 0;
  puVar2[1] = 0;
  *puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 0xd) = 0;
  *(undefined1 *)(puVar2 + 6) = 0;
  *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
  *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) & 0xfb;
  puVar2 = (undefined2 *)unaff_A3[5];
  *(undefined1 *)(puVar2 + 5) = 0;
  puVar2[1] = 0;
  *puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 0xd) = 0;
  *(undefined1 *)(puVar2 + 6) = 0;
  *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) | 1;
  *(byte *)((int)puVar2 + 0xb) = *(byte *)((int)puVar2 + 0xb) & 0xfb;
  FUN_0003a992();
  FUN_0003aa8a();
  FUN_0003a992();
  FUN_0003aa8a();
  return;
}


// ---------------------------------------------------------------
// FUN_0003ae68 @ 0003ae68

void FUN_0003ae68(void)

{
  byte bVar1;
  int unaff_A3;
  
  bVar1 = **(byte **)(unaff_A3 + 8) & 0xf;
  *(byte *)(unaff_A3 + 0x2b) = bVar1;
  (*(byte **)(unaff_A3 + 8))[0x30] = bVar1;
  return;
}


