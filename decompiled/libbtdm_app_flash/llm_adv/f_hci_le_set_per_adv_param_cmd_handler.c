/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llm_adv.o -> f_hci_le_set_per_adv_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_set_per_adv_param_cmd_handler(byte *param_1,undefined4 param_2)

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
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L722:
    iVar3 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    if (*param_1 < 0xf0) {
      iVar2 = r_llm_adv_hdl_to_id(0);
      if (iVar2 == 0xff) {
        iVar3 = 0x42;
        goto _L724;
      }
      iVar2 = iVar2 * 0x44;
      bStack_2d = *(byte *)(*(int *)(_p_llm_env + 8) + iVar2 + 0x3d);
      if (bStack_2d == 0xff) {
        iVar3 = r_llm_activity_free_get(&bStack_2d);
        if (iVar3 != 0) goto _L724;
        iVar3 = *(int *)(_p_llm_env + 8);
        *(byte *)(iVar3 + iVar2 + 0x3d) = bStack_2d;
        *(undefined1 *)(iVar3 + (uint)bStack_2d * 0x44 + 0x32) = 0xff;
        uVar1 = 0;
      }
      else {
        uVar1 = extraout_a1;
        if (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44 + 0x40) != '\n') goto _L722;
      }
      if (((*param_1 < 0xf0) && (*(ushort *)(param_1 + 2) <= *(ushort *)(param_1 + 4))) &&
         ((*(ushort *)(*(int *)(*(int *)(_p_llm_env + 8) + iVar2) + 2) & 0x20) == 0)) {
        iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_2d * 0x44);
        if (iVar3 != 0) {
          r_ke_msg_free(iVar3 + -0xc,uVar1);
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
        goto _L732;
      }
    }
    iVar3 = 0x12;
  }
_L724:
  uVar1 = 0;
_L732:
  r_llm_cmd_cmp_send(param_2,iVar3);
  return uVar1;
}

