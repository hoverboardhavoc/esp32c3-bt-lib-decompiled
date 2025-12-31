/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_clear_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_clear_wlst_cmd_handler(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar4 = r_llm_is_wl_accessible();
  if (iVar4 == 0) {
    r_ble_log_internal_x1(0x802e019e,0xc);
    uVar5 = 0xc;
  }
  else {
    uVar3 = 0;
    do {
      iVar4 = _p_llm_env;
      iVar6 = uVar3 * 10 + _p_llm_env;
      bVar1 = *(byte *)(iVar6 + 0x2d);
      if ((bVar1 & 1) != 0) {
        if ((bVar1 & 4) == 0) {
          bVar2 = 0xfc;
        }
        else {
          bVar2 = 0xfd;
        }
        *(byte *)(iVar6 + 0x2d) = bVar1 & bVar2;
        r_lld_white_list_rem(iVar4 + uVar3 * 10 + 0x24,*(undefined1 *)(iVar4 + uVar3 * 10 + 0x2c));
        lld_wl_res_rem(uVar3 & 0xff);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0xc);
    uVar5 = 0;
  }
  r_llm_cmd_cmp_send(param_1,uVar5);
  return 0;
}

