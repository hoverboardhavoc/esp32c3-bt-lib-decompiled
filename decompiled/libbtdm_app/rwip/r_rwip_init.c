/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
  if (DAT_00011016 != '\0') {
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
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((*(char *)(iVar1 + 0x11) != '\0') || (rwip_rf != '\0')) {
    (**(code **)(_r_ip_funcs_p + 0x120))(_LANCHOR0,*(code **)(_r_ip_funcs_p + 0x120));
  }
  (**(code **)(_r_modules_funcs_p + 0x29c))(_LANCHOR0,*(code **)(_r_modules_funcs_p + 0x29c));
  (**(code **)(_r_modules_funcs_p + 0x288))(1,*(code **)(_r_modules_funcs_p + 0x288));
  _LANCHOR0 = 1;
  _btdm_pwr_state = 0;
                    /* WARNING: Could not recover jumptable at 0x000101e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x38))(g_waking_sleeping_sem);
  return;
}

