/*
 * Last changed at upstream commit 79152b519023f26462498f3ef8805cff2a80e193
 * https://github.com/espressif/esp32c3-bt-lib/commit/79152b519023f26462498f3ef8805cff2a80e193
 * Upstream date: 2022-11-29 17:30:47 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(02bfb7f1) - Fixed lld_con.c line 3048 assert - Fixed crash sometimes when connected as a slave by the 8th device
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_stop_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_stop_hack(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
    uVar1 = 0xc;
    if ((byte)lld_con_term_info[param_1 * 4 + 3] < 6) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,"lld_con.c",0x51f,*(code **)(_r_plf_funcs_p + 0xc));
      uVar1 = 0xc;
    }
    goto _L124;
  }
  if (*(char *)(iVar2 + 0x8f) == '\0') {
    if (param_2 == 0) goto _L123;
    (**(code **)(_r_ip_funcs_p + 0x6b8))(0,*(code **)(_r_ip_funcs_p + 0x6b8));
    (**(code **)(_r_ip_funcs_p + 800))(param_1,1,0x16,*(code **)(_r_ip_funcs_p + 800));
  }
  else if (*(char *)(iVar2 + 0x8f) == '\x01') {
_L123:
    *(undefined1 *)(iVar2 + 0x8f) = 2;
  }
  uVar1 = 0;
_L124:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

