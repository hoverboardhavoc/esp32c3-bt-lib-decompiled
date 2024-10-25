/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rmv_dev_from_wlst_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rmv_dev_from_wlst_cmd_handler(char *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  byte bVar4;
  char local_19;
  undefined1 auStack_18 [12];
  
  iVar1 = r_llm_is_wl_accessible();
  uVar3 = 0xc;
  if (iVar1 != 0) {
    if (0xfc < (byte)(*param_1 - 2U)) {
      local_19 = *param_1;
      memcpy(auStack_18,param_1 + 1,6);
      lld_wl_rpa_res(auStack_18,&local_19,0);
      uVar2 = r_llm_dev_list_search(auStack_18,local_19);
      if (uVar2 < 0xc) {
        iVar1 = _p_llm_env + uVar2 * 10;
        bVar4 = *(byte *)(iVar1 + 0x2d);
        if ((bVar4 & 2) != 0) {
          if ((bVar4 & 4) == 0) {
            bVar4 = bVar4 & 0xfc;
          }
          else {
            bVar4 = bVar4 & 0xfd;
          }
          *(byte *)(iVar1 + 0x2d) = bVar4;
          r_lld_white_list_rem(uVar2,auStack_18,local_19);
          lld_wl_res_rem(uVar2);
          uVar3 = 0;
          goto _L203;
        }
      }
    }
    uVar3 = 0x12;
  }
_L203:
  r_llm_cmd_cmp_send(param_2,uVar3);
  return 0;
}

