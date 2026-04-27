/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_scan.o -> r_lld_scan_frm_skip_isr_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_skip_isr_eco(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = _r_ip_funcs_p;
  bVar2 = false;
  if (_lld_scan_env != 0) {
    iVar6 = *(int *)(_lld_scan_env + param_1 * 4);
    if (iVar6 != 0) {
      cVar1 = *(char *)(iVar6 + 0x3d);
      bVar4 = *(byte *)((int)&scan_skip_count + param_1) + 1;
      *(byte *)((int)&scan_skip_count + param_1) = bVar4;
      bVar2 = cVar1 == '\x01';
      iVar3 = (**(code **)(iVar3 + 0x264))(*(code **)(iVar3 + 0x264));
      uVar5 = (uint)bVar4 << 2;
      if (0x20 < uVar5) {
        uVar5 = 0x20;
      }
      *(uint *)(iVar6 + 4) = uVar5 + iVar3 & 0xffffffe;
    }
  }
  r_lld_scan_frm_skip_isr(param_1);
  if ((((bVar2) && (_lld_scan_env != 0)) && (*(int *)(param_1 * 4 + _lld_scan_env) != 0)) &&
     (*(char *)(_lld_scan_env + 0x17) != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x00013178. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x930))(*(code **)(_r_ip_funcs_p + 0x930));
    return;
  }
  return;
}

