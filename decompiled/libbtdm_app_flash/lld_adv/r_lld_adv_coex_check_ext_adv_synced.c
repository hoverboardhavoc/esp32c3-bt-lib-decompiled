/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_coex_check_ext_adv_synced
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 r_lld_adv_coex_check_ext_adv_synced(uint param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  iVar3 = 0;
  while( true ) {
    iVar4 = r_sdk_config_get_opts();
    if (*(byte *)(iVar4 + 0xd) <= uVar2) break;
    iVar4 = *(int *)(&lld_adv_env + uVar2 * 4);
    if (((iVar4 != 0) && (*(byte *)(iVar4 + 0x88) == param_1)) && (param_1 != 0xff)) {
      iVar3 = iVar4;
    }
    uVar2 = uVar2 + 1 & 0xff;
  }
  if (iVar3 == 0) {
    uVar1 = 0;
    if (1 < _g_bt_plf_log_level) {
      ets_printf("ext_adv unfound for per_adv: %d\n");
      uVar1 = 0;
    }
  }
  else {
    uVar1 = *(undefined1 *)(iVar3 + 0x96);
    *(undefined1 *)(iVar3 + 0x96) = 0;
  }
  return uVar1;
}

