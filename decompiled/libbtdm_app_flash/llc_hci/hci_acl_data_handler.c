/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_hci.o -> hci_acl_data_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_acl_data_handler(ushort *param_1,uint param_2)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  
  uVar8 = param_2 >> 8 & 0xff;
  iVar9 = *(int *)(&llc_env + (param_2 >> 8) * 4);
  iVar5 = r_sdk_config_get_opts();
  if (((uVar8 < *(byte *)(iVar5 + 0xd)) &&
      (iVar5 = *(int *)(&llc_env + (param_2 >> 8) * 4), iVar5 != 0)) &&
     ((*(byte *)(iVar5 + 0x44) & 3) != 3)) {
    if (param_1[1] == 0) {
      if (((int)(uint)*param_1 >> 0xc & 3U) == 0) {
        *(undefined1 *)(iVar9 + 0x48) = 1;
      }
      goto _L93;
    }
    iVar5 = r_ble_util_buf_acl_tx_elt_get(param_1[2]);
    uVar2 = param_1[1];
    *(undefined2 *)(iVar5 + 6) = 0;
    if ((uVar2 & 0xfc00) != 0) {
      r_assert_param(0x3ff,"llc_hci.c",0x21f);
    }
    uVar2 = *param_1;
    uVar7 = *(ushort *)(iVar5 + 6) & 0xfc00 | param_1[1];
    uVar3 = uVar2 & 0xc000;
    cVar1 = *(char *)(iVar9 + 0x48);
    *(ushort *)(iVar5 + 6) = uVar7 & 0x3fff | uVar3;
    if (cVar1 == '\0') {
      *(ushort *)(iVar5 + 6) = uVar7 & 0xfff | uVar3 | uVar2 & 0x3000;
    }
    else {
      *(ushort *)(iVar5 + 6) = uVar7 & 0xfff | uVar3;
      *(undefined1 *)(iVar9 + 0x48) = 0;
    }
    iVar5 = r_lld_con_data_tx(uVar8,iVar5);
    pcVar4 = ble_acl_data_tx_cb;
    if (ble_acl_data_tx_cb != (code *)0x0) {
      uVar6 = r_emi_get_mem_addr_by_offset(param_1[2]);
      (*pcVar4)(0,uVar6,param_1[1]);
    }
    if (iVar5 == 0) {
      return 0;
    }
  }
  if (param_1[1] != 0) {
    r_ble_util_buf_acl_tx_free(param_1[2]);
  }
_L93:
  r_llc_hci_nb_cmp_pkts_evt_send(uVar8,1);
  return 0;
}

