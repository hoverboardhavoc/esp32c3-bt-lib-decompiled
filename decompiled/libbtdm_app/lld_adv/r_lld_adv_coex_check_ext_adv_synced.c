/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_coex_check_ext_adv_synced
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_adv_coex_check_ext_adv_synced(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar2 = 0;
  while( true ) {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar4 + 0xd) <= uVar1) break;
    iVar4 = *(int *)(&lld_adv_env + uVar1 * 4);
    if (((iVar4 != 0) && (*(byte *)(iVar4 + 0x88) == param_1)) && (param_1 != 0xff)) {
      iVar2 = iVar4;
    }
    uVar1 = uVar1 + 1 & 0xff;
  }
  if (iVar2 == 0) {
    if (1 < _g_bt_plf_log_level) {
      ets_printf("ext_adv unfound for per_adv: %d\n");
    }
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined1 *)(iVar2 + 0x96);
    *(undefined1 *)(iVar2 + 0x96) = 0;
  }
  return uVar3;
}

