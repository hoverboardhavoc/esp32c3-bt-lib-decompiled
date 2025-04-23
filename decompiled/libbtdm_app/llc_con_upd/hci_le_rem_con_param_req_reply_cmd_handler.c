/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_con_upd.o -> hci_le_rem_con_param_req_reply_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rem_con_param_req_reply_cmd_handler(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar4;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (((param_1 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
     ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x5e8))
                      (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                       *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                       *(code **)(_r_ip_funcs_p + 0x5e8));
    uVar3 = 0x20;
    if (iVar1 == 0) goto _L275;
    iVar2 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,0x20,*(code **)(_r_ip_funcs_p + 0x674));
    iVar1 = _r_ip_funcs_p;
    if (iVar2 != 0) {
      uVar4 = *(ushort *)(iVar2 + 10);
      if (*(ushort *)(iVar2 + 10) < *(ushort *)(param_2 + 4)) {
        uVar4 = *(ushort *)(param_2 + 4);
      }
      *(ushort *)(iVar2 + 10) = uVar4;
      uVar4 = *(ushort *)(iVar2 + 8);
      if (*(ushort *)(iVar2 + 8) < *(ushort *)(param_2 + 2)) {
        uVar4 = *(ushort *)(param_2 + 2);
      }
      *(ushort *)(iVar2 + 8) = uVar4;
      uVar4 = *(ushort *)(iVar2 + 0xe);
      if (*(ushort *)(iVar2 + 0xe) < *(ushort *)(param_2 + 8)) {
        uVar4 = *(ushort *)(param_2 + 8);
      }
      *(ushort *)(iVar2 + 0xe) = uVar4;
      (**(code **)(iVar1 + 0x600))(param_1,8,0,*(code **)(iVar1 + 0x600));
      uVar3 = 0;
      goto _L275;
    }
  }
  uVar3 = 0xc;
_L275:
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,uVar3,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

