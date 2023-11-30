/*
 * Last changed at upstream commit a075a8fde411bdd92973051edf2cd234601b259c
 * https://github.com/espressif/esp32c3-bt-lib/commit/a075a8fde411bdd92973051edf2cd234601b259c
 * Upstream date: 2023-11-30 21:15:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(70ab55f)
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
  size_t __n;
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
        iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
        __src = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                                  ((iVar2 + (uVar3 & 0xff) * 0x1a + 0x648) * 0x20000 >> 0x10,
                                   *(code **)(_r_plf_funcs_p + 0xbc));
        __n = 0x10;
        goto _L277;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 10);
    if (param_3 == 0) {
      piVar4 = &lld_wl_res_list;
      iVar2 = 0;
      do {
        if ((*piVar4 != 0) && (iVar1 = lld_rpa_res(*piVar4 + 7,param_1), iVar1 != 0)) {
          __n = 6;
          *param_2 = *(byte *)(&lld_wl_res_list)[iVar2];
          __src = (void *)((&lld_wl_res_list)[iVar2] + 1);
_L277:
          memcpy(param_1,__src,__n);
          return iVar1;
        }
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar2 != 0xc);
    }
  }
  return 0;
}

