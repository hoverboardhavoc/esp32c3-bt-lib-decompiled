/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_hci.o -> hci_acl_data_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_acl_data_handler(ushort *param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  
  param_2 = param_2 >> 8;
  iVar5 = *(int *)(&llc_env + param_2 * 4);
  iVar2 = r_sdk_config_get_opts();
  if (((param_2 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_2 * 4), iVar2 != 0))
     && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
    if (param_1[1] == 0) {
      if ((*param_1 >> 0xc & 3) == 0) {
        *(undefined1 *)(iVar5 + 0x48) = 1;
      }
      goto _L93;
    }
    iVar2 = r_ble_util_buf_acl_tx_elt_get(param_1[2]);
    uVar4 = param_1[1];
    *(undefined2 *)(iVar2 + 6) = 0;
    if (0x3ff < uVar4) {
      r_assert_param("llc_hci.c",0x21f);
    }
    uVar4 = (*(ushort *)(iVar2 + 6) & 0xfc00 | param_1[1]) & 0xfff | *param_1 & 0xc000;
    if (*(char *)(iVar5 + 0x48) == '\0') {
      *(ushort *)(iVar2 + 6) = uVar4 | *param_1 & 0x3000;
    }
    else {
      *(ushort *)(iVar2 + 6) = uVar4;
      *(undefined1 *)(iVar5 + 0x48) = 0;
    }
    iVar2 = r_lld_con_data_tx(param_2,iVar2);
    pcVar1 = ble_acl_data_tx_cb;
    if (ble_acl_data_tx_cb != (code *)0x0) {
      uVar3 = r_emi_get_mem_addr_by_offset(param_1[2]);
      (*pcVar1)(0,uVar3,param_1[1]);
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (param_1[1] != 0) {
    r_ble_util_buf_acl_tx_free(param_1[2]);
  }
_L93:
  r_llc_hci_nb_cmp_pkts_evt_send(param_2,1);
  return 0;
}

