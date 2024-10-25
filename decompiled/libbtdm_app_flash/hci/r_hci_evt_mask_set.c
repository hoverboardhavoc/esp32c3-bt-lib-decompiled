/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci.o -> r_hci_evt_mask_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 r_hci_evt_mask_set(void *param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  switch(param_2) {
  case 0:
  case 1:
    r_assert_param(param_2,"hci.c",0x51c);
    break;
  case 2:
    goto _L92;
  case 3:
    memcpy(&hci_env,param_1,8);
    iVar2 = 0;
    pbVar3 = &hci_env;
    do {
      pbVar1 = &hci_rsvd_evt_msk + iVar2;
      iVar2 = iVar2 + 1;
      *pbVar3 = *pbVar1 | *pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (iVar2 != 8);
    break;
  case 4:
_L92:
    memcpy(&hci_env,param_1,8);
    break;
  default:
    r_assert_err(0,"hci.c",0x537);
  }
  return 0;
}

