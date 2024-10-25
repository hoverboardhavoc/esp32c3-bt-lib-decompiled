/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  uVar5 = 0xc;
  if (iVar4 != 0) {
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
        r_lld_white_list_rem
                  (uVar3 & 0xff,iVar4 + uVar3 * 10 + 0x24,*(undefined1 *)(iVar4 + uVar3 * 10 + 0x2c)
                  );
        lld_wl_res_rem(uVar3 & 0xff);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0xc);
    uVar5 = 0;
  }
  r_llm_cmd_cmp_send(param_1,uVar5);
  return 0;
}

