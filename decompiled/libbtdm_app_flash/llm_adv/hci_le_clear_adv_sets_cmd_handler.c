/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> hci_le_clear_adv_sets_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_adv_sets_cmd_handler(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar2 + 0x18) == '\0') {
    r_llm_cmd_cmp_send(param_2,0xc);
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    for (uVar1 = 0; param_1 = r_sdk_config_get_opts(param_1), uVar1 < *(byte *)(param_1 + 0xd);
        uVar1 = uVar1 + 1 & 0xff) {
      uVar4 = (uint)*(byte *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40);
      if ((uVar4 - 2 & 0xff) < 2) {
        uVar4 = uVar1 << 8 | uVar4 << 0x10;
        uVar3 = 0x802e0188;
_L185:
        r_ble_log_internal_x1(uVar3,uVar4 | 0xc);
        break;
      }
      if ((uVar4 - 0xc & 0xff) < 2) {
        uVar4 = uVar4 << 0x10 | uVar1 << 8;
        uVar3 = 0x802e0189;
        goto _L185;
      }
    }
    iVar2 = r_sdk_config_get_opts();
    if (*(byte *)(iVar2 + 0xd) <= uVar1) {
      for (uVar1 = 0; iVar2 = r_sdk_config_get_opts(), uVar1 < *(byte *)(iVar2 + 0xd);
          uVar1 = uVar1 + 1 & 0xff) {
        if (*(char *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44 + 0x40) == '\x01') {
          r_llm_adv_set_release_hack(uVar1);
        }
      }
      uVar3 = 0;
      goto _L174;
    }
  }
  uVar3 = 0xc;
_L174:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

