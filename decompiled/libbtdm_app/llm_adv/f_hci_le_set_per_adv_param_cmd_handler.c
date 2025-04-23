/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> f_hci_le_set_per_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_per_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_a1;
  char cVar5;
  int *piVar6;
  byte bStack_2d;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L456:
    iVar4 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    if (*param_1 < 0xf0) {
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544));
      if (iVar3 == 0xff) {
        iVar4 = 0x42;
        goto _L458;
      }
      iVar3 = iVar3 * 0x44;
      bStack_2d = *(byte *)(*(int *)(_p_llm_env + 8) + iVar3 + 0x3d);
      if (bStack_2d == 0xff) {
        iVar4 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_2d,*(code **)(_r_ip_funcs_p + 0x4ac));
        if (iVar4 != 0) goto _L458;
        iVar4 = *(int *)(_p_llm_env + 8);
        *(byte *)(iVar4 + iVar3 + 0x3d) = bStack_2d;
        *(undefined1 *)(iVar4 + (uint)bStack_2d * 0x44 + 0x32) = 0xff;
        uVar2 = 0;
      }
      else {
        uVar2 = extraout_a1;
        if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) != '\n') goto _L456;
      }
      if (((*param_1 < 0xf0) && (*(ushort *)(param_1 + 2) <= *(ushort *)(param_1 + 4))) &&
         (iVar4 = *(int *)(_p_llm_env + 8), (*(ushort *)(*(int *)(iVar4 + iVar3) + 2) & 0x20) == 0))
      {
        piVar6 = (int *)((uint)bStack_2d * 0x44 + iVar4);
        if (*piVar6 != 0) {
          (**(code **)(_r_modules_funcs_p + 0xd8))
                    (*piVar6 + -0xc,uVar2,*(code **)(_r_modules_funcs_p + 0xd8));
          iVar4 = *(int *)(_p_llm_env + 8);
          piVar6 = (int *)((uint)bStack_2d * 0x44 + iVar4);
          *piVar6 = 0;
        }
        *(undefined1 *)(piVar6 + 0x10) = 10;
        iVar1 = _bt_rf_coex_hooks_p;
        *piVar6 = (int)param_1;
        if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
          iVar3 = *(int *)(iVar4 + iVar3);
          uStack_2c = (uint)*(ushort *)(param_1 + 4);
          uStack_28 = *(undefined2 *)((int)piVar6 + 0x2a);
          uStack_26 = 0;
          uStack_24 = 0;
          uStack_22 = 0;
          if ((*(byte *)(iVar3 + 0x17) < 3) || (iVar4 = lld_phy_coded_500k_get(), iVar4 == 0)) {
            cVar5 = *(char *)(iVar3 + 0x17) + -1;
          }
          else {
            cVar5 = *(char *)(iVar3 + 0x17);
          }
          uStack_26 = CONCAT11(uStack_26._1_1_,cVar5);
          (**(code **)(_bt_rf_coex_hooks_p + 4))
                    (bStack_2d,4,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
        }
        iVar4 = 0;
        uVar2 = 1;
        goto _L467;
      }
    }
    iVar4 = 0x12;
  }
_L458:
  uVar2 = 0;
_L467:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return uVar2;
}

