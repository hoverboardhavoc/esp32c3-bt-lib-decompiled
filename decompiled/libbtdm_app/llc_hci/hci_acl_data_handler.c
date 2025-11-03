/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llc_hci.o -> hci_acl_data_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_acl_data_handler(ushort *param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  
  param_2 = param_2 >> 8;
  iVar5 = *(int *)(&llc_env + param_2 * 4);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (param_2 < *(byte *)(iVar2 + 0xd)) {
    iVar2 = *(int *)(&llc_env + param_2 * 4);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x44) & 3) != 3)) {
      if (param_1[1] == 0) {
        if (((int)(uint)*param_1 >> 0xc & 3U) == 0) {
          *(undefined1 *)(iVar5 + 0x48) = 1;
        }
        goto _L92;
      }
      iVar2 = (**(code **)(_r_ip_funcs_p + 200))(param_1[2],*(code **)(_r_ip_funcs_p + 200));
      uVar4 = param_1[1];
      *(undefined2 *)(iVar2 + 6) = 0;
      if ((uVar4 & 0xfc00) != 0) {
        (**(code **)(_r_plf_funcs_p + 0xc))
                  (0x3ff,"llc_hci.c",0x221,*(code **)(_r_plf_funcs_p + 0xc));
      }
      uVar4 = (*(ushort *)(iVar2 + 6) & 0xfc00 | param_1[1]) & 0xfff | *param_1 & 0xc000;
      if (*(char *)(iVar5 + 0x48) == '\0') {
        *(ushort *)(iVar2 + 6) = uVar4 | *param_1 & 0x3000;
      }
      else {
        *(ushort *)(iVar2 + 6) = uVar4;
        *(undefined1 *)(iVar5 + 0x48) = 0;
      }
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x330))(param_2,iVar2,*(code **)(_r_ip_funcs_p + 0x330));
      pcVar1 = ble_acl_data_tx_cb;
      if (ble_acl_data_tx_cb != (code *)0x0) {
        uVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(param_1[2],*(code **)(_r_plf_funcs_p + 0xbc));
        (*pcVar1)(0,uVar3,param_1[1]);
      }
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  if (param_1[1] != 0) {
    (**(code **)(_r_ip_funcs_p + 0xcc))(param_1[2],*(code **)(_r_ip_funcs_p + 0xcc));
  }
_L92:
  (**(code **)(_r_ip_funcs_p + 0x63c))(param_2,1,*(code **)(_r_ip_funcs_p + 0x63c));
  return 0;
}

