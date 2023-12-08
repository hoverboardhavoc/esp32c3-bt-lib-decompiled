/*
 * Last changed at upstream commit bb9f0f59db474924c9288ab92aed1abb88bc9419
 * https://github.com/espressif/esp32c3-bt-lib/commit/bb9f0f59db474924c9288ab92aed1abb88bc9419
 * Upstream date: 2023-12-08 13:35:16 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(65db61f)
 * Source: libbtdm_app -> lld.o -> lld_wl_rpa_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int lld_wl_rpa_res(void *param_1,byte *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *__src;
  uint uVar3;
  int *piVar4;
  
  if ((((param_2 != (byte *)0x0) && (param_1 != (void *)0x0)) && (*param_2 != 0)) &&
     ((*(byte *)((int)param_1 + 5) & 0xc0) == 0x40)) {
    uVar3 = 0;
    do {
      iVar1 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
      if ((*(short *)(iVar1 + uVar3 * 0x34) < 0) &&
         (iVar1 = lld_peer_rpa_res(param_1,uVar3 & 0xff), iVar1 != 0)) {
        iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        *param_2 = (byte)*(undefined2 *)(iVar2 + uVar3 * 0x34) & 1;
        __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                  ((uVar3 & 0xff) * 0x34 + 0xc78,*(code **)(_r_plf_funcs_p + 0xbc));
        goto _L280;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 10);
    if (param_3 == 0) {
      piVar4 = &lld_wl_res_list;
      iVar2 = 0;
      do {
        if ((*piVar4 != 0) && (iVar1 = lld_rpa_res(*piVar4 + 7,param_1), iVar1 != 0)) {
          *param_2 = *(byte *)(&lld_wl_res_list)[iVar2];
          __src = (void *)((&lld_wl_res_list)[iVar2] + 1);
_L280:
          memcpy(param_1,__src,6);
          return iVar1;
        }
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar2 != 0xc);
    }
  }
  return 0;
}

