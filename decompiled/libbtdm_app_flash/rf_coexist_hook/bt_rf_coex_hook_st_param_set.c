/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> rf_coexist_hook.o -> bt_rf_coex_hook_st_param_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_rf_coex_hook_st_param_set(undefined4 param_1,int param_2,ushort *param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  int iVar7;
  uint uVar8;
  
  bVar2 = false;
  switch(param_2) {
  case 1:
  case 3:
  case 5:
  case 6:
    break;
  case 2:
    uVar8 = (uint)(byte)param_3[4];
    if (uVar8 != 0) {
      uVar8 = __popcountsi2(uVar8);
      uVar8 = uVar8 & 0xff;
    }
    bVar1 = *(byte *)((int)param_3 + 0xb);
    iVar3 = 0;
    if (*(byte *)((int)param_3 + 9) < 4) {
      iVar3 = (int)*(short *)((int)&CSWTCH_22 + (uint)*(byte *)((int)param_3 + 9) * 2);
    }
    iVar4 = coex_hook_calc_aux_adv_dur(param_3[2],(char)param_3[5]);
    iVar4 = iVar4 + (iVar3 + 0x96) * uVar8 + 300;
    if (iVar4 < 0x1771) {
_L26:
      bVar2 = false;
      goto _L16;
    }
    if (iVar4 < 0xc351) {
      iVar3 = (bVar1 + 1 & 0xff) * *(int *)param_3;
      iVar7 = 0x271;
_L43:
      bVar2 = (uint)(iVar3 * iVar7) <= (uint)(iVar4 * 10);
      goto _L16;
    }
    break;
  case 4:
    iVar4 = coex_hook_calc_aux_adv_dur(param_3[2],(char)param_3[3]);
    if (iVar4 < 0x1771) goto _L26;
    if (iVar4 < 0xc351) {
      iVar7 = *(int *)param_3;
      iVar3 = 0x4e2;
      goto _L43;
    }
    break;
  case 7:
    uVar8 = 1;
    if ((char)param_3[3] == '\0') {
      uVar8 = param_3[1] + 1 & 0xffff;
    }
    uVar6 = (uint)param_3[2] * 0x271;
    if (uVar6 < 0x1771) {
      bVar2 = (int)(*param_3 * uVar8 * 0x4e2) < 0x61a9;
    }
    else {
      bVar2 = true;
      if (uVar6 < 0xc351) {
        bVar2 = (int)(*param_3 * uVar8 * 0x4e2) <= (int)((uint)param_3[2] * 0x186a);
      }
    }
    if (2 < _g_bt_plf_log_level) {
      ets_printf("CHK: ACT %d, CONN mst %d, intv %d, ce %d, latency %d\n",param_1,*param_3,
                 param_3[1]);
    }
  default:
    goto _L16;
  }
  bVar2 = true;
_L16:
  iVar4 = _g_bt_plf_log_level;
  (&DAT_000104e1)[param_2 * 2] = bVar2;
  if (2 < iVar4) {
    ets_printf("CHK: st %d sleep %d\n",param_2,bVar2);
  }
  iVar4 = coex_hook_check_wifi_sleep();
  if (iVar4 == 0) {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("UNSLP2\n");
    }
    uVar5 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xac);
  }
  else {
    if (2 < _g_bt_plf_log_level) {
      ets_printf("SLP2\n");
    }
    uVar5 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_osi_funcs_p + 0xac);
  }
                    /* WARNING: Could not recover jumptable at 0x0001023e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar5,UNRECOVERED_JUMPTABLE);
  return;
}

