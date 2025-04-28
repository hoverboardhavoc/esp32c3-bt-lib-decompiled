/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci.o -> r_hci_send_2_controller
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_send_2_controller(ushort *param_1)

{
  ushort uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  ushort uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  if (hci_ext_host == '\0') {
    uVar1 = param_1[-4];
    if (uVar1 != 0x1105) {
      uVar5 = 0x1106;
      goto _L72;
    }
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x90))(param_1[-2],*(code **)(_r_ip_funcs_p + 0x90));
    if (iVar4 != 0) {
      uVar5 = *(byte *)(iVar4 + 2) & 0xf;
      if (uVar5 == 2) {
_L67:
        uVar1 = 0;
_L63:
        iVar4 = _r_modules_funcs_p;
        param_1[-3] = uVar1;
        UNRECOVERED_JUMPTABLE = *(code **)(iVar4 + 0xe0);
        goto _L73;
      }
      if (uVar5 < 3) {
        uVar1 = 1;
        if ((*(byte *)(iVar4 + 2) & 0xf) == 0) goto _L67;
      }
      else {
        uVar1 = 3;
      }
_L72:
      if (uVar1 == uVar5) {
        uVar2 = *param_1 & 0xfff;
        pbVar3 = (byte *)(**(code **)(_r_plf_funcs_p + 0x20))(*(code **)(_r_plf_funcs_p + 0x20));
        if ((uVar2 < *pbVar3) && ((&hci_rsvd_evt_msk)[uVar2] != '\0')) {
          uVar1 = (ushort)(uVar2 << 8) | 1;
          goto _L63;
        }
      }
    }
    (**(code **)(_r_plf_funcs_p + 0x10))
              (param_1[-4],param_1[-2],"hci.c",0x4c5,*(code **)(_r_plf_funcs_p + 0x10));
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"hci.c",0x4cf,*(code **)(_r_plf_funcs_p + 8));
  }
  UNRECOVERED_JUMPTABLE = *(code **)(_r_modules_funcs_p + 0xd8);
  param_1 = param_1 + -6;
_L73:
                    /* WARNING: Could not recover jumptable at 0x000103e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,UNRECOVERED_JUMPTABLE);
  return;
}

