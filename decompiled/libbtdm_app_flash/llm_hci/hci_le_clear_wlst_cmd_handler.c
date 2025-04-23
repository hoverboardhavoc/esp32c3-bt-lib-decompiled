/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  
  iVar3 = r_llm_is_wl_accessible();
  uVar4 = 0xc;
  if (iVar3 != 0) {
    uVar2 = 0;
    do {
      iVar3 = _p_llm_env;
      bVar1 = *(byte *)(uVar2 * 10 + _p_llm_env + 0x2d);
      if ((bVar1 & 1) != 0) {
        bVar5 = bVar1 & 0xfc;
        if ((bVar1 & 4) != 0) {
          bVar5 = bVar1 & 0xfd;
        }
        iVar6 = _p_llm_env + uVar2 * 10;
        *(byte *)(iVar6 + 0x2d) = bVar5;
        r_lld_white_list_rem(iVar3 + uVar2 * 10 + 0x24,*(undefined1 *)(iVar6 + 0x2c));
        lld_wl_res_rem(uVar2 & 0xff);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 0xc);
    uVar4 = 0;
  }
  r_llm_cmd_cmp_send(param_1,uVar4);
  return 0;
}

