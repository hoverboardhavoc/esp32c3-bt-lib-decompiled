/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_stop
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
    uVar1 = 0xc;
    if (*(byte *)((int)&lld_con_cntl_pkt_info + param_1 * 4 + 3) < 6) {
      r_assert_param(param_1,"lld_con.c",0x5b5);
      uVar1 = 0xc;
    }
    goto _L253;
  }
  if (*(char *)(iVar2 + 0x8f) == '\0') {
    if (param_2 == 0) goto _L252;
    r_sch_arb_remove(0);
    r_lld_con_cleanup(param_1,1,0x16);
  }
  else if (*(char *)(iVar2 + 0x8f) == '\x01') {
_L252:
    *(undefined1 *)(iVar2 + 0x8f) = 2;
  }
  uVar1 = 0;
_L253:
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar1;
}

