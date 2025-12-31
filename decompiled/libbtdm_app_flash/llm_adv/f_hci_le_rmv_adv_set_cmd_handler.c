/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_rmv_adv_set_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_rmv_adv_set_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_24 [8];
  
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    iVar2 = r_llm_adv_hdl_to_id(*param_1,auStack_24);
    if (iVar2 == 0xff) {
      r_ble_log_internal_x1(0x802e0185,(uint)*param_1 << 8 | 0xff0042);
      uVar3 = 0x42;
      goto _L900;
    }
    iVar5 = *(int *)(_p_llm_env + 8) + iVar2 * 0x44;
    uVar4 = (uint)*(byte *)(iVar5 + 0x40);
    if (uVar4 == 1) {
      uVar4 = (uint)*(byte *)(iVar5 + 0x3d);
      iVar5 = r_sdk_config_get_opts();
      if (uVar4 < *(byte *)(iVar5 + 0xd)) {
        bVar1 = *(byte *)(*(int *)(_p_llm_env + 8) + uVar4 * 0x44 + 0x40);
        if (bVar1 != 10) {
          uVar4 = iVar2 << 8 | (uint)bVar1 << 0x18 | uVar4 << 0x10;
          uVar3 = 0x802e0187;
          goto _L903;
        }
      }
      r_llm_adv_set_release_hack(iVar2);
      uVar3 = 0;
      goto _L900;
    }
    uVar4 = iVar2 << 8 | uVar4 << 0x10;
    uVar3 = 0x802e0186;
_L903:
    r_ble_log_internal_x1(uVar3,uVar4 | 0xc);
  }
  uVar3 = 0xc;
_L900:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

