/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> f_hci_le_per_adv_term_sync_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_per_adv_term_sync_cmd_handler(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar1 = (uint)*param_1;
    iVar3 = r_sdk_config_get_opts();
    if ((uVar1 < *(byte *)(iVar3 + 0xd)) &&
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) == '\x0f')) {
      uVar2 = r_lld_sync_stop(uVar1);
      if (uVar2 == 0) {
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) = 0x10;
        r_ble_log_internal_x1(0x404e018c,uVar1 | 0x1000);
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar1,5,0);
        return 0;
      }
      r_ble_log_internal_x1(0x802e018d,uVar1 << 8 | uVar2);
      goto _L77;
    }
    r_ble_log_internal_x1(0x802e018b,uVar1 << 8 | 0xc);
  }
  uVar2 = 0xc;
_L77:
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

