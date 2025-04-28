/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  undefined4 uVar2;
  ushort uVar3;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if (param_1 < *(byte *)(iVar1 + 0xd)) {
    if ((*(int *)(&llc_env + param_1 * 4) != 0) &&
       ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x5e8))
                        (param_1,*(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                         *(undefined2 *)(param_2 + 6),*(undefined2 *)(param_2 + 8),
                         *(code **)(_r_ip_funcs_p + 0x5e8));
      uVar2 = 0x20;
      if (iVar1 == 0) goto _L270;
      iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,1,0x20,*(code **)(_r_ip_funcs_p + 0x674))
      ;
      if (iVar1 != 0) {
        uVar3 = *(ushort *)(iVar1 + 10);
        if (*(ushort *)(iVar1 + 10) < *(ushort *)(param_2 + 4)) {
          uVar3 = *(ushort *)(param_2 + 4);
        }
        *(ushort *)(iVar1 + 10) = uVar3;
        uVar3 = *(ushort *)(iVar1 + 8);
        if (*(ushort *)(iVar1 + 8) < *(ushort *)(param_2 + 2)) {
          uVar3 = *(ushort *)(param_2 + 2);
        }
        *(ushort *)(iVar1 + 8) = uVar3;
        uVar3 = *(ushort *)(iVar1 + 0xe);
        if (*(ushort *)(iVar1 + 0xe) < *(ushort *)(param_2 + 8)) {
          uVar3 = *(ushort *)(param_2 + 8);
        }
        *(ushort *)(iVar1 + 0xe) = uVar3;
        (**(code **)(_r_ip_funcs_p + 0x600))(param_1,8,0,*(code **)(_r_ip_funcs_p + 0x600));
        uVar2 = 0;
        goto _L270;
      }
    }
  }
  uVar2 = 0xc;
_L270:
  (**(code **)(_r_ip_funcs_p + 0x630))(param_1,param_3,uVar2,*(code **)(_r_ip_funcs_p + 0x630));
  return 0;
}

