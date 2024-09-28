/*
 * Last changed at upstream commit 73ae8322b2d7c990c195bfe3dca118ff43196f70
 * https://github.com/espressif/esp32c3-bt-lib/commit/73ae8322b2d7c990c195bfe3dca118ff43196f70
 * Upstream date: 2024-09-28 12:07:47 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(01cc408)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_per_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_per_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_a1;
  char cVar5;
  undefined4 *puVar6;
  byte bStack_2d;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L423:
    iVar4 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    if (*param_1 < 0xf0) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x544))(0,*(code **)(_r_ip_funcs_p + 0x544));
      if (iVar2 == 0xff) {
        iVar4 = 0x42;
        goto _L425;
      }
      iVar2 = iVar2 * 0x44;
      bStack_2d = *(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
      if (bStack_2d == 0xff) {
        iVar4 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_2d,*(code **)(_r_ip_funcs_p + 0x4ac));
        if (iVar4 != 0) goto _L425;
        iVar4 = *(int *)(_p_llm_env + 8);
        *(byte *)(iVar4 + iVar2 + 0x3d) = bStack_2d;
        *(undefined1 *)(iVar4 + (uint)bStack_2d * 0x44 + 0x32) = 0xff;
        uVar1 = 0;
      }
      else {
        uVar1 = extraout_a1;
        if (*(char *)((uint)bStack_2d * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\n') goto _L423;
      }
      if ((*param_1 < 0xf0) && (*(ushort *)(param_1 + 2) <= *(ushort *)(param_1 + 4))) {
        if ((*(ushort *)(*(int *)(*(int *)(_p_llm_env + 8) + iVar2) + 2) & 0x20) == 0) {
          iVar4 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
          if (iVar4 != 0) {
            (**(code **)(_r_modules_funcs_p + 0xd8))
                      (iVar4 + -0xc,uVar1,*(code **)(_r_modules_funcs_p + 0xd8));
            *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44) = 0;
          }
          iVar3 = *(int *)(_p_llm_env + 8);
          puVar6 = (undefined4 *)((uint)bStack_2d * 0x44 + iVar3);
          *(undefined1 *)(puVar6 + 0x10) = 10;
          iVar4 = _bt_rf_coex_hooks_p;
          *puVar6 = param_1;
          if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != 0)) {
            iVar2 = *(int *)(iVar3 + iVar2);
            uStack_2c = (uint)*(ushort *)(param_1 + 4);
            uStack_28 = *(undefined2 *)((int)puVar6 + 0x2a);
            uStack_26 = 0;
            uStack_24 = 0;
            uStack_22 = 0;
            if ((*(byte *)(iVar2 + 0x17) < 3) || (iVar4 = lld_phy_coded_500k_get(), iVar4 == 0)) {
              cVar5 = *(char *)(iVar2 + 0x17) + -1;
            }
            else {
              cVar5 = *(char *)(iVar2 + 0x17);
            }
            uStack_26 = CONCAT11(uStack_26._1_1_,cVar5);
            (**(code **)(_bt_rf_coex_hooks_p + 4))
                      (bStack_2d,4,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
          }
          iVar4 = 0;
          uVar1 = 1;
          goto _L433;
        }
      }
    }
    iVar4 = 0x12;
  }
_L425:
  uVar1 = 0;
_L433:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return uVar1;
}

