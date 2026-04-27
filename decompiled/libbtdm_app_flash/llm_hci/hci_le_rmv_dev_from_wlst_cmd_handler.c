/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rmv_dev_from_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_dev_from_wlst_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  byte local_19;
  undefined1 auStack_18 [12];
  
  iVar1 = r_llm_is_wl_accessible();
  if (iVar1 == 0) {
    r_ble_log_internal_x1(0x802e01cd,0xc);
    uVar2 = 0xc;
  }
  else {
    uVar4 = (uint)*param_1;
    if ((uVar4 - 2 & 0xff) < 0xfd) {
      uVar2 = 0x802e01ce;
    }
    else {
      local_19 = *param_1;
      memcpy(auStack_18,param_1 + 1,6);
      iVar1 = lld_peer_rpa_to_id(auStack_18,&local_19);
      if (iVar1 == 0) {
        lld_wl_rpa_res(auStack_18,&local_19);
      }
      uVar4 = r_llm_dev_list_search(auStack_18,local_19);
      if (uVar4 < 0xc) {
        iVar1 = _p_llm_env + uVar4 * 10;
        bVar3 = *(byte *)(iVar1 + 0x2d);
        if ((bVar3 & 2) != 0) {
          if ((bVar3 & 4) == 0) {
            bVar3 = bVar3 & 0xfc;
          }
          else {
            bVar3 = bVar3 & 0xfd;
          }
          *(byte *)(iVar1 + 0x2d) = bVar3;
          r_lld_white_list_rem(auStack_18,local_19);
          lld_wl_res_rem(uVar4);
          uVar2 = 0;
          goto _L222;
        }
      }
      uVar2 = 0x802e01cf;
    }
    r_ble_log_internal_x1(uVar2,uVar4 << 8 | 0x12);
    uVar2 = 0x12;
  }
_L222:
  r_llm_cmd_cmp_send(param_2,uVar2);
  return 0;
}

