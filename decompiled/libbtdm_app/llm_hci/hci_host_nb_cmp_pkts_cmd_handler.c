/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llm_hci.o -> hci_host_nb_cmp_pkts_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
      (**(code **)(_r_ip_funcs_p + 0xbc))(sVar3,*(code **)(_r_ip_funcs_p + 0xbc));
      (**(code **)(_r_ip_funcs_p + 0x34))(*(code **)(_r_ip_funcs_p + 0x34));
      return 0;
    }
    uVar1 = *(ushort *)(param_1 + uVar2 * 2 + 2);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar4 + 0xd) <= uVar1) break;
    iVar4 = uVar2 * 2;
    uVar2 = uVar2 + 1 & 0xff;
    sVar3 = sVar3 + *(short *)(param_1 + iVar4 + 0x18);
  }
  (**(code **)(_r_plf_funcs_p + 8))(0,"llm_hci.c",0x176,*(code **)(_r_plf_funcs_p + 8));
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0x12,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

