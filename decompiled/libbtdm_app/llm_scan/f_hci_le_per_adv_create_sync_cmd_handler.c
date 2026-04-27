/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_scan.o -> f_hci_le_per_adv_create_sync_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 f_hci_le_per_adv_create_sync_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  undefined1 uVar7;
  byte bStack_21;
  
  if (((((ushort)(*(short *)(param_1 + 0xc) - 10U) < 0x3ff7) && (*param_1 < 2)) && (param_1[2] < 2))
     && ((param_1[1] < 0x10 && (*(ushort *)(param_1 + 10) < 500)))) {
    if (((*param_1 != 1) || (iVar3 = llm_is_pal_empty(), iVar3 == 0)) &&
       (iVar3 = _r_ip_funcs_p, *(char *)(_p_llm_env + 0xd7) != '\x01')) {
      *(undefined1 *)(_p_llm_env + 0xd7) = 2;
      bStack_21 = (**(code **)(iVar3 + 0x510))(*(code **)(iVar3 + 0x510));
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (*(byte *)(iVar3 + 0xd) <= bStack_21) {
        if (*param_1 == 0) {
          iVar3 = 0xb;
          iVar4 = (**(code **)(_r_ip_funcs_p + 0x4dc))
                            (param_1 + 3,param_1[2],param_1[1],*(code **)(_r_ip_funcs_p + 0x4dc));
          uVar7 = 0;
          if (iVar4 != 0) goto _L161;
        }
        uVar7 = 0;
        iVar3 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
        if (iVar3 == 0) {
          piVar5 = (int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
          *(undefined1 *)(piVar5 + 0x10) = 0xe;
          llm_sync_cancel_cc_act_id = 0xff;
          if (*piVar5 != 0) {
            (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",900,*(code **)(_r_plf_funcs_p + 8));
          }
          bVar1 = param_1[5];
          bVar2 = param_1[7];
          pcVar6 = *(code **)(_r_ip_funcs_p + 0x3dc);
          uVar7 = 1;
          *(byte **)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44) = param_1;
          iVar3 = (*pcVar6)(bStack_21,*param_1,param_1[1],param_1[2],
                            CONCAT13(param_1[6],CONCAT12(bVar1,*(undefined2 *)(param_1 + 3))),
                            CONCAT11(param_1[8],bVar2),pcVar6);
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(bStack_21,6,1);
          }
        }
        goto _L161;
      }
    }
    uVar7 = 0;
    iVar3 = 0xc;
  }
  else {
    uVar7 = 0;
    iVar3 = 0x12;
  }
_L161:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,iVar3,*(code **)(_r_ip_funcs_p + 0x4bc));
  return uVar7;
}

