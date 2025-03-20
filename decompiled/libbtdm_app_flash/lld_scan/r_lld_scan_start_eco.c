/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_start_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte r_lld_scan_start_eco(uint param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte bStack_31;
  
  bStack_31 = 0xc;
  iVar4 = r_lld_scan_start();
  bStack_31 = (byte)iVar4;
  if (iVar4 == 0) {
    iVar4 = r_ble_ll_qa_config_get();
    if (*(char *)(iVar4 + 1) == '\0') {
      iVar4 = r_sdk_config_get_opts_ext();
      if (*(short *)(iVar4 + 0x14) != 0) {
        _DAT_60031124 = 0x10001;
        iVar4 = r_sdk_config_get_opts_ext();
        uVar2 = *(ushort *)(iVar4 + 0x14);
        if ((uVar2 & 0xfe00) != 0) {
          r_assert_err(0,"lld_scan.c",0x29ed);
        }
        _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | (uint)uVar2;
      }
    }
    else {
      _DAT_60031124 = 0x10001;
      _DAT_60031364 = _DAT_60031364 & 0xfffffe00 | 1;
    }
    if ((bStack_31 == 0) && (_lld_scan_env != 0)) {
      iVar4 = 0;
      while( true ) {
        iVar7 = *(int *)(_lld_scan_env + iVar4 * 4);
        if (iVar7 != 0) {
          bVar1 = *(byte *)(iVar7 + 0x38);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          iVar3 = (uint)bVar1 * 0x5a;
          uVar2 = *(ushort *)(iVar5 + iVar3);
          iVar5 = r_emi_get_mem_addr_by_offset(0x400);
          uVar6 = *(undefined4 *)(iVar7 + 4);
          *(ushort *)(iVar5 + iVar3) = uVar2 & 0xffdf;
          (&_LANCHOR0)[iVar4] = uVar6;
        }
        if (iVar4 == 1) break;
        iVar4 = 1;
      }
    }
  }
  r_lld_scan_start_hook_part_1(&bStack_31,param_2);
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 8) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x1
              (0x40010000,(uint)*(byte *)(param_2 + 7) << 8 | (uint)bStack_31 << 0x10 | param_1);
  }
  iVar4 = r_sdk_config_get_opts_ext();
  if (((*(uint *)(iVar4 + 0x28) & 8) != 0) &&
     (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
    r_ble_log_internal_x2(0x40010005,_DAT_60031124,_DAT_60031364 & 0x1ff);
  }
  return bStack_31;
}

