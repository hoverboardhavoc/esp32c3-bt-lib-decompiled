/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_init
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
  ushort uVar4;
  undefined1 uStack_29;
  undefined1 auStack_28 [24];
  
  if (param_1 != 1) {
    if (param_1 != 2) goto _L564;
    if (_lld_rpa_renew_env != 0) {
      r_ke_free();
    }
  }
  pvVar2 = _p_lld_env;
  memcpy(auStack_28,(void *)((int)_p_lld_env + 0x104),0x18);
  memset(pvVar2,0,0x11c);
  memcpy((void *)((int)_p_lld_env + 0x104),auStack_28,0x18);
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x19) == '\x02') {
    r_lld_cca_sw_init();
  }
  else {
    iVar3 = r_sdk_config_get_opts_ext();
    if ((*(char *)(iVar3 + 0x19) == '\x01') || (sdk_cfg_priv_opts != '\0')) {
      r_lld_cca_data_reset();
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
  uVar4 = 7;
  uVar1 = *(ushort *)((int)_p_lld_env + 0xd4);
  if ((((0x14 < uVar1) && (uVar4 = 6, 0x1e < uVar1)) && (uVar4 = 5, 0x32 < uVar1)) &&
     (((uVar4 = 4, 0x4b < uVar1 && (uVar4 = 3, 100 < uVar1)) && (uVar4 = 2, 0x96 < uVar1)))) {
    uVar4 = (ushort)(uVar1 < 0xfb);
  }
  *(ushort *)((int)_p_lld_env + 0xd6) = uVar4;
  uStack_29 = 1;
  (*_rwip_param)(0x85,&uStack_29,(int)pvVar2 + 0xda,_rwip_param);
  aa_gen = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  DAT_00014095 = 0;
  DAT_00014096 = 0;
_L564:
  r_lld_core_init(param_1);
  r_lld_adv_init(param_1);
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x18) != '\0') {
    r_lld_per_adv_init(param_1);
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x23) != '\0') {
    r_lld_scan_init(param_1);
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x18) != '\0') {
    r_lld_sync_init(param_1);
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x22) != '\0') {
    r_lld_init_init(param_1);
  }
  iVar3 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar3 + 0x1f) != '\0') {
    r_lld_test_init(param_1);
  }
  r_lld_con_init(param_1);
  r_lld_reset_reg();
  memset(&lld_rpa_res_list,0,0x82);
  return;
}

