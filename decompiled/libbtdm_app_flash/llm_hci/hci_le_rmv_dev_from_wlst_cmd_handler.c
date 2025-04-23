/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rmv_dev_from_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_dev_from_wlst_cmd_handler(char *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  char local_19;
  undefined1 auStack_18 [12];
  
  iVar3 = r_llm_is_wl_accessible();
  uVar5 = 0xc;
  if (iVar3 != 0) {
    if (0xfc < (byte)(*param_1 - 2U)) {
      local_19 = *param_1;
      memcpy(auStack_18,param_1 + 1,6);
      iVar3 = lld_peer_rpa_to_id(auStack_18,&local_19);
      if (iVar3 == 0) {
        lld_wl_rpa_res(auStack_18,&local_19);
      }
      uVar4 = r_llm_dev_list_search(auStack_18,local_19);
      if (uVar4 < 0xc) {
        bVar1 = *(byte *)(uVar4 * 10 + _p_llm_env + 0x2d);
        if ((bVar1 & 2) != 0) {
          bVar2 = 0xfc;
          if ((bVar1 & 4) != 0) {
            bVar2 = 0xfd;
          }
          *(byte *)(_p_llm_env + uVar4 * 10 + 0x2d) = bVar1 & bVar2;
          r_lld_white_list_rem(auStack_18,local_19);
          lld_wl_res_rem(uVar4);
          uVar5 = 0;
          goto _L217;
        }
      }
    }
    uVar5 = 0x12;
  }
_L217:
  r_llm_cmd_cmp_send(param_2,uVar5);
  return 0;
}

