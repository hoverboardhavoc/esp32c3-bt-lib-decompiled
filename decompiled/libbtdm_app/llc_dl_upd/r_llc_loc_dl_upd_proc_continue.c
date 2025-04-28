/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_dl_upd.o -> r_llc_loc_dl_upd_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_dl_upd_proc_continue(uint param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  ushort uVar8;
  ushort uVar9;
  code *pcVar10;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar6 != 0) {
    if (iVar6 == 1) {
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
      if (param_2 == 0) {
        if (*(char *)(iVar4 + 0x1c) == '\x03') {
          uVar8 = *(ushort *)(iVar5 + 10);
          if (uVar8 < 0xa90) {
            uVar8 = 0xa90;
          }
          *(ushort *)(iVar5 + 10) = uVar8;
        }
        if (*(char *)(iVar4 + 0x1d) == '\x03') {
          uVar8 = *(ushort *)(iVar5 + 0xe);
          if (uVar8 < 0xa90) {
            uVar8 = 0xa90;
          }
          *(ushort *)(iVar5 + 0xe) = uVar8;
        }
        if (((((*(short *)(iVar4 + 0x16) != *(short *)(iVar5 + 0xc)) ||
              (*(short *)(iVar4 + 0x14) != *(short *)(iVar5 + 8))) ||
             (*(short *)(iVar4 + 0x1a) != *(short *)(iVar5 + 0xe))) ||
            (*(short *)(iVar4 + 0x18) != *(short *)(iVar5 + 10))) &&
           (iVar6 = (**(code **)(_r_ip_funcs_p + 0x32c))(param_1,*(code **)(_r_ip_funcs_p + 0x32c)),
           iVar6 == 0)) {
          uVar1 = *(undefined2 *)(iVar5 + 8);
          uVar2 = *(undefined2 *)(iVar5 + 0xe);
          uVar3 = *(undefined2 *)(iVar5 + 10);
          pcVar10 = *(code **)(_r_ip_funcs_p + 0x5d0);
          *(undefined2 *)(iVar4 + 0x16) = *(undefined2 *)(iVar5 + 0xc);
          *(undefined2 *)(iVar4 + 0x14) = uVar1;
          *(undefined2 *)(iVar4 + 0x1a) = uVar2;
          *(undefined2 *)(iVar4 + 0x18) = uVar3;
          (*pcVar10)(param_1,0,pcVar10);
        }
      }
    }
    else {
      pcVar10 = *(code **)(_r_plf_funcs_p + 0xc);
      uVar7 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar5,*(code **)(_r_ip_funcs_p + 0x680));
      (*pcVar10)(param_1,uVar7,"llc_dl_upd.c",0x162);
    }
    if (*(char *)(iVar5 + 0x10) != '\0') {
      *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) & 0xdf;
    }
                    /* WARNING: Could not recover jumptable at 0x00010406. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
    return;
  }
  (**(code **)(_r_ip_funcs_p + 0x684))(iVar5,param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
  iVar6 = _r_modules_funcs_p;
  if (*(char *)(iVar4 + 0x1c) == '\x03') {
    uVar8 = *(ushort *)(iVar5 + 10);
    if (*(ushort *)(iVar5 + 10) < 0xa90) {
      uVar8 = 0xa90;
    }
    *(ushort *)(iVar5 + 10) = uVar8;
    iVar6 = (**(code **)(iVar6 + 0x188))(*(code **)(iVar6 + 0x188));
    if (iVar6 != 0) {
      iVar6 = (**(code **)(_r_modules_funcs_p + 0x188))(*(code **)(_r_modules_funcs_p + 0x188));
      if (iVar6 == 0) {
        uVar8 = 0xa90;
      }
      else {
        uVar8 = *(ushort *)(*(int *)(_bt_rf_coex_cfg_p + 0x44) + 2);
      }
      if (uVar8 < 0xa90) {
        uVar8 = 0xa90;
      }
      uVar9 = *(ushort *)(iVar5 + 10);
      if (uVar8 < *(ushort *)(iVar5 + 10)) {
        uVar9 = uVar8;
      }
      *(ushort *)(iVar5 + 10) = uVar9;
    }
    if (*(char *)(iVar4 + 0x1d) != '\x03') goto _L25;
  }
  else if (*(char *)(iVar4 + 0x1d) != '\x03') {
    if ((((*(ushort *)(iVar4 + 0x42) & 0x80) == 0) ||
        (iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38)),
        *(byte *)(iVar4 + 0xd) <= param_1)) ||
       ((iVar4 = *(int *)(&llc_env + param_1 * 4), iVar4 == 0 ||
        (((int)(uint)*(byte *)(iVar4 + 0x31) >> 3 & 1U) == 0)))) {
      uVar8 = *(ushort *)(iVar5 + 10);
      if (0x848 < uVar8) {
        uVar8 = 0x848;
      }
      uVar9 = *(ushort *)(iVar5 + 0xe);
      *(ushort *)(iVar5 + 10) = uVar8;
      if (0x848 < uVar9) {
        uVar9 = 0x848;
      }
      *(ushort *)(iVar5 + 0xe) = uVar9;
    }
    goto _L25;
  }
  iVar4 = _r_modules_funcs_p;
  uVar8 = *(ushort *)(iVar5 + 0xe);
  if (*(ushort *)(iVar5 + 0xe) < 0xa90) {
    uVar8 = 0xa90;
  }
  *(ushort *)(iVar5 + 0xe) = uVar8;
  iVar4 = (**(code **)(iVar4 + 0x188))(*(code **)(iVar4 + 0x188));
  if (iVar4 != 0) {
    iVar4 = (**(code **)(_r_modules_funcs_p + 0x188))(*(code **)(_r_modules_funcs_p + 0x188));
    if (iVar4 == 0) {
      uVar8 = 0xa90;
    }
    else {
      uVar8 = **(ushort **)(_bt_rf_coex_cfg_p + 0x44);
    }
    if (uVar8 < 0xa90) {
      uVar8 = 0xa90;
    }
    uVar9 = *(ushort *)(iVar5 + 0xe);
    if (uVar8 < *(ushort *)(iVar5 + 0xe)) {
      uVar9 = uVar8;
    }
    *(ushort *)(iVar5 + 0xe) = uVar9;
  }
_L25:
  llc_ll_length_req_pdu_send
            (param_1,*(undefined2 *)(iVar5 + 10),*(undefined2 *)(iVar5 + 8),
             *(undefined2 *)(iVar5 + 0xe),*(undefined2 *)(iVar5 + 0xc));
                    /* WARNING: Could not recover jumptable at 0x0001022e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x68c));
  return;
}

