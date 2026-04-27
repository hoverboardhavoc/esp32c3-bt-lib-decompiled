/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
  undefined4 extraout_a1;
  char cVar4;
  int *piVar5;
  byte bStack_2d;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar2 = _r_ip_funcs_p;
  if (*(char *)(iVar3 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L484:
    iVar3 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    if (*param_1 < 0xf0) {
      iVar2 = (**(code **)(iVar2 + 0x544))(0,*(code **)(iVar2 + 0x544));
      if (iVar2 == 0xff) {
        iVar3 = 0x42;
        goto _L486;
      }
      iVar2 = iVar2 * 0x44;
      bStack_2d = *(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
      if (bStack_2d == 0xff) {
        iVar3 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_2d,*(code **)(_r_ip_funcs_p + 0x4ac));
        if (iVar3 != 0) goto _L486;
        iVar3 = *(int *)(_p_llm_env + 8);
        *(byte *)(iVar3 + iVar2 + 0x3d) = bStack_2d;
        *(undefined1 *)(iVar3 + (uint)bStack_2d * 0x44 + 0x32) = 0xff;
        uVar1 = 0;
      }
      else {
        uVar1 = extraout_a1;
        if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) != '\n') goto _L484;
      }
      if (((*param_1 < 0xf0) && (*(ushort *)(param_1 + 2) <= *(ushort *)(param_1 + 4))) &&
         ((*(ushort *)(*(int *)(*(int *)(_p_llm_env + 8) + iVar2) + 2) & 0x33) == 0)) {
        iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
        if (iVar3 != 0) {
          (**(code **)(_r_modules_funcs_p + 0xd8))
                    (iVar3 + -0xc,uVar1,*(code **)(_r_modules_funcs_p + 0xd8));
          *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44) = 0;
        }
        iVar3 = *(int *)(_p_llm_env + 8);
        *(byte **)((uint)bStack_2d * 0x44 + iVar3) = param_1;
        piVar5 = (int *)((uint)bStack_2d * 0x44 + iVar3);
        *(undefined1 *)(piVar5 + 0x10) = 10;
        if ((_bt_rf_coex_hooks_p != 0) && (*(int *)(_bt_rf_coex_hooks_p + 4) != 0)) {
          iVar2 = *(int *)(iVar3 + iVar2);
          uStack_2c = (uint)*(ushort *)(*piVar5 + 4);
          uStack_28 = (uint)*(ushort *)((int)piVar5 + 0x2a);
          uStack_24 = 0;
          if ((*(byte *)(iVar2 + 0x17) < 3) || (iVar3 = lld_phy_coded_500k_get(), iVar3 == 0)) {
            cVar4 = *(char *)(iVar2 + 0x17) + -1;
          }
          else {
            cVar4 = *(char *)(iVar2 + 0x17);
          }
          uStack_28._0_3_ = CONCAT12(cVar4,(undefined2)uStack_28);
          (**(code **)(_bt_rf_coex_hooks_p + 4))
                    (bStack_2d,4,&uStack_2c,*(code **)(_bt_rf_coex_hooks_p + 4));
        }
        iVar3 = 0;
        uVar1 = 1;
        goto _L494;
      }
    }
    iVar3 = 0x12;
  }
_L486:
  uVar1 = 0;
_L494:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return uVar1;
}

