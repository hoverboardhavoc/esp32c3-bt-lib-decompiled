/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_cca.o -> r_lld_cca_config_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_config_init(uint param_1,char param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar2 = r_sdk_config_get_opts_ext();
  iVar1 = p_lld_cca;
  if (*(char *)(iVar2 + 0x19) == '\x02') {
    *(short *)(p_lld_cca + 4) = (short)param_1;
    *(char *)(iVar1 + 7) = -param_2;
    if (param_3 != 0) {
      *(char *)(iVar1 + 0x1a) = (char)param_3;
    }
    if (param_4 == 0) {
      if (((param_1 & 0x10) == 0) || (param_1 >> 0xc == 4)) {
        uVar3 = 0x40;
      }
      else {
        uVar3 = 0x60;
      }
    }
    else {
      uVar3 = (undefined2)((param_4 * 1000) / 0x271);
    }
    *(undefined2 *)(iVar1 + 0x10) = uVar3;
    if (param_5 != 0) {
      *(short *)(iVar1 + 0x12) = (short)((param_5 * 1000) / 0x271);
    }
    if ((param_1 & 4) != 0) {
      _sdk_cfg_priv_opts = 400;
    }
    if (param_1 >> 0xc == 4) {
      _DAT_60011084 = _DAT_60011084 | 2;
    }
    else {
      _DAT_60011084 = _DAT_60011084 & 0xfffffffd;
    }
  }
  return;
}

