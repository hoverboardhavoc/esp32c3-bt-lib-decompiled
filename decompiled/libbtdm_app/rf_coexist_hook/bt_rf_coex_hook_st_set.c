/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> rf_coexist_hook.o -> bt_rf_coex_hook_st_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_rf_coex_hook_st_set(uint param_1,uint param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  ushort *puVar6;
  
  if (8 < param_2) {
    return;
  }
  (&_LANCHOR1)[param_2 * 2] = (char)param_3;
  iVar3 = _r_osi_funcs_p;
  if (param_2 == 8) {
    if (param_3 != 0) goto _L42;
    _LANCHOR0 = 0;
    _LANCHOR3 = 0;
    DAT_00010420 = 0;
    pcVar5 = *(code **)(_r_osi_funcs_p + 0xb8);
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = (uint)(byte)(&_LANCHOR5)[(byte)(&_LANCHOR4)[param_2]];
    puVar6 = (ushort *)((int)&_LANCHOR3 + (uint)(byte)(&_LANCHOR4)[param_2] * 2);
    uVar1 = *puVar6;
    uVar2 = (ushort)(1 << (param_1 & 0x1f));
    if (param_3 == 1) {
      _LANCHOR0 = _LANCHOR0 | uVar2;
      *puVar6 = uVar2 | uVar1;
      if (uVar1 != 0) goto _L42;
      pcVar5 = *(code **)(iVar3 + 0xb4);
    }
    else {
      _LANCHOR0 = _LANCHOR0 & ~uVar2;
      uVar2 = ~uVar2 & uVar1;
      *puVar6 = uVar2;
      if ((uVar1 == 0) || (uVar2 != 0)) goto _L42;
      pcVar5 = *(code **)(iVar3 + 0xb8);
    }
  }
  (*pcVar5)(1,uVar4,pcVar5);
_L42:
  iVar3 = coex_hook_check_wifi_sleep();
  if (iVar3 != 0) {
    iVar3 = 1;
  }
                    /* WARNING: Could not recover jumptable at 0x00010346. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0xac))(iVar3);
  return;
}

