/*
 * Last changed at upstream commit b223604efd557d0a5314afb3b751229df424d244
 * https://github.com/espressif/esp32c3-bt-lib/commit/b223604efd557d0a5314afb3b751229df424d244
 * Upstream date: 2021-06-24 21:26:02 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (9c99115)
 * Source: libbtdm_app -> rwip.o -> r_rwip_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_init(void)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  _rwip_param = *(undefined4 *)(_r_modules_funcs_p + 0x23c);
  _btdm_env_p = *(undefined4 **)(_r_modules_funcs_p + 600);
  _sdk_cfg_priv_opts = *(undefined4 *)(_r_modules_funcs_p + 0x234);
  _LANCHOR0 = 0;
  (**(code **)(_r_modules_funcs_p + 0x134))(*(code **)(_r_modules_funcs_p + 0x134));
  (**(code **)(_r_modules_funcs_p + 0x124))
            (0,*_btdm_env_p,*(undefined2 *)(_btdm_env_p + 1),*(code **)(_r_modules_funcs_p + 0x124))
  ;
  if (sdk_cfg_priv_opts != '\0') {
    (**(code **)(_r_modules_funcs_p + 0x124))
              (1,_btdm_env_p[6],*(undefined2 *)(_btdm_env_p + 7),
               *(code **)(_r_modules_funcs_p + 0x124));
  }
  (**(code **)(_r_modules_funcs_p + 0x124))
            (2,_btdm_env_p[2],*(undefined2 *)(_btdm_env_p + 3),
             *(code **)(_r_modules_funcs_p + 0x124));
  (**(code **)(_r_modules_funcs_p + 0x124))
            (3,_btdm_env_p[4],*(undefined2 *)(_btdm_env_p + 5),
             *(code **)(_r_modules_funcs_p + 0x124));
  (**(code **)(_r_modules_funcs_p + 0x268))(_LANCHOR0,*(code **)(_r_modules_funcs_p + 0x268));
  (**(code **)(_r_modules_funcs_p + 0x1c0))(*(code **)(_r_modules_funcs_p + 0x1c0));
  (**(code **)(_r_modules_funcs_p + 0x1ec))(*(code **)(_r_modules_funcs_p + 0x1ec));
  rtp_pwr_tbl_desc_init();
  (**(code **)(_r_modules_funcs_p + 0x22c))(&rwip_rf,*(code **)(_r_modules_funcs_p + 0x22c));
  (**(code **)(_r_modules_funcs_p + 0x378))(_LANCHOR0,*(code **)(_r_modules_funcs_p + 0x378));
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (*(char *)(iVar1 + 0x17) == '\0') {
    pcVar3 = *(code **)(_r_modules_funcs_p + 0x60);
    uVar2 = (**(code **)(_r_plf_funcs_p + 0x18))(0,*(code **)(_r_plf_funcs_p + 0x18));
    (*pcVar3)(0,uVar2);
  }
  else {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(char *)(iVar1 + 0x17) == '\x01') {
      (**(code **)(_r_plf_funcs_p + 0xd8))(*(code **)(_r_plf_funcs_p + 0xd8));
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x73c))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x73c));
  (**(code **)(_r_ip_funcs_p + 0x84))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x84));
  if (*(code **)(_r_hli_funcs_p + 0xc) != (code *)0x0) {
    (**(code **)(_r_hli_funcs_p + 0xc))();
  }
  if (*(code **)(_r_hli_funcs_p + 8) != (code *)0x0) {
    (**(code **)(_r_hli_funcs_p + 8))(_LANCHOR0);
  }
  (**(code **)(_r_ip_funcs_p + 0x128))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x128));
  bb_int_init(_LANCHOR0);
  (**(code **)(_r_modules_funcs_p + 0x29c))(_LANCHOR0,*(code **)(_r_modules_funcs_p + 0x29c));
  (**(code **)(_r_modules_funcs_p + 0x288))(1,*(code **)(_r_modules_funcs_p + 0x288));
  _LANCHOR0 = 1;
  _btdm_pwr_state = 0;
                    /* WARNING: Could not recover jumptable at 0x000101bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x38))(g_waking_sleeping_sem);
  return;
}

