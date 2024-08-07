/*
 * Last changed at upstream commit ef1dfc518572e9cda55f13906e32207b40ee280b
 * https://github.com/espressif/esp32c3-bt-lib/commit/ef1dfc518572e9cda55f13906e32207b40ee280b
 * Upstream date: 2024-08-07 12:57:51 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(f583012)
 * Source: libbtdm_app -> lld.o -> r_lld_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init(int param_1)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  undefined2 uVar4;
  code *pcVar5;
  undefined1 uStack_29;
  undefined1 auStack_28 [24];
  
  if (param_1 != 1) {
    if (param_1 != 2) goto _L161;
    if (_lld_rpa_renew_env != 0) {
      (**(code **)(_r_modules_funcs_p + 0x110))(*(code **)(_r_modules_funcs_p + 0x110));
    }
  }
  pvVar2 = _p_lld_env;
  memcpy(auStack_28,(void *)((int)_p_lld_env + 0x104),0x18);
  memset(pvVar2,0,0x11c);
  memcpy((void *)((int)_p_lld_env + 0x104),auStack_28,0x18);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar3 + 0x19) == '\x02') {
    pcVar5 = *(code **)(_r_ip_funcs_p + 0x948);
_L186:
    (*pcVar5)(pcVar5);
  }
  else {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(char *)(iVar3 + 0x19) == '\x01') || (sdk_cfg_priv_opts != '\0')) {
      pcVar5 = *(code **)(_r_ip_funcs_p + 0x4a4);
      goto _L186;
    }
  }
  pvVar2 = _p_lld_env;
  iVar3 = 0;
  do {
    *(char *)((int)pvVar2 + iVar3 + 0xdb) = (char)iVar3;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0x25);
  *(undefined1 *)((int)pvVar2 + 0x100) = 0x25;
  _lld_rpa_renew_env = 0;
  uStack_29 = 2;
  iVar3 = (*_rwip_param)(7,&uStack_29,(int)pvVar2 + 0xd4,_rwip_param);
  if (iVar3 != 0) {
    *(undefined2 *)((int)_p_lld_env + 0xd4) = 500;
  }
  pvVar2 = _p_lld_env;
  uVar1 = *(ushort *)((int)_p_lld_env + 0xd4);
  if (uVar1 < 0x15) {
    uVar4 = 7;
_L187:
    *(undefined2 *)((int)_p_lld_env + 0xd6) = uVar4;
  }
  else {
    if (uVar1 < 0x1f) {
      uVar4 = 6;
      goto _L187;
    }
    if (uVar1 < 0x33) {
      uVar4 = 5;
      goto _L187;
    }
    if (uVar1 < 0x4c) {
      uVar4 = 4;
      goto _L187;
    }
    if (uVar1 < 0x65) {
      uVar4 = 3;
      goto _L187;
    }
    if (uVar1 < 0x97) {
      uVar4 = 2;
      goto _L187;
    }
    if (uVar1 < 0xfb) {
      uVar4 = 1;
      goto _L187;
    }
    *(undefined2 *)((int)_p_lld_env + 0xd6) = 0;
  }
  uStack_29 = 1;
  (*_rwip_param)(0x85,&uStack_29,(int)pvVar2 + 0xda,_rwip_param);
  aa_gen = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  DAT_00012049 = 0;
  DAT_0001204a = 0;
_L161:
  (**(code **)(_r_ip_funcs_p + 0x238))(param_1,*(code **)(_r_ip_funcs_p + 0x238));
  (**(code **)(_r_ip_funcs_p + 0x1c0))(param_1,*(code **)(_r_ip_funcs_p + 0x1c0));
  (**(code **)(_r_ip_funcs_p + 0x2f8))(param_1,*(code **)(_r_ip_funcs_p + 0x2f8));
  (**(code **)(_r_ip_funcs_p + 0x400))(param_1,*(code **)(_r_ip_funcs_p + 0x400));
  (**(code **)(_r_ip_funcs_p + 0x158))(param_1,*(code **)(_r_ip_funcs_p + 0x158));
  (**(code **)(_r_ip_funcs_p + 0x470))(param_1,*(code **)(_r_ip_funcs_p + 0x470));
  (**(code **)(_r_ip_funcs_p + 0x20c))(param_1,*(code **)(_r_ip_funcs_p + 0x20c));
  (**(code **)(_r_ip_funcs_p + 0x364))(param_1,*(code **)(_r_ip_funcs_p + 0x364));
  (**(code **)(_r_ip_funcs_p + 0x270))(*(code **)(_r_ip_funcs_p + 0x270));
  lld_rpa_res_list_init();
  return;
}

