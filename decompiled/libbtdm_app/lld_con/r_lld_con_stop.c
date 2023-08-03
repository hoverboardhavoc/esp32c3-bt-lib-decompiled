/*
 * Last changed at upstream commit 040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * https://github.com/espressif/esp32c3-bt-lib/commit/040cd0eafd8c6ee52bc7f7d5d633c9dc1b99bba2
 * Upstream date: 2023-08-03 10:45:08 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(ff6efe7)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_con_stop(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
    uVar1 = 0xc;
    if (*(byte *)(iVar2 + param_1 * 4 + 3) < 6) {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (param_1,param_2,"lld_con.c",0x590,*(code **)(_r_plf_funcs_p + 0xc));
      uVar1 = 0xc;
    }
    goto _L204;
  }
  if (*(char *)(iVar2 + 0x8f) == '\0') {
    if (param_2 == 0) goto _L203;
    (**(code **)(_r_ip_funcs_p + 0x6b8))(0,*(code **)(_r_ip_funcs_p + 0x6b8));
    (**(code **)(_r_ip_funcs_p + 800))(param_1,1,0x16,*(code **)(_r_ip_funcs_p + 800));
  }
  else if (*(char *)(iVar2 + 0x8f) == '\x01') {
_L203:
    *(undefined1 *)(iVar2 + 0x8f) = 2;
  }
  uVar1 = 0;
_L204:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

