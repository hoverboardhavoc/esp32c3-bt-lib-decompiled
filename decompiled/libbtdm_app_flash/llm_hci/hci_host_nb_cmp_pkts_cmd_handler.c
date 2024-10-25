/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_host_nb_cmp_pkts_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 hci_host_nb_cmp_pkts_cmd_handler(byte *param_1,undefined4 param_2)

{
  ushort uVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  
  sVar3 = 0;
  uVar2 = 0;
  while( true ) {
    if (*param_1 <= uVar2) {
      r_hci_fc_host_nb_acl_pkts_complete(sVar3);
      r_hci_tl_c2h_data_flow_on();
      return 0;
    }
    uVar1 = *(ushort *)(param_1 + uVar2 * 2 + 2);
    iVar4 = r_sdk_config_get_opts();
    if (*(byte *)(iVar4 + 0xd) <= uVar1) break;
    iVar4 = uVar2 * 2;
    uVar2 = uVar2 + 1 & 0xff;
    sVar3 = sVar3 + *(short *)(param_1 + iVar4 + 0x18);
  }
  r_assert_err(0,"llm_hci.c",0x176);
  r_llm_cmd_cmp_send(param_2,0x12);
  return 0;
}

