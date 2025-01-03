/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  r_assert_err(0,"llm_hci.c",0x1a1);
  r_llm_cmd_cmp_send(param_2,0x12);
  return 0;
}

