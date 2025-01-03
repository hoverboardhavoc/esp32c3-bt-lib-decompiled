/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
 * Source: libbtdm_app -> lld.o -> lld_wl_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int lld_wl_rpa_res(void *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if ((((param_2 != (char *)0x0) && (param_1 != (void *)0x0)) && (*param_2 == '\x01')) &&
     ((*(byte *)((int)param_1 + 5) & 0xc0) == 0x40)) {
    piVar3 = &lld_wl_res_list;
    iVar1 = 0;
    do {
      if ((*piVar3 != 0) && (iVar2 = lld_rpa_res(*piVar3 + 7,param_1), iVar2 != 0)) {
        *param_2 = *(char *)(&lld_wl_res_list)[iVar1];
        memcpy(param_1,(void *)((&lld_wl_res_list)[iVar1] + 1),6);
        return iVar2;
      }
      iVar1 = iVar1 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar1 != 0xc);
  }
  return 0;
}

